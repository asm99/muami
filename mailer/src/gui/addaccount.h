#ifndef ADDACCOUNT_H
#define ADDACCOUNT_H

#include <QDialog>

namespace Ui {
class AddAccount;
}

class AddAccount : public QDialog
{
    Q_OBJECT

public:
    explicit AddAccount(QWidget *parent = 0);
    ~AddAccount();

signals :
    void sendAccount(QString, QString) ;

private slots:
    void on_cancelButton_clicked();

    void sendClick();

private:
    Ui::AddAccount *ui;
};

#endif // ADDACCOUNT_H
