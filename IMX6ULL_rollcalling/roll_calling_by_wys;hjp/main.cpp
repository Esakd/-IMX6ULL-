#include "mainwindow.h"
#include <QApplication>
#include "clock.h"
int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));//启用虚拟键盘
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
