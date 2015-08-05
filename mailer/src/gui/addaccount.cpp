#include "src/gui/addaccount.h"
#include "ui_addaccount.h"
#include "src/gui/mailbox.h"
#include "src/gui/handleissues.h"

AddAccount::AddAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAccount)
{
    ui->setupUi(this);


    ui->accountName->setStyleSheet("background-color: #FFFFFF; "
                                   "border:1px solid gray; "
                                   "border-radius:3px");

    ui->tabName->setStyleSheet("background-color: #FFFFFF; "
                               "border:1px solid gray; "
                               "border-radius:3px");

    connect(ui->cancelButton,
            SIGNAL(clicked(bool)),
            SLOT(close()));

    connect(ui->okButton,
            SIGNAL(clicked()),
            SLOT(sendClick()));

    connect(this,
            SIGNAL(sendAccount(QString, QString)),
            this->parentWidget(),
            SLOT(addNewAccount(QString, QString))) ;

    connect(ui->tabName,
            SIGNAL(returnPressed()),
            SLOT(sendClick()));

    connect(ui->accountName,
            SIGNAL(returnPressed()),
            SLOT(sendClick()));
}


AddAccount::~AddAccount()
{
    delete ui;
}

void AddAccount::on_cancelButton_clicked()
{
    close() ;
}

void AddAccount::sendClick()
{
    QString accountName = ui->accountName->text() ;
    QString tabName = ui->tabName->text() ;
    QString issues ;
    if (accountName.length() == 0) issues.append("- Il manque le nom du compte");
    if (tabName.length() == 0) issues.append("\n- Il manque le path du compte");
    if (issues.length() != 0)
    {
        HandleIssues *box = new HandleIssues(this, issues, "account");
        box->show();
    }

    else
    {
        emit sendAccount(tabName, accountName) ;
        close() ;
    }
}

