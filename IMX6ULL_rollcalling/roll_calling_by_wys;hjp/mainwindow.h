#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QParallelAnimationGroup>
#include "settingwindow.h"
#include "clock.h"
#include "dht11.h"
#include "Map/baidumap.h"
#include "Music/musicplayer.h"
#include "Weather/weather.h"
#include "Monitor/monitor.h"
#include "speechrecognition.h"
#include "onevideo.h"
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void SendCommandToMusic(int);
    void SendCommandToMap(int);
    void SendCommandToMonitor(int);
private slots:
    void on_pBtn_Setting_clicked();
    void on_update_humidity_temp(QString, QString);
    void getSpeechResult(QNetworkReply *reply);

    void on_pBtn_Music_clicked();

    void on_pBtn_Weather_clicked();

    void on_pBtn_Monitor_clicked();

    void on_pBtn_Map_clicked();
    void on_timer_updateTime();

    void on_handleRecord();

private:
    Ui::MainWindow *ui;
    Clock clock;
    OneVideo oneVideo;
    SettingWindow settingWindow;
    bool eventFilter(QObject *watched, QEvent *event);
    QParallelAnimationGroup *myAnimationGroup;
    Dht11 *dht11;

    // QObject interface
    Monitor *monitor;
    Weather *weather;
    MusicPlayer *musicPlayer;
    BaiduMap *baiduMap;
    QTimer *time;
    SpeechRecognition *AsrThread;
    QNetworkAccessManager *networkManage;
    QNetworkRequest *request;
    QVector<QMainWindow *> windows;

};
#endif // MAINWINDOW_H
