#ifndef BAIDUMAP_H
#define BAIDUMAP_H

#include "gps.h"
#include <QMainWindow>
#include <QTimer>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QDebug>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QVector>
#include <QFile>
#include <QDate>
#include <QSslSocket>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QAudioRecorder>
#include <QPair>
#include <QPainter>
#include <QDebug>

#define MAP_COMMAND_CLOSE 0
#define MAP_COMMAND_SHOW 1
#define MAP_COMMAND_AMPLIFY 2
#define MAP_COMMAND_SHRINK 3


namespace Ui {
class BaiduMap;
}

class BaiduMap : public QMainWindow
{
    Q_OBJECT

public:
    explicit BaiduMap(QWidget *parent = nullptr);
    ~BaiduMap();

private:
    Ui::BaiduMap *ui;
private:
    QNetworkAccessManager netManager;
    QNetworkRequest request;
    QFile file;
    char N_S_Flag = 'N';
    char E_W_Flag = 'E';
    double jingdu = 113.3800;
    double weidu = 34.3500;

    int img_Zoom=10;
    int img_Zoon_Min=3;
    int img_Zoom_Max=18;
    int img_Width=1024;
    int img_Height=600;
    QString MapImgUrl="http://api.map.baidu.com/staticimage/v2?ak=qpl1IIdlgxP12rKmNwlVZ3flcuAllu1e"
                        "&width=1024&height=600&scale=1&copyright=1&center=%1&markers=%1&zoom=%2";
private:
    void updateMap();
public slots:
    void ReceiveMapImg(QNetworkReply *reply);

    void on_pBtn_ZoomUp_clicked();
    void on_pBtn_ZoomDown_clicked();
    void on_pBtn_Close_clicked();
    void on_handleCommand(int);
};

#endif // BAIDUMAP_H
