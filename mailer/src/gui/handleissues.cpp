#include "src/gui/handleissues.h"
#include "ui_handleissues.h"

HandleIssues::HandleIssues(QWidget *parent, QString str, QString type) :
    QDialog(parent),
    ui(new Ui::HandleIssues)
{
    ui->setupUi(this);

    ui->issueLabel->setText(str);

    if(type == "forceSending")
    {
        ui->okButton->setVisible(false);

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(send_confirmed())) ;
    }

    if(type == "forbidSending")
    {
        ui->ouiButton->setVisible(false);
        ui->nonButton->setVisible(false);
        ui->saveButton->setVisible(false);

        connect(ui->okButton,
                SIGNAL(clicked()),
                SLOT(close())) ;
    }

    if(type == "deleteFromNew")
    {
        ui->okButton->setVisible(false);
        ui->saveButton->setVisible(false);

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parent->parentWidget(),
                SLOT(deleteItem())) ;

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(close())) ;
    }

    if(type == "cancelFromNew")
    {
        ui->okButton->setVisible(false);

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(close())) ;
    }

    if(type == "deleteFromBox")
    {
        ui->okButton->setVisible(false);
        ui->saveButton->setVisible(false);

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(deleteItem())) ;
    }

    if(type == "cancelFromBox")
    {
        ui->okButton->setVisible(false);

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(on_actionCancel_confirmed_triggered())) ;
    }

    if(type == "leave")
    {
        ui->okButton->setVisible(false);
        ui->saveButton->setVisible(false);

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(get_actionQuitter_triggered())) ;
    }

    if(type == "helper")
    {
        ui->ouiButton->setVisible(false);
        ui->nonButton->setVisible(false);
        ui->saveButton->setVisible(false);

        connect(ui->okButton,
                SIGNAL(clicked()),
                SLOT(close())) ;
    }

    if(type == "delAccount")
    {
        ui->okButton->setVisible(false);
        ui->saveButton->setVisible(false);

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(delAccountTriggered()));
    }

    if(type == "account")
    {
        ui->ouiButton->setVisible(false);
        ui->nonButton->setVisible(false);
        ui->saveButton->setVisible(false);

        connect(ui->okButton,
                SIGNAL(clicked()),
                SLOT(close())) ;
    }

    if(type == "deleteAddress")
    {
        ui->okButton->setVisible(false);
        ui->saveButton->setVisible(false);

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(confirmDelete()));
    }
}

HandleIssues::~HandleIssues()
{
    delete ui;
}

void HandleIssues::on_ouiButton_clicked()
{
    this->close();
}

void HandleIssues::on_okButton_clicked()
{
    this->close();
}

void HandleIssues::on_nonButton_clicked()
{
    this->close();
}
