

#include <linux/module.h>
#include <linux/delay.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/major.h>
#include <linux/stat.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/gpio/consumer.h>
#include <linux/platform_device.h>
#include <linux/of_gpio.h>
#include <linux/cdev.h>
#include <linux/spinlock.h>
#include <linux/uaccess.h>
typedef unsigned char  uint8_t;

#define DEV_DTS_NODE_PATH    "/dht11"               
#define DEV_PIN_DTS_NAME     "dht11-gpios"       
#define DEV_NAME             "dht11"                 
#define DEV_DTS_COMPATIBLE   "xgj,dht11"             



 struct oneWire
{
	int gpio;
	int irq;
	dev_t dev_no;
	struct cdev chrdev;
	struct class *class;
	spinlock_t lock;
};

struct oneWire dht11_dev;


#define OneWire_PIN               dht11_dev.gpio
#define OneWire_IO_OUT()          gpio_direction_output(OneWire_PIN, 1);
#define OneWire_IO_IN()           gpio_direction_input(OneWire_PIN)
#define OneWire_WRITE(bit)        gpio_set_value(OneWire_PIN, bit)
#define OneWire_READ()            gpio_get_value(OneWire_PIN)


static int OneWire_wait_for_ready(void)
{   
    int timeout;

    timeout = 400;
    while (OneWire_READ() && timeout)      /* 等待低电平到来 */
    {
        udelay(1);
        --timeout;
    }
    if (!timeout) 
    {
        printk("timeout %d\n", __LINE__);
        return -1;    /* 超时 */
    }

    timeout = 1000;
    while (!OneWire_READ() && timeout)      /* 等待高电平到来    */
    {
        udelay(1);
        --timeout;
    }
    if (!timeout) 
    {
        printk("timeout %d\n", __LINE__);
        return -1;    /* 超时 */
    }

    timeout = 1000;
    while (OneWire_READ() && timeout)  /* 等待高电平结束 */
    {
        udelay(1);
        --timeout;
    }
    if (!timeout) 
    {
        printk("timeout %d\n", __LINE__);
        return -1;    /* 超时 */
    }

    return 0;
}

static int OneWire_start(void)      
{
    OneWire_IO_OUT();
    OneWire_WRITE(0);
    mdelay(20);
    OneWire_WRITE(1);
    udelay(30);
    OneWire_IO_IN();          /* 设置为输入 */ 
    udelay(2);
   
    if (OneWire_wait_for_ready()) return -1;
    return 0;
}

static int OneWire_read_byte(unsigned char *byte)
{
    unsigned char i;
    unsigned char bit = 0;
    unsigned char data = 0;
    int timeout = 0;   
    
    for (i = 0; i < 8; i++)
    {
        timeout = 1000;  
        while (OneWire_READ() && timeout)   /* 等待变为低电平 */
        {
            udelay(1);
            --timeout;
        }
        if (!timeout) 
        {
            printk("timeout %d\n", __LINE__);         
            return -1;           /* 超时 */
        }

        timeout = 1000;
        while (!OneWire_READ() && timeout)    /* 等待变为高电平 */
        {
            udelay(1);
            --timeout;
        }
        if (!timeout) 
        {
            printk("timeout %d\n", __LINE__);
            return -1;           /* 超时 */
        }
        udelay(40);
        
        bit = OneWire_READ();

        data <<= 1;            
        if (bit) 
        {
            data |= 0x01;
        #if 0
            timeout = 1000;
            while (OneWire_READ() && timeout)    /* 等待高电平结束 */
            {
                udelay(1);
                --timeout;
            }
            if (!timeout) 
            {
                printk("timeout %d\n", __LINE__);
                return -1;           /* 超时 */
            }
        #endif
        }
        // data <<= 1;          /* 导致错误的原因 ： 移位要放前面，不能放在这里，若放在后面一旦获取最后一个位就会多移动一位导致数据不对 */
    }

    *byte = data;
    return 0;
}


/* 使设备只能被一个进程打开 */
static int _drv_open (struct inode *node, struct file *file)   
{
    printk("dht11 open\n");
    return 0;
}

static ssize_t _drv_read(struct file *filp, char __user *buf, size_t size, loff_t *offset)
{
    int ret;
    int i;
    unsigned  char data[5] = {0};
    unsigned long flags;

    if (size != 5) return -EINVAL;
    
    /* 关闭中断,防止时序被中断破坏 */
    spin_lock_irqsave(&dht11_dev.lock, flags);
    
    /* 启动信号 */
    if (OneWire_start() != 0)
    {
        printk("dht11 start failed\n");
        ret = -EFAULT;
        goto failed1;
    }

    /* 读出5字节数据 */
    for (i = 0; i < 5; i++)    
    {
        if (OneWire_read_byte(&data[i]))
        {
            printk("read data err\n");
            ret = -EAGAIN;
            goto failed1;
        }
    }
    
     /* 打开中断 */
    spin_unlock_irqrestore(&dht11_dev.lock, flags);
        /* 校验数据 */
    if (data[4] != (data[0]+data[1]+data[2]+data[3]))
    {
        printk("check data failed\n");
        ret = -EAGAIN;
        goto failed1;
    }
    
    /* 将数据拷贝回用户空间 */
	if (copy_to_user(buf, data, 5)) 
    {
        ret = -EFAULT;
    } 
    else 
    {
        ret = 5;
    }

    return ret;
failed1:
    spin_unlock_irqrestore(&dht11_dev.lock, flags);
    return ret;
}

