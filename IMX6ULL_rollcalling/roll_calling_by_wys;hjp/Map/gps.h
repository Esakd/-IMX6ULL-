#ifndef GPS_H
#define GPS_H

#ifdef __cplusplus
extern "C"{
#endif



static char dataBuf[100];
static int OneFramFlag;
static int OneFramStart = 0;
static int saveData_location=0;
static int gps_fd;
static char* gps_device = "/dev/ttymxc2";

static int gps_valid=0;

int gps_init();
//int set_gps_async_update();
int analyseRawData();
int getGpsData(char* N_S_Flag,char *E_W_Flag,double *jingdu,double *weidu);
#ifdef __cplusplus
}
#endif

#endif
