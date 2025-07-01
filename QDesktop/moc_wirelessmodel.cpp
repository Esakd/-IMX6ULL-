/****************************************************************************
** Meta object code from reading C++ file 'wirelessmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "wireless/wirelessmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wirelessmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_wirelessListModel_t {
    QByteArrayData data[27];
    char stringdata0[344];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_wirelessListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_wirelessListModel_t qt_meta_stringdata_wirelessListModel = {
    {
QT_MOC_LITERAL(0, 0, 17), // "wirelessListModel"
QT_MOC_LITERAL(1, 18, 19), // "currentIndexChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 23), // "returnMainWinWifiResult"
QT_MOC_LITERAL(4, 63, 20), // "wirelessReadyChanged"
QT_MOC_LITERAL(5, 84, 29), // "standardOutput_WifiConnectSta"
QT_MOC_LITERAL(6, 114, 28), // "standardError_WifiConnectSta"
QT_MOC_LITERAL(7, 143, 11), // "randomIndex"
QT_MOC_LITERAL(8, 155, 15), // "getcurrentTitle"
QT_MOC_LITERAL(9, 171, 14), // "getcurrentPath"
QT_MOC_LITERAL(10, 186, 12), // "wirelessInit"
QT_MOC_LITERAL(11, 199, 13), // "wirelessClose"
QT_MOC_LITERAL(12, 213, 16), // "getMyWifiSSIDPSK"
QT_MOC_LITERAL(13, 230, 4), // "ssid"
QT_MOC_LITERAL(14, 235, 3), // "psk"
QT_MOC_LITERAL(15, 239, 22), // "passwordLessConnection"
QT_MOC_LITERAL(16, 262, 4), // "move"
QT_MOC_LITERAL(17, 267, 4), // "from"
QT_MOC_LITERAL(18, 272, 2), // "to"
QT_MOC_LITERAL(19, 275, 6), // "remove"
QT_MOC_LITERAL(20, 282, 5), // "first"
QT_MOC_LITERAL(21, 288, 4), // "last"
QT_MOC_LITERAL(22, 293, 15), // "setCurrentTitle"
QT_MOC_LITERAL(23, 309, 5), // "title"
QT_MOC_LITERAL(24, 315, 12), // "currentIndex"
QT_MOC_LITERAL(25, 328, 5), // "state"
QT_MOC_LITERAL(26, 334, 9) // "readyFlag"

    },
    "wirelessListModel\0currentIndexChanged\0"
    "\0returnMainWinWifiResult\0wirelessReadyChanged\0"
    "standardOutput_WifiConnectSta\0"
    "standardError_WifiConnectSta\0randomIndex\0"
    "getcurrentTitle\0getcurrentPath\0"
    "wirelessInit\0wirelessClose\0getMyWifiSSIDPSK\0"
    "ssid\0psk\0passwordLessConnection\0move\0"
    "from\0to\0remove\0first\0last\0setCurrentTitle\0"
    "title\0currentIndex\0state\0readyFlag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wirelessListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       3,  120, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    0,   94,    2, 0x02 /* Public */,
       8,    0,   95,    2, 0x02 /* Public */,
       9,    0,   96,    2, 0x02 /* Public */,
      10,    0,   97,    2, 0x02 /* Public */,
      11,    0,   98,    2, 0x02 /* Public */,
      12,    2,   99,    2, 0x02 /* Public */,
      15,    1,  104,    2, 0x02 /* Public */,
      16,    2,  107,    2, 0x02 /* Public */,
      19,    2,  112,    2, 0x02 /* Public */,
      22,    1,  117,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::QUrl,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   13,   14,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,   21,
    QMetaType::Void, QMetaType::QString,   23,

 // properties: name, type, flags
      24, QMetaType::Int, 0x00495103,
      25, QMetaType::Int, 0x00495001,
      26, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void wirelessListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<wirelessListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentIndexChanged(); break;
        case 1: _t->returnMainWinWifiResult(); break;
        case 2: _t->wirelessReadyChanged(); break;
        case 3: _t->standardOutput_WifiConnectSta(); break;
        case 4: _t->standardError_WifiConnectSta(); break;
        case 5: { int _r = _t->randomIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { QString _r = _t->getcurrentTitle();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QUrl _r = _t->getcurrentPath();
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->wirelessInit(); break;
        case 9: _t->wirelessClose(); break;
        case 10: _t->getMyWifiSSIDPSK((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->passwordLessConnection((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->move((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->remove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->setCurrentTitle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (wirelessListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&wirelessListModel::currentIndexChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (wirelessListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&wirelessListModel::returnMainWinWifiResult)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (wirelessListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&wirelessListModel::wirelessReadyChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<wirelessListModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->currentIndex(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->currentSate(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->readyFlag(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<wirelessListModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentIndex(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject wirelessListModel::staticMetaObject = { {
    &QAbstractListModel::staticMetaObject,
    qt_meta_stringdata_wirelessListModel.data,
    qt_meta_data_wirelessListModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *wirelessListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wirelessListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_wirelessListModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int wirelessListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void wirelessListModel::currentIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void wirelessListModel::returnMainWinWifiResult()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void wirelessListModel::wirelessReadyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
