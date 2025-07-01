#ifndef MONITOR_H
#define MONITOR_H

#include <QMainWindow>
#include <QLabel>
#include <QImage>
#include <QPushButton>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QTimer>

#include "capture_thread.h"
#include "ap3216.h"
#define MONITOR_COMMAND_CLOSE 0
#define MONITOR_COMMAND_SHOW 1
namespace Ui {
class Monitor;
}

class Monitor : public QMainWindow
{
    Q_OBJECT
public:
    static Monitor* getInstance();
private:
    Monitor(QWidget *parent = nullptr);
    static Monitor* monitor;
    ~Monitor();

private:
    Ui::Monitor *ui;
    void restart();
private:
    QTimer *DisUpdate_Timer;

    /* 用于显示捕获到的图像 */
    QLabel *videoLabel;

    /* 摄像头线程 */
    CaptureThread *captureThread;

    /* 开始捕获图像按钮 */
    QPushButton *startCaptureButton;

    /* 用于开启本地图像显示 */
    QCheckBox *checkBox1;

    /* 用于开启网络广播 */
    QCheckBox *checkBox2;
    QLabel *showDistance;

    /*      Ap3216c   */
    Ap3216c *ap3216;

    /* 重写大小事件 */
    void resizeEvent(QResizeEvent *event) override;
public :
    void myStart();
    void myStop();
public slots:
    /* 显示图像 */
    void showImage(QImage);
    /* 开始采集按钮被点击 */
    void startCaptureButtonClicked(bool);
    void on_timer_timeout();
    void on_handleCommand(int);
};


#endif // MONITOR_H
