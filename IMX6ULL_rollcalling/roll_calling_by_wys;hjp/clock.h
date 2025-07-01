#ifndef CLOCK_H
#define CLOCK_H

#include <QWidget>
#include<math.h>
#include<QResizeEvent>
#include<QGroupBox>
#include<QTimer>
#include<QTime>
#include<QPainter>
namespace Ui {
class Clock;
}

class Clock : public QWidget
{
    Q_OBJECT

public:
    explicit Clock(QWidget *parent = nullptr);
    ~Clock();

private:
    Ui::Clock *ui;
    QTime time;
    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // CLOCK_H
