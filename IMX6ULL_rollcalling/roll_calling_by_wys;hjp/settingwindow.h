#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QDir>
#include <QFile>
#include <QMediaObject>
#include <QTimer>
#include <QTime>
#include <QDate>
#include <QProcess>
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class SettingWindow;
}

class SettingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = nullptr);
    ~SettingWindow();
    void ScanGif();
private slots:
    void on_pushButton_8_clicked();

    void on_pBtn_PauseGif_clicked(bool checked);

    void on_pBtn_SwitchGif_clicked();

    void on_pBtn_ModifyDate_clicked();

    void on_pBtn_ModifyTime_clicked();
    void on_timer_updateTime();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::SettingWindow *ui;
    QString LocalGifPath="/MyGif";
    QMovie *movie = new QMovie;
    QVector<QString> gif_Files;
    int currentGifIndex=0;
    int GifSum=0;
    QTimer *timer;
    QProcess process;

};

#endif // SETTINGWINDOW_H
