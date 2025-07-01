#include "clock.h"
#include "ui_clock.h"

Clock::Clock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Clock)
{
    ui->setupUi(this);
    //QTimer *timer = new QTimer(this);  //连接信号与槽
    //connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    //timer->start(5000000);
    //设置窗体名称与大小
    setWindowTitle(tr("Clock"));
    ui->setupUi(this);
    resize(350,350);
}

Clock::~Clock()
{
    delete ui;
}

void Clock::paintEvent(QPaintEvent *event)
{
    static const QPoint hourHand[3] =
        {
            QPoint(5, 14),
            QPoint(-5, 14),
            QPoint(0, -50)
        };
    static const QPoint minuteHand[3] =
        {
            QPoint(5, 14),
            QPoint(-5,14),
            QPoint(0, -70)
        };
    static const QPoint secondHand[3] =
        {
            QPoint(5, 14),
            QPoint(-5, 14),
            QPoint(0, -80)
        };
    static const QPoint line_long[2]=
        {
            QPoint(0,100),
            QPoint(0,80)
        };
    static const QPoint line_short[2]={
        QPoint(0,100),
        QPoint(0,95)
    };
    //绘制的范围
    int side = qMin(width(), height());
    //获取当前的时间
    time = QTime::currentTime();
    //声明用来绘图用的painter
    QPainter painter(this);
    //绘制的图像反锯齿
    painter.setRenderHint(QPainter::Antialiasing);
    //重新定位坐标起始点，把坐标原点放到窗体的中央
    painter.translate(width() / 2, height() / 2);
    //在表盘内添加文字（任意）
    //painter.drawText(-75,-120,100,170,Qt::AlignRight,tr("ROLEX"));
    //设定画布的边界
    painter.scale(side / 200.0, side / 200.0);
    //填充边线设为黑色，也可以设置为NoPen
    painter.setPen( Qt::black );
    //画刷颜色设定
    painter.setBrush(Qt::black);
    //保存painter的状态
    painter.save();
    //设置painter的旋转角度
    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    //填充时针的区域
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();
    painter.setPen(Qt::blue);
    //12个个刻度循环
    for (int i = 0; i < 12; ++i)
    {
        painter.drawLine(line_long[0],line_long[1]);
        painter.rotate(30.0);
    }
    //绘制分针转角、刻度
    painter.setPen(Qt::green);
    painter.setBrush(Qt::green);
    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();
    painter.setPen(Qt::green);
    for (int j = 0; j < 60; ++j)
    {
        if ((j % 5) != 0)
            painter.drawLine(line_short[0],line_short[1]);
        painter.rotate(6.0);
    }

    //绘制分针转角、刻度
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.save();
    painter.rotate(6.0 * (time.minute() + time.second() / 60.0));
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();
    painter.setPen(Qt::black);
    for (int j = 0; j < 60; ++j)
    {
        if ((j % 5) != 0)
            painter.drawLine(line_short[0],line_short[1]);
        painter.rotate(6.0);
    }
    //绘制秒针转角
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.save();
    painter.rotate(6.0*time.second());
    painter.drawConvexPolygon(secondHand,3);
    painter.restore();
}
