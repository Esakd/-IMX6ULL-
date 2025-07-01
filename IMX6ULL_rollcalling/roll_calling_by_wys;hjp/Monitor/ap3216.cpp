/******************************************************************
Copyright © Deng Zhimao Co., Ltd. 1990-2030. All rights reserved.
* @projectName   sensor
* @brief         ap3216c.cpp
* @author        Deng Zhimao
* @email         1252699831@qq.com
* @date          2020-07-10
*******************************************************************/
#include "ap3216.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <QDebug>

Ap3216c::Ap3216c(QObject *parent) : QObject (parent)
{

}

Ap3216c::~Ap3216c()
{

}

QString Ap3216c::readIrData()
{
#if __arm__
    char const *filename = "/sys/class/misc/ap3216c/ir";
    int err = 0;
    int fd;
    char buf[10];

    fd = open(filename, O_RDONLY);
    if(fd < 0){
        close(fd);
        return "open file error!";
    }

    err = read(fd, buf, sizeof(buf));
    if (err < 0){
        close(fd);
        return "read data error!";
    }
    close(fd);

    QString adcValue = buf;
    QStringList list = adcValue.split("\n");
    return list[0];
#else
    return "No";
#endif
}

QString Ap3216c::readPsData()
{
#if __arm__
    char const *filename = "/sys/class/misc/ap3216c/ps";
    int err = 0;
    int fd;
    char buf[10];

    fd = open(filename, O_RDONLY);
    if(fd < 0){
        close(fd);
        return "open file error!";
    }

    err = read(fd, buf, sizeof(buf));
    if (err < 0){
        close(fd);
        return "read data error!";
    }
    close(fd);

    QString adcValue = buf;
    QStringList list = adcValue.split("\n");
    return list[0];
#else
    return "No";
#endif
}

QString Ap3216c::readAlsData()
{
#if __arm__
    char const *filename = "/sys/class/misc/ap3216c/als";
    int err = 0;
    int fd;
    char buf[10];

    fd = open(filename, O_RDONLY);
    if(fd < 0){
        close(fd);
        return "open file error!";
    }

    err = read(fd, buf, sizeof(buf));
    if (err < 0){
        close(fd);
        return "read data error!";
    }
    close(fd);

    QString adcValue = buf;
    QStringList list = adcValue.split("\n");
    return list[0];
#else
    return "No";
#endif
}

QString Ap3216c::alsData()
{
    return alsdata;
}

QString Ap3216c::irData()
{
    return irdata;
}

QString Ap3216c::psData()
{
    return psdata;
}

