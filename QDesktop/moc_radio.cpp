/****************************************************************************
** Meta object code from reading C++ file 'radio.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "radio/radio.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'radio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_myRadio_t {
    QByteArrayData data[11];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myRadio_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myRadio_t qt_meta_stringdata_myRadio = {
    {
QT_MOC_LITERAL(0, 0, 7), // "myRadio"
QT_MOC_LITERAL(1, 8, 12), // "namesChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 10), // "nameCalled"
QT_MOC_LITERAL(4, 33, 4), // "name"
QT_MOC_LITERAL(5, 38, 7), // "addName"
QT_MOC_LITERAL(6, 46, 10), // "deleteName"
QT_MOC_LITERAL(7, 57, 5), // "index"
QT_MOC_LITERAL(8, 63, 8), // "getNames"
QT_MOC_LITERAL(9, 72, 9), // "startCall"
QT_MOC_LITERAL(10, 82, 10) // "randomCall"

    },
    "myRadio\0namesChanged\0\0nameCalled\0name\0"
    "addName\0deleteName\0index\0getNames\0"
    "startCall\0randomCall"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myRadio[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    1,   53,    2, 0x02 /* Public */,
       6,    1,   56,    2, 0x02 /* Public */,
       8,    0,   59,    2, 0x02 /* Public */,
       9,    0,   60,    2, 0x02 /* Public */,
      10,    0,   61,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::QStringList,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void myRadio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<myRadio *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->namesChanged(); break;
        case 1: _t->nameCalled((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->addName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->deleteName((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: { QStringList _r = _t->getNames();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->startCall(); break;
        case 6: _t->randomCall(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (myRadio::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myRadio::namesChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (myRadio::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&myRadio::nameCalled)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject myRadio::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_myRadio.data,
    qt_meta_data_myRadio,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *myRadio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myRadio::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_myRadio.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int myRadio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void myRadio::namesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void myRadio::nameCalled(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
