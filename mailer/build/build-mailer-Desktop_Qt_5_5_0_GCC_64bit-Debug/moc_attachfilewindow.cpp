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
    QByteArrayData data[14];
    char stringdata0[215];
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
QT_MOC_LITERAL(7, 113, 14), // "accessToFolder"
QT_MOC_LITERAL(8, 128, 18), // "displayPathContent"
QT_MOC_LITERAL(9, 147, 3), // "str"
QT_MOC_LITERAL(10, 151, 11), // "showDetails"
QT_MOC_LITERAL(11, 163, 7), // "addFile"
QT_MOC_LITERAL(12, 171, 32), // "on_contentList_itemDoubleClicked"
QT_MOC_LITERAL(13, 204, 10) // "openHelper"

    },
    "AttachFileWindow\0sendFileToMail\0\0"
    "on_folderList_itemDoubleClicked\0"
    "QListWidgetItem*\0item\0on_folderList_itemClicked\0"
    "accessToFolder\0displayPathContent\0str\0"
    "showDetails\0addFile\0"
    "on_contentList_itemDoubleClicked\0"
    "openHelper"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AttachFileWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   62,    2, 0x08 /* Private */,
       6,    1,   65,    2, 0x08 /* Private */,
       7,    0,   68,    2, 0x08 /* Private */,
       8,    1,   69,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      11,    0,   75,    2, 0x08 /* Private */,
      12,    1,   76,    2, 0x08 /* Private */,
      13,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,

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
        case 3: _t->accessToFolder(); break;
        case 4: _t->displayPathContent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->showDetails((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->addFile(); break;
        case 7: _t->on_contentList_itemDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->openHelper(); break;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
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
