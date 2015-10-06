#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <QDesktopWidget>
#include <QTreeWidgetItem>
#include "src/gui/gui_writemail.h"

namespace Ui {
class AddressBook;
}

class AddressBook : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit AddressBook(QWidget *parent = 0, QString addressBook = "");
    ~AddressBook();

    QStringList addresses;
    QString addressBookPath;
    bool modified;  // Used to check if some entries have been modified
                    // to ask the user to save before closing the window
                    // or not
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
    void modificationAdded(QTreeWidgetItem*,int);
    void checkBeforeClose();
    void connectWidgets();

private:
    Ui::AddressBook *ui;
};

#endif // ADDRESSBOOK_H
