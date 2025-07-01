/****************************************************************************
** Meta object code from reading C++ file 'mymodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "weather/mymodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mymodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyModel_t {
    QByteArrayData data[24];
    char stringdata0[299];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyModel_t qt_meta_stringdata_MyModel = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MyModel"
QT_MOC_LITERAL(1, 8, 16), // "indexDataChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 18), // "weatherDataChanged"
QT_MOC_LITERAL(4, 45, 12), // "readyChanged"
QT_MOC_LITERAL(5, 58, 11), // "cityChanged"
QT_MOC_LITERAL(6, 70, 11), // "pm25Changed"
QT_MOC_LITERAL(7, 82, 11), // "downRefresh"
QT_MOC_LITERAL(8, 94, 8), // "setReady"
QT_MOC_LITERAL(9, 103, 3), // "arg"
QT_MOC_LITERAL(10, 107, 7), // "setCity"
QT_MOC_LITERAL(11, 115, 14), // "setCurrentTemp"
QT_MOC_LITERAL(12, 130, 13), // "updateWeather"
QT_MOC_LITERAL(13, 144, 14), // "QNetworkReply*"
QT_MOC_LITERAL(14, 159, 5), // "reply"
QT_MOC_LITERAL(15, 165, 11), // "getCityName"
QT_MOC_LITERAL(16, 177, 24), // "slotFinishedTimeGetReply"
QT_MOC_LITERAL(17, 202, 9), // "indexData"
QT_MOC_LITERAL(18, 212, 27), // "QQmlListProperty<IndexData>"
QT_MOC_LITERAL(19, 240, 11), // "weatherData"
QT_MOC_LITERAL(20, 252, 29), // "QQmlListProperty<WeatherData>"
QT_MOC_LITERAL(21, 282, 4), // "city"
QT_MOC_LITERAL(22, 287, 5), // "cTemp"
QT_MOC_LITERAL(23, 293, 5) // "ready"

    },
    "MyModel\0indexDataChanged\0\0weatherDataChanged\0"
    "readyChanged\0cityChanged\0pm25Changed\0"
    "downRefresh\0setReady\0arg\0setCity\0"
    "setCurrentTemp\0updateWeather\0"
    "QNetworkReply*\0reply\0getCityName\0"
    "slotFinishedTimeGetReply\0indexData\0"
    "QQmlListProperty<IndexData>\0weatherData\0"
    "QQmlListProperty<WeatherData>\0city\0"
    "cTemp\0ready"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       5,   94, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   79,    2, 0x0a /* Public */,
       8,    1,   80,    2, 0x0a /* Public */,
      10,    1,   83,    2, 0x0a /* Public */,
      11,    1,   86,    2, 0x0a /* Public */,
      12,    1,   89,    2, 0x0a /* Public */,
      15,    0,   92,    2, 0x0a /* Public */,
      16,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      17, 0x80000000 | 18, 0x00495009,
      19, 0x80000000 | 20, 0x00495009,
      21, QMetaType::QString, 0x00495103,
      22, QMetaType::QString, 0x00495003,
      23, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       3,
       4,
       2,

       0        // eod
};

void MyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->indexDataChanged(); break;
        case 1: _t->weatherDataChanged(); break;
        case 2: _t->readyChanged(); break;
        case 3: _t->cityChanged(); break;
        case 4: _t->pm25Changed(); break;
        case 5: _t->downRefresh(); break;
        case 6: _t->setReady((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setCity((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->setCurrentTemp((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->updateWeather((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: _t->getCityName(); break;
        case 11: _t->slotFinishedTimeGetReply(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyModel::indexDataChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyModel::weatherDataChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyModel::readyChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MyModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyModel::cityChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MyModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyModel::pm25Changed)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MyModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QQmlListProperty<IndexData>*>(_v) = _t->indexData(); break;
        case 1: *reinterpret_cast< QQmlListProperty<WeatherData>*>(_v) = _t->weatherData(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->city(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->cTemp(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->ready(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MyModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->setCity(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setCurrentTemp(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setReady(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject MyModel::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MyModel.data,
    qt_meta_data_MyModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MyModel::indexDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyModel::weatherDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MyModel::readyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MyModel::cityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MyModel::pm25Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
