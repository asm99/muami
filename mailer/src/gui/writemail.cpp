#include <QDesktopWidget>
#include <QCompleter>
#include "ui_writemail.h"
#include "src/gui/writemail.h"
#include "src/gui/addressbook.h"
#include "src/gui/handleissues.h"
#include "src/gui/attachfilewindow.h"
#include "src/gui/mailbox.h"


WriteMail::WriteMail(QWidget *parent, bool display) :
    QMainWindow(parent),
    ui(new Ui::WriteMail)
{
    ui->setupUi(this);
    this->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignLeft,
            this->size(),
            qApp->desktop()->availableGeometry()
            )
        ) ;

    ui->attachedFiles->setStyleSheet("QListWidget::item{border-bottom:0px}");
    ui->title->setMaxLength(80);
    ui->message->setFontPointSize(11);
    ui->message->setFontWeight(40) ;
    ui->attachedFiles->setVisible(false);
    ui->deleteFile->setVisible(false);

    connect(ui->deleteFile,
            SIGNAL(clicked()),
            SLOT(deleteAttachedFile()));

    connect(ui->addressBookButton,
            SIGNAL(clicked()),
            SLOT(showAddressBook()));

    connect(this,
            SIGNAL(sendAddressesListToMailBox(QStringList)),
            this->parentWidget(),
            SLOT(getAddressesListFromNewMail(QStringList)));

    if (!display)
    {
        ui->title->setVisible(false);
        ui->to->setVisible(false);
        ui->cc->setVisible(false);
        ui->bcc->setVisible(false);
        ui->addressBookButton->setVisible(false);
        ui->attachButton->setVisible(false);
        ui->sendButton->setVisible(false);
        ui->cancelButton->setVisible(false);
        ui->message->setReadOnly(true);
    }
    else
    {
        ui->replyAllButton->setVisible(false);
        ui->replyButton->setVisible(false);
        ui->transferButton->setVisible(false);
        ui->closeButton->setVisible(false);
        ui->deleteButton->setVisible(false);
    }
}

WriteMail::~WriteMail()
{
    delete ui;
}

void WriteMail::addContent(QStringList content)
{
    ui->to->setText(content[0]);
    ui->cc->setText(content[1]);
    ui->bcc->setText(content[2]);
    ui->title->setText(content[3]);
    ui->message->setText(content[4]);
}

/** ++ Gestion de l'envoi ++ **/
void WriteMail::on_sendButton_clicked()
{
    on_actionSend_triggered();
}

void WriteMail::on_actionEnvoyer_triggered()
{
    on_actionSend_triggered();
}

void WriteMail::on_actionSend_triggered()
{
    QString alarm ;
    QString block ;

    if (ui->title->text() == "")
    {
        alarm.append("- Il manque l'objet du mail.\n") ;
        block = "forceSending";
    }

    if (ui->message->toPlainText() == "")
    {
        alarm.append("- Il manque le corps du mail.\n") ;
        block = "forceSending";
    }

    if (ui->to->text().length() > 0)
    {
        QRegExp mailRegex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b") ;
        mailRegex.setCaseSensitivity(Qt::CaseInsensitive);
        mailRegex.setPatternSyntax(QRegExp::RegExp);

        if (!mailRegex.exactMatch(ui->to->text()))
        {
            alarm.append("- L'adresse mail est invalide.\n") ;
            block = "forbidSending" ;
        }
    }

    if (ui->to->text().length() == 0)
    {
        alarm.append("- Il manque un destinataire.\n") ;
        block = "forbidSending" ;
    }

    if (block.length() > 0)
    {
        HandleIssues *box = new HandleIssues(this, alarm, block) ;
        box->show();
    }

    else if (block.length() == 0)
    {
        // send_confirmed() en dessous
        this->close() ;
    }
}

