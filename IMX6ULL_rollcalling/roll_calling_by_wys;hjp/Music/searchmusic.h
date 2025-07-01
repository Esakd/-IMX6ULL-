#ifndef SEARCHMUSIC_H
#define SEARCHMUSIC_H


#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QVector>
#include <QFile>
#include <QLocale>
#include <QInputMethod>
QT_BEGIN_NAMESPACE
namespace Ui { class SearchMusic; }
QT_END_NAMESPACE

class Song
{
public:
    Song();
    Song(QString SongName,QString SongId,QString AlbumName,QString SingerName,int duration);
    const QString &getSongName() const;
    void setSongName(const QString &newSongName);

    void setSongId(const QString &newSongId);

    const QString &getAlbumName() const;
    void setAlbumName(const QString &newAlbumName);

    const QString &getSingerName() const;
    void setSingerName(const QString &newSingerName);

    const QString &getTime() const;
    void setDuration(int newDuration);

    const QString &getSongDownloadUrl() const;

    const QString &getLyricDownloadUrl() const;

private:
    QString SongName;
    QString SongId;
    QString AlbumName;
    QString SingerName;
    QString Time;
    QString SongDownloadUrl;
    //QString LyricDownloadUrl;  //歌词下载功能废除
    QString Song_DownloadBaseUrl = "http://music.163.com/song/media/outer/url?id=%1.mp3";
    //QString Lyric_DownloadBaseUrl = "https://api.imjad.cn/cloudmusic/?type=lyric&id=%1";
    int duration;
};

class SearchMusic : public QMainWindow
{
    Q_OBJECT

public:
    SearchMusic(QWidget *parent = nullptr);
    ~SearchMusic();
    void DownloadSong(Song *song);

signals:
    void AddUrlMusic(QString name, QString Path);


private:
    Ui::SearchMusic *ui;
    QNetworkAccessManager * NetAccessManager;
    void onReplied(QNetworkReply *reply);	//判断网络连接是否成功，返回网络请求后的数据，都存储在reply中
    int searchNum = 2;
    QVector<Song *> songsVector;
    Song *song;
    QString Url_String = "http://music.163.com/api/search/get/web?csrf_token=hlpretag=&hlposttag=&s={%1}&type=1&offset=0&total=true&limit=%2";
    QNetworkAccessManager * SongNetworkManager;
    QNetworkReply *SongReply;
protected:
    void GetNetJson(QString url);
private slots:
    void on_pBtn_Search_clicked();
    void fromNetJson(QByteArray &byteArr);
    void SongDownloadFinished();
    void SongDownloadReadyRead();
    void SongDownloadDownloadProgress(qint64,qint64);
    void on_pushButton_clicked();
};
#endif // SEARCHMUSIC_H

