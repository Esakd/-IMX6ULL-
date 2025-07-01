#ifndef WEATHER_H
#define WEATHER_H

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

namespace Ui {
class Weather;
}

class Weather : public QMainWindow
{
    Q_OBJECT

public:
    explicit Weather(QWidget *parent = nullptr);
    ~Weather();
    QString TransDataToWeek(QString Data);
    QString TransDataToMyData(QString Data);
    QString TransTempToStr(QString tmpDay,QString tmpNight);
    QString SelectWeatherImg(QString WeatherDes);
    void updateInfo();
private:
    Ui::Weather *ui;
    QNetworkAccessManager netManager;
    QNetworkRequest request;
    QList<QString> weather_data;
    QList<QString> weather_wea;
    QList<QString> weather_wea_img;
    QList<QString> weather_tem_day;
    QList<QString> weather_tem_night;
    QList<QString> weather_win;
    QList<QString> weather_win_speed;
    QString cityName;
    QString UpdateTime;
private slots:
    void getWeatherInfo(QNetworkReply *reply);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

};

#endif // WEATHER_H
