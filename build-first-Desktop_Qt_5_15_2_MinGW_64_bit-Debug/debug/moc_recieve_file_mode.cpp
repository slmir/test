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
    QByteArrayData data[10];
    char stringdata0[277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Recieve_file_mode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Recieve_file_mode_t qt_meta_stringdata_Recieve_file_mode = {
    {
QT_MOC_LITERAL(0, 0, 17), // "Recieve_file_mode"
QT_MOC_LITERAL(1, 18, 41), // "on_Soglsie_to_recieve_file_bu..."
QT_MOC_LITERAL(2, 60, 0), // ""
QT_MOC_LITERAL(3, 61, 36), // "on_Save_recieved_file_button_..."
QT_MOC_LITERAL(4, 98, 36), // "on_Open_folder_dialog_button_..."
QT_MOC_LITERAL(5, 135, 36), // "on_File_directory_choosed_tex..."
QT_MOC_LITERAL(6, 172, 4), // "arg1"
QT_MOC_LITERAL(7, 177, 37), // "on_File_directory_choosed_tex..."
QT_MOC_LITERAL(8, 215, 27), // "on_Save_file_button_clicked"
QT_MOC_LITERAL(9, 243, 33) // "on_Check_file_name_button_cli..."

    },
    "Recieve_file_mode\0"
    "on_Soglsie_to_recieve_file_button_clicked\0"
    "\0on_Save_recieved_file_button_clicked\0"
    "on_Open_folder_dialog_button_clicked\0"
    "on_File_directory_choosed_textEdited\0"
    "arg1\0on_File_directory_choosed_textChanged\0"
    "on_Save_file_button_clicked\0"
    "on_Check_file_name_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Recieve_file_mode[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    1,   52,    2, 0x08 /* Private */,
       7,    1,   55,    2, 0x08 /* Private */,
       8,    0,   58,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Recieve_file_mode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Recieve_file_mode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Soglsie_to_recieve_file_button_clicked(); break;
        case 1: _t->on_Save_recieved_file_button_clicked(); break;
        case 2: _t->on_Open_folder_dialog_button_clicked(); break;
        case 3: _t->on_File_directory_choosed_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_File_directory_choosed_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_Save_file_button_clicked(); break;
        case 6: _t->on_Check_file_name_button_clicked(); break;
        default: ;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
