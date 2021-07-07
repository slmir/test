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
<<<<<<< HEAD
<<<<<<< HEAD
    QByteArrayData data[23];
    char stringdata0[430];
=======
    QByteArrayData data[29];
    char stringdata0[550];
>>>>>>> interface
=======
    QByteArrayData data[28];
    char stringdata0[536];
>>>>>>> interface
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
<<<<<<< HEAD
<<<<<<< HEAD
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
QT_MOC_LITERAL(20, 388, 6), // "status"
QT_MOC_LITERAL(21, 395, 25), // "OnFileSendRequestReceived"
QT_MOC_LITERAL(22, 421, 8) // "fileSize"
=======
=======
>>>>>>> interface
QT_MOC_LITERAL(1, 11, 7), // "slotAdd"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 1), // "a"
QT_MOC_LITERAL(4, 22, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 44, 36), // "on_Parameters_connect_button_..."
QT_MOC_LITERAL(6, 81, 27), // "on_Open_file_button_clicked"
QT_MOC_LITERAL(7, 109, 32), // "on_File_name_choosed_textChanged"
QT_MOC_LITERAL(8, 142, 4), // "arg1"
QT_MOC_LITERAL(9, 147, 27), // "on_Send_file_button_clicked"
QT_MOC_LITERAL(10, 175, 23), // "OnOpenPortButtonClicked"
QT_MOC_LITERAL(11, 199, 21), // "on_action_4_triggered"
QT_MOC_LITERAL(12, 221, 23), // "on_about_menu_triggered"
QT_MOC_LITERAL(13, 245, 21), // "on_action_5_triggered"
QT_MOC_LITERAL(14, 267, 19), // "on_action_triggered"
QT_MOC_LITERAL(15, 287, 21), // "on_action_3_triggered"
QT_MOC_LITERAL(16, 309, 13), // "OnPortChanged"
QT_MOC_LITERAL(17, 323, 15), // "QSerialPortInfo"
QT_MOC_LITERAL(18, 339, 4), // "port"
QT_MOC_LITERAL(19, 344, 8), // "baudRate"
QT_MOC_LITERAL(20, 353, 36), // "on_File_name_choosed_editingF..."
QT_MOC_LITERAL(21, 390, 31), // "on_Do_connection_button_clicked"
QT_MOC_LITERAL(22, 422, 25), // "on_Do_open_button_clicked"
<<<<<<< HEAD
QT_MOC_LITERAL(23, 448, 13), // "OnNewDataRead"
QT_MOC_LITERAL(24, 462, 25), // "OnConnectionStatusChanged"
QT_MOC_LITERAL(25, 488, 6), // "status"
QT_MOC_LITERAL(26, 495, 19), // "OnPortStatusChanged"
QT_MOC_LITERAL(27, 515, 25), // "OnFileSendRequestReceived"
QT_MOC_LITERAL(28, 541, 8) // "fileSize"
>>>>>>> interface
=======
QT_MOC_LITERAL(23, 448, 25), // "OnConnectionStatusChanged"
QT_MOC_LITERAL(24, 474, 6), // "status"
QT_MOC_LITERAL(25, 481, 19), // "OnPortStatusChanged"
QT_MOC_LITERAL(26, 501, 25), // "OnFileSendRequestReceived"
QT_MOC_LITERAL(27, 527, 8) // "fileSize"
>>>>>>> interface

    },
    "MainWindow\0slotAdd\0\0a\0on_pushButton_clicked\0"
    "on_Parameters_connect_button_clicked\0"
    "on_Open_file_button_clicked\0"
    "on_File_name_choosed_textChanged\0arg1\0"
    "on_Send_file_button_clicked\0"
<<<<<<< HEAD
<<<<<<< HEAD
    "on_Do_connect_button_clicked\0"
    "on_action_4_triggered\0on_about_menu_triggered\0"
    "on_action_5_triggered\0on_action_triggered\0"
    "on_action_3_triggered\0OnPortChanged\0"
    "QSerialPortInfo\0port\0baudRate\0"
    "OnNewDataRead\0OnConnectionStatusChanged\0"
    "status\0OnFileSendRequestReceived\0"
=======
=======
>>>>>>> interface
    "OnOpenPortButtonClicked\0on_action_4_triggered\0"
    "on_about_menu_triggered\0on_action_5_triggered\0"
    "on_action_triggered\0on_action_3_triggered\0"
    "OnPortChanged\0QSerialPortInfo\0port\0"
    "baudRate\0on_File_name_choosed_editingFinished\0"
    "on_Do_connection_button_clicked\0"
<<<<<<< HEAD
    "on_Do_open_button_clicked\0OnNewDataRead\0"
    "OnConnectionStatusChanged\0status\0"
    "OnPortStatusChanged\0OnFileSendRequestReceived\0"
>>>>>>> interface
=======
    "on_Do_open_button_clicked\0"
    "OnConnectionStatusChanged\0status\0"
    "OnPortStatusChanged\0OnFileSendRequestReceived\0"
>>>>>>> interface
    "fileSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
<<<<<<< HEAD
<<<<<<< HEAD
      15,   14, // methods
=======
      20,   14, // methods
>>>>>>> interface
=======
      19,   14, // methods
