#ifndef WRITEMAIL_H
#define WRITEMAIL_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QFrame>
#include <QListWidget>
#include <QDesktopWidget>
#include <QCompleter>

namespace Ui {
class WriteMail;
}

class WriteMail : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit WriteMail(QWidget *parent = 0, bool display = true);
    ~WriteMail();

    QStringList addresses ;
    void addContent(QStringList content);
    void addFileToMail(QString);

signals:
    void sendAddressesListToMailBox(QStringList);

public slots:
    void getAddressesListFromBook(QStringList);
    void getAddressesListFromMailBox(QStringList);

private slots:
    void on_cancelButton_clicked();
    void openAddressBook();
    void on_actionSend_triggered();
    void on_actionReply_triggered();
    void on_actionReplyAll_triggered();
    void on_actionTransfer_triggered();
    void on_actionDelete_triggered();
    void on_actionCancel_triggered();
    void on_actionSave_triggered();
    void on_actionClose_triggered();
    void setStuff() ;
    void sendConfirmed();
    void on_sendButton_clicked();
    void on_actionEnvoyer_triggered();
    void on_replyButton_clicked();
    void on_actionR_pondre_triggered();
    void on_actionR_pondre_tous_triggered();
    void on_replyAllButton_clicked();
    void on_actionTransf_rer_triggered();
    void on_transferButton_clicked();
    void on_deleteButton_clicked();
    void on_saveButton_clicked();
    void on_closeButton_clicked();
    void openAttachFileWindow();
    void on_attachButton_clicked();
    void addFile(QString);
    void deleteAttachedFile();
    void on_actionAttachFiletriggered();
    void on_actionDeleteAddedFile_triggered();
    void addToAddressField(QString);
    void showAddressBook();

private:
    Ui::WriteMail *ui;

};

#endif // WRITEMAIL_H
