#include "settingwindow.h"
#include "ui_settingwindow.h"

SettingWindow::SettingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);
    this->resize(1024,600);

    ui->label_ShowGif->setFixedSize(500,300);
    ui->label_ShowGif->setScaledContents(true);
    ui->label_setting_date->setFixedWidth(225);
    timer = new QTimer;
    timer->setInterval(500);
    timer->start();
    connect(timer,SIGNAL(timeout()),this,SLOT(on_timer_updateTime()));
    ScanGif();

}

SettingWindow::~SettingWindow()
{
    delete ui;
}

void SettingWindow::on_pushButton_8_clicked()
{
    this->hide();
}


/* 遍历本地gif文件  */
void SettingWindow::ScanGif()
{
    QDir dir(QCoreApplication::applicationDirPath() + LocalGifPath);
    QDir dirAbsolutePath(dir.absolutePath());
    if(dirAbsolutePath.exists())
    {
        QStringList filter;
        filter<<"*.gif";
        QFileInfoList files = dirAbsolutePath.entryInfoList(filter,QDir::Files);
        GifSum = files.count();
        gif_Files.clear();
        for(int i=0;i<files.count();i++)
        {
            gif_Files.append(files.at(i).absoluteFilePath());
        }
    }
    if(0==GifSum)
    {
        ui->label_ShowGif->setText("./MyGif 目录下没有可用的Gif文件");
        return;
    }
    currentGifIndex = 0;
    movie->setFileName(gif_Files.at(0));
    ui->label_ShowGif->setMovie(movie);
    movie->start();
}

/* 暂停或者播放 gif 图片的显示  */
void SettingWindow::on_pBtn_PauseGif_clicked(bool checked)
{
    if(0==GifSum)return;
    if(!checked)
    {
        ui->pBtn_PauseGif->setText("暂停");
        movie->start();
    }
    else
    {
        ui->pBtn_PauseGif->setText("播放");
        movie->stop();
    }
}

/*切换gif图片  */
void SettingWindow::on_pBtn_SwitchGif_clicked()
{
    if(GifSum==0)return;
    int id = qrand()%GifSum;
    movie->stop();
    movie->setFileName(gif_Files.at(id));

    if(!ui->pBtn_ModifyTime->isChecked())
        movie->start();
}

/* 修改日期按钮 */
void SettingWindow::on_pBtn_ModifyDate_clicked()
{
    QString dateStr = ui->dateEdit->date().toString("yyyy-MM-dd");
    QString timeStr = QTime::currentTime().toString("hh:mm:ss");
    QString string = QString("%1 %2").arg(dateStr).arg(timeStr);
    qDebug()<<string;
    process.start("date",QStringList()<<"-s"<<string);
    process.start("hwclock",QStringList()<<"-w");
    process.waitForFinished();
    qDebug()<<process.readAllStandardOutput();
    process.close();
}


/* 修改时间按钮 */
void SettingWindow::on_pBtn_ModifyTime_clicked()
{
    int hour = ui->spinBox_hour->value();
    int min = ui->spinBox_Min->value();
    int second = ui->spinBox_Sec->value();
    QString string = QString("%1:%2:%3").arg(hour).arg(min).arg(second);
    qDebug()<<string;
    process.start("date",QStringList()<<"-s"<<string);
    process.start("hwclock",QStringList()<<"-w");
    process.waitForFinished();
    qDebug()<<process.readAllStandardOutput();
    process.close();

}

/* 更新当前窗口的时间显示 */
void SettingWindow::on_timer_updateTime()
{
    ui->label_setting_date->setText(QDate::currentDate().toString("yyyy-MM-dd"));
    ui->label_setting_time->setText(QTime::currentTime().toString("hh:mm:ss"));
}

/* 连接wifi 功能 不再使用*/
void SettingWindow::on_pushButton_3_clicked()
{
    process.start("ifconfig",QStringList()<<"wlan0"<<"up");
    process.waitForFinished();
    QString error = QString(process.readAllStandardError());
    process.close();
    if(0<error.length())
    {
        QMessageBox::warning(this,"error",error);
        return;
    }
}

/* 连接wifi 功能 不再使用*/
void SettingWindow::on_pushButton_4_clicked()
{
    process.start("wpa_cli",QStringList()<<"-i"<<"wlan0"<<"scan_result");
    process.waitForFinished();
    QString error = QString(process.readAllStandardError());
    if(0<error.length())
    {
        QMessageBox::warning(this,"error",error);
        return;
    }
    QStringList scanResult = QString(process.readAllStandardOutput()).split("\n");
    process.close();
    ui->listWidget->clear();
    for (int i=1; i<scanResult.count();i++ ) {
        QString str = scanResult.at(i).split("\t").last();
        ui->listWidget->addItem(str);
        qDebug()<<scanResult.at(i);
    }
}

/* 连接wifi 功能 不再使用*/
void SettingWindow::on_pushButton_5_clicked()
{
    QString wifiName = ui->listWidget->selectedItems()[0]->text();
    QString password = ui->lineEdit_password->text();
    qDebug()<<"wifiName:"<<wifiName<<"password:"<<password;
    process.start("source",QStringList()<<"/home/root/shell/wifi/alientek_usb_wifi_setup.sh"<<"-m"<<"station"<<"-i"<<wifiName<<"-p"<<password<<"-d"<<"wlan0");
    process.waitForFinished();
    QString error = QString(process.readAllStandardError());
    if(0<error.length())
    {
        QMessageBox::warning(this,"error",error);
        return;
    }
    QMessageBox::information(this,"Wifi Connected","wifi 链接成功");
}
