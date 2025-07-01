#ifndef MYRADIO_H
#define MYRADIO_H

#include <QObject>
#include <QStringList>
#include <QtGlobal>

class myRadio : public QObject
{
    Q_OBJECT

public:
    explicit myRadio(QObject *parent = nullptr);
    ~myRadio();

    // 添加名字
    Q_INVOKABLE void addName(const QString &name);
    // 删除名字
    Q_INVOKABLE void deleteName(int index);
    // 获取名字列表
    Q_INVOKABLE QStringList getNames() const;
    // 顺序点名
    Q_INVOKABLE void startCall();
    // 随机点名
    Q_INVOKABLE void randomCall();

signals:
    void namesChanged();              // 名单变更信号
    void nameCalled(const QString &name); // 点名结果信号

private:
    QStringList nameList;
    int currentIndex; // 当前点名位置
};

#endif // MYRADIO_H
