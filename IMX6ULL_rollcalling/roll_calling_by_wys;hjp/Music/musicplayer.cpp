#include "Music/musicplayer.h"
#include "ui_musicplayer.h"

#include <QMouseEvent>

MusicPlayer::MusicPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MusicPlayer)
{
    ui->setupUi(this);
    this->setMinimumSize(1024,600);
    searchMusicWin = new SearchMusic(this);
    mediaPlayerInit();
    ScanLocalSongs();
    QSslConfiguration config = QSslConfiguration::defaultConfiguration();
    config.setPeerVerifyMode(QSslSocket::VerifyNone);
    Second_request.setSslConfiguration(config);
    QFile style_file(":/music/Music/style.qss");
    if(style_file.exists())
    {
        style_file.open(QFile::ReadOnly);
        QString styleStr = QLatin1String(style_file.readAll());
        this->setStyleSheet(styleStr);
    }

    connect(searchMusicWin,&SearchMusic::AddUrlMusic,this,&MusicPlayer::AddMusicFromUrl);
    connect(musicPlayer,SIGNAL(durationChanged(qint64)),this,SLOT(on_musicPlayer_DurationChanged(qint64)));
    connect(musicPlayer,SIGNAL(positionChanged(qint64)),this,SLOT(on_musicPlayer_CurPostionChanged(qint64)));
    connect(&First_netManager,SIGNAL(finished(QNetworkReply* )),this,SLOT(on_GetSongTrueUrl(QNetworkReply* )));
    connect(&Second_netManager,SIGNAL(finished(QNetworkReply* )),this,SLOT(on_DownSong(QNetworkReply* )));

}

MusicPlayer::~MusicPlayer()
{
    delete ui;
}

/*  扫描本地音乐  */
void MusicPlayer::ScanLocalSongs()
{
    QDir dir(QCoreApplication::applicationDirPath() + LocalSongsPath);
    QDir dirAbsolutePath(dir.absolutePath());
    if(dirAbsolutePath.exists())
    {
        QStringList filter;
        filter<<"*.mp3";
        QFileInfoList files = dirAbsolutePath.entryInfoList(filter,QDir::Files);
        for(int i=0;i<files.count();i++)
        {
            MediaObjectInfo info;
            QString fileName = QString::fromUtf8(files.at(i).fileName().replace(".mp3","").toUtf8().data());
            info.fileName = fileName;
            info.filePath = QString::fromUtf8(files.at(i).filePath().toUtf8().data());
            if(musicPlayList->addMedia(QUrl::fromLocalFile(info.filePath)))
            {
                SongInfoVector.append(info);
                ui->listWidget->addItem(info.fileName);
            }
            else
            {
                qDebug()<<musicPlayList->errorString()<<endl;
                qDebug()<<"Error number:"<<musicPlayList->error()<<endl;
            }
        }
    }

}

/* 初始化音乐播放器  */
void MusicPlayer::mediaPlayerInit()
{
    musicPlayer = new QMediaPlayer(this);
    musicPlayList = new QMediaPlaylist(this);
    musicPlayList->clear();
    musicPlayer->setPlaylist(musicPlayList);
    musicPlayList->setPlaybackMode(QMediaPlaylist::Random);//设置播放模式 循环、随机、顺序、当前循环、当前一次
}

/*  打开在线搜索音乐界面  */
void MusicPlayer::on_pBtn_OpenSearchWin_clicked()
{
    searchMusicWin->show();
}


/*  根据音乐url地址下载音乐 添加到本地  */
void MusicPlayer::AddMusicFromUrl(QString name, QString UrlPath)
{
    qDebug()<<UrlPath;
    First_request.setUrl(QUrl(UrlPath));
    First_netManager.get(First_request);
    CurrentSaveSongFileName = name;
}


/*  用户点击其他音乐进行播放  */
void MusicPlayer::on_listWidget_currentRowChanged(int currentRow)
{
    musicPlayer->stop();
    musicPlayList->setCurrentIndex(currentRow);
    musicPlayer->play();
}

/* 点击切换上一首按钮 */
void MusicPlayer::on_pBtn_Pre_clicked()
{
    musicPlayer->stop();
    ui->listWidget->setCurrentRow(musicPlayList->previousIndex(1));
    musicPlayList->previous();
    musicPlayer->play();
}

/* 点击切换下一首按钮 */
void MusicPlayer::on_pBtn_Next_clicked()
{
    musicPlayer->stop();
    ui->listWidget->setCurrentRow(musicPlayList->nextIndex(1));
    musicPlayList->next();
    musicPlayer->play();
}


/* 暂停音乐 */
void MusicPlayer::on_pBtn_Pause_clicked()
{
    if(ui->pBtn_Pause->isChecked())
    {
        musicPlayer->stop();
    }
    else
        musicPlayer->play();
}


/*  增加音量  */
void MusicPlayer::on_pBtn_Loud_clicked()
{
    int curVolume = musicPlayer->volume();
    if(curVolume>99)
        return;
    else
        musicPlayer->setVolume(curVolume+10);
    qDebug()<<"Curr Volumn"<<QString::number(musicPlayer->volume()) <<endl;
}