void WriteMail::sendConfirmed()    // PARSER LES DONNEES POUR GESTION PAR LES FONCTIONS DE MM
{
    // ACTION D'ENVOI
    // GERER LES OBJETS ATTACHES
}
/** ~~ Gestion de l'envoi ~~ **/


/** ++ Gestion des réponses ++ **/
void WriteMail::on_replyButton_clicked()
{
    on_actionReply_triggered();
}

void WriteMail::on_actionR_pondre_triggered()
{
    on_actionReply_triggered();
}

void WriteMail::on_actionReply_triggered()
{
    setStuff() ;
    // remplir les champs to, cc, etc..
}

void WriteMail::on_replyAllButton_clicked()
{
    on_actionReplyAll_triggered();
}

void WriteMail::on_actionR_pondre_tous_triggered()
{
    on_actionReplyAll_triggered();
}

void WriteMail::on_actionReplyAll_triggered()
{
    setStuff() ;
    // idem que reply
}

void WriteMail::on_transferButton_clicked()
{
    on_actionTransfer_triggered();
}

void WriteMail::on_actionTransf_rer_triggered()
{
    on_actionTransfer_triggered();
}

void WriteMail::on_actionTransfer_triggered()
{
    setStuff() ;
    // idem que reply
}
/** ~~ Gestion des réponses ~~ **/


/** ++ Gestion des actions diverses ++ **/
void WriteMail::on_deleteButton_clicked()
{
    on_actionDelete_triggered();
}

void WriteMail::on_actionDelete_triggered()
{
    QString str = "Voulez-vous supprimer ce courrier ?" ;
    HandleIssues *box = new HandleIssues(this, str, "deleteFromNew") ;
    box->show();
}

void WriteMail::on_cancelButton_clicked()
{
    on_actionCancel_triggered() ;
}

void WriteMail::on_actionCancel_triggered()
{
    QString str = "Voulez-vous annuler les modifications et fermer la fenêtre ?" ;
    HandleIssues *box = new HandleIssues(this, str, "cancelFromNew") ;
    box->show();
}

void WriteMail::on_saveButton_clicked()
{
    on_actionSave_triggered();
}

void WriteMail::on_actionSave_triggered()       // Sauvegarder sur DD ou brouillon ?
{

}

void WriteMail::on_closeButton_clicked()
{
    on_actionClose_triggered();
}

void WriteMail::on_actionClose_triggered()
{
    this->close();
}

void WriteMail::setStuff()
{
    ui->title->setVisible(true);
    ui->to->setVisible(true);
    ui->cc->setVisible(true);
    ui->bcc->setVisible(true);
    ui->addressBookButton->setVisible(true);
    ui->attachButton->setVisible(true);
    ui->sendButton->setVisible(true);
    ui->cancelButton->setVisible(true);
    ui->closeButton->setVisible(false);
    ui->replyAllButton->setVisible(false);
    ui->replyButton->setVisible(false);
    ui->transferButton->setVisible(false);
    ui->message->setReadOnly(false);
}
/** ~~ Gestion des actions diverses ~~ **/


/** ++ Gestion des pièces jointes et carnet d'adresses ++ **/
void WriteMail::on_actionAttachFiletriggered()
{
    openAttachFileWindow();
}

void WriteMail::on_attachButton_clicked()
{
    openAttachFileWindow() ;
}

void WriteMail::openAttachFileWindow()
{
    AttachFileWindow *child = this->findChild<AttachFileWindow *>();
    if (!child)
    {
        AttachFileWindow *box = new AttachFileWindow(this) ;
        box->show();
        delete child ;
    }
    else
    {
        child->close();
        delete child ;
    }
}

void WriteMail::addFile(QString filepath)
{
    QStringList parts = filepath.split("\\");
    QString file = parts.last();
    ui->attachedFiles->setVisible(true);
    ui->deleteFile->setVisible(true);
    QListWidgetItem *item = new QListWidgetItem(ui->attachedFiles);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);
    item->setText(file);
}

