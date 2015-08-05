#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui {
class AddressBook;
}

class AddressBook : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit AddressBook(QWidget *parent = 0);
    ~AddressBook();
    
private slots:


private:
    Ui::AddressBook *ui;
};

#endif // ADDRESSBOOK_H
