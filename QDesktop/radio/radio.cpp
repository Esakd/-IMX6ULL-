#include "radio.h"
#include <QDebug>
#include <QtGlobal> // QRandomGenerator

myRadio::myRadio(QObject *parent) : QObject(parent), currentIndex(0)
{
}

void myRadio::addName(const QString &name)
{
    if (!name.isEmpty()) {
        nameList.append(name);
        emit namesChanged();
    }
}

void myRadio::deleteName(int index)
{
    if (index >= 0 && index < nameList.size()) {
        nameList.removeAt(index);
        emit namesChanged();
    }
}

QStringList myRadio::getNames() const
{
    return nameList;
}

void myRadio::startCall()
{
    if (!nameList.isEmpty()) {
        if (currentIndex >= nameList.size()) {
            currentIndex = 0; // 重置
        }

        emit nameCalled(nameList.at(currentIndex));
        currentIndex++;
    } else {
        emit nameCalled("没有可点名的学生");
    }
}

void myRadio::randomCall()
{
    if (!nameList.isEmpty()) {
        int index = qrand() % nameList.size();
        emit nameCalled(nameList.at(index));
    } else {
        emit nameCalled("没有可点名的学生");
    }
}

myRadio::~myRadio()
{
}
