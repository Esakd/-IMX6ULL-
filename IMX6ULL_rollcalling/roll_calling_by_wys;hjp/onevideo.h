#ifndef ONEVIDEO_H
#define ONEVIDEO_H
#include <QtMultimedia>
#include <QtMultimediaWidgets/QVideoWidget>

#include <QWidget>
namespace Ui {
class OneVideo;
}
class OneVideo : public QWidget
{
    Q_OBJECT
public:
    explicit OneVideo(QWidget *parent = nullptr);
    ~OneVideo();
private:
    Ui::OneVideo *ui;
    QVideoWidget *m_pPlayerWidget;// 视频显示组件
    QMediaPlayer * m_pPlayer;//媒体播放器类

public slots:
    void PlayVideo();
};

#endif // ONEVIDEO_H
