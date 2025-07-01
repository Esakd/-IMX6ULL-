/****************************************************************************
** Meta object code from reading C++ file 'photolistmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "photoview/photolistmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'photolistmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_photoListModel_t {
    QByteArrayData data[19];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_photoListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_photoListModel_t qt_meta_stringdata_photoListModel = {
    {
QT_MOC_LITERAL(0, 0, 14), // "photoListModel"
QT_MOC_LITERAL(1, 15, 19), // "currentIndexChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 11), // "randomIndex"
QT_MOC_LITERAL(4, 48, 15), // "getcurrentTitle"
QT_MOC_LITERAL(5, 64, 14), // "getcurrentPath"
QT_MOC_LITERAL(6, 79, 3), // "add"
QT_MOC_LITERAL(7, 83, 5), // "paths"
QT_MOC_LITERAL(8, 89, 4), // "move"
QT_MOC_LITERAL(9, 94, 4), // "from"
QT_MOC_LITERAL(10, 99, 2), // "to"
QT_MOC_LITERAL(11, 102, 6), // "remove"
QT_MOC_LITERAL(12, 109, 5), // "first"
QT_MOC_LITERAL(13, 115, 4), // "last"
QT_MOC_LITERAL(14, 120, 15), // "setCurrentTitle"
QT_MOC_LITERAL(15, 136, 5), // "title"
QT_MOC_LITERAL(16, 142, 15), // "setCurrentIndex"
QT_MOC_LITERAL(17, 158, 1), // "i"
QT_MOC_LITERAL(18, 160, 12) // "currentIndex"

    },
    "photoListModel\0currentIndexChanged\0\0"
    "randomIndex\0getcurrentTitle\0getcurrentPath\0"
    "add\0paths\0move\0from\0to\0remove\0first\0"
    "last\0setCurrentTitle\0title\0setCurrentIndex\0"
    "i\0currentIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_photoListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       1,   82, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x02 /* Public */,
       4,    0,   61,    2, 0x02 /* Public */,
       5,    0,   62,    2, 0x02 /* Public */,
       6,    1,   63,    2, 0x02 /* Public */,
       8,    2,   66,    2, 0x02 /* Public */,
      11,    2,   71,    2, 0x02 /* Public */,
      14,    1,   76,    2, 0x02 /* Public */,
      16,    1,   79,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::QUrl,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Int,   17,

 // properties: name, type, flags
      18, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void photoListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<photoListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentIndexChanged(); break;
        case 1: { int _r = _t->randomIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->getcurrentTitle();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QUrl _r = _t->getcurrentPath();
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->add((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->move((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->remove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->setCurrentTitle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->setCurrentIndex((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (photoListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&photoListModel::currentIndexChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<photoListModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->currentIndex(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<photoListModel *>(_o);
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

QT_INIT_METAOBJECT const QMetaObject photoListModel::staticMetaObject = { {
    &QAbstractListModel::staticMetaObject,
    qt_meta_stringdata_photoListModel.data,
    qt_meta_data_photoListModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *photoListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *photoListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_photoListModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int photoListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
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
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void photoListModel::currentIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
