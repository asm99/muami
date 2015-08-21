#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>
#include <QListWidgetItem>
#include "src/gui/writemail.h"

namespace Ui {
class AddressBook;
}

class AddressBook : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit AddressBook(QWidget *parent = 0);
    ~AddressBook();

    QStringList addresses ;

    void loadAddressFile(QString);
    
signals:
    void addToMail(QString);

private slots:
    void addToBook();

    void findAddress(QString);

    void clickToAdd();

    void forceAddAddress(QListWidgetItem *);

    void deleteAddress();

    void confirmDelete();

private:
    Ui::AddressBook *ui;
};

#endif // ADDRESSBOOK_H
