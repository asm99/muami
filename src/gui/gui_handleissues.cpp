#include "src/gui/gui_handleissues.h"
#include "ui_gui_handleissues.h"

HandleIssues::HandleIssues(QWidget *parent, QString str, QString type) :
    QDialog(parent),
    ui(new Ui::HandleIssues)
{
    ui->setupUi(this);

    this->setStyleSheet("QPushButton {"
                               "background:#3eacd1;"
                               "border:0px; "
                               "border-top:1px solid qlineargradient"
                                    "(spread:pad, x1:0 y1:0, x2:1 y2:0,"
                                    "stop:0 rgba(38, 124, 153, 255), "
                                    "stop:1 rgba(38, 124, 153, 255));"
                               "border-right:1px solid qlineargradient"
                                    "(spread:pad, x1:0 y1:0, x2:0 y2:1,"
                                    "stop:0 rgba(38, 124, 153, 255), "
                                    "stop:1 rgba(38, 124, 153, 255));}");

    ui->issueLabel->setStyleSheet("background:#252b2b; "
                                  "color:#FFFFFF;");

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

        connect(ui->okButton,
                SIGNAL(clicked()),
                SLOT(close())) ;
    }

    if(type == "deleteFromNew")
    {
        ui->okButton->setVisible(false);

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parent->parentWidget(),
                SLOT(deleteItem())) ;

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(close())) ;
    }

    if(type == "closeFromNew")
    {
        ui->okButton->setVisible(false);

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(close())) ;
    }

    if(type == "cancelModifFromNew")
    {
        ui->okButton->setVisible(false);

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(displayCleanBody())) ;
    }

    if(type == "deleteFromBox")
    {
        ui->okButton->setVisible(false);

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(deleteItem())) ;

        connect(ui->nonButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(removeCheckbox()));
    }

    if(type == "saveMail")
    {
        ui->okButton->setVisible(false);

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(openExplorerToSave())) ;
    }

    if(type == "denySave")
    {
        ui->ouiButton->setVisible(false);
        ui->nonButton->setVisible(false);

        connect(ui->okButton,
                SIGNAL(clicked()),
                SLOT(close())) ;
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

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(get_actionQuitter_triggered())) ;
    }

    if(type == "helper")
    {
        ui->ouiButton->setVisible(false);
        ui->nonButton->setVisible(false);

        connect(ui->okButton,
                SIGNAL(clicked()),
                SLOT(close())) ;
    }

    if(type == "delAccount")
    {
        ui->okButton->setVisible(false);

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(delAccountTriggered()));
    }

    if(type == "account")
    {
        ui->ouiButton->setVisible(false);
        ui->nonButton->setVisible(false);

        connect(ui->okButton,
                SIGNAL(clicked()),
                SLOT(close())) ;
    }

    if(type == "deleteAddress")
    {
        ui->okButton->setVisible(false);

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(confirmDelete()));
    }

    if(type == "confirmModifAddBook")
    {
        ui->okButton->setVisible(false);

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(saveModification()));

        connect(ui->ouiButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(close()));

        connect(ui->nonButton,
                SIGNAL(clicked()),
                parentWidget(),
                SLOT(close()));
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
