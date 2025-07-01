/******************************************************************
Copyright © Deng Zhimao Co., Ltd. 1990-2030. All rights reserved.
* @projectName   sensor
* @brief         ap3216c.h
* @author        Deng Zhimao
* @email         1252699831@qq.com
* @date          2020-07-10
*******************************************************************/
#ifndef AP3216C_H
#define AP3216C_H

#include <QObject>
#include <QTimer>

class Ap3216c : public QObject
{
    Q_OBJECT

public:
    explicit Ap3216c(QObject *parent = 0);
    ~Ap3216c();

private:
    QString alsdata;
    QString psdata;
    QString irdata;
public:
    QString alsData();
    QString psData();
    QString irData();

    QString readAlsData();
    QString readPsData();
    QString readIrData();


};

#endif // AP3216C_H
