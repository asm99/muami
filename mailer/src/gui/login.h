#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots :

    void checkHash();

    void createHash();

private:
    Ui::Login *ui;

    QString hash(QString, QString) ;
};

#endif // LOGIN_H
