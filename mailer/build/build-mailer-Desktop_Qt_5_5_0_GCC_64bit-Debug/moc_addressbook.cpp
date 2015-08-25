/****************************************************************************
** Meta object code from reading C++ file 'addressbook.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui/addressbook.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addressbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddressBook_t {
    QByteArrayData data[11];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddressBook_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddressBook_t qt_meta_stringdata_AddressBook = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AddressBook"
QT_MOC_LITERAL(1, 12, 9), // "addToMail"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 17), // "sendAddressesList"
QT_MOC_LITERAL(4, 41, 16), // "addAddressToBook"
QT_MOC_LITERAL(5, 58, 11), // "findAddress"
QT_MOC_LITERAL(6, 70, 10), // "clickToAdd"
QT_MOC_LITERAL(7, 81, 15), // "forceAddAddress"
QT_MOC_LITERAL(8, 97, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(9, 114, 13), // "deleteAddress"
QT_MOC_LITERAL(10, 128, 13) // "confirmDelete"

    },
    "AddressBook\0addToMail\0\0sendAddressesList\0"
    "addAddressToBook\0findAddress\0clickToAdd\0"
    "forceAddAddress\0QListWidgetItem*\0"
    "deleteAddress\0confirmDelete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddressBook[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   60,    2, 0x08 /* Private */,
       5,    1,   61,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    1,   65,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AddressBook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddressBook *_t = static_cast<AddressBook *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addToMail((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendAddressesList((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->addAddressToBook(); break;
        case 3: _t->findAddress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->clickToAdd(); break;
        case 5: _t->forceAddAddress((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->deleteAddress(); break;
        case 7: _t->confirmDelete(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddressBook::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddressBook::addToMail)) {
                *result = 0;
            }
        }
        {
            typedef void (AddressBook::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddressBook::sendAddressesList)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject AddressBook::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AddressBook.data,
      qt_meta_data_AddressBook,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddressBook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddressBook::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddressBook.stringdata0))
        return static_cast<void*>(const_cast< AddressBook*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int AddressBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void AddressBook::addToMail(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AddressBook::sendAddressesList(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
