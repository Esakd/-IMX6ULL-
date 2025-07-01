/****************************************************************************
** Meta object code from reading C++ file 'mytcpclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tcpclient/mytcpclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytcpclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_myTcpclient_t {
    QByteArrayData data[15];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myTcpclient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myTcpclient_t qt_meta_stringdata_myTcpclient = {
    {
QT_MOC_LITERAL(0, 0, 11), // "myTcpclient"
QT_MOC_LITERAL(1, 12, 17), // "recMessageChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "newConnetChanged"
QT_MOC_LITERAL(4, 48, 16), // "slot_tcp_connect"
QT_MOC_LITERAL(5, 65, 17), // "slot_tcp_readData"
QT_MOC_LITERAL(6, 83, 17), // "getLocalIpAddress"
QT_MOC_LITERAL(7, 101, 11), // "sendMessage"
QT_MOC_LITERAL(8, 113, 3), // "str"
QT_MOC_LITERAL(9, 117, 10), // "disConnect"
QT_MOC_LITERAL(10, 128, 20), // "buttonConnectClicked"
QT_MOC_LITERAL(11, 149, 4), // "str1"
QT_MOC_LITERAL(12, 154, 4), // "str2"
QT_MOC_LITERAL(13, 159, 10), // "recMessage"
QT_MOC_LITERAL(14, 170, 9) // "newConnet"

    },
    "myTcpclient\0recMessageChanged\0\0"
    "newConnetChanged\0slot_tcp_connect\0"
    "slot_tcp_readData\0getLocalIpAddress\0"
    "sendMessage\0str\0disConnect\0"
    "buttonConnectClicked\0str1\0str2\0"
    "recMessage\0newConnet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myTcpclient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       2,   68, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       6,    0,   58,    2, 0x02 /* Public */,
       7,    1,   59,    2, 0x02 /* Public */,
       9,    0,   62,    2, 0x02 /* Public */,
      10,    2,   63,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,

 // properties: name, type, flags
      13, QMetaType::QString, 0x00495103,
      14, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void myTcpclient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<myTcpclient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recMessageChanged(); break;
        case 1: _t->newConnetChanged(); break;
        case 2: _t->slot_tcp_connect(); break;
        case 3: _t->slot_tcp_readData(); break;
        case 4: { QString _r = _t->getLocalIpAddress();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->sendMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->disConnect(); break;
        case 7: _t->buttonConnectClicked((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (myTcpclient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myTcpclient::recMessageChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (myTcpclient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myTcpclient::newConnetChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<myTcpclient *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->recMessage(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->newConnet(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<myTcpclient *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRecMessage(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject myTcpclient::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_myTcpclient.data,
    qt_meta_data_myTcpclient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *myTcpclient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myTcpclient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_myTcpclient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int myTcpclient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void myTcpclient::recMessageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void myTcpclient::newConnetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
