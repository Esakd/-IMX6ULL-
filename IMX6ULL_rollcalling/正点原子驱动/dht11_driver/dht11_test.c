#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <poll.h>
#include <stdint.h>

#define DEV_NAME   "/dev/dht11"

void sleep_ms(unsigned int ms)
{
    struct timeval delay;
	delay.tv_sec = 0;
	delay.tv_usec = ms * 1000; 
	select(0, NULL, NULL, NULL, &delay);
}

int main(int argc, char **argv)
{
	int fd;
    int ret;
  
    struct pollfd fds[1];
	
	/* 2. 打开文件 */
	fd = open(DEV_NAME, O_RDWR);   // | O_NONBLOCK

	if (fd < 0)
	{
		printf("can not open file %s, %d\n", DEV_NAME, fd);
		return -1;
	}

    uint8_t dht11_data[5];
    while (1)
    {
        if ((ret = read(fd, dht11_data, sizeof(dht11_data))) == sizeof(dht11_data))
        {
            printf("temp %d.%d  humi %d.%d\r\n", dht11_data[2], dht11_data[3], dht11_data[0], dht11_data[1]);  
        }
        else
        {
            printf("get temp err %d\r\n", ret);
        }
        sleep_ms(500);   
    }
}

