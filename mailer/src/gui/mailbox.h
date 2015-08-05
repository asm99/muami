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

    void showFolderContent(QTreeWidgetItem*, int);

    void showFolderMenu(const QPoint &pos);

    void showMailContent(QListWidgetItem*);

    void showMailMenu(const QPoint &pos);

    void on_actionNouveau_courrier_triggered();

    void on_actionSupprimer_triggered();

    void on_actionR_pondre_triggered();

    void on_actionIsoler_triggered();

    void on_actionQuitter_triggered();

    void get_actionQuitter_triggered();

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

    void on_mailList_itemDoubleClicked(QListWidgetItem *);

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

private:
    Ui::MailBox *ui;

    QString temp ;

    QPoint clickPos ;
};


#endif // MAILBOX_H
