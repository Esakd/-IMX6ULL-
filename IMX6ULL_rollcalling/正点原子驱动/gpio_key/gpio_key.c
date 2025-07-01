#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/ide.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/gpio.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_gpio.h>
#include <linux/semaphore.h>
#include <asm/mach/map.h>
#include <asm/uaccess.h>
#include <asm/io.h>

#define KEY_CNT 1
#define KEY_NAME "key"
#define KEY0VALUE 0xF0
#define INVAKEY 0x00

struct key_dev{
	dev_t devid;
	struct cdev cdev;
	struct class *class;
	struct device *device;
	int major;
	int minor;
	struct device_node *nd;
	int key_gpio;
	atomic_t keyValue;
};

struct key_dev keydev;

static int keyio_init(void)
{
	keydev.nd = of_find_node_by_name(NULL,"mykey");
	if(keydev.nd==NULL){
		printk("can't find node by path:/gpio_keys\n");
		return -EINVAL;
	}
	keydev.key_gpio = of_get_named_gpio(keydev.nd,"gpios",0);
	if(keydev.key_gpio<0)
	{
		printk("Can't get key0\n");
		return -EINVAL;
	}
	printk("key_gpio=%d\n",keydev.key_gpio);
	gpio_request(keydev.key_gpio,"key0");
	gpio_direction_input(keydev.key_gpio);
	return 0;
}

static int key_open(struct inode *inode,struct file*flip)
{
	int ret = 0;
	flip->private_data = &keydev;
	ret = keyio_init();
	if(ret<0)
		return ret;
	return 0;
}

static ssize_t key_read(struct file*flip,char __user *buf,size_t cnt,loff_t *offt)
{
	int ret = 0;
	char data;
	char value;
	struct key_dev *dev = flip->private_data;

	if(gpio_get_value(dev->key_gpio)==0){
		//while(!gpio_get_value(dev->key_gpio));
		atomic_set(&dev->keyValue,KEY0VALUE);
		//value = KEY0VALUE;
	}else{
		//value = INVAKEY;
		atomic_set(&dev->keyValue,INVAKEY);
	}
	value = atomic_read(&dev->keyValue);
	ret = copy_to_user(buf,&value,sizeof(value));
	return ret;
	/*
	struct key_dev *dev = flip->private_data;

	if(gpio_get_value(dev->key_gpio)==0){
		data = 0;
		//printk("key pressed");
	}else{
		data = 1;
		//printk("key released");
	}
	ret = copy_to_user(buf,&data,sizeof(data));
	return ret;
*/
}

static struct file_operations key_fops = {
	.owner = THIS_MODULE,
	.open = key_open,
	.read = key_read,
};


static int __init mykey_init(void)
{
    printk("%s-%d\n",__func__,__LINE__);
	atomic_set(&keydev.keyValue,INVAKEY);
	if(keydev.major)
	{
		keydev.devid = MKDEV(keydev.major,0);
		register_chrdev_region(keydev.devid,KEY_CNT,KEY_NAME);
	}else {
		alloc_chrdev_region(&keydev.devid,0,KEY_CNT,KEY_NAME);
		keydev.major = MAJOR(keydev.devid);
		keydev.minor = MINOR(keydev.devid);
	}
	/*初始化 cdev*/
	printk("%s-%d",__func__,__LINE__);
	keydev.cdev.owner = THIS_MODULE;
	cdev_init(&keydev.cdev,&key_fops);
	printk("%s-%d\n",__func__,__LINE__);

	cdev_add(&keydev.cdev,keydev.devid,KEY_CNT);

	keydev.class = class_create(THIS_MODULE, KEY_NAME);
	if(IS_ERR(keydev.class))
	{
		return PTR_ERR(keydev.class);
	}
	printk("%s-%d\n",__func__,__LINE__);

	/*创建 设备*/
	keydev.device = device_create(keydev.class,NULL,keydev.devid,NULL,KEY_NAME);
	if(IS_ERR(keydev.device))
	{
		return PTR_ERR(keydev.device);
	}
	printk("%s-%d\n",__func__,__LINE__);
	return 0;
}

static void __exit mykey_exit(void)
{
	printk("%s-%d\n",__func__,__LINE__);
	gpio_free(keydev.key_gpio);
	cdev_del(&keydev.cdev);
	unregister_chrdev_region(keydev.devid,KEY_CNT);
	device_destroy(keydev.class,keydev.devid);
	class_destroy(keydev.class);
	printk("%s-%d\n",__func__,__LINE__);
}

module_init(mykey_init);
module_exit(mykey_exit);
MODULE_LICENSE("GPL");

