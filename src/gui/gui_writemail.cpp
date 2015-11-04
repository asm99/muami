#include "ui_gui_writemail.h"
#include "src/gui/gui_writemail.h"
#include "src/gui/gui_addressbook.h"
#include "src/gui/gui_handleissues.h"
#include "src/gui/gui_attachfilewindow.h"
#include "src/gui/gui_mailbox.h"

/**
 * Delete action : Envoyer l'id du mail en lecture à cette fenetre en parametre
 * pour permettre de retourner une action qui detruise le mail de la liste
 */

WriteMail::WriteMail(QWidget *parent,
                     bool display,
                     QString detail,
                     QString unchangedBody) :
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

    details = detail;
    cleanBody = unchangedBody;
    ui->attachedFiles->setStyleSheet("QListWidget::item{border-bottom:0px}");
    ui->title->setMaxLength(80);
    ui->displayer->setFontPointSize(11);
    ui->displayer->setFontWeight(40) ;
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
        ui->addressBookButton->setVisible(false);
        ui->attachButton->setVisible(false);
        ui->sendButton->setVisible(false);
        ui->cancelButton->setVisible(false);
        ui->to->setReadOnly(true);
        ui->cc->setReadOnly(true);
        ui->bcc->setReadOnly(true);
        ui->title->setReadOnly(true);
        ui->displayer->setReadOnly(true);
        ui->deleteButton->setVisible(false);
    }
    else
    {
        ui->to->setReadOnly(false);
        ui->cc->setReadOnly(false);
        ui->bcc->setReadOnly(false);
        ui->title->setReadOnly(false);
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
    ui->displayer->setText(content[4]);
    if(ui->cc->text() != "")
    {
        ui->cc->setVisible(true);
    }
    else
    {
        ui->cc->setVisible(false);
    }

    if(ui->bcc->text() != "")
    {
        ui->bcc->setVisible(true);
    }
    else
    {
        ui->bcc->setVisible(false);
    }
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

    if (ui->displayer->toPlainText() == "")
    {
        alarm.append("- Il manque le corps du mail.\n") ;
        block = "forceSending";
    }

    QRegExp comaSeparator("\\s*,+\\s*") ;
    comaSeparator.setPatternSyntax(QRegExp::RegExp);
    QRegExp semicolonSeparator("\\s*;+\\s*");
    semicolonSeparator.setPatternSyntax(QRegExp::RegExp);
    QRegExp blank(";+\\s*;+");
    blank.setPatternSyntax(QRegExp::RegExp);
    QRegExp startPos("^\\s*;+\\s*");
    startPos.setPatternSyntax(QRegExp::RegExp);
    QRegExp endPos("\\s*;+\\s*$");
    endPos.setPatternSyntax(QRegExp::RegExp);

    for(int x = 0; x < 10; x++)
    {
        QString to = ui->to->text().replace(comaSeparator,"; ");
        to = to.replace(semicolonSeparator, "; ");
        to = to.replace(blank, "; ");
        to = to.replace(startPos, "");
        to = to.replace(endPos, "");
        ui->to->setText(to);

        QString cc = ui->cc->text().replace(comaSeparator, "; ");
        cc = cc.replace(semicolonSeparator, "; ");
        cc = cc.replace(blank, "; ");
        cc = cc.replace(startPos, "");
        cc = cc.replace(endPos, "");
        ui->cc->setText(cc);

        QString bcc = ui->bcc->text().replace(comaSeparator, "; ");
        bcc = bcc.replace(semicolonSeparator, "; ");
        bcc = bcc.replace(blank, "; ");
        bcc = bcc.replace(startPos, "");
        bcc = bcc.replace(endPos, "");
        ui->bcc->setText(bcc);
    }

    vector<QStringList> lists;
    if(ui->to->text().length() > 0)lists.push_back(ui->to->text().split("; "));
    if(ui->cc->text().length() > 0) lists.push_back(ui->cc->text().split("; "));
    if(ui->bcc->text().length() > 0) lists.push_back(ui->bcc->text().split("; "));

    QRegExp mailRegex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b") ;
    mailRegex.setCaseSensitivity(Qt::CaseInsensitive);
    mailRegex.setPatternSyntax(QRegExp::RegExp);

    for(int mails_list = 0; mails_list < lists.size(); mails_list++)
    {
        QStringList current_list = lists[mails_list];
        for(int email = 0; email < current_list.count(); email++)
        {
            if (!mailRegex.exactMatch(current_list[email]))
            {
                alarm.append("- L'adresse mail "+ current_list[email] + " est invalide.\n") ;
                block = "forbidSending" ;
            }
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
        sendConfirmed();
    }
}

void WriteMail::sendConfirmed()    // PARSER LES DONNEES POUR GESTION PAR LES FONCTIONS DE MM
{
    vector<Out_email*> emails;
    QStringList to_list = ui->to->text().split("; ");
    QStringList cc_list = ui->cc->text().split("; ");
    QStringList bcc_list = ui->bcc->text().split("; ");

    for(int to_mail = 0; to_mail < to_list.count(); to_mail++)
    {
        Address *to = new Address();
        to->set_adl("NIL");
        to->set_name((to_list[to_mail].split("@")[0]).toStdString());
        to->set_host((to_list[to_mail].split("@")[1]).toStdString());
        to->set_mailbox("test");

        Out_email *email = new Out_email();
        email->set_to(*to);
        email->set_subject(ui->title->text().toStdString());
        email->set_content(ui->displayer->toPlainText().toStdString());

/* PROBLEMES DE PUSHBACK DES FONCTIONS add_cc et add_bcc
        for(int cc_mail = 0; cc_mail < cc_list.count(); cc_mail++)
        {
            Address *cc = new Address();
            cc->set_adl("NIL");
            cc->set_name((cc_list[cc_mail].split("@")[0]).toStdString());
            cc->set_host((cc_list[cc_mail].split("@")[1]).toStdString());
            cc->set_mailbox("test");
            email->add_cc(cc);
        }

        for(int bcc_mail = 0; bcc_mail < bcc_list.count(); bcc_mail++)
        {
            Address *bcc = new Address();
            bcc->set_adl("NIL");
            bcc->set_name((bcc_list[bcc_mail].split("@")[0]).toStdString());
            bcc->set_host((bcc_list[bcc_mail].split("@")[1]).toStdString());
            bcc->set_mailbox("test");
            email->add_bcc(bcc);
        }
*/
        emails.push_back(email);
    }

    for(int email = 0; email < emails.size(); email++)
    {
        emails[email]->dump();
    }

/*    Address *to = new Address();
    to->set_adl("NIL");
    to->set_host((ui->to->text().split("@")[1]).toStdString());
    to->set_mailbox("test");
    to->set_name((ui->to->text().split("@")[0]).toStdString());
    email->set_to(*to);
    email->set_subject(ui->title->text().toStdString());
    email->set_content(ui->displayer->toPlainText().toStdString());
    email->dump();*/
    this->close();
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
    if(ui->displayer->toPlainText() != cleanBody)
    {
        QString str = "Voulez-vous annuler les modifications ?" ;
        HandleIssues *box = new HandleIssues(this, str, "cancelModifFromNew") ;
        box->show();
    }
    else if(ui->displayer->toPlainText() == cleanBody)
    {
        QString str = "Voulez-vous fermer la fenêtre ?" ;
        HandleIssues *box = new HandleIssues(this, str, "closeFromNew") ;
        box->show();
    }
}

void WriteMail::displayCleanBody()
{
    ui->displayer->clear();
    ui->displayer->setReadOnly(true);
    ui->displayer->setText(cleanBody);

    ui->addressBookButton->setVisible(false);
    ui->attachButton->setVisible(false);
    ui->sendButton->setVisible(false);
    ui->cancelButton->setVisible(false);
    ui->closeButton->setVisible(true);
    ui->replyAllButton->setVisible(true);
    ui->replyButton->setVisible(true);
    ui->transferButton->setVisible(true);
    if(ui->cc->text() != "")
    {
        ui->cc->setVisible(true);
    }
    else
    {
        ui->cc->setVisible(false);
    }

    if(ui->bcc->text() != "")
    {
        ui->bcc->setVisible(true);
    }
    else
    {
        ui->bcc->setVisible(false);
    }
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
    ui->addressBookButton->setVisible(true);
    ui->attachButton->setVisible(true);
    ui->sendButton->setVisible(true);
    ui->cancelButton->setVisible(true);
    ui->closeButton->setVisible(false);
    ui->replyAllButton->setVisible(false);
    ui->replyButton->setVisible(false);
    ui->transferButton->setVisible(false);
    ui->displayer->setReadOnly(false);
    ui->cc->setVisible(true);
    ui->bcc->setVisible(true);

    QString writter = details;
    QString old = emailFormatting(ui->displayer->toPlainText());
    writter.append(old);
    ui->displayer->clear();
    ui->displayer->setText(writter);
}

QString WriteMail::emailFormatting(QString old)
{
    unsigned int pos = 0;
    old.insert(0, '>');
    for(unsigned int letter = 0; letter < old.size(); letter++)
    {
        if(pos < 79)
        {
            if(old.at(letter) != '\n') pos++;
            else if(old.at(letter) == '\n')
            {
                pos = 0;
                old.insert(letter+1, '>');
            }
        }

        else if(pos == 79)
        {
            if(old.at(letter) == ' ') old.replace(letter, 1, "\n>");
            else if (old.at(letter) == '\n')
            {
                pos = 0;
                old.insert(letter+1, '>');
            }
            else
            {
                while(old.at(letter) != ' ')
                {
                    pos--;
                    letter--;
                }
                pos = 0;
                old.replace(letter, 1, "\n>");
            }
        }
    }

    return old;
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
