/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../first/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[395];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 36), // "on_Parameters_connect_button_..."
QT_MOC_LITERAL(4, 71, 27), // "on_Open_file_button_clicked"
QT_MOC_LITERAL(5, 99, 32), // "on_File_name_choosed_textChanged"
QT_MOC_LITERAL(6, 132, 4), // "arg1"
QT_MOC_LITERAL(7, 137, 27), // "on_Send_file_button_clicked"
QT_MOC_LITERAL(8, 165, 28), // "on_Do_connect_button_clicked"
QT_MOC_LITERAL(9, 194, 21), // "on_action_4_triggered"
QT_MOC_LITERAL(10, 216, 23), // "on_about_menu_triggered"
QT_MOC_LITERAL(11, 240, 21), // "on_action_5_triggered"
QT_MOC_LITERAL(12, 262, 19), // "on_action_triggered"
QT_MOC_LITERAL(13, 282, 21), // "on_action_3_triggered"
QT_MOC_LITERAL(14, 304, 13), // "OnPortChanged"
QT_MOC_LITERAL(15, 318, 15), // "QSerialPortInfo"
QT_MOC_LITERAL(16, 334, 4), // "port"
QT_MOC_LITERAL(17, 339, 8), // "baudRate"
QT_MOC_LITERAL(18, 348, 13), // "OnNewDataRead"
QT_MOC_LITERAL(19, 362, 25), // "OnConnectionStatusChanged"
QT_MOC_LITERAL(20, 388, 6) // "status"

    },
    "MainWindow\0on_pushButton_clicked\0\0"
    "on_Parameters_connect_button_clicked\0"
    "on_Open_file_button_clicked\0"
    "on_File_name_choosed_textChanged\0arg1\0"
    "on_Send_file_button_clicked\0"
    "on_Do_connect_button_clicked\0"
    "on_action_4_triggered\0on_about_menu_triggered\0"
    "on_action_5_triggered\0on_action_triggered\0"
    "on_action_3_triggered\0OnPortChanged\0"
    "QSerialPortInfo\0port\0baudRate\0"
    "OnNewDataRead\0OnConnectionStatusChanged\0"
    "status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    1,   87,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    2,   97,    2, 0x08 /* Private */,
      18,    0,  102,    2, 0x0a /* Public */,
      19,    1,  103,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int,   16,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   20,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_Parameters_connect_button_clicked(); break;
        case 2: _t->on_Open_file_button_clicked(); break;
        case 3: _t->on_File_name_choosed_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_Send_file_button_clicked(); break;
        case 5: _t->on_Do_connect_button_clicked(); break;
        case 6: _t->on_action_4_triggered(); break;
        case 7: _t->on_about_menu_triggered(); break;
        case 8: _t->on_action_5_triggered(); break;
        case 9: _t->on_action_triggered(); break;
        case 10: _t->on_action_3_triggered(); break;
        case 11: _t->OnPortChanged((*reinterpret_cast< QSerialPortInfo(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->OnNewDataRead(); break;
        case 13: _t->OnConnectionStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
