
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define KEY0VALUE 0xF0
#define INVAKEY 0x00
int main()
{
    int fd,ret;
    fd = open("/dev/key",O_RDWR);
    char keyvalue;
    if(fd<0)
    {
        printf("file /dev/key open failed\n");
        return -1;
    }
    while(1)
    {
        read(fd,&keyvalue,sizeof(keyvalue));
        printf("KEY VALUE:%d\n",keyvalue);
	usleep(500000);
    }
    ret = close(fd);
    return 0;
}
