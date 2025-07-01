#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout;
    ui->videoVLayout->addWidget(&clock);
    this->resize(1024,600);
    ui->stackedWidget->installEventFilter(this);
    dht11 = new Dht11;

    baiduMap = new BaiduMap(this);
    monitor = Monitor::getInstance();
    musicPlayer = new MusicPlayer(this);
    weather = new Weather(this);
    windows.append(baiduMap);
    windows.append(monitor);
    windows.append(weather);
    windows.append(musicPlayer);
    time = new QTimer;
    time->setInterval(500);
    time->start();
    dht11->start();
    request  = new QNetworkRequest;
    networkManage = new QNetworkAccessManager;
    request->setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    connect(networkManage,SIGNAL(finished(QNetworkReply *)),this,SLOT(getSpeechResult(QNetworkReply *)));
    SR = new SpeechRecognition();
    SR->startSpeechRecognition();
    connect(SR,SIGNAL(RecordFinished()),this,SLOT(on_handleRecord()));
    connect(time,SIGNAL(timeout()),this,SLOT(on_timer_updateTime()));
    connect(dht11,SIGNAL(updateDht11Data(QString ,QString )),this,SLOT(on_update_humidity_temp(QString, QString)));

    connect(this,SIGNAL(SendCommandToMap(int)),baiduMap,SLOT(on_handleCommand(int)));
    connect(this,SIGNAL(SendCommandToMonitor(int)),monitor,SLOT(on_handleCommand(int)));
    connect(this,SIGNAL(SendCommandToMusic(int)),musicPlayer,SLOT(on_handleCommand(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pBtn_Setting_clicked()
{
    settingWindow.ScanGif();
    settingWindow.show();
}

void MainWindow::on_update_humidity_temp(QString humidity, QString temp)
{
    ui->label_humi->setText(humidity);
    ui->label_temp->setText(temp);
}

void MainWindow::getSpeechResult(QNetworkReply *reply)
{
    qDebug()<<"getSpeechResult";
    qDebug()<<"reply is Readable"<<reply->isReadable();

    QByteArray content = reply->readAll();
    content.remove(content.lastIndexOf('\n'),1);
    qDebug()<<content;
    QJsonDocument doc = QJsonDocument::fromJson(content);
    if(!doc.isObject()){
        qDebug()<<"Netjson not an jsonObject!";
        return;
    }
    QJsonObject obj = doc.object();
    QJsonArray resutls = obj.value("result").toArray();
    QString AsrResult = resutls.at(0).toString();
    qDebug()<<"识别结果:"<<AsrResult;
    if (AsrResult.contains("播放音乐")) {
        emit SendCommandToMusic(MUSIC_COMMAND_SHOW);
        emit SendCommandToMusic(MUSIC_COMMAND_PLAY);
    }
    else if(AsrResult.contains("下一首"))
    {
        emit SendCommandToMusic(MUSIC_COMMAND_SHOW);
        emit SendCommandToMusic(MUSIC_COMMAND_NEXT);
    }
    else if(AsrResult.contains("上一首"))
    {
        emit SendCommandToMusic(MUSIC_COMMAND_SHOW);
        emit SendCommandToMusic(MUSIC_COMMAND_PRE);
    }
    else if(AsrResult.contains("暂停音乐"))
    {
        emit SendCommandToMusic(MUSIC_COMMAND_SHOW);
        emit SendCommandToMusic(MUSIC_COMMAND_PAUSE);
    }
    else if(AsrResult.contains("退出音乐"))
    {
        emit SendCommandToMusic(MUSIC_COMMAND_CLOSE);
        this->show();
    }
    else if(AsrResult.contains("打开地图"))
    {
        emit SendCommandToMap(MAP_COMMAND_SHOW);
    }
    else if(AsrResult.contains("地图放大"))
    {
        emit SendCommandToMap(MAP_COMMAND_SHOW);
        emit SendCommandToMap(MAP_COMMAND_AMPLIFY);

    }
    else if(AsrResult.contains("地图缩小"))
    {
        emit SendCommandToMap(MAP_COMMAND_SHOW);
        emit SendCommandToMap(MAP_COMMAND_SHRINK);

    }
    else if(AsrResult.contains("开始倒车"))
    {
        emit SendCommandToMonitor(MONITOR_COMMAND_SHOW);
    }
    else if(AsrResult.contains("查看天气"))
    {
        weather->show();
    }
    else
    {
        qDebug()<<"未识别的指令:"<<AsrResult;
    }
}
QPoint point,last_point;//按下坐标

bool MainWindow::eventFilter(QObject *watched, QEvent *ev)
{

    int index,sum;
        QMouseEvent* event = static_cast<QMouseEvent*>(ev);
        index = ui->stackedWidget->currentIndex();
        sum = ui->stackedWidget->count();
        switch (event->type()) {
        case QEvent::MouseButtonPress:
            qDebug()<<"mouse press";
            point.setY(event->globalY());     // 记录按下点的y坐标
            point.setX(event->globalX());     // 记录按下点的x坐标
            break;
        case QEvent::MouseButtonRelease:
            qDebug()<<"mouse release";
            last_point.setY(event->globalY());     // 记录按下点的y坐标
            last_point.setX(event->globalX());     // 记录按下点的x坐标

            if(last_point.x()-point.x()>200)
            {
                ui->stackedWidget->setCurrentIndex(index<(sum-1)?index+1:0);
            }
            else if(point.x()-last_point.x()>200)
            {
                ui->stackedWidget->setCurrentIndex(index>0?index-1:(sum-1));
            }
            break;
        default:
            break;
        }
    return QWidget::eventFilter(watched,event);//将事件传递给父类
}

void MainWindow::on_pBtn_Music_clicked()
{
    musicPlayer->show();
}

void MainWindow::on_pBtn_Weather_clicked()
{
    weather->show();
}

void MainWindow::on_pBtn_Monitor_clicked()
{
    monitor->show();
    monitor->myStart();
}

void MainWindow::on_pBtn_Map_clicked()
{
    baiduMap->show();
}

void MainWindow::on_timer_updateTime()
{
    QString time = QTime::currentTime().toString("hh:mm:ss");
    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    ui->label_Time->setText(time);
    ui->label_Date->setText(date);
}

void MainWindow::on_handleRecord()
{
    qDebug()<<"TransWavToStr";
    QFile file("./record.wav");
    qDebug()<<file.exists();
    qDebug()<<file.isReadable();
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"无法打开文件";
        return ;
    }
    request->setUrl(QUrl::fromUserInput("http://vop.baidu.com/server_api"));
    QByteArray fileData = file.readAll();
    file.close();
    QByteArray base64Encoded = fileData.toBase64();
    QJsonObject obj;
    obj.insert("format",QJsonValue("pcm"));
    obj.insert("rate",QJsonValue(16000));
    obj.insert("channel",QJsonValue(1));
    obj.insert("cuid",QJsonValue("L5a9DNZMyQD4MyipDR3ck7jhmdvtagjZ"));
    obj.insert("token",QJsonValue("24.464f01bbb7583296b1e578ddf66073f0.2592000.1731685220.282335-115895512"));
    obj.insert("speech",QJsonValue(QString(base64Encoded)));
    obj.insert("len",QJsonValue(fileData.length()));
    QByteArray byte_array = QJsonDocument(obj).toJson();
    networkManage->post(*request,byte_array);

}
