/****************************************************************************
** Meta object code from reading C++ file 'weatherdata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "weather/weatherdata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weatherdata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_IndexData_t {
    QByteArrayData data[15];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IndexData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IndexData_t qt_meta_stringdata_IndexData = {
    {
QT_MOC_LITERAL(0, 0, 9), // "IndexData"
QT_MOC_LITERAL(1, 10, 15), // "descriptChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "tiptChanged"
QT_MOC_LITERAL(4, 39, 12), // "titleChanged"
QT_MOC_LITERAL(5, 52, 12), // "stateChanged"
QT_MOC_LITERAL(6, 65, 11), // "setDescript"
QT_MOC_LITERAL(7, 77, 3), // "arg"
QT_MOC_LITERAL(8, 81, 7), // "setTipt"
QT_MOC_LITERAL(9, 89, 8), // "setTitle"
QT_MOC_LITERAL(10, 98, 8), // "setState"
QT_MOC_LITERAL(11, 107, 8), // "descript"
QT_MOC_LITERAL(12, 116, 4), // "tipt"
QT_MOC_LITERAL(13, 121, 5), // "title"
QT_MOC_LITERAL(14, 127, 5) // "state"

    },
    "IndexData\0descriptChanged\0\0tiptChanged\0"
    "titleChanged\0stateChanged\0setDescript\0"
    "arg\0setTipt\0setTitle\0setState\0descript\0"
    "tipt\0title\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IndexData[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       4,   70, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   58,    2, 0x0a /* Public */,
       8,    1,   61,    2, 0x0a /* Public */,
       9,    1,   64,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,

 // properties: name, type, flags
      11, QMetaType::QString, 0x00495103,
      12, QMetaType::QString, 0x00495103,
      13, QMetaType::QString, 0x00495103,
      14, QMetaType::QString, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void IndexData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<IndexData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->descriptChanged(); break;
        case 1: _t->tiptChanged(); break;
        case 2: _t->titleChanged(); break;
        case 3: _t->stateChanged(); break;
        case 4: _t->setDescript((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setTipt((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->setTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->setState((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (IndexData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IndexData::descriptChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (IndexData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IndexData::tiptChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (IndexData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IndexData::titleChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (IndexData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&IndexData::stateChanged)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<IndexData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->descript(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->tipt(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->title(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->state(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<IndexData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDescript(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setTipt(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setTitle(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setState(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject IndexData::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_IndexData.data,
    qt_meta_data_IndexData,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *IndexData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IndexData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_IndexData.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int IndexData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void IndexData::descriptChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void IndexData::tiptChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void IndexData::titleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void IndexData::stateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
struct qt_meta_stringdata_WeatherData_t {
    QByteArrayData data[24];
    char stringdata0[303];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeatherData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeatherData_t qt_meta_stringdata_WeatherData = {
    {
QT_MOC_LITERAL(0, 0, 11), // "WeatherData"
QT_MOC_LITERAL(1, 12, 11), // "dateChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 17), // "dayPictureChanged"
QT_MOC_LITERAL(4, 43, 19), // "nightPictureChanged"
QT_MOC_LITERAL(5, 63, 14), // "weatherChanged"
QT_MOC_LITERAL(6, 78, 11), // "windChanged"
QT_MOC_LITERAL(7, 90, 21), // "maxTemperatureChanged"
QT_MOC_LITERAL(8, 112, 21), // "minTemperatureChanged"
QT_MOC_LITERAL(9, 134, 7), // "setDate"
QT_MOC_LITERAL(10, 142, 3), // "arg"
QT_MOC_LITERAL(11, 146, 13), // "setDayPicture"
QT_MOC_LITERAL(12, 160, 15), // "setNightPicture"
QT_MOC_LITERAL(13, 176, 10), // "setWeather"
QT_MOC_LITERAL(14, 187, 7), // "setWind"
QT_MOC_LITERAL(15, 195, 17), // "setMaxTemperature"
QT_MOC_LITERAL(16, 213, 17), // "setMinTemperature"
QT_MOC_LITERAL(17, 231, 4), // "date"
QT_MOC_LITERAL(18, 236, 10), // "dayPicture"
QT_MOC_LITERAL(19, 247, 12), // "nightPicture"
QT_MOC_LITERAL(20, 260, 7), // "weather"
QT_MOC_LITERAL(21, 268, 4), // "wind"
QT_MOC_LITERAL(22, 273, 14), // "maxTemperature"
QT_MOC_LITERAL(23, 288, 14) // "minTemperature"

    },
    "WeatherData\0dateChanged\0\0dayPictureChanged\0"
    "nightPictureChanged\0weatherChanged\0"
    "windChanged\0maxTemperatureChanged\0"
    "minTemperatureChanged\0setDate\0arg\0"
    "setDayPicture\0setNightPicture\0setWeather\0"
    "setWind\0setMaxTemperature\0setMinTemperature\0"
    "date\0dayPicture\0nightPicture\0weather\0"
    "wind\0maxTemperature\0minTemperature"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeatherData[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       7,  112, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,
       6,    0,   88,    2, 0x06 /* Public */,
       7,    0,   89,    2, 0x06 /* Public */,
       8,    0,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   91,    2, 0x0a /* Public */,
      11,    1,   94,    2, 0x0a /* Public */,
      12,    1,   97,    2, 0x0a /* Public */,
      13,    1,  100,    2, 0x0a /* Public */,
      14,    1,  103,    2, 0x0a /* Public */,
      15,    1,  106,    2, 0x0a /* Public */,
      16,    1,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,

 // properties: name, type, flags
      17, QMetaType::QString, 0x00495103,
      18, QMetaType::QString, 0x00495103,
      19, QMetaType::QString, 0x00495103,
      20, QMetaType::QString, 0x00495103,
      21, QMetaType::QString, 0x00495103,
      22, QMetaType::Int, 0x00495103,
      23, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,

       0        // eod
};

void WeatherData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WeatherData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dateChanged(); break;
        case 1: _t->dayPictureChanged(); break;
        case 2: _t->nightPictureChanged(); break;
        case 3: _t->weatherChanged(); break;
        case 4: _t->windChanged(); break;
        case 5: _t->maxTemperatureChanged(); break;
        case 6: _t->minTemperatureChanged(); break;
        case 7: _t->setDate((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->setDayPicture((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->setNightPicture((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->setWeather((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->setWind((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->setMaxTemperature((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setMinTemperature((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WeatherData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WeatherData::dateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WeatherData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WeatherData::dayPictureChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WeatherData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WeatherData::nightPictureChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WeatherData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WeatherData::weatherChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (WeatherData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WeatherData::windChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (WeatherData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WeatherData::maxTemperatureChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (WeatherData::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WeatherData::minTemperatureChanged)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<WeatherData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->date(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->dayPicture(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->nightPicture(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->weather(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->wind(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->maxTemperature(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->minTemperature(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<WeatherData *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDate(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setDayPicture(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setNightPicture(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setWeather(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setWind(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setMaxTemperature(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setMinTemperature(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject WeatherData::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_WeatherData.data,
    qt_meta_data_WeatherData,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WeatherData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeatherData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WeatherData.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int WeatherData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void WeatherData::dateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WeatherData::dayPictureChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void WeatherData::nightPictureChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void WeatherData::weatherChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void WeatherData::windChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void WeatherData::maxTemperatureChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void WeatherData::minTemperatureChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
