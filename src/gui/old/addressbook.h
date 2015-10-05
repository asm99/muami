#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QTreeWidgetItem>
#include "src/gui/writemail.h"

namespace Ui {
class AddressBook;
}

class AddressBook : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit AddressBook(QWidget *parent = 0, QString addressBook = "");
    ~AddressBook();

    QStringList addresses ;

    QString addressBookPath ;

    void loadAddressFile(QString);
    
signals:
    void addToMail(QString);

    void sendAddressesList(QStringList);

private slots:

    void addAddressToBook();

    void findAddress(QString);

    void clickToAdd();

    void forceAddAddress(QTreeWidgetItem *, int);

    void deleteAddress();

    void confirmDelete();

    void saveModification();

private:
    Ui::AddressBook *ui;
};

#endif // ADDRESSBOOK_H
