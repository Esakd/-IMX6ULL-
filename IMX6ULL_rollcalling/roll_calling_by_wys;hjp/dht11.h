#ifndef DHT11_H
#define DHT11_H

#include <QObject>
#include <QThread>
#include <QFile>
#include <QDebug>
class Dht11 : public QThread
{

    Q_OBJECT

public:
    Dht11();
protected:
    void run();
signals:
    void updateDht11Data(QString humi,QString temp);
private:
    QFile file;
};

#endif // DHT11_H
