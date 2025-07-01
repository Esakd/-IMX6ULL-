#include "onevideo.h"
#include "ui_oneVideo.h"
#include<QDebug>
OneVideo::OneVideo(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::OneVideo)
{
    ui->setupUi(this);
    //setFixedSize(350,350);//设置固定大小
    // 1.放置播放窗口
    m_pPlayer = new QMediaPlayer;//媒体播放器类
    m_pPlayerWidget = new QVideoWidget;// 视频显示组件窗口
    m_pPlayer->setVideoOutput(m_pPlayerWidget);//视频输出:设置视频输出，允许用户将视频渲染到自定义的视频输出设备上。
    ui->verticalLayout->addWidget(m_pPlayerWidget);//将视频显示组件窗口添加到QVBoxLayout垂直布局
    // 设置视频小部件是否自动填充背景。true则视频小部件将自动填充背景，以便在视频播放期间保持视觉效果。
    m_pPlayerWidget->setAutoFillBackground(true);
    // 2.界面美化
    QPalette qplte;// 调色板
    qplte.setColor(QPalette::Window, QColor(0,0,0));// 透明
    m_pPlayerWidget->setPalette(qplte);// 设置窗口部件的调色板
    m_pPlayer->setMedia(QUrl::fromLocalFile("/home/alientek/Desktop/QtProject/VehicleTerminal/Video/show.mp4"));
}

OneVideo::~OneVideo()
{
    delete m_pPlayer;
    delete m_pPlayerWidget;
    delete ui;
}

void OneVideo::PlayVideo()
{
    m_pPlayer->play();
}

