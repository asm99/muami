/****************************************************************************
** Meta object code from reading C++ file 'mailbox.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui/mailbox.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mailbox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MailBox_t {
    QByteArrayData data[68];
    char stringdata0[1357];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MailBox_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MailBox_t qt_meta_stringdata_MailBox = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MailBox"
QT_MOC_LITERAL(1, 8, 24), // "getAddressesListFromBook"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 27), // "getAddressesListFromNewMail"
QT_MOC_LITERAL(4, 62, 8), // "showInfo"
QT_MOC_LITERAL(5, 71, 13), // "inboxBarInfo1"
QT_MOC_LITERAL(6, 85, 13), // "inboxBarInfo2"
QT_MOC_LITERAL(7, 99, 13), // "inboxBarInfo3"
QT_MOC_LITERAL(8, 113, 13), // "inboxBarInfo4"
QT_MOC_LITERAL(9, 127, 8), // "hideInfo"
QT_MOC_LITERAL(10, 136, 11), // "addChildren"
QT_MOC_LITERAL(11, 148, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(12, 165, 17), // "showFolderContent"
QT_MOC_LITERAL(13, 183, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(14, 200, 21), // "changeBackgroundColor"
QT_MOC_LITERAL(15, 222, 14), // "showFolderMenu"
QT_MOC_LITERAL(16, 237, 3), // "pos"
QT_MOC_LITERAL(17, 241, 15), // "showMailContent"
QT_MOC_LITERAL(18, 257, 12), // "showMailMenu"
QT_MOC_LITERAL(19, 270, 35), // "on_actionNouveau_courrier_tri..."
QT_MOC_LITERAL(20, 306, 28), // "on_actionSupprimer_triggered"
QT_MOC_LITERAL(21, 335, 27), // "on_actionR_pondre_triggered"
QT_MOC_LITERAL(22, 363, 25), // "on_actionIsoler_triggered"
QT_MOC_LITERAL(23, 389, 26), // "on_actionQuitter_triggered"
QT_MOC_LITERAL(24, 416, 27), // "get_actionQuitter_triggered"
QT_MOC_LITERAL(25, 444, 17), // "accountRegistered"
QT_MOC_LITERAL(26, 462, 8), // "findMail"
QT_MOC_LITERAL(27, 471, 21), // "on_addAccount_clicked"
QT_MOC_LITERAL(28, 493, 15), // "previousAccount"
QT_MOC_LITERAL(29, 509, 11), // "nextAccount"
QT_MOC_LITERAL(30, 521, 11), // "showAccount"
QT_MOC_LITERAL(31, 533, 13), // "addNewAccount"
QT_MOC_LITERAL(32, 547, 10), // "delAccount"
QT_MOC_LITERAL(33, 558, 19), // "delAccountTriggered"
QT_MOC_LITERAL(34, 578, 20), // "on_newButton_clicked"
QT_MOC_LITERAL(35, 599, 20), // "on_repButton_clicked"
QT_MOC_LITERAL(36, 620, 23), // "on_repAllButton_clicked"
QT_MOC_LITERAL(37, 644, 25), // "on_transferButton_clicked"
QT_MOC_LITERAL(38, 670, 23), // "on_deleteButton_clicked"
QT_MOC_LITERAL(39, 694, 10), // "deleteItem"
QT_MOC_LITERAL(40, 705, 24), // "on_isolateButton_clicked"
QT_MOC_LITERAL(41, 730, 22), // "on_inboxButton_clicked"
QT_MOC_LITERAL(42, 753, 22), // "on_actionAdd_triggered"
QT_MOC_LITERAL(43, 776, 29), // "on_actionTransf_rer_triggered"
QT_MOC_LITERAL(44, 806, 29), // "on_mailList_itemDoubleClicked"
QT_MOC_LITERAL(45, 836, 16), // "deleteFileAction"
QT_MOC_LITERAL(46, 853, 12), // "toggleFields"
QT_MOC_LITERAL(47, 866, 13), // "toggleButtons"
QT_MOC_LITERAL(48, 880, 14), // "toggleNakedApp"
QT_MOC_LITERAL(49, 895, 18), // "toggleAccountPanel"
QT_MOC_LITERAL(50, 914, 17), // "inboxButtonsStyle"
QT_MOC_LITERAL(51, 932, 19), // "groupBoxButtonStyle"
QT_MOC_LITERAL(52, 952, 9), // "listStyle"
QT_MOC_LITERAL(53, 962, 17), // "openedMailButtons"
QT_MOC_LITERAL(54, 980, 21), // "on_sendButton_clicked"
QT_MOC_LITERAL(55, 1002, 24), // "on_actionAlert_triggered"
QT_MOC_LITERAL(56, 1027, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(57, 1051, 35), // "on_actionCancel_confirmed_tri..."
QT_MOC_LITERAL(58, 1087, 20), // "openAttachFileWindow"
QT_MOC_LITERAL(59, 1108, 7), // "addFile"
QT_MOC_LITERAL(60, 1116, 38), // "on_actionSupprimer_le_compte_..."
QT_MOC_LITERAL(61, 1155, 32), // "on_actionR_pondre_tous_triggered"
QT_MOC_LITERAL(62, 1188, 46), // "on_actionAttacher_des_pi_ces_..."
QT_MOC_LITERAL(63, 1235, 44), // "on_actionSupprimer_la_pi_ce_j..."
QT_MOC_LITERAL(64, 1280, 26), // "on_actionEnvoyer_triggered"
QT_MOC_LITERAL(65, 1307, 17), // "addToAddressField"
QT_MOC_LITERAL(66, 1325, 15), // "showAddressBook"
QT_MOC_LITERAL(67, 1341, 15) // "loadAddressFile"

    },
    "MailBox\0getAddressesListFromBook\0\0"
    "getAddressesListFromNewMail\0showInfo\0"
    "inboxBarInfo1\0inboxBarInfo2\0inboxBarInfo3\0"
    "inboxBarInfo4\0hideInfo\0addChildren\0"
    "QTreeWidgetItem*\0showFolderContent\0"
    "QListWidgetItem*\0changeBackgroundColor\0"
    "showFolderMenu\0pos\0showMailContent\0"
    "showMailMenu\0on_actionNouveau_courrier_triggered\0"
    "on_actionSupprimer_triggered\0"
    "on_actionR_pondre_triggered\0"
    "on_actionIsoler_triggered\0"
    "on_actionQuitter_triggered\0"
    "get_actionQuitter_triggered\0"
    "accountRegistered\0findMail\0"
    "on_addAccount_clicked\0previousAccount\0"
    "nextAccount\0showAccount\0addNewAccount\0"
    "delAccount\0delAccountTriggered\0"
    "on_newButton_clicked\0on_repButton_clicked\0"
    "on_repAllButton_clicked\0"
    "on_transferButton_clicked\0"
    "on_deleteButton_clicked\0deleteItem\0"
    "on_isolateButton_clicked\0"
    "on_inboxButton_clicked\0on_actionAdd_triggered\0"
    "on_actionTransf_rer_triggered\0"
    "on_mailList_itemDoubleClicked\0"
    "deleteFileAction\0toggleFields\0"
    "toggleButtons\0toggleNakedApp\0"
    "toggleAccountPanel\0inboxButtonsStyle\0"
    "groupBoxButtonStyle\0listStyle\0"
    "openedMailButtons\0on_sendButton_clicked\0"
    "on_actionAlert_triggered\0"
    "on_cancelButton_clicked\0"
    "on_actionCancel_confirmed_triggered\0"
    "openAttachFileWindow\0addFile\0"
    "on_actionSupprimer_le_compte_triggered\0"
    "on_actionR_pondre_tous_triggered\0"
    "on_actionAttacher_des_pi_ces_jointes_triggered\0"
    "on_actionSupprimer_la_pi_ce_jointe_triggered\0"
    "on_actionEnvoyer_triggered\0addToAddressField\0"
    "showAddressBook\0loadAddressFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MailBox[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      63,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  329,    2, 0x0a /* Public */,
       3,    1,  332,    2, 0x0a /* Public */,
       4,    0,  335,    2, 0x08 /* Private */,
       5,    0,  336,    2, 0x08 /* Private */,
       6,    0,  337,    2, 0x08 /* Private */,
       7,    0,  338,    2, 0x08 /* Private */,
       8,    0,  339,    2, 0x08 /* Private */,
       9,    0,  340,    2, 0x08 /* Private */,
      10,    2,  341,    2, 0x08 /* Private */,
      12,    1,  346,    2, 0x08 /* Private */,
      14,    1,  349,    2, 0x08 /* Private */,
      15,    1,  352,    2, 0x08 /* Private */,
      17,    1,  355,    2, 0x08 /* Private */,
      18,    1,  358,    2, 0x08 /* Private */,
      19,    0,  361,    2, 0x08 /* Private */,
      20,    0,  362,    2, 0x08 /* Private */,
      21,    0,  363,    2, 0x08 /* Private */,
      22,    0,  364,    2, 0x08 /* Private */,
      23,    0,  365,    2, 0x08 /* Private */,
      24,    0,  366,    2, 0x08 /* Private */,
      25,    0,  367,    2, 0x08 /* Private */,
      26,    1,  368,    2, 0x08 /* Private */,
      27,    0,  371,    2, 0x08 /* Private */,
      28,    0,  372,    2, 0x08 /* Private */,
      29,    0,  373,    2, 0x08 /* Private */,
      30,    2,  374,    2, 0x08 /* Private */,
      31,    0,  379,    2, 0x08 /* Private */,
      32,    0,  380,    2, 0x08 /* Private */,
      33,    0,  381,    2, 0x08 /* Private */,
      34,    0,  382,    2, 0x08 /* Private */,
      35,    0,  383,    2, 0x08 /* Private */,
      36,    0,  384,    2, 0x08 /* Private */,
      37,    0,  385,    2, 0x08 /* Private */,
      38,    0,  386,    2, 0x08 /* Private */,
      39,    0,  387,    2, 0x08 /* Private */,
      40,    0,  388,    2, 0x08 /* Private */,
      41,    0,  389,    2, 0x08 /* Private */,
      42,    0,  390,    2, 0x08 /* Private */,
      43,    0,  391,    2, 0x08 /* Private */,
      44,    0,  392,    2, 0x08 /* Private */,
      45,    0,  393,    2, 0x08 /* Private */,
      46,    1,  394,    2, 0x08 /* Private */,
      47,    1,  397,    2, 0x08 /* Private */,
      48,    1,  400,    2, 0x08 /* Private */,
      49,    1,  403,    2, 0x08 /* Private */,
      50,    0,  406,    2, 0x08 /* Private */,
      51,    0,  407,    2, 0x08 /* Private */,
      52,    0,  408,    2, 0x08 /* Private */,
      53,    0,  409,    2, 0x08 /* Private */,
      54,    0,  410,    2, 0x08 /* Private */,
      55,    0,  411,    2, 0x08 /* Private */,
      56,    0,  412,    2, 0x08 /* Private */,
      57,    0,  413,    2, 0x08 /* Private */,
      58,    0,  414,    2, 0x08 /* Private */,
      59,    1,  415,    2, 0x08 /* Private */,
      60,    0,  418,    2, 0x08 /* Private */,
      61,    0,  419,    2, 0x08 /* Private */,
      62,    0,  420,    2, 0x08 /* Private */,
      63,    0,  421,    2, 0x08 /* Private */,
      64,    0,  422,    2, 0x08 /* Private */,
      65,    1,  423,    2, 0x08 /* Private */,
      66,    0,  426,    2, 0x08 /* Private */,
      67,    0,  427,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, QMetaType::QPoint,   16,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, QMetaType::QPoint,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MailBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MailBox *_t = static_cast<MailBox *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getAddressesListFromBook((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->getAddressesListFromNewMail((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->showInfo(); break;
        case 3: _t->inboxBarInfo1(); break;
        case 4: _t->inboxBarInfo2(); break;
        case 5: _t->inboxBarInfo3(); break;
        case 6: _t->inboxBarInfo4(); break;
        case 7: _t->hideInfo(); break;
        case 8: _t->addChildren((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->showFolderContent((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->changeBackgroundColor((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 11: _t->showFolderMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 12: _t->showMailContent((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 13: _t->showMailMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 14: _t->on_actionNouveau_courrier_triggered(); break;
        case 15: _t->on_actionSupprimer_triggered(); break;
        case 16: _t->on_actionR_pondre_triggered(); break;
        case 17: _t->on_actionIsoler_triggered(); break;
        case 18: _t->on_actionQuitter_triggered(); break;
        case 19: _t->get_actionQuitter_triggered(); break;
        case 20: _t->accountRegistered(); break;
        case 21: _t->findMail((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->on_addAccount_clicked(); break;
        case 23: _t->previousAccount(); break;
        case 24: _t->nextAccount(); break;
        case 25: _t->showAccount((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 26: _t->addNewAccount(); break;
        case 27: _t->delAccount(); break;
        case 28: _t->delAccountTriggered(); break;
        case 29: _t->on_newButton_clicked(); break;
        case 30: _t->on_repButton_clicked(); break;
        case 31: _t->on_repAllButton_clicked(); break;
        case 32: _t->on_transferButton_clicked(); break;
        case 33: _t->on_deleteButton_clicked(); break;
        case 34: _t->deleteItem(); break;
        case 35: _t->on_isolateButton_clicked(); break;
        case 36: _t->on_inboxButton_clicked(); break;
        case 37: _t->on_actionAdd_triggered(); break;
        case 38: _t->on_actionTransf_rer_triggered(); break;
        case 39: _t->on_mailList_itemDoubleClicked(); break;
        case 40: _t->deleteFileAction(); break;
        case 41: _t->toggleFields((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->toggleButtons((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->toggleNakedApp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 44: _t->toggleAccountPanel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 45: _t->inboxButtonsStyle(); break;
        case 46: _t->groupBoxButtonStyle(); break;
        case 47: _t->listStyle(); break;
        case 48: _t->openedMailButtons(); break;
        case 49: _t->on_sendButton_clicked(); break;
        case 50: _t->on_actionAlert_triggered(); break;
        case 51: _t->on_cancelButton_clicked(); break;
        case 52: _t->on_actionCancel_confirmed_triggered(); break;
        case 53: _t->openAttachFileWindow(); break;
        case 54: _t->addFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 55: _t->on_actionSupprimer_le_compte_triggered(); break;
        case 56: _t->on_actionR_pondre_tous_triggered(); break;
        case 57: _t->on_actionAttacher_des_pi_ces_jointes_triggered(); break;
        case 58: _t->on_actionSupprimer_la_pi_ce_jointe_triggered(); break;
        case 59: _t->on_actionEnvoyer_triggered(); break;
        case 60: _t->addToAddressField((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 61: _t->showAddressBook(); break;
        case 62: _t->loadAddressFile(); break;
        default: ;
        }
    }
}

const QMetaObject MailBox::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MailBox.data,
      qt_meta_data_MailBox,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MailBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MailBox::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MailBox.stringdata0))
        return static_cast<void*>(const_cast< MailBox*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MailBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 63)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 63;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 63)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 63;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
