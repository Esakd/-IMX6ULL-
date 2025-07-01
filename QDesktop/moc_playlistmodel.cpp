/****************************************************************************
** Meta object code from reading C++ file 'playlistmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "music/playlistmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playlistmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_playListModel_t {
    QByteArrayData data[20];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_playListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_playListModel_t qt_meta_stringdata_playListModel = {
    {
QT_MOC_LITERAL(0, 0, 13), // "playListModel"
QT_MOC_LITERAL(1, 14, 19), // "currentIndexChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 11), // "randomIndex"
QT_MOC_LITERAL(4, 47, 15), // "getcurrentTitle"
QT_MOC_LITERAL(5, 63, 16), // "getcurrentAuthor"
QT_MOC_LITERAL(6, 80, 14), // "getcurrentPath"
QT_MOC_LITERAL(7, 95, 3), // "add"
QT_MOC_LITERAL(8, 99, 5), // "paths"
QT_MOC_LITERAL(9, 105, 4), // "move"
QT_MOC_LITERAL(10, 110, 4), // "from"
QT_MOC_LITERAL(11, 115, 2), // "to"
QT_MOC_LITERAL(12, 118, 6), // "remove"
QT_MOC_LITERAL(13, 125, 5), // "first"
QT_MOC_LITERAL(14, 131, 4), // "last"
QT_MOC_LITERAL(15, 136, 15), // "setCurrentTitle"
QT_MOC_LITERAL(16, 152, 5), // "title"
QT_MOC_LITERAL(17, 158, 16), // "setCurrentAuthor"
QT_MOC_LITERAL(18, 175, 6), // "author"
QT_MOC_LITERAL(19, 182, 12) // "currentIndex"

    },
    "playListModel\0currentIndexChanged\0\0"
    "randomIndex\0getcurrentTitle\0"
    "getcurrentAuthor\0getcurrentPath\0add\0"
    "paths\0move\0from\0to\0remove\0first\0last\0"
    "setCurrentTitle\0title\0setCurrentAuthor\0"
    "author\0currentIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_playListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       1,   88, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       3,    0,   65,    2, 0x02 /* Public */,
       4,    0,   66,    2, 0x02 /* Public */,
       5,    0,   67,    2, 0x02 /* Public */,
       6,    0,   68,    2, 0x02 /* Public */,
       7,    1,   69,    2, 0x02 /* Public */,
       9,    2,   72,    2, 0x02 /* Public */,
      12,    2,   77,    2, 0x02 /* Public */,
      15,    1,   82,    2, 0x02 /* Public */,
      17,    1,   85,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QUrl,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   18,

 // properties: name, type, flags
      19, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void playListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<playListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentIndexChanged(); break;
        case 1: { int _r = _t->randomIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->getcurrentTitle();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->getcurrentAuthor();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QUrl _r = _t->getcurrentPath();
            if (_a[0]) *reinterpret_cast< QUrl*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->add((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->move((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->remove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->setCurrentTitle((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setCurrentAuthor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (playListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&playListModel::currentIndexChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<playListModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->currentIndex(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<playListModel *>(_o);
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

QT_INIT_METAOBJECT const QMetaObject playListModel::staticMetaObject = { {
    &QAbstractListModel::staticMetaObject,
    qt_meta_stringdata_playListModel.data,
    qt_meta_data_playListModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *playListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *playListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_playListModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int playListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
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
void playListModel::currentIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