/* 降低音量 */
void MusicPlayer::on_pBtn_Low_clicked()
{
    int curVolume = musicPlayer->volume();
    if(curVolume<1)
        return;
    else
        musicPlayer->setVolume(curVolume-10);
    qDebug()<<"Curr Volumn"<<QString::number(musicPlayer->volume()) <<endl;
}




/* 上下滑动音乐列表时 */
void MusicPlayer::on_horizontalSlider_sliderReleased()
{
    musicPlayer->setPosition(ui->horizontalSlider->value()*1000);
}


/* 切换音乐时更新音乐总时长  */
void MusicPlayer::on_musicPlayer_DurationChanged(qint64 duration)
{
    ui->horizontalSlider->setMaximum(duration/1000);
    int min = duration/1000/60;
    int sec = (duration/1000)%60;
    QString minStr = QString::number(min);
    QString secStr = QString::number(sec);
    if(min<10)minStr="0"+minStr;
    if(sec<10)secStr="0"+secStr;
    QString durationShow = QString("%1:%2").arg(minStr,secStr);
    ui->label_TotalTime->setText(durationShow);
}

/*  */
void MusicPlayer::on_musicPlayer_CurPostionChanged(qint64 value )
{
    ui->horizontalSlider->setValue(value/1000);
    int min = value/1000/60;
    int sec = (value/1000)%60;
    QString minStr = QString::number(min);
    QString secStr = QString::number(sec);
    if(min<10)minStr="0"+minStr;
    if(sec<10)secStr="0"+secStr;
    QString curTime = QString("%1:%2").arg(minStr,secStr);
    ui->label_CurTime->setText(curTime);
}


/* 点击循环播放按钮 */
void MusicPlayer::on_pBtn_loop_clicked()
{
    if(ui->pBtn_SetLove->isChecked())
    {
        musicPlayList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    }
    else
        musicPlayList->setPlaybackMode(QMediaPlaylist::Random);
}


/* 根据音乐搜索网络请求，获取音乐的真实下载地址 */
void MusicPlayer::on_GetSongTrueUrl(QNetworkReply *reply)
{
    qDebug()<<"on_GetSongTrueUrl";
    qDebug()<<reply->rawHeaderList();
    qDebug()<<reply->rawHeaderPairs();
    qDebug()<<reply->readAll();
    int total = reply->rawHeaderPairs().length();
    qDebug()<<total;
    for(int i=0;i<total;i++)
        {
            QString first = QString(reply->rawHeaderPairs().at(i).first);
            if(first.compare(QString("Location"))==0)
            {
                QString urlDownload = QString(reply->rawHeaderPairs().at(i).second);
                if(urlDownload.endsWith("404"))
                {
                    QMessageBox::warning(this,"warning","该歌曲无法下载，请换一首");
                    return;
                }
                qDebug()<<urlDownload;
                Second_request.setUrl(QUrl(urlDownload));
                Second_netManager.get(Second_request);
            }
        }
}


/* 下载音乐到本地文件 */
void MusicPlayer::on_DownSong(QNetworkReply *reply)
{
    QFile file;
    QString FilePath = QCoreApplication::applicationDirPath()+LocalSongsPath+QString("/")+CurrentSaveSongFileName+QString(".mp3");
    file.setFileName(FilePath);
    file.open(QIODevice::Append | QIODevice::Truncate);
    file.write(reply->readAll());
    file.close();
    qDebug()<<"Save Song <"<<CurrentSaveSongFileName<<"> "<<"Finished";
    MediaObjectInfo info;
    info.fileName = CurrentSaveSongFileName;
    info.filePath = FilePath;
    if(musicPlayList->addMedia(QUrl::fromLocalFile(info.filePath)))
    {
        SongInfoVector.append(info);
        ui->listWidget->addItem(info.fileName);
    }
    else
    {
        qDebug()<<musicPlayList->errorString()<<endl;
        qDebug()<<"Error number:"<<musicPlayList->error()<<endl;
    }
}


/* 退出按钮  */
void MusicPlayer::on_pushButton_clicked()
{
    this->hide();
}


/* 处理语音控制传来的指令 */
void MusicPlayer::on_handleCommand(int command)
{
    switch (command) {
    case MUSIC_COMMAND_SHOW:
        this->show();
        break;
    case MUSIC_COMMAND_CLOSE:
        this->hide();
        break;
    case MUSIC_COMMAND_PAUSE:
        musicPlayer->pause();
        break;
    case MUSIC_COMMAND_PLAY:
        if(musicPlayList->isEmpty())return;
        ui->listWidget->setCurrentRow(musicPlayList->previousIndex(1));
        musicPlayer->play();
        break;
    case MUSIC_COMMAND_PRE:
        musicPlayList->previous();
        break;
    case MUSIC_COMMAND_NEXT:
        ui->listWidget->setCurrentRow(musicPlayList->nextIndex(1));
           break;
    default:
        break;
    }
}
