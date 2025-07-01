#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <Music/searchmusic.h>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDir>
#include <QFile>
#include <QUrl>
#include <QVector>
#include <QNetworkReply>
#include <QMessageBox>
#include <QLocale>

#define MUSIC_COMMAND_CLOSE 0
#define MUSIC_COMMAND_SHOW 1
#define MUSIC_COMMAND_CLOSE 0
#define MUSIC_COMMAND_PRE 2
#define MUSIC_COMMAND_NEXT 3
#define MUSIC_COMMAND_PLAY 4
#define MUSIC_COMMAND_PAUSE 5

namespace Ui {
class MusicPlayer;
}

/* 媒体信息结构体 */
struct MediaObjectInfo {
    /* 用于保存歌曲文件名 */
    QString fileName;
    /* 用于保存歌曲文件路径 */
    QString filePath;
};

class MusicPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MusicPlayer(QWidget *parent = nullptr);
    ~MusicPlayer();
    QString LocalSongsPath = "/myMusic";
    void ScanLocalSongs();
    void mediaPlayerInit();

private slots:

    void on_pBtn_OpenSearchWin_clicked();
    void AddMusicFromUrl(QString name,QString UrlPath);

    void on_listWidget_currentRowChanged(int currentRow);

    void on_pBtn_Pre_clicked();

    void on_pBtn_Next_clicked();

    void on_pBtn_Pause_clicked();

    void on_pBtn_Loud_clicked();

    void on_pBtn_Low_clicked();

    void on_horizontalSlider_sliderReleased();

    void on_musicPlayer_DurationChanged(qint64);
    void on_musicPlayer_CurPostionChanged(qint64);

    void on_pBtn_loop_clicked();

    void on_GetSongTrueUrl(QNetworkReply *reply);
    void on_DownSong(QNetworkReply *reply);

    void on_pushButton_clicked();
public slots:
    void on_handleCommand(int);
private:
    class SearchMusic *searchMusicWin;
    Ui::MusicPlayer *ui;
    QMediaPlayer *musicPlayer;
    QMediaPlaylist *musicPlayList;
    QString CurrentSaveSongFileName;
    QVector<MediaObjectInfo> SongInfoVector;

    QNetworkAccessManager First_netManager;
    QNetworkRequest First_request;
    QNetworkAccessManager Second_netManager;
    QNetworkRequest Second_request;

};

#endif // MUSICPLAYER_H
