#include "dht11.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
Dht11::Dht11()
{

}

void Dht11::run()
{
    unsigned char date[5]={0};
   QString humidity ,temp;
   unsigned char tmp=0 ;
   int ret;

#if __arm__
   int fd = open("/dev/dht11",O_RDWR);
   if(fd<0)
   {
       qDebug()<<"can't open /dev/dht11";
       return;
   }

   while (1) {
       if((ret = read(fd, date, sizeof(date))) != sizeof(date))
       {
           continue;
       }
       tmp = 0;
       tmp+=date[0];
       tmp+=date[1];
       tmp+=date[2];
       tmp+=date[3];
       if(tmp==date[4])
       {
           humidity = QString("%1.%2").arg(date[0]).arg(date[1]);
           temp = QString("%1.%2").arg(date[2]).arg(date[3]);
       }
       else
       {
           humidity = "error";
           temp = "error";
       }
       emit updateDht11Data(humidity, temp);
       usleep(500000);
   }
#else
    while(1)
    {
        humidity = "23.1";
        temp = "32.5";
        emit updateDht11Data(humidity, temp);
        usleep(500000);
    }
#endif
}
