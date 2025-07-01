/****************************************************************************
** Meta object code from reading C++ file 'udpsender.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "udpchat/udpsender.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udpsender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UdpSender_t {
    QByteArrayData data[10];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UdpSender_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UdpSender_t qt_meta_stringdata_UdpSender = {
    {
QT_MOC_LITERAL(0, 0, 9), // "UdpSender"
QT_MOC_LITERAL(1, 10, 6), // "recMsg"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 7), // "msgInfo"
QT_MOC_LITERAL(4, 26, 4), // "send"
QT_MOC_LITERAL(5, 31, 3), // "msg"
QT_MOC_LITERAL(6, 35, 17), // "getLocalIpAddress"
QT_MOC_LITERAL(7, 53, 17), // "setUdpReciverInfo"
QT_MOC_LITERAL(8, 71, 7), // "desHost"
QT_MOC_LITERAL(9, 79, 4) // "port"

    },
    "UdpSender\0recMsg\0\0msgInfo\0send\0msg\0"
    "getLocalIpAddress\0setUdpReciverInfo\0"
    "desHost\0port"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UdpSender[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x02 /* Public */,
       6,    0,   40,    2, 0x02 /* Public */,
       7,    2,   41,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // methods: parameters
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    9,

       0        // eod
};

void UdpSender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UdpSender *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recMsg((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->send((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: { QString _r = _t->getLocalIpAddress();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->setUdpReciverInfo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject UdpSender::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_UdpSender.data,
    qt_meta_data_UdpSender,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *UdpSender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UdpSender::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UdpSender.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UdpSender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
