/****************************************************************************
** Meta object code from reading C++ file 'attachfilewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui/attachfilewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'attachfilewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AttachFileWindow_t {
    QByteArrayData data[21];
    char stringdata0[303];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AttachFileWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AttachFileWindow_t qt_meta_stringdata_AttachFileWindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AttachFileWindow"
QT_MOC_LITERAL(1, 17, 14), // "sendFileToMail"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 31), // "on_folderList_itemDoubleClicked"
QT_MOC_LITERAL(4, 65, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 82, 4), // "item"
QT_MOC_LITERAL(6, 87, 25), // "on_folderList_itemClicked"
QT_MOC_LITERAL(7, 113, 19), // "onBackButtonClicked"
QT_MOC_LITERAL(8, 133, 17), // "onGoButtonClicked"
QT_MOC_LITERAL(9, 151, 14), // "accessToFolder"
QT_MOC_LITERAL(10, 166, 8), // "findFile"
QT_MOC_LITERAL(11, 175, 18), // "displayPathContent"
QT_MOC_LITERAL(12, 194, 3), // "str"
QT_MOC_LITERAL(13, 198, 13), // "displayHelper"
QT_MOC_LITERAL(14, 212, 11), // "showDetails"
QT_MOC_LITERAL(15, 224, 10), // "infoButton"
QT_MOC_LITERAL(16, 235, 8), // "showInfo"
QT_MOC_LITERAL(17, 244, 8), // "hideInfo"
QT_MOC_LITERAL(18, 253, 8), // "objStyle"
QT_MOC_LITERAL(19, 262, 7), // "addFile"
QT_MOC_LITERAL(20, 270, 32) // "on_contentList_itemDoubleClicked"

    },
    "AttachFileWindow\0sendFileToMail\0\0"
    "on_folderList_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0on_folderList_itemClicked\0"
    "onBackButtonClicked\0onGoButtonClicked\0"
    "accessToFolder\0findFile\0displayPathContent\0"
    "str\0displayHelper\0showDetails\0infoButton\0"
    "showInfo\0hideInfo\0objStyle\0addFile\0"
    "on_contentList_itemDoubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AttachFileWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   97,    2, 0x08 /* Private */,
       6,    1,  100,    2, 0x08 /* Private */,
       7,    0,  103,    2, 0x08 /* Private */,
       8,    0,  104,    2, 0x08 /* Private */,
       9,    0,  105,    2, 0x08 /* Private */,
      10,    1,  106,    2, 0x08 /* Private */,
      11,    1,  109,    2, 0x08 /* Private */,
      13,    0,  112,    2, 0x08 /* Private */,
      14,    1,  113,    2, 0x08 /* Private */,
      15,    0,  116,    2, 0x08 /* Private */,
      16,    0,  117,    2, 0x08 /* Private */,
      17,    0,  118,    2, 0x08 /* Private */,
      18,    0,  119,    2, 0x08 /* Private */,
      19,    0,  120,    2, 0x08 /* Private */,
      20,    1,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void AttachFileWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AttachFileWindow *_t = static_cast<AttachFileWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendFileToMail((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_folderList_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->on_folderList_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->onBackButtonClicked(); break;
        case 4: _t->onGoButtonClicked(); break;
        case 5: _t->accessToFolder(); break;
        case 6: _t->findFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->displayPathContent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->displayHelper(); break;
        case 9: _t->showDetails((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->infoButton(); break;
        case 11: _t->showInfo(); break;
        case 12: _t->hideInfo(); break;
        case 13: _t->objStyle(); break;
        case 14: _t->addFile(); break;
        case 15: _t->on_contentList_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AttachFileWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AttachFileWindow::sendFileToMail)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject AttachFileWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AttachFileWindow.data,
      qt_meta_data_AttachFileWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AttachFileWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AttachFileWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AttachFileWindow.stringdata0))
        return static_cast<void*>(const_cast< AttachFileWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AttachFileWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void AttachFileWindow::sendFileToMail(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