>>>>>>> interface
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
<<<<<<< HEAD
<<<<<<< HEAD
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    1,   92,    2, 0x08 /* Private */,
       7,    0,   95,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    0,   97,    2, 0x08 /* Private */,
      10,    0,   98,    2, 0x08 /* Private */,
      11,    0,   99,    2, 0x08 /* Private */,
      12,    0,  100,    2, 0x08 /* Private */,
      13,    0,  101,    2, 0x08 /* Private */,
      14,    2,  102,    2, 0x08 /* Private */,
      18,    0,  107,    2, 0x0a /* Public */,
      19,    1,  108,    2, 0x0a /* Public */,
      21,    1,  111,    2, 0x0a /* Public */,
=======
       1,    1,  114,    2, 0x08 /* Private */,
       4,    0,  117,    2, 0x08 /* Private */,
       5,    0,  118,    2, 0x08 /* Private */,
       6,    0,  119,    2, 0x08 /* Private */,
       7,    1,  120,    2, 0x08 /* Private */,
       9,    0,  123,    2, 0x08 /* Private */,
      10,    0,  124,    2, 0x08 /* Private */,
      11,    0,  125,    2, 0x08 /* Private */,
      12,    0,  126,    2, 0x08 /* Private */,
      13,    0,  127,    2, 0x08 /* Private */,
      14,    0,  128,    2, 0x08 /* Private */,
      15,    0,  129,    2, 0x08 /* Private */,
      16,    2,  130,    2, 0x08 /* Private */,
      20,    0,  135,    2, 0x08 /* Private */,
      21,    0,  136,    2, 0x08 /* Private */,
      22,    0,  137,    2, 0x08 /* Private */,
      23,    0,  138,    2, 0x0a /* Public */,
      24,    1,  139,    2, 0x0a /* Public */,
      26,    1,  142,    2, 0x0a /* Public */,
      27,    1,  145,    2, 0x0a /* Public */,
>>>>>>> interface
=======
       1,    1,  109,    2, 0x08 /* Private */,
       4,    0,  112,    2, 0x08 /* Private */,
       5,    0,  113,    2, 0x08 /* Private */,
       6,    0,  114,    2, 0x08 /* Private */,
       7,    1,  115,    2, 0x08 /* Private */,
       9,    0,  118,    2, 0x08 /* Private */,
      10,    0,  119,    2, 0x08 /* Private */,
      11,    0,  120,    2, 0x08 /* Private */,
      12,    0,  121,    2, 0x08 /* Private */,
      13,    0,  122,    2, 0x08 /* Private */,
      14,    0,  123,    2, 0x08 /* Private */,
      15,    0,  124,    2, 0x08 /* Private */,
      16,    2,  125,    2, 0x08 /* Private */,
      20,    0,  130,    2, 0x08 /* Private */,
      21,    0,  131,    2, 0x08 /* Private */,
      22,    0,  132,    2, 0x08 /* Private */,
      23,    1,  133,    2, 0x0a /* Public */,
      25,    1,  136,    2, 0x0a /* Public */,
      26,    1,  139,    2, 0x0a /* Public */,
>>>>>>> interface

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17, QMetaType::Int,   18,   19,
    QMetaType::Void,
<<<<<<< HEAD
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Bool, QMetaType::Int,   22,
=======
    QMetaType::Void,
    QMetaType::Void,
<<<<<<< HEAD
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Bool, QMetaType::Int,   28,
>>>>>>> interface
=======
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Void, QMetaType::Bool,   24,
    QMetaType::Bool, QMetaType::Int,   27,
>>>>>>> interface

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
<<<<<<< HEAD
<<<<<<< HEAD
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
        case 14: { bool _r = _t->OnFileSendRequestReceived((*reinterpret_cast< int(*)>(_a[1])));
=======
=======
>>>>>>> interface
        case 0: _t->slotAdd((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_Parameters_connect_button_clicked(); break;
        case 3: _t->on_Open_file_button_clicked(); break;
        case 4: _t->on_File_name_choosed_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_Send_file_button_clicked(); break;
        case 6: _t->OnOpenPortButtonClicked(); break;
        case 7: _t->on_action_4_triggered(); break;
        case 8: _t->on_about_menu_triggered(); break;
        case 9: _t->on_action_5_triggered(); break;
        case 10: _t->on_action_triggered(); break;
        case 11: _t->on_action_3_triggered(); break;
        case 12: _t->OnPortChanged((*reinterpret_cast< QSerialPortInfo(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->on_File_name_choosed_editingFinished(); break;
        case 14: _t->on_Do_connection_button_clicked(); break;
        case 15: _t->on_Do_open_button_clicked(); break;
<<<<<<< HEAD
        case 16: _t->OnNewDataRead(); break;
        case 17: _t->OnConnectionStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->OnPortStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: { bool _r = _t->OnFileSendRequestReceived((*reinterpret_cast< int(*)>(_a[1])));
>>>>>>> interface
=======
        case 16: _t->OnConnectionStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->OnPortStatusChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: { bool _r = _t->OnFileSendRequestReceived((*reinterpret_cast< int(*)>(_a[1])));
>>>>>>> interface
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
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
<<<<<<< HEAD
<<<<<<< HEAD
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
=======
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
>>>>>>> interface
=======
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
>>>>>>> interface
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
