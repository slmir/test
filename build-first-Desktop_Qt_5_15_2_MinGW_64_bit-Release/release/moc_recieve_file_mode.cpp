/****************************************************************************
** Meta object code from reading C++ file 'recieve_file_mode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../first/recieve_file_mode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recieve_file_mode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Recieve_file_mode_t {
    QByteArrayData data[17];
    char stringdata0[388];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Recieve_file_mode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Recieve_file_mode_t qt_meta_stringdata_Recieve_file_mode = {
    {
QT_MOC_LITERAL(0, 0, 17), // "Recieve_file_mode"
QT_MOC_LITERAL(1, 18, 15), // "ReceiveAccepted"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 14), // "ReceiveAborted"
QT_MOC_LITERAL(4, 50, 21), // "SaveFileButtonClicked"
QT_MOC_LITERAL(5, 72, 4), // "path"
QT_MOC_LITERAL(6, 77, 41), // "on_Soglsie_to_recieve_file_bu..."
QT_MOC_LITERAL(7, 119, 36), // "on_Save_recieved_file_button_..."
QT_MOC_LITERAL(8, 156, 36), // "on_Open_folder_dialog_button_..."
QT_MOC_LITERAL(9, 193, 36), // "on_File_directory_choosed_tex..."
QT_MOC_LITERAL(10, 230, 4), // "arg1"
QT_MOC_LITERAL(11, 235, 37), // "on_File_directory_choosed_tex..."
QT_MOC_LITERAL(12, 273, 27), // "on_Save_file_button_clicked"
QT_MOC_LITERAL(13, 301, 33), // "on_Check_file_name_button_cli..."
QT_MOC_LITERAL(14, 335, 18), // "OnNewFrameReceived"
QT_MOC_LITERAL(15, 354, 15), // "currentProgress"
QT_MOC_LITERAL(16, 370, 17) // "OnExchangeAborted"

    },
    "Recieve_file_mode\0ReceiveAccepted\0\0"
    "ReceiveAborted\0SaveFileButtonClicked\0"
    "path\0on_Soglsie_to_recieve_file_button_clicked\0"
    "on_Save_recieved_file_button_clicked\0"
    "on_Open_folder_dialog_button_clicked\0"
    "on_File_directory_choosed_textEdited\0"
    "arg1\0on_File_directory_choosed_textChanged\0"
    "on_Save_file_button_clicked\0"
    "on_Check_file_name_button_clicked\0"
    "OnNewFrameReceived\0currentProgress\0"
    "OnExchangeAborted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Recieve_file_mode[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    1,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    1,   82,    2, 0x08 /* Private */,
      11,    1,   85,    2, 0x08 /* Private */,
      12,    0,   88,    2, 0x08 /* Private */,
      13,    0,   89,    2, 0x08 /* Private */,
      14,    1,   90,    2, 0x08 /* Private */,
      16,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,   15,
    QMetaType::Void,

       0        // eod
};

void Recieve_file_mode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Recieve_file_mode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReceiveAccepted(); break;
        case 1: _t->ReceiveAborted(); break;
        case 2: _t->SaveFileButtonClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_Soglsie_to_recieve_file_button_clicked(); break;
        case 4: _t->on_Save_recieved_file_button_clicked(); break;
        case 5: _t->on_Open_folder_dialog_button_clicked(); break;
        case 6: _t->on_File_directory_choosed_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_File_directory_choosed_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_Save_file_button_clicked(); break;
        case 9: _t->on_Check_file_name_button_clicked(); break;
        case 10: _t->OnNewFrameReceived((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 11: _t->OnExchangeAborted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Recieve_file_mode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Recieve_file_mode::ReceiveAccepted)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Recieve_file_mode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Recieve_file_mode::ReceiveAborted)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Recieve_file_mode::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Recieve_file_mode::SaveFileButtonClicked)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Recieve_file_mode::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Recieve_file_mode.data,
    qt_meta_data_Recieve_file_mode,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Recieve_file_mode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Recieve_file_mode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Recieve_file_mode.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Recieve_file_mode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Recieve_file_mode::ReceiveAccepted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Recieve_file_mode::ReceiveAborted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Recieve_file_mode::SaveFileButtonClicked(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
