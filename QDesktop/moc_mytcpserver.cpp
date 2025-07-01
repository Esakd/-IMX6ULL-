/****************************************************************************
** Meta object code from reading C++ file 'mytcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tcpserver/mytcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_myTcpserver_t {
    QByteArrayData data[12];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myTcpserver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myTcpserver_t qt_meta_stringdata_myTcpserver = {
    {
QT_MOC_LITERAL(0, 0, 11), // "myTcpserver"
QT_MOC_LITERAL(1, 12, 17), // "recMessageChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 16), // "newConnetChanged"
QT_MOC_LITERAL(4, 48, 16), // "slot_tcp_connect"
QT_MOC_LITERAL(5, 65, 17), // "slot_tcp_readData"
QT_MOC_LITERAL(6, 83, 17), // "getLocalIpAddress"
QT_MOC_LITERAL(7, 101, 11), // "sendMessage"
QT_MOC_LITERAL(8, 113, 3), // "str"
QT_MOC_LITERAL(9, 117, 10), // "disConnect"
QT_MOC_LITERAL(10, 128, 10), // "recMessage"
QT_MOC_LITERAL(11, 139, 9) // "newConnet"

    },
    "myTcpserver\0recMessageChanged\0\0"
    "newConnetChanged\0slot_tcp_connect\0"
    "slot_tcp_readData\0getLocalIpAddress\0"
    "sendMessage\0str\0disConnect\0recMessage\0"
    "newConnet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myTcpserver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       2,   58, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       6,    0,   53,    2, 0x02 /* Public */,
       7,    1,   54,    2, 0x02 /* Public */,
       9,    0,   57,    2, 0x02 /* Public */,

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

 // properties: name, type, flags
      10, QMetaType::QString, 0x00495103,
      11, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void myTcpserver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<myTcpserver *>(_o);
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
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (myTcpserver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myTcpserver::recMessageChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (myTcpserver::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myTcpserver::newConnetChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<myTcpserver *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->recMessage(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->newConnet(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<myTcpserver *>(_o);
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

QT_INIT_METAOBJECT const QMetaObject myTcpserver::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_myTcpserver.data,
    qt_meta_data_myTcpserver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *myTcpserver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myTcpserver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_myTcpserver.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int myTcpserver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
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
void myTcpserver::recMessageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void myTcpserver::newConnetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
