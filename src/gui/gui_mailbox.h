#ifndef GUI_MAILBOX_H
#define GUI_MAILBOX_H

#include <QDir>
#include <QWidget>
#include <QMouseEvent>
#include <QCompleter>
#include <QtConcurrent/QtConcurrent>
#include <QtConcurrent/QtConcurrentRun>
#include <QFuture>
#include "src/gui/gui_writemail.h"
#include "src/gui/gui_handleissues.h"
#include "src/gui/gui_attachfilewindow.h"
#include "src/gui/gui_addressbook.h"
#include "../mm/config/Config_manager.hpp"
#include "../mm/protocol/Protocol_manager.hpp"
#include "../mm/protocol/imap/IMAP_manager.hpp"

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
    vector<Email*> emails;
    int accountListSize;
    int currentAccount;
    bool checkbox;

public slots:
    void getAddressesListFromBook(QStringList);
    void getAddressesListFromNewMail(QStringList);

private slots:

    /** Recherche et info **/
    void findMail(QString);
    /** Recherche et info **/

    /** Gestion des dossiers + mails **/
    void accountConnector();
    void displayMailSubject(Email*);
    void showMailContent(QListWidgetItem*);
    void showMailMenu(const QPoint &pos);
    /** Gestion des dossiers + mails **/

    /** Nouveau courrier **/
    void on_newButton_clicked();
    void on_actionNouveau_courrier_triggered();
    /** Nouveau courrier **/

    /** Suppression de courrier **/
    void on_deleteButton_clicked();
    void on_actionSupprimer_triggered();
    void deleteItem();
    /** Suppression de courrier **/

    /** Annuler l'action **/
    void on_cancelButton_clicked();
    void on_actionCancel_confirmed_triggered();
    /** Annuler l'action **/

    /** Répondre au courrier **/
    void on_repButton_clicked();
    void on_actionR_pondre_triggered();
    void on_repAllButton_clicked();
    void on_actionR_pondre_tous_triggered();
    void on_transferButton_clicked();
    void on_actionTransf_rer_triggered();
    /** Répondre au courrier **/

    /** Isoler le courrier **/
    void on_isolateButton_clicked();
    void on_actionIsoler_triggered();
    void on_mailList_itemDoubleClicked();
    /** Isoler le courrier **/

    /** Quitter l'appli **/
    void on_actionQuitter_triggered();
    void get_actionQuitter_triggered();
    /** Quitter l'appli **/

    /** Affichage des comptes **/
    void previousAccount();
    void nextAccount();
    /** Affichage des comptes **/

    /** Ajout de compte **/
    void on_addAccount_clicked();
    void on_actionAdd_triggered();
    void addNewAccount() ;
    /** Ajout de compte **/

    /** Suppression de compte **/
    void on_actionSupprimer_le_compte_triggered();
    void delAccount();
    void delAccountTriggered();
    /** Suppression de compte **/

    /** Envoi de courrier **/
    void on_sendButton_clicked();
    void on_actionEnvoyer_triggered();
    void on_actionAlert_triggered();
    /** Envoi de courrier **/

    /** Gestion des pièces jointes **/
    void on_actionAttacher_des_pi_ces_jointes_triggered();
    void openAttachFileWindow();
    void addFile(QString);
    void on_actionSupprimer_la_pi_ce_jointe_triggered();
    void deleteFileAction() ;
    /** Gestion des pièces jointes **/

    /** Gestion du carnet d'adresses **/
    // Les fonctions getAddressesListFrom<Widget>() sont publiques
    void loadAddressFile();
    void addToAddressField(QString);
    void showAddressBook();
    /** Gestion du carnet d'adresses **/

    /** Gestion de l'affichage dynamique **/
    void toggleFields(bool);
    void toggleButtons(bool);
    void toggleAccountPanel(bool);
    void inboxButtonsStyle();
    void groupBoxButtonStyle();
    void listStyle();
    void openedMailButtons() ;
    void turnAccountPanelOff();
    /** Gestion de l'affichage dynamique **/

    void connectWidgets();

private:
    Ui::MailBox *ui;

    QString temp ;

    QPoint clickPos ;
};


#endif // GUI_MAILBOX_H
