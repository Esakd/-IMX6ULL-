/****************************************************************************
** Meta object code from reading C++ file 'desktop.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "desktop/desktop.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'desktop.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyDesktop_t {
    QByteArrayData data[14];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyDesktop_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyDesktop_t qt_meta_stringdata_MyDesktop = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MyDesktop"
QT_MOC_LITERAL(1, 10, 16), // "sysVolumeChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "cpuTempChanged"
QT_MOC_LITERAL(4, 43, 25), // "standardOutput_ReadVolume"
QT_MOC_LITERAL(5, 69, 12), // "systemReboot"
QT_MOC_LITERAL(6, 82, 14), // "systemPoweroff"
QT_MOC_LITERAL(7, 97, 15), // "getSystemVolume"
QT_MOC_LITERAL(8, 113, 15), // "setSystemVolume"
QT_MOC_LITERAL(9, 129, 5), // "value"
QT_MOC_LITERAL(10, 135, 10), // "getCpuTemp"
QT_MOC_LITERAL(11, 146, 16), // "getCoreBoardInfo"
QT_MOC_LITERAL(12, 163, 9), // "sysVolume"
QT_MOC_LITERAL(13, 173, 7) // "cpuTemp"

    },
    "MyDesktop\0sysVolumeChanged\0\0cpuTempChanged\0"
    "standardOutput_ReadVolume\0systemReboot\0"
    "systemPoweroff\0getSystemVolume\0"
    "setSystemVolume\0value\0getCpuTemp\0"
    "getCoreBoardInfo\0sysVolume\0cpuTemp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyDesktop[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       2,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       5,    0,   62,    2, 0x02 /* Public */,
       6,    0,   63,    2, 0x02 /* Public */,
       7,    0,   64,    2, 0x02 /* Public */,
       8,    1,   65,    2, 0x02 /* Public */,
      10,    0,   68,    2, 0x02 /* Public */,
      11,    0,   69,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Bool,

 // properties: name, type, flags
      12, QMetaType::QString, 0x00495001,
      13, QMetaType::QString, 0x00495001,

 // properties: notify_signal_id
       0,
       1,

       0        // eod
};

void MyDesktop::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyDesktop *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sysVolumeChanged(); break;
        case 1: _t->cpuTempChanged(); break;
        case 2: _t->standardOutput_ReadVolume(); break;
        case 3: _t->systemReboot(); break;
        case 4: _t->systemPoweroff(); break;
        case 5: _t->getSystemVolume(); break;
        case 6: _t->setSystemVolume((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->getCpuTemp(); break;
        case 8: { bool _r = _t->getCoreBoardInfo();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyDesktop::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyDesktop::sysVolumeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyDesktop::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyDesktop::cpuTempChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MyDesktop *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->sysVolume(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->cpuTemp(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject MyDesktop::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MyDesktop.data,
    qt_meta_data_MyDesktop,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyDesktop::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyDesktop::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyDesktop.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MyDesktop::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
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
void MyDesktop::sysVolumeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MyDesktop::cpuTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
