#include "src/gui/login.h"
#include "ui_login.h"
#include <QTextStream>
#include <QFile>
#include <vector>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    connect(ui->okButton,
            SIGNAL(clicked()),
            SLOT(checkHash()));

    connect(ui->cancelButton,
            SIGNAL(clicked()),
            SLOT(close()));

    connect(ui->createButton,
            SIGNAL(clicked()),
            SLOT(createHash()));
}

Login::~Login()
{
    delete ui;
}

void Login::checkHash()
{
    QString key = hash(ui->compteText->text(), ui->passText->text());

    int compte = ui->compteText->text().length() ;
    int modulo = (key.length()%
                (compte
               + ui->passText->text().length())) + 10;

    QString fileName ;

    while(modulo)
    {
        fileName.append(key[modulo*compte]);
        modulo -= 1;
    }
}

void Login::createHash()
{
    QString key = hash(ui->compteText->text(), ui->passText->text());

    int compte = ui->compteText->text().length() ;
    int modulo = (key.length()%
                (compte
                + ui->passText->text().length())) + 20;

    QString fileName ;

    while(modulo)
    {
        fileName = fileName.append(key[modulo*compte]);
        modulo -= 1 ;
    }
    QString fichier = fileName.toUtf8().toBase64();
    ui->textEdit->setText(fichier);
    QString path = "/home/furya/Bureau/Qt/mailer/src/usr/";
    QFile file(fichier.append(".txt")) ;
    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        stream << key << endl ;
        file.close();
    }
}

QString Login::hash(QString compte, QString passe)
{
    QString acc = compte.toUtf8().toBase64();
    QString pw = passe.toUtf8().toBase64();
    QString hash = acc.append(pw);

    for(int x = 0; x < 7; x++)
    {
        hash = hash.toUtf8().toBase64();
        acc = acc.toUtf8().toBase64();
        pw = pw.toUtf8().toBase64();
        hash = hash.append(acc).append(pw);
    }

    return hash ;
}
