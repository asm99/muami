#include <QDesktopWidget>
#include "src/gui/mainwindow.h"
#include "ui_mainwindow.h"
#include "src/gui/mailbox.h"
#include "src/gui/writemail.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    this->size(),
                    qApp->desktop()->availableGeometry()
                    )
                ) ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mailBox_clicked()
{
    MailBox *mailbox = new MailBox(this) ;
    mailbox->show();
}

void MainWindow::on_actionBoite_de_r_ception_triggered()
{
    MailBox *mailbox = new MailBox(this) ;
    mailbox->show();
}

void MainWindow::on_newMail_clicked()
{
    WriteMail *new_mail = new WriteMail(this) ;
    new_mail->show();
}

void MainWindow::on_actionNouveau_courrier_triggered()
{
    WriteMail *new_mail = new WriteMail(this) ;
    new_mail->show();
}

void MainWindow::on_actionQuitter_triggered()
{
    close();
}


