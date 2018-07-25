#ifndef GUI_MAILBOX_H
#define GUI_MAILBOX_H

#include <QDir>
#include <QWidget>
#include <QMouseEvent>
#include <QCompleter>
#include <QtConcurrent/QtConcurrent>
#include <QtConcurrent/QtConcurrentRun>
#include <QFuture>
#include "../gui/gui_writemail.h"
#include "../gui/gui_handleissues.h"
#include "../gui/gui_attachfilewindow.h"
#include "../gui/gui_addressbook.h"
#include "../net/config/Config_manager.hpp"
#include "../net/protocol/Protocol_manager.hpp"
#include "../net/protocol/imap/IMAP_manager.hpp"
#include "../net/smtp/SMTP_manager.hpp"
#include "../net/smtp/Out_email.hpp"

namespace Ui {
class MailBox;
}

class MailBox : public QMainWindow
{
    Q_OBJECT

public:
    explicit MailBox(QWidget *parent = 0);
    ~MailBox();
    QList<QStringList> accountList;
    QStringList addressesBook;
    QString details;
    QString unchangedBody;

private:
    QMap<int, QMap<int, QStringList>> bodies;
    int accountListSize;
    int currentAccount;
    vector<int> offsetPerAcc;
    vector<int> displayedEmailsPerAcc;
    bool checkbox;
    Config_manager *cm;
    QMovie *movie;

public slots:
    void getAddressesListFromBook(QStringList);
    void getAddressesListFromNewMail(QStringList);

private slots:
    /** Finder **/
    void findMail(QString);
    /** Finder **/

    /** Back-end handler **/
    void accountConnector();
    void runRefreshThread();
    void displayMailSubject(QStringList);
    void toLocalMemory(Email *, QString);
    QString ccConstructor(Email *);
    void showMailContent(QListWidgetItem*);
    void showMailMenu(const QPoint &pos);
    void showMoreEmails();
    /** Back-end handler **/

    /** New mail **/
    void on_newButton_clicked();
    void on_actionNouveau_courrier_triggered();
    /** New mail **/

    /** Deleting functions **/
    void on_deleteButton_clicked();
    void on_actionSupprimer_triggered();
    void deleteItem();
    void removeCheckbox();
    /** Deleting functions **/

    /** Saving functions **/
    void askToSaveMail();
    void openExplorerToSave();
    /** Saving functions **/

    /** Cancelling functions **/
    void on_cancelButton_clicked();
    void on_actionCancel_confirmed_triggered();
    /** Cancelling functions **/

    /** Reply functions **/
    void on_repButton_clicked();
    void on_actionR_pondre_triggered();
    void on_repAllButton_clicked();
    void on_actionR_pondre_tous_triggered();
    void on_transferButton_clicked();
    void on_actionTransf_rer_triggered();
    /** Reply functions **/

    /** Filling functions **/
    QString fillMailFields(QString);
    QString emailFormatting(QString);
    /** Filling functions **/

    /** Isolating functions **/
    void on_isolateButton_clicked();
    void on_actionIsoler_triggered();
    void on_mailList_itemDoubleClicked();
    /** Isolating functions **/

    /** Close app **/
    void on_actionQuitter_triggered();
    void get_actionQuitter_triggered();
    /** Close app **/

    /** Account functions **/
    void previousAccount();
    void nextAccount();
    void accountOptions();
    void displayAccountFields();
    void on_actionAdd();
    void addNewAccount() ;
    void on_actionSupprimer_le_compte_triggered();
    void delAccount();
    void delAccountTriggered();
    void submitAccountRequisite(QString);
    /** Account functions **/

    /** Sending functions **/
    void on_sendButton_clicked();
    void on_actionEnvoyer_triggered();
    void on_actionAlert_triggered();
    void sendConfirmed(vector<QStringList>);
    /** Sending functions **/

    /** Attached files functions **/
    void on_actionAttacher_des_pi_ces_jointes_triggered();
    void openAttachFileWindow();
    void addFile(QString);
    void on_actionSupprimer_la_pi_ce_jointe_triggered();
    void deleteFileAction() ;
    /** Attached files functions **/

    /** Address Book functions **/
    // Les fonctions getAddressesListFrom<Widget>() sont publiques
    void loadAddressFile();
    void addToAddressField(QString);
    void showAddressBook();
    /** Address Book functions **/

    /** Display functions **/
    void toggleMailFields(bool);
    void toggleAccountFields(bool);
    void toggleAccountButtons(bool);
    void toggleButtons(bool);
    void inboxButtonsStyle();
    void groupBoxButtonStyle();
    void listStyle();
    void openedMailButtons() ;
    /** Display functions **/

    void connectWidgets();

    void on_saveButton_clicked();

private:
    Ui::MailBox *ui;

    QString temp ;

    QPoint clickPos ;
};


#endif // GUI_MAILBOX_H
