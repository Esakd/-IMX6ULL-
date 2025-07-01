#include "Music/searchmusic.h"
#include "ui_searchmusic.h"

SearchMusic::SearchMusic(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SearchMusic)
{
    ui->setupUi(this);
    NetAccessManager = new QNetworkAccessManager(this);

    //在网络请求成功之后会自动调用onReplied函数，对返回的数据包解析
    connect(NetAccessManager,&QNetworkAccessManager::finished,
            this,&SearchMusic::onReplied);
    this->setLocale(QLocale::Chinese);
}

SearchMusic::~SearchMusic()
{
    delete ui;
}


/* 下载音乐到本地  */
void SearchMusic::DownloadSong(Song *song)
{
    QString fileName = QString("%1_%2_%3.mp3").arg(song->getSongName(),song->getAlbumName(),song->getSingerName());
    if(QFile::exists(fileName))
    {
        QFile::remove(fileName);
    }
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug()<<"fileName"<<"Can't open"<<endl;
        return;
    }
    QUrl songUrl = QUrl::fromUserInput(song->getSongDownloadUrl());
    if(!songUrl.isValid())
    {
        qDebug()<<"下载地址无效"<<endl;
        return;
    }
    ui->pBtn_Search->setEnabled(false);
    SongReply = SongNetworkManager->get(QNetworkRequest(songUrl));
    connect(SongReply,SIGNAL(finished()),this,SLOT(SongDownloadFinished()));
    connect(SongReply,SIGNAL(readyRead()),this,SLOT(SongDownloadReadyRead()));
    connect(SongReply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(SongDownloadDownloadProgress(qint64,qint64)));
}

void SearchMusic::onReplied(QNetworkReply *reply)
{
   // qDebug()<<"onReplied successed";
    int satus_code = reply->attribute(
                              QNetworkRequest::HttpStatusCodeAttribute).toInt();
    //qDebug() 用于测试和查看网络信息
    qDebug()<<"operation: "<<reply->operation();
    qDebug()<<"satus_code: "<<satus_code;
    qDebug()<<"url: "<<reply->url();
    qDebug()<<"raw header: "<<reply->rawHeaderList();
    //satus_code 为200 表示请求成功 常见状态码 404 403 等
    //    if(reply->error() != QNetworkReply::NoError){
    //        qDebug()<<reply->errorString().toLatin1().data();
    //        QMessageBox::warning(this,"QtNetImg",
    //                             "网络连接失败",QMessageBox::Ok);
    //    }else{
    QByteArray byteArray = reply->readAll();
    //qDebug()<<"read all:" <<byteArray.data();
    //将获取到的所有信息通过readAll()传给fromNetJson
    //用于对数据解析
    //添加成员函数
    fromNetJson(byteArray);
    //    }
    reply->deleteLater();
}

void SearchMusic::GetNetJson(QString urlString)
{
    QUrl url(urlString);
    //调用get方法 QNetworkRequest对目标api网址发出请求
    NetAccessManager->get(QNetworkRequest(url));
}

/*  点击音乐搜索按钮  */
void SearchMusic::on_pBtn_Search_clicked()
{
    QString SongName = ui->SongName->text();
    int num = ui->spinBox_SearchNum->value();
    searchNum = num;
    if(SongName.length()==0)
    {
        QMessageBox::warning(nullptr,"warning","请输入要搜索的歌曲名字");
        return;
    }
    GetNetJson(Url_String.arg(SongName,QString::number(num)));
    //GetNetJson("https://music.163.com/song/media/outer/url?id=28996036.mp3");
}


/*  解析 json 数据包，显示搜索结果  */
void SearchMusic::fromNetJson(QByteArray &byteArr)
{
    QJsonDocument doc = QJsonDocument::fromJson(byteArr);
    if(!doc.isObject()){
        qDebug()<<"Netjson not an jsonObject!";
        return;
    }
    QJsonObject obj = doc.object();
    QJsonObject val = obj.value("result").toObject();
    QJsonArray songs = val.value("songs").toArray();
    ui->listWidget->clear();
    for (int i=0; i<searchNum; i++) {
        QJsonObject singleSong = songs.at(i).toObject();
        song = new Song();
        song->setAlbumName(singleSong.value("album").toObject().value("name").toString());
        song->setDuration(singleSong.value("duration").toInt());
        song->setSingerName(singleSong.value("artists").toArray()[0].toObject().value("name").toString());
        song->setSongId(QString::number(singleSong.value("id").toInt()));
        song->setSongName(singleSong.value("name").toString());
        songsVector.append(song);
        ui->listWidget->addItem(song->getSongName()+QString("_")+song->getSingerName()+QString("_")+song->getAlbumName());
    }
    qDebug()<<"*****************************/n";

}

void SearchMusic::SongDownloadFinished()
{

}

void SearchMusic::SongDownloadReadyRead()
{

}

void SearchMusic::SongDownloadDownloadProgress(qint64, qint64)
{

}


Song::Song()
{

}

Song::Song(QString SongName, QString SongId, QString AlbumName, QString SingerName, int duration)
{
    this->SongName = SongName;
    this->SongId = SongId;
    this->AlbumName = AlbumName;
    this->SingerName = SingerName;
    this->duration = duration;
}

const QString &Song::getSongName() const
{
    return this->SongName;
}

void Song::setSongName(const QString &newSongName)
{
    this->SongName = newSongName;
}

void Song::setSongId(const QString &newSongId)
{
    this->SongId = newSongId;
    //LyricDownloadUrl = Lyric_DownloadBaseUrl.arg(newSongId);
    this->SongDownloadUrl = this->Song_DownloadBaseUrl.arg(newSongId);
}

const QString &Song::getAlbumName() const
{
    return this->AlbumName;
}
/*  设置音乐 专辑名称 属性 */
void Song::setAlbumName(const QString &newAlbumName)
{
    this->AlbumName = newAlbumName;
}

const QString &Song::getSingerName() const
{
    return this->SingerName;
}

void Song::setSingerName(const QString &newSingerName)
{
    this->SingerName = newSingerName;
}

const QString &Song::getTime() const
{
    return this->Time;
}

/* 设置音乐时长属性  */
void Song::setDuration(int newDuration)
{
    this->duration = newDuration;
    int time=this->duration/1000;
    this->Time = QString("%1:%2").arg(QString::number(time/60),QString::number(time%60));
}
const QString &Song::getSongDownloadUrl() const
{
    return this->SongDownloadUrl;
}

//const QString &Song::getLyricDownloadUrl() const
//{
//    return LyricDownloadUrl;
//}

/* 点击下载音乐按钮  */
void SearchMusic::on_pushButton_clicked()
{
    int index = ui->listWidget->currentRow();
    emit AddUrlMusic(ui->listWidget->currentItem()->text(),this->songsVector.at(index)->getSongDownloadUrl());
    this->hide();
}

