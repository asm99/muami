#ifndef MAILBOX_H
#define MAILBOX_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QListWidget>
#include <QtGui>
#include <QtCore>

namespace Ui {
class MailBox;
}

class MailBox : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MailBox(QWidget *parent = 0);
    ~MailBox();
/*
protected :
    void mousePressEvent( QMouseEvent *);
    void mouseMoveEvent( QMouseEvent *);
*/
private slots:

    void addChildren(QTreeWidgetItem *, QString);

    void showFolderContent(QListWidgetItem*);

    void changeBackgroundColor(QListWidgetItem*);

    void showFolderMenu(const QPoint &pos);

    void showMailContent(QListWidgetItem*);

    void showMailMenu(const QPoint &pos);

    void on_actionNouveau_courrier_triggered();

    void on_actionSupprimer_triggered();

    void on_actionR_pondre_triggered();

    void on_actionIsoler_triggered();

    void on_actionQuitter_triggered();

    void get_actionQuitter_triggered();

    void accountRegistered();

    void findMail(QString);

    void on_addAccount_clicked();

    void addNewAccount(QString, QString) ;

    void delAccount();

    void delAccountTriggered();

    void on_newButton_clicked();

    void on_repButton_clicked();

    void on_repAllButton_clicked();

    void on_transferButton_clicked();

    void on_deleteButton_clicked();

    void deleteItem();

    void on_isolateButton_clicked();

    void on_inboxButton_clicked();

    void on_actionAdd_triggered();

    void on_actionTransf_rer_triggered();

    void on_mailList_itemDoubleClicked();

    void deleteFileAction() ;

    void toggleFields(bool);

    void toggleButtons(bool);

    void toggleNakedApp(bool);

    void openedMailButtons() ;

    void on_sendButton_clicked();

    void on_actionAlert_triggered();

    void on_cancelButton_clicked();

    void on_actionCancel_confirmed_triggered();

    void openAttachFileWindow();

    void addFile(QString);

    void on_actionSupprimer_le_compte_triggered();

    void on_actionR_pondre_tous_triggered();

    void on_actionAttacher_des_pi_ces_jointes_triggered();

    void on_actionSupprimer_la_pi_ce_jointe_triggered();

    void on_actionEnvoyer_triggered();

private:
    Ui::MailBox *ui;

    QString temp ;

    QPoint clickPos ;
};


#endif // MAILBOX_H