static int _drv_release(struct inode *node, struct file *file)
{
    printk("dht11 release\n");
    return 0;
}

static struct file_operations drv_file_ops = { 
	.owner	= THIS_MODULE,
	.open   = _drv_open,
    .read   = _drv_read,
    .release = _drv_release,
};

/* 设备树的匹配列表 */
static struct of_device_id dts_match_table[] = {
    {.compatible = DEV_DTS_COMPATIBLE, },                     /* 通过设备树来匹配 */
};

static int _driver_probe(struct platform_device *pdev)
{ 
	
    int err;
	
    struct device *ds_dev;
    struct device_node *dev_node;
    
    struct device_node *node = pdev->dev.of_node;
	printk("dht11 func: %s, line:%d \n", __FUNCTION__,__LINE__);
    if (!node) {          
        printk("hc-sr501 dts node can not found!\r\n");    
        return -EINVAL; 
    }
	printk("dht11 func: %s, line:%d \n", __FUNCTION__,__LINE__);
    dev_node = of_find_node_by_path(DEV_DTS_NODE_PATH);       /* 找到dht11的设备树节点  */
    if (IS_ERR(dev_node)) {          
        printk("dht11 DTS Node not found!\r\n"); 
        return PTR_ERR(dev_node); 
    }
	printk("dht11 func: %s, line:%d \n", __FUNCTION__,__LINE__);
    dht11_dev.gpio = of_get_named_gpio(dev_node, DEV_PIN_DTS_NAME, 0);   /* 获取dht11的gpio编号 */
    if ( dht11_dev.gpio < 0) {
        printk("dht11-gpio not found!\r\n"); 
        return -EINVAL;
    }
	printk("dht11 func: %s, line:%d \n", __FUNCTION__,__LINE__);
    err = gpio_request(dht11_dev.gpio, DEV_PIN_DTS_NAME);  
	if(err) 
    {
		printk("gpio_request gpio is failed!\n");
        return -EINVAL;
	}
	
    printk("dht11 gpio %d\n", dht11_dev.gpio);

    /* 内核自动分配设备号 */
    err = alloc_chrdev_region(&dht11_dev.dev_no, 0, 1, DEV_NAME);        
	if (err < 0) {
		pr_err("Error: failed to register mbochs_dev, err: %d\n", err);
        goto failed3;
	}

	cdev_init(&dht11_dev.chrdev, &drv_file_ops);

	cdev_add(&dht11_dev.chrdev, dht11_dev.dev_no, 1);

    dht11_dev.class = class_create(THIS_MODULE, DEV_NAME);
	if (IS_ERR(dht11_dev.class)) {   
        err = PTR_ERR(dht11_dev.class);
        goto failed1;
	}

    /* 创建设备节点 */
    ds_dev = device_create(dht11_dev.class , NULL, dht11_dev.dev_no, NULL, DEV_NAME); 
    if (IS_ERR(ds_dev)) {       /* 判断指针是否合法 */
        err = PTR_ERR(ds_dev);
		goto failed2;
	}
	
    spin_lock_init(&dht11_dev.lock);          /* 初始化自旋锁 */
    printk("dht11 probe success\r\n");
    return 0;
failed2:
    device_destroy(dht11_dev.class, dht11_dev.dev_no);
    class_destroy(dht11_dev.class);
failed1:
    unregister_chrdev_region(dht11_dev.dev_no, 1);
    cdev_del(&dht11_dev.chrdev);
failed3:
    gpio_free(dht11_dev.gpio);
    return err;
}

static int _driver_remove(struct platform_device *pdev)
{
    device_destroy(dht11_dev.class, dht11_dev.dev_no);
	class_destroy(dht11_dev.class);
	unregister_chrdev_region(dht11_dev.dev_no, 1);
    cdev_del(&dht11_dev.chrdev);
    gpio_free(dht11_dev.gpio);

    printk(KERN_INFO"dht11 remove success\n");

    return 0;
}

static struct platform_driver _platform_driver = {
      .probe = _driver_probe,
      .remove = _driver_remove,
      .driver = {
        .name = DEV_DTS_COMPATIBLE,
        .owner = THIS_MODULE,
        .of_match_table = dts_match_table,         /* 通过设备树匹配 */
      },
};

/* 入口函数 */ 
static int __init _driver_init(void)
{
    int ret;
    printk("dht11 %s\n", __FUNCTION__);
    
    ret = platform_driver_register(&_platform_driver);   //注册platform驱动
    printk("dht11 %s\n over", __FUNCTION__);
    return ret;
}

/*  出口函数 */
static void __exit _driver_exit(void)
{
    printk("dht11  %s\n", __FUNCTION__);
    platform_driver_unregister(&_platform_driver);
}

module_init(_driver_init);
module_exit(_driver_exit);

MODULE_LICENSE("GPL");