void WriteMail::addFileToMail(QString filepath)
{
    QStringList parts = filepath.split("\\");
    QString file = parts.last();
    ui->attachedFiles->setVisible(true);
    ui->deleteFile->setVisible(true);
    QListWidgetItem *item = new QListWidgetItem(ui->attachedFiles);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);
    item->setText(file);
}

void WriteMail::on_actionDeleteAddedFile_triggered()
{
    deleteAttachedFile();
}

void WriteMail::deleteAttachedFile()
{
    int x = 0 ;
    while(x < ui->attachedFiles->count())
    {
        QListWidgetItem *file = ui->attachedFiles->item(x) ;
        if (file->checkState() == Qt::Checked)
        {
            delete file ;
            x = 0;
        }
        else x++ ;
    }

    ui->deleteFile->setText("Supprimer la pièce jointe");

    if (ui->attachedFiles->count() == 0)
    {
        ui->attachedFiles->setVisible(false);
        ui->deleteFile->setVisible(false);
    }
}

void WriteMail::openAddressBook()
{
    AddressBook *child = this->findChild<AddressBook *>();
    if (!child)
    {
        AddressBook *book = new AddressBook(this);
        book->show();
        delete child ;
    }
    else
    {
        child->close();
        delete child ;
    }
}

void WriteMail::addToAddressField(QString address)
{
    QString addresses = ui->to->text();
    if (addresses == "")
    {
        addresses.append(address);
        ui->to->setText(addresses);
    }
    else
    {
        addresses.append("; ");
        addresses.append(address);
        ui->to->setText(addresses);
    }
}

void WriteMail::showAddressBook()
{
    AddressBook *child = this->findChild<AddressBook *>();
    if (!child)
    {
        QString addressBook = "" ;
        QString dir = "";
        QString appPath = QDir::homePath();
        appPath.append("/.config");

        QDir *appliPath = new QDir(appPath);

        QFileInfoList dirList = appliPath->entryInfoList();
        foreach(QFileInfo fileInfo, dirList)
        {
            if (fileInfo.isDir())
            {
                QString dir = fileInfo.fileName() ;
                if(dir == "muami")
                {
                    dir = fileInfo.filePath();
                    QDir *usrPath = new QDir(dir);
                    QFileInfoList files = usrPath->entryInfoList();
                    foreach(QFileInfo fileInfo, files)
                    {
                        if (fileInfo.isFile())
                        {
                            QString file = fileInfo.fileName() ;
                            if(file == "address_book.txt")
                            {
                                addressBook = dir.append("/");
                                addressBook.append(file);
                                break ;
                            }
                        }
                    }
                }
                else if (dir != "") break;
                else continue ;
            }
        }

        if(dir == "")
        {
            appliPath->mkdir("muami");
            addressBook = appliPath->path();
            addressBook.append("/muami/address_book.txt");
            QFile file(addressBook);
            if(file.open(QIODevice::ReadWrite))
            {
                QTextStream stream(&file);
                stream << "Carnet d'adresses\n";
                file.close();
            }
        }

        AddressBook *book = new AddressBook(this, addressBook);
        book->show();
        delete child;
    }

    else
    {
        child->close();
        delete child ;
    }
}

void WriteMail::getAddressesListFromBook(QStringList addressesList)
{
    addresses = addressesList ;

    QCompleter *completer = new QCompleter(addresses, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->to->setCompleter(completer);
    ui->cc->setCompleter(completer);
    ui->bcc->setCompleter(completer);

    emit sendAddressesListToMailBox(addresses);
}

void WriteMail::getAddressesListFromMailBox(QStringList addressesList)
{
    addresses = addressesList ;

    QCompleter *completer = new QCompleter(addresses, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->to->setCompleter(completer);
    ui->cc->setCompleter(completer);
    ui->bcc->setCompleter(completer);
}

/** ~~ Gestion des pièces jointes et carnet d'adresses ~~ **/
