/****************************************************************************
** Meta object code from reading C++ file 'data_link.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../first/data_link.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'data_link.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataLink_t {
<<<<<<< HEAD
<<<<<<< HEAD
    QByteArrayData data[11];
    char stringdata0[138];
=======
    QByteArrayData data[16];
    char stringdata0[220];
>>>>>>> interface
=======
    QByteArrayData data[16];
    char stringdata0[220];
>>>>>>> interface
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataLink_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataLink_t qt_meta_stringdata_DataLink = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DataLink"
QT_MOC_LITERAL(1, 9, 20), // "NewInfoFrameReceived"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 15), // "currentProgress"
QT_MOC_LITERAL(4, 47, 23), // "ConnectionStatusChanged"
QT_MOC_LITERAL(5, 71, 6), // "status"
<<<<<<< HEAD
<<<<<<< HEAD
QT_MOC_LITERAL(6, 78, 17), // "FileSendRequested"
QT_MOC_LITERAL(7, 96, 8), // "fileSize"
QT_MOC_LITERAL(8, 105, 15), // "OnNewDataToRead"
QT_MOC_LITERAL(9, 121, 11), // "QByteArray*"
QT_MOC_LITERAL(10, 133, 4) // "data"
=======
=======
>>>>>>> interface
QT_MOC_LITERAL(6, 78, 17), // "PortStatusChanged"
QT_MOC_LITERAL(7, 96, 17), // "FileSendRequested"
QT_MOC_LITERAL(8, 114, 8), // "fileSize"
QT_MOC_LITERAL(9, 123, 15), // "OnNewDataToRead"
QT_MOC_LITERAL(10, 139, 11), // "QByteArray*"
QT_MOC_LITERAL(11, 151, 4), // "data"
QT_MOC_LITERAL(12, 156, 17), // "OnReceiveAccepted"
QT_MOC_LITERAL(13, 174, 16), // "OnReceiveAborted"
QT_MOC_LITERAL(14, 191, 23), // "OnSaveFileButtonClicked"
QT_MOC_LITERAL(15, 215, 4) // "path"
<<<<<<< HEAD
>>>>>>> interface
=======
>>>>>>> interface

    },
    "DataLink\0NewInfoFrameReceived\0\0"
    "currentProgress\0ConnectionStatusChanged\0"
<<<<<<< HEAD
<<<<<<< HEAD
    "status\0FileSendRequested\0fileSize\0"
    "OnNewDataToRead\0QByteArray*\0data"
=======
=======
>>>>>>> interface
    "status\0PortStatusChanged\0FileSendRequested\0"
    "fileSize\0OnNewDataToRead\0QByteArray*\0"
    "data\0OnReceiveAccepted\0OnReceiveAborted\0"
    "OnSaveFileButtonClicked\0path"
<<<<<<< HEAD
>>>>>>> interface
=======
>>>>>>> interface
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataLink[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
<<<<<<< HEAD
<<<<<<< HEAD
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   43,    2, 0x0a /* Public */,
=======
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,
       7,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
=======
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       6,    1,   60,    2, 0x06 /* Public */,
       7,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
>>>>>>> interface
       9,    1,   66,    2, 0x0a /* Public */,
      12,    0,   69,    2, 0x0a /* Public */,
      13,    0,   70,    2, 0x0a /* Public */,
      14,    1,   71,    2, 0x0a /* Public */,
<<<<<<< HEAD
>>>>>>> interface
=======
>>>>>>> interface

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Bool,    5,
<<<<<<< HEAD
<<<<<<< HEAD
    QMetaType::Bool, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
=======
=======
>>>>>>> interface
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Bool, QMetaType::Int,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
<<<<<<< HEAD
>>>>>>> interface
=======
>>>>>>> interface

       0        // eod
};

void DataLink::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataLink *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewInfoFrameReceived((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->ConnectionStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
<<<<<<< HEAD
<<<<<<< HEAD
        case 2: { bool _r = _t->FileSendRequested((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->OnNewDataToRead((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
=======
=======
>>>>>>> interface
        case 2: _t->PortStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: { bool _r = _t->FileSendRequested((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->OnNewDataToRead((*reinterpret_cast< QByteArray*(*)>(_a[1]))); break;
        case 5: _t->OnReceiveAccepted(); break;
        case 6: _t->OnReceiveAborted(); break;
        case 7: _t->OnSaveFileButtonClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
<<<<<<< HEAD
>>>>>>> interface
=======
>>>>>>> interface
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataLink::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataLink::NewInfoFrameReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataLink::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataLink::ConnectionStatusChanged)) {
                *result = 1;
                return;
            }
        }
        {
<<<<<<< HEAD
<<<<<<< HEAD
            using _t = bool (DataLink::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataLink::FileSendRequested)) {
=======
            using _t = void (DataLink::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataLink::PortStatusChanged)) {
>>>>>>> interface
=======
            using _t = void (DataLink::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataLink::PortStatusChanged)) {
>>>>>>> interface
                *result = 2;
                return;
            }
        }
        {
            using _t = bool (DataLink::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataLink::FileSendRequested)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataLink::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DataLink.data,
    qt_meta_data_DataLink,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataLink::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataLink::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataLink.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataLink::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void DataLink::NewInfoFrameReceived(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataLink::ConnectionStatusChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> interface
void DataLink::PortStatusChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
<<<<<<< HEAD
>>>>>>> interface
=======
>>>>>>> interface
bool DataLink::FileSendRequested(int _t1)
{
    bool _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
<<<<<<< HEAD
<<<<<<< HEAD
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
=======
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
>>>>>>> interface
=======
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
>>>>>>> interface
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
