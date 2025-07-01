#include "monitor.h"
#include "ui_monitor.h"
#include "ap3216.h"

Monitor * Monitor::monitor = nullptr;
Monitor * Monitor::getInstance()
{
    if(monitor==nullptr)
        return new Monitor();
   else
        return monitor;
}

Monitor::Monitor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Monitor)
{
    this->setGeometry(0, 0, 1024, 600);

    ap3216 = new Ap3216c();

    videoLabel = new QLabel(this);
    videoLabel->setText("未获取到图像数据");
    videoLabel->setStyleSheet("QWidget {color: white;}");
    videoLabel->setAlignment(Qt::AlignCenter);
    videoLabel->resize(1024, 600);
    DisUpdate_Timer = new QTimer(this);
    DisUpdate_Timer->setInterval(500);
    DisUpdate_Timer->start();
//    checkBox1 = new QCheckBox(this);
//    checkBox2 = new QCheckBox(this);

//    checkBox1->resize(120, 50);
//    checkBox2->resize(120, 50);

//    checkBox1->setText("本地显示");
//    checkBox2->setText("开启广播");

//    checkBox1->setStyleSheet("QCheckBox {color: yellow;}"
//                             "QCheckBox:indicator {width: 40; height: 40;}");
//    checkBox2->setStyleSheet("QCheckBox {color: yellow;}"
//                             "QCheckBox:indicator {width: 40; height: 40}");
    showDistance = new QLabel(this);
    showDistance->resize(120,50);
    showDistance->setStyleSheet("QLabel{color:blue;}"
                                "QLabel{background:argb(255,255,255,50)}"
                                );
    showDistance->setAlignment(Qt::AlignCenter);
    QFont font("宋体",12);
    font.setBold(true);
    showDistance->setFont(font);
    showDistance->setText("距离:xxxx");
    /* 按钮 */
    startCaptureButton = new QPushButton(this);
    startCaptureButton->setCheckable(true);
    startCaptureButton->setText("返回");

    /* 设置背景颜色为黑色 */
    QColor color = QColor(Qt::black);
    QPalette p;
    p.setColor(QPalette::Window, color);
    this->setPalette(p);

    /* 样式表 */
    startCaptureButton->setStyleSheet("QPushButton {background-color: white; border-radius: 30}"
                                      "QPushButton:pressed  {background-color: red;}");

    captureThread = new CaptureThread(this);
    captureThread->setLocalDisplay(true);
    //connect(startCaptureButton, SIGNAL(clicked(bool)), captureThread, SLOT(setThreadStart(bool)));
    connect(startCaptureButton, SIGNAL(clicked(bool)), this, SLOT(startCaptureButtonClicked(bool)));
    connect(captureThread, SIGNAL(imageReady(QImage)), this, SLOT(showImage(QImage)));
//    connect(checkBox1, SIGNAL(clicked(bool)), captureThread, SLOT(setLocalDisplay(bool)));
//    connect(checkBox2, SIGNAL(clicked(bool)), captureThread, SLOT(setBroadcast(bool)));
    connect(DisUpdate_Timer,SIGNAL(timeout()),this,SLOT(on_timer_timeout()));
    DisUpdate_Timer->setInterval(500);
}

Monitor::~Monitor()
{
    delete ui;
}


void Monitor::showImage(QImage image)
{
    videoLabel->setPixmap(QPixmap::fromImage(image));
}

void Monitor::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    startCaptureButton->move((this->width() - 200) / 2, this->height() - 80);
    startCaptureButton->resize(200, 40);
    showDistance->resize(200,60);
    showDistance->move((this->width() - 200) / 2, this->height() - 140);
   // videoLabel->move((this->width() - 640) / 2, (this->height() - 480) / 2);
//    checkBox1->move(this->width() - 120, this->height() / 2 - 50);
    //    checkBox2->move(this->width() - 120, this->height() / 2 + 25);
}

void Monitor::myStart()
{
    DisUpdate_Timer->start();
    captureThread->startThread();
}

void Monitor::myStop()
{
    DisUpdate_Timer->stop();

    captureThread->stopThread();
}

void Monitor::startCaptureButtonClicked(bool start)
{
    Q_UNUSED(start);
    myStop();
    this->hide();
}

void Monitor::on_timer_timeout()
{
    //qDebug()<<"updateDistance ";
    QString str = QString("距离: %1").arg(ap3216->readPsData());
    this->showDistance->setText(str);
}

void Monitor::on_handleCommand(int command)
{
    switch (command) {
    case MONITOR_COMMAND_SHOW:
        this->show();
        break;
    case MONITOR_COMMAND_CLOSE:
        this->hide();
    default:
        break;
    }
}
