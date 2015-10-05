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
    QByteArrayData data[69];
    char stringdata0[1361];
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
QT_MOC_LITERAL(4, 62, 8), // "findMail"
QT_MOC_LITERAL(5, 71, 8), // "showInfo"
QT_MOC_LITERAL(6, 80, 13), // "inboxBarInfo1"
QT_MOC_LITERAL(7, 94, 13), // "inboxBarInfo2"
QT_MOC_LITERAL(8, 108, 13), // "inboxBarInfo3"
QT_MOC_LITERAL(9, 122, 13), // "inboxBarInfo4"
QT_MOC_LITERAL(10, 136, 8), // "hideInfo"
QT_MOC_LITERAL(11, 145, 18), // "displayMailSubject"
QT_MOC_LITERAL(12, 164, 6), // "Email*"
QT_MOC_LITERAL(13, 171, 11), // "addChildren"
QT_MOC_LITERAL(14, 183, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(15, 200, 17), // "showFolderContent"
QT_MOC_LITERAL(16, 218, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(17, 235, 14), // "showFolderMenu"
QT_MOC_LITERAL(18, 250, 3), // "pos"
QT_MOC_LITERAL(19, 254, 15), // "showMailContent"
QT_MOC_LITERAL(20, 270, 12), // "showMailMenu"
QT_MOC_LITERAL(21, 283, 20), // "on_newButton_clicked"
QT_MOC_LITERAL(22, 304, 35), // "on_actionNouveau_courrier_tri..."
QT_MOC_LITERAL(23, 340, 23), // "on_deleteButton_clicked"
QT_MOC_LITERAL(24, 364, 28), // "on_actionSupprimer_triggered"
QT_MOC_LITERAL(25, 393, 10), // "deleteItem"
QT_MOC_LITERAL(26, 404, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(27, 428, 35), // "on_actionCancel_confirmed_tri..."
QT_MOC_LITERAL(28, 464, 20), // "on_repButton_clicked"
QT_MOC_LITERAL(29, 485, 27), // "on_actionR_pondre_triggered"
QT_MOC_LITERAL(30, 513, 23), // "on_repAllButton_clicked"
QT_MOC_LITERAL(31, 537, 32), // "on_actionR_pondre_tous_triggered"
QT_MOC_LITERAL(32, 570, 25), // "on_transferButton_clicked"
QT_MOC_LITERAL(33, 596, 29), // "on_actionTransf_rer_triggered"
QT_MOC_LITERAL(34, 626, 24), // "on_isolateButton_clicked"
QT_MOC_LITERAL(35, 651, 25), // "on_actionIsoler_triggered"
QT_MOC_LITERAL(36, 677, 29), // "on_mailList_itemDoubleClicked"
QT_MOC_LITERAL(37, 707, 26), // "on_actionQuitter_triggered"
QT_MOC_LITERAL(38, 734, 27), // "get_actionQuitter_triggered"
QT_MOC_LITERAL(39, 762, 17), // "accountRegistered"
QT_MOC_LITERAL(40, 780, 15), // "previousAccount"
QT_MOC_LITERAL(41, 796, 11), // "nextAccount"
QT_MOC_LITERAL(42, 808, 11), // "showAccount"
QT_MOC_LITERAL(43, 820, 21), // "on_addAccount_clicked"
QT_MOC_LITERAL(44, 842, 22), // "on_actionAdd_triggered"
QT_MOC_LITERAL(45, 865, 13), // "addNewAccount"
QT_MOC_LITERAL(46, 879, 38), // "on_actionSupprimer_le_compte_..."
QT_MOC_LITERAL(47, 918, 10), // "delAccount"
QT_MOC_LITERAL(48, 929, 19), // "delAccountTriggered"
QT_MOC_LITERAL(49, 949, 21), // "on_sendButton_clicked"
QT_MOC_LITERAL(50, 971, 26), // "on_actionEnvoyer_triggered"
QT_MOC_LITERAL(51, 998, 24), // "on_actionAlert_triggered"
QT_MOC_LITERAL(52, 1023, 46), // "on_actionAttacher_des_pi_ces_..."
QT_MOC_LITERAL(53, 1070, 20), // "openAttachFileWindow"
QT_MOC_LITERAL(54, 1091, 7), // "addFile"
QT_MOC_LITERAL(55, 1099, 44), // "on_actionSupprimer_la_pi_ce_j..."
QT_MOC_LITERAL(56, 1144, 16), // "deleteFileAction"
QT_MOC_LITERAL(57, 1161, 15), // "loadAddressFile"
QT_MOC_LITERAL(58, 1177, 17), // "addToAddressField"
QT_MOC_LITERAL(59, 1195, 15), // "showAddressBook"
QT_MOC_LITERAL(60, 1211, 22), // "on_inboxButton_clicked"
QT_MOC_LITERAL(61, 1234, 12), // "toggleFields"
QT_MOC_LITERAL(62, 1247, 13), // "toggleButtons"
QT_MOC_LITERAL(63, 1261, 14), // "toggleNakedApp"
QT_MOC_LITERAL(64, 1276, 18), // "toggleAccountPanel"
QT_MOC_LITERAL(65, 1295, 17), // "inboxButtonsStyle"
QT_MOC_LITERAL(66, 1313, 19), // "groupBoxButtonStyle"
QT_MOC_LITERAL(67, 1333, 9), // "listStyle"
QT_MOC_LITERAL(68, 1343, 17) // "openedMailButtons"

    },
    "MailBox\0getAddressesListFromBook\0\0"
    "getAddressesListFromNewMail\0findMail\0"
    "showInfo\0inboxBarInfo1\0inboxBarInfo2\0"
    "inboxBarInfo3\0inboxBarInfo4\0hideInfo\0"
    "displayMailSubject\0Email*\0addChildren\0"
    "QTreeWidgetItem*\0showFolderContent\0"
    "QListWidgetItem*\0showFolderMenu\0pos\0"
    "showMailContent\0showMailMenu\0"
    "on_newButton_clicked\0"
    "on_actionNouveau_courrier_triggered\0"
    "on_deleteButton_clicked\0"
    "on_actionSupprimer_triggered\0deleteItem\0"
    "on_cancelButton_clicked\0"
    "on_actionCancel_confirmed_triggered\0"
    "on_repButton_clicked\0on_actionR_pondre_triggered\0"
    "on_repAllButton_clicked\0"
    "on_actionR_pondre_tous_triggered\0"
    "on_transferButton_clicked\0"
    "on_actionTransf_rer_triggered\0"
    "on_isolateButton_clicked\0"
    "on_actionIsoler_triggered\0"
    "on_mailList_itemDoubleClicked\0"
    "on_actionQuitter_triggered\0"
    "get_actionQuitter_triggered\0"
    "accountRegistered\0previousAccount\0"
    "nextAccount\0showAccount\0on_addAccount_clicked\0"
    "on_actionAdd_triggered\0addNewAccount\0"
    "on_actionSupprimer_le_compte_triggered\0"
    "delAccount\0delAccountTriggered\0"
    "on_sendButton_clicked\0on_actionEnvoyer_triggered\0"
    "on_actionAlert_triggered\0"
    "on_actionAttacher_des_pi_ces_jointes_triggered\0"
    "openAttachFileWindow\0addFile\0"
    "on_actionSupprimer_la_pi_ce_jointe_triggered\0"
    "deleteFileAction\0loadAddressFile\0"
    "addToAddressField\0showAddressBook\0"
    "on_inboxButton_clicked\0toggleFields\0"
    "toggleButtons\0toggleNakedApp\0"
    "toggleAccountPanel\0inboxButtonsStyle\0"
    "groupBoxButtonStyle\0listStyle\0"
    "openedMailButtons"
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
       4,    1,  335,    2, 0x08 /* Private */,
       5,    0,  338,    2, 0x08 /* Private */,
       6,    0,  339,    2, 0x08 /* Private */,
       7,    0,  340,    2, 0x08 /* Private */,
       8,    0,  341,    2, 0x08 /* Private */,
       9,    0,  342,    2, 0x08 /* Private */,
      10,    0,  343,    2, 0x08 /* Private */,
      11,    1,  344,    2, 0x08 /* Private */,
      13,    2,  347,    2, 0x08 /* Private */,
      15,    1,  352,    2, 0x08 /* Private */,
      17,    1,  355,    2, 0x08 /* Private */,
      19,    1,  358,    2, 0x08 /* Private */,
      20,    1,  361,    2, 0x08 /* Private */,
      21,    0,  364,    2, 0x08 /* Private */,
      22,    0,  365,    2, 0x08 /* Private */,
      23,    0,  366,    2, 0x08 /* Private */,
      24,    0,  367,    2, 0x08 /* Private */,
      25,    0,  368,    2, 0x08 /* Private */,
      26,    0,  369,    2, 0x08 /* Private */,
      27,    0,  370,    2, 0x08 /* Private */,
      28,    0,  371,    2, 0x08 /* Private */,
      29,    0,  372,    2, 0x08 /* Private */,
      30,    0,  373,    2, 0x08 /* Private */,
      31,    0,  374,    2, 0x08 /* Private */,
      32,    0,  375,    2, 0x08 /* Private */,
      33,    0,  376,    2, 0x08 /* Private */,
      34,    0,  377,    2, 0x08 /* Private */,
      35,    0,  378,    2, 0x08 /* Private */,
      36,    0,  379,    2, 0x08 /* Private */,
      37,    0,  380,    2, 0x08 /* Private */,
      38,    0,  381,    2, 0x08 /* Private */,
      39,    0,  382,    2, 0x08 /* Private */,
      40,    0,  383,    2, 0x08 /* Private */,
      41,    0,  384,    2, 0x08 /* Private */,
      42,    2,  385,    2, 0x08 /* Private */,
      43,    0,  390,    2, 0x08 /* Private */,
      44,    0,  391,    2, 0x08 /* Private */,
      45,    0,  392,    2, 0x08 /* Private */,
      46,    0,  393,    2, 0x08 /* Private */,
      47,    0,  394,    2, 0x08 /* Private */,
      48,    0,  395,    2, 0x08 /* Private */,
      49,    0,  396,    2, 0x08 /* Private */,
      50,    0,  397,    2, 0x08 /* Private */,
      51,    0,  398,    2, 0x08 /* Private */,
      52,    0,  399,    2, 0x08 /* Private */,
      53,    0,  400,    2, 0x08 /* Private */,
      54,    1,  401,    2, 0x08 /* Private */,
      55,    0,  404,    2, 0x08 /* Private */,
      56,    0,  405,    2, 0x08 /* Private */,
      57,    0,  406,    2, 0x08 /* Private */,
      58,    1,  407,    2, 0x08 /* Private */,
      59,    0,  410,    2, 0x08 /* Private */,
      60,    0,  411,    2, 0x08 /* Private */,
      61,    1,  412,    2, 0x08 /* Private */,
      62,    1,  415,    2, 0x08 /* Private */,
      63,    1,  418,    2, 0x08 /* Private */,
      64,    1,  421,    2, 0x08 /* Private */,
      65,    0,  424,    2, 0x08 /* Private */,
      66,    0,  425,    2, 0x08 /* Private */,
      67,    0,  426,    2, 0x08 /* Private */,
      68,    0,  427,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 14, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, QMetaType::QPoint,   18,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, QMetaType::QPoint,   18,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
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
        case 2: _t->findMail((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->showInfo(); break;
        case 4: _t->inboxBarInfo1(); break;
        case 5: _t->inboxBarInfo2(); break;
        case 6: _t->inboxBarInfo3(); break;
        case 7: _t->inboxBarInfo4(); break;
        case 8: _t->hideInfo(); break;
        case 9: _t->displayMailSubject((*reinterpret_cast< Email*(*)>(_a[1]))); break;
        case 10: _t->addChildren((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->showFolderContent((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 12: _t->showFolderMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 13: _t->showMailContent((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->showMailMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 15: _t->on_newButton_clicked(); break;
        case 16: _t->on_actionNouveau_courrier_triggered(); break;
        case 17: _t->on_deleteButton_clicked(); break;
        case 18: _t->on_actionSupprimer_triggered(); break;
        case 19: _t->deleteItem(); break;
        case 20: _t->on_cancelButton_clicked(); break;
        case 21: _t->on_actionCancel_confirmed_triggered(); break;
        case 22: _t->on_repButton_clicked(); break;
        case 23: _t->on_actionR_pondre_triggered(); break;
        case 24: _t->on_repAllButton_clicked(); break;
        case 25: _t->on_actionR_pondre_tous_triggered(); break;
        case 26: _t->on_transferButton_clicked(); break;
        case 27: _t->on_actionTransf_rer_triggered(); break;
        case 28: _t->on_isolateButton_clicked(); break;
        case 29: _t->on_actionIsoler_triggered(); break;
        case 30: _t->on_mailList_itemDoubleClicked(); break;
        case 31: _t->on_actionQuitter_triggered(); break;
        case 32: _t->get_actionQuitter_triggered(); break;
        case 33: _t->accountRegistered(); break;
        case 34: _t->previousAccount(); break;
        case 35: _t->nextAccount(); break;
        case 36: _t->showAccount((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 37: _t->on_addAccount_clicked(); break;
        case 38: _t->on_actionAdd_triggered(); break;
        case 39: _t->addNewAccount(); break;
        case 40: _t->on_actionSupprimer_le_compte_triggered(); break;
        case 41: _t->delAccount(); break;
        case 42: _t->delAccountTriggered(); break;
        case 43: _t->on_sendButton_clicked(); break;
        case 44: _t->on_actionEnvoyer_triggered(); break;
        case 45: _t->on_actionAlert_triggered(); break;
        case 46: _t->on_actionAttacher_des_pi_ces_jointes_triggered(); break;
        case 47: _t->openAttachFileWindow(); break;
        case 48: _t->addFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 49: _t->on_actionSupprimer_la_pi_ce_jointe_triggered(); break;
        case 50: _t->deleteFileAction(); break;
        case 51: _t->loadAddressFile(); break;
        case 52: _t->addToAddressField((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 53: _t->showAddressBook(); break;
        case 54: _t->on_inboxButton_clicked(); break;
        case 55: _t->toggleFields((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 56: _t->toggleButtons((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 57: _t->toggleNakedApp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 58: _t->toggleAccountPanel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 59: _t->inboxButtonsStyle(); break;
        case 60: _t->groupBoxButtonStyle(); break;
        case 61: _t->listStyle(); break;
        case 62: _t->openedMailButtons(); break;
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
