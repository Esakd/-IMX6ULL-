QT       += core gui multimedia
QT += multimediawidgets #使用QVideoWidget视频显示组件
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Map/baidumap.cpp \
    Map/gps.c \
    Map/uart.c \
    Monitor/ap3216.cpp \
    Monitor/capture_thread.cpp \
    Monitor/monitor.cpp \
    Music/musicplayer.cpp \
    Music/searchmusic.cpp \
    Weather/weather.cpp \
    clock.cpp \
    dht11.cpp \
    main.cpp \
    mainwindow.cpp \
    onevideo.cpp \
    settingwindow.cpp \
    speechrecognition.cpp

HEADERS += \
    Map/baidumap.h \
    Map/gps.h \
    Map/uart.h \
    Monitor/ap3216.h \
    Monitor/capture_thread.h \
    Monitor/monitor.h \
    Music/musicplayer.h \
    Music/searchmusic.h \
    Weather/weather.h \
    clock.h \
    dht11.h \
    mainwindow.h \
    onevideo.h \
    settingwindow.h \
    speechrecognition.h

FORMS += \
    Map/baidumap.ui \
    Monitor/monitor.ui \
    Music/musicplayer.ui \
    Music/searchmusic.ui \
    Weather/weather.ui \
    clock.ui \
    mainwindow.ui \
    oneVideo.ui \
    settingwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc

DISTFILES += \
    Monitor/ap3216 \
    Music/style.qss
