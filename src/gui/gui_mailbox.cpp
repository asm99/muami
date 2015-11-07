#include "ui_gui_mailbox.h"
#include "src/gui/gui_mailbox.h"
#include <QMovie>

MailBox::MailBox(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MailBox)
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

    this->setWindowFlags(Qt::FramelessWindowHint) ;

    ui->toolBar->setVisible(false);
    ui->deleteFile->setVisible(false);
    ui->actionSupprimer_la_pi_ce_jointe->setVisible(false);
    ui->attachedFileList->setVisible(false);

    ui->displayer->setReadOnly(true);
    ui->displayer->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

    toggleMailFields(false) ;
    toggleAccountFields(false);
    toggleAccountButtons(false);
    toggleButtons(false) ;

    movie = new QMovie("/home/furya/Bureau/L2/Qt/mailer/src/gui/res/spinner.gif");
    ui->spinner->setAttribute(Qt::WA_NoSystemBackground);
    ui->spinner->setMovie(movie);
    movie->start();

    try {
            currentAccount = 0;
            QtConcurrent::run(this, &MailBox::accountConnector);
            /** Repasser cm en globale lorsque la commande NOOP sera implémentée
             * ça permet de maintenir les sockets, ne nécessitant plus la
             * création de cm à la demande
             */
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }

    inboxButtonsStyle();
    groupBoxButtonStyle();
    listStyle();
    loadAddressFile();
    connectWidgets();
    checkbox = false ;
    ui->mailList->setContextMenuPolicy(Qt::CustomContextMenu);
}



MailBox::~MailBox()
{
    delete ui;
}

/** ++ Display mails ++ **/
void MailBox::accountConnector()
{
    ui->spinner->show();

    //Config_manager* cm = new Config_manager(); /**Pour test avec renew de
                                                 /** connexion **/
    cm = new Config_manager();                   /** Pour test local **/
    accountListSize = cm->get_accounts_count();
    if(accountListSize > 1)
    {
        ui->previousAccount->setVisible(true);
        ui->nextAccount->setVisible(true);
    }
    else
    {
        ui->previousAccount->setVisible(false);
        ui->nextAccount->setVisible(false);
    }

    Account* acc = cm->get_account_at_index(currentAccount);

    acc->connect();
    acc->login();
    acc->list_mboxes();
    acc->select_mbox("INBOX");
    acc->fetch_emails_list(5, 0);

    ui->mailList->clear();

    cout << "nb of emails: " << acc->cur_mbox()->emails().size() << endl;

    for (auto em : acc->cur_mbox()->emails()) {
        em->dump();
        displayMailSubject(em);
    }
    QListWidgetItem *more = new QListWidgetItem(ui->mailList);
    more->setText("Voir plus de mails");
    ui->mailList->addItem(more); /** Le rendre cliquable pour lui assigner
                                   * une action **/
    acc->logout();
    movie->stop();
    ui->spinner->hide();
}

void MailBox::displayMailSubject(Email *mail)
{
    ui->actionTransf_rer->setVisible(false);
    ui->actionR_pondre->setVisible(false);
    ui->actionIsoler->setVisible(false);
    ui->actionSupprimer->setVisible(false);
    ui->mailField->setVisible(true);

    QListWidgetItem *item = new QListWidgetItem(ui->mailList);
    QString subject = QString::fromStdString(mail->envelope().subject().str());
    QString from = QString::fromStdString(mail->envelope().from()->name());
    QStringList dateLine = QString::fromStdString(mail->internaldate()).split(" ");
    QString date = dateLine.at(0) + " - " + dateLine.at(1);
    QString toDisplay = from + "\n" + date + "\n" + subject ;
    item->setText(toDisplay);
    item->setWhatsThis(QString::number(mail->uid()));
    ui->mailList->addItem(item);
}

void MailBox::showMailContent(QListWidgetItem* mail)
{
    ui->displayer->setReadOnly(true);
    ui->actionTransf_rer->setVisible(true);
    ui->actionR_pondre->setVisible(true);
    ui->actionIsoler->setVisible(false);
    toggleMailFields(false) ;

    fillMailFields("ALL");
    ui->title->setVisible(true);
    ui->title->setReadOnly(true);
    ui->to->setVisible(true);
    ui->to->setReadOnly(true);
    if(ui->cc->text() != "")
    {
        ui->cc->setVisible(true);
        ui->cc->setReadOnly(true);
    }
    else
    {
        ui->cc->setVisible(false);
        ui->cc->setReadOnly(false);
    }

    if(ui->bcc->text() != "")
    {
        ui->bcc->setVisible(true);
        ui->bcc->setReadOnly(true);
    }
    else
    {
        ui->bcc->setVisible(false);
        ui->bcc->setReadOnly(false);
    }

    toggleButtons(true) ;
    ui->cancelButton->setVisible(false);
    ui->sendButton->setVisible(false);
    ui->actionEnvoyer->setVisible(false);
    ui->actionAttacher_des_pi_ces_jointes->setVisible(false);

    int id = mail->whatsThis().toInt();

    /** Boucle pour chercher l'id du mail dans le vecteur et afficher
     * son contenu
     */
}

void MailBox::showMailMenu(const QPoint &pos)
{
    QPoint globalPos = ui->mailList->mapToGlobal(pos);
    QMenu myMenu;
    myMenu.addAction("Répondre", this, SLOT(on_actionR_pondre_triggered()));
    myMenu.addAction("Répondre à tous");
    myMenu.addAction("Transférer", this, SLOT(on_actionTransf_rer_triggered()));
    myMenu.addSeparator();
    myMenu.addAction("Sauvegarder");
    myMenu.addSeparator();
    myMenu.addAction("Supprimer", this, SLOT(on_actionSupprimer_triggered()));

    if (ui->mailList->currentItem())
        QAction *selectedItem = myMenu.exec(globalPos);
}
/** ~~ Display mails ~~ **/


/** ++ Create a new mail ++ **/
void MailBox::on_newButton_clicked()
{
    on_actionNouveau_courrier_triggered();
}

void MailBox::on_actionNouveau_courrier_triggered()
{
    WriteMail *new_mail = new WriteMail(this) ;
    new_mail->show();
    new_mail->getAddressesListFromMailBox(addressesBook);
    toggleMailFields(false) ;
}
/** ~~ Create a new mail ~~ **/


/** ++ Delete mails ++ **/
void MailBox::on_deleteButton_clicked()
{
    on_actionSupprimer_triggered();
}

void MailBox::on_actionSupprimer_triggered()
{
    if (!checkbox)
    {
        for(int x = 0; x < ui->mailList->count(); x++)
        {
            QListWidgetItem *mail = ui->mailList->item(x);
            mail->setFlags(mail->flags() | Qt::ItemIsUserCheckable);
            mail->setCheckState(Qt::Unchecked);
        }
        checkbox = true;
    }
    else
    {
        int checked_mail = 0 ;
        for(int x = 0; x < ui->mailList->count(); x++)
        {
            QListWidgetItem *mail = ui->mailList->item(x);
            if (mail->checkState() == Qt::Checked)
            {
                checked_mail ++ ;
            }
        }
        if (checked_mail > 1)
        {
            QString str = "Voulez-vous supprimer ces courriers ?" ;
            HandleIssues *box = new HandleIssues(this, str, "deleteFromBox") ;
            box->show();
        }

        else if (checked_mail == 1)
        {
            QString str = "Voulez-vous supprimer ce courrier ?" ;
            HandleIssues *box = new HandleIssues(this, str, "deleteFromBox") ;
            box->show();
        }

        else if (!checked_mail)
        {
            for(int x = 0; x < ui->mailList->count(); x++)
            {
                QListWidgetItem *mail = ui->mailList->item(x);
                mail->setData(Qt::CheckStateRole, QVariant());
                checkbox = false;
            }
        }
    }
}

void MailBox::deleteItem()
{
    int x = 0 ;
    while(x < ui->mailList->count())
    {
        QListWidgetItem *mail = ui->mailList->item(x) ;
        if (mail->checkState() == Qt::Checked)
        {
            delete mail ;
            x = 0;
        }
        else x++ ;
    }
    for(int y = 0; y < ui->mailList->count(); y++)
    {
        QListWidgetItem *mail = ui->mailList->item(y);
        mail->setData(Qt::CheckStateRole, QVariant());
    }
    ui->mailField->clear();
    checkbox = false;
}
/** ~~ Delete mails ~~ **/


/** ++ Cancel operation ++ **/
void MailBox::on_cancelButton_clicked()
{
    QString str = "Voulez-vous annuler les modifications ?" ;
    HandleIssues *box = new HandleIssues(this, str, "cancelFromBox") ;
    box->show();
}

void MailBox::on_actionCancel_confirmed_triggered()
{
    showMailContent(ui->mailList->currentItem());
    ui->mailList->setVisible(true);
    ui->mailField->setVisible(true);
    ui->attachedFileList->setVisible(false);
    ui->deleteFile->setVisible(false);
    ui->actionSupprimer_la_pi_ce_jointe->setVisible(false);
    ui->actionAttacher_des_pi_ces_jointes->setVisible(false);
}
/** ~~ Cancel operation ~~ **/


/** ++ Reply ++ **/
void MailBox::on_repButton_clicked()
{
    on_actionR_pondre_triggered();
}

void MailBox::on_actionR_pondre_triggered()  // REMPLIR LES CHAMPS TO, CC, ETC
{
    if(ui->mailList->currentItem())
    {
        ui->displayer->clear();
        ui->displayer->setReadOnly(false);
        QTextCursor cursor = ui->displayer->textCursor() ;
        cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor,1);
        ui->displayer->setTextCursor(cursor);
        QString old = ui->displayer->toPlainText() ;
        QString newline = "\n\n_______________________________________________\n\n\n";
        newline.append(old);
        ui->displayer->setText(newline);

        fillMailFields("");
        toggleMailFields(true) ;
        toggleButtons(false);
        openedMailButtons() ;
    }
}

void MailBox::on_repAllButton_clicked()
{
    on_actionR_pondre_tous_triggered();
}

void MailBox::on_actionR_pondre_tous_triggered()     // REMPLIR LES CHAMPS TO, CC, ETC
{
    if(ui->mailList->currentItem())
    {
        ui->displayer->clear();
        ui->displayer->setReadOnly(false);
        QTextCursor cursor = ui->displayer->textCursor() ;
        cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor,1);
        ui->displayer->setTextCursor(cursor);
        QString old = ui->displayer->toPlainText() ;
        QString newline = "\n\n_______________________________________________\n\n\n";
        newline.append(old);
        ui->displayer->setText(newline);

        fillMailFields("ALL");
        toggleMailFields(true) ;
        toggleButtons(false) ;
        openedMailButtons() ;
    }
}

void MailBox::on_transferButton_clicked()
{
    on_actionTransf_rer_triggered();
}

void MailBox::on_actionTransf_rer_triggered()
{
    if(ui->mailList->currentItem())
    {
        ui->displayer->clear();
        ui->displayer->setReadOnly(false);
        QTextCursor cursor = ui->displayer->textCursor() ;
        cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor,1);
        ui->displayer->setTextCursor(cursor);
        QString old = ui->displayer->toPlainText() ;
        QString newline = "\n\n_______________________________________________\n\n\n";
        newline.append(old);
        ui->displayer->setText(newline);

        toggleMailFields(true) ;
        toggleButtons(false) ;
        openedMailButtons() ;
    }
}
/** ~~ Reply ~~ **/

/** ++ Fill functions ++ **/

void MailBox::fillMailFields(QString reply)
{
    Account *acc = cm->get_account_at_index(currentAccount);
    for(auto em : acc->cur_mbox()->emails())
    {
        if(em->uid() == ui->mailList->currentItem()->whatsThis().toInt())
        {
            ui->title->setText(QString::fromStdString(em->envelope().subject().str()));

            QString mail = QString::fromStdString(em->envelope().from()->mailbox());
            mail.append("@");
            mail.append(QString::fromStdString(em->envelope().from()->host()));
            mail.replace(" ", "");
            ui->to->setText(mail);

            if (reply == "ALL")
                {
                    mail = "";

                    Addresses *cc = em->envelope().cc();
                    for(unsigned int x = 0; x < cc->size(); x++)
                    {
                        QString name = QString::fromStdString(cc->operator [](x)->mailbox());
                        mail.append(name.replace(" ", ""));
                        mail.append("@");
                        name = QString::fromStdString(cc->operator [](x)->host());
                        mail.append(name.replace(" ", ""));
                        mail.append("; ");
                    }
                    ui->cc->setText(mail);
                }
        }
    }
}

/** ~~ Fill functions ~~ **/

/** ++ Isolate ++ **/
void MailBox::on_mailList_itemDoubleClicked()
{
    on_actionIsoler_triggered();
}

void MailBox::on_isolateButton_clicked()
{
    on_actionIsoler_triggered();
}

void MailBox::on_actionIsoler_triggered()     // REMPLIR LES CHAMPS TO, CC, ETC
{
    QString to = ui->to->text() ;
    QString cc = ui->cc->text() ;
    QString bcc = ui->bcc->text() ;
    QString title = ui->title->text() ;
    QString content = ui->displayer->toPlainText() ;
    QStringList list ;
    list << to << cc << bcc << title << content ;

    WriteMail *new_mail ;
    if (!ui->displayer->isReadOnly())
    {
        new_mail = new WriteMail(this, true) ;
    }
    else if (ui->displayer->isReadOnly())
    {
        new_mail = new WriteMail(this, false) ;
    }

    new_mail->getAddressesListFromMailBox(addressesBook);
    new_mail->show() ;
    new_mail->addContent(list);
    int count = ui->attachedFileList->count();
    if (count > 0)
    {
        for(int x = 0 ; x < count; x++)
        {
            new_mail->addFileToMail(ui->attachedFileList->item(x)->text());
        }
    }

    int resizer = ui->mailList->width()
                + ui->displayer->width()
                + ui->attachedFileList->width() ;

    showMailContent(ui->mailList->currentItem()) ;
    ui->attachedFileList->clear();
    ui->attachedFileList->setVisible(false);
    ui->deleteFile->setVisible(false);
    ui->actionSupprimer_la_pi_ce_jointe->setVisible(false);
    ui->mailList->setVisible(true);
    ui->mailField->setVisible(true);
    ui->mailList->resize(resizer/2, ui->mailList->height());
    ui->displayer->resize(resizer/2, ui->displayer->height());
}
/** ~~ Isolate ~~ **/

/** ++ Mail finder ++ **/
void MailBox::findMail(QString toFind)
{
    QRegExp finder(".*"+toFind+".*") ;
    finder.setCaseSensitivity(Qt::CaseInsensitive);
    finder.setPatternSyntax(QRegExp::RegExp);

    for(int x = 0; x < ui->mailList->count(); x++)
    {
        QListWidgetItem *item = ui->mailList->item(x);
        QString match = item->text();
        if (!finder.exactMatch(match))
        {
            item->setHidden(true);
        }
        else
        {
            item->setHidden(false);
        }
    }
}
/** ~~ Mail finder ~~ **/


/** ++ Quit ++ **/
void MailBox::on_actionQuitter_triggered()
{
    QString str = "Voulez-vous quitter l'application ?" ;
    HandleIssues *box = new HandleIssues(this, str, "leave") ;
    box->show();
}

void MailBox::get_actionQuitter_triggered()
{
    qApp->quit();
}
/** ~~ Quit ~~ **/


/** ++ Account monitoring functions ++ **/
void MailBox::previousAccount()
{
    if (currentAccount - 1 < 0)
    {
        currentAccount = accountListSize - 1;
    }
    else
    {
        currentAccount -= 1;
    }

    QtConcurrent::run(this, &MailBox::accountConnector);
}

void MailBox::nextAccount()
{
    cout<<currentAccount<<endl;
    if (currentAccount + 1 == accountListSize)
    {
        currentAccount = 0;
    }
    else
    {
        currentAccount += 1;
    }

    QtConcurrent::run(this, &MailBox::accountConnector);
}

void MailBox::accountOptions()
{
    bool n ;
    if (ui->accountMenuBtn->isVisible()) n = false;
    else if(ui->cancelAccount->isVisible()) n = true;

    if(n == true && accountListSize > 1)
    {
        ui->nextAccount->setVisible(n);
        ui->previousAccount->setVisible(n);
    }

    if(n == false)
    {
        ui->nextAccount->setVisible(n);
        ui->previousAccount->setVisible(n);
    }

    ui->accountMenuBtn->setVisible(n);
    ui->addAccount->setVisible(!n);
    ui->delAccount->setVisible(!n);
    ui->cancelAccount->setVisible(!n);

    ui->imapServer->setVisible(false);
    ui->imapPort->setVisible(false);
    ui->smtpServer->setVisible(false);
    ui->smtpPort->setVisible(false);
    ui->name->setVisible(false);
    ui->mailAccount->setVisible(false);
    ui->password->setVisible(false);
}

void MailBox::displayAccountFields()
{
    ui->imapServer->clear();
    ui->imapPort->clear();
    ui->smtpServer->clear();
    ui->smtpPort->clear();
    ui->name->clear();
    ui->mailAccount->clear();
    ui->password->clear();

    ui->imapServer->setVisible(true);
    ui->imapPort->setVisible(true);
    ui->smtpServer->setVisible(true);
    ui->smtpPort->setVisible(true);
    ui->name->setVisible(true);
    ui->mailAccount->setVisible(true);
    ui->password->setVisible(true);
}

/*
 * FIXME: add email variable of account->conf()
 * "from" is now only the wanted username   "FROM" (<email@address.com>)
 * "email" is the e-mail address, ie: email@address.com
 */
void MailBox::addNewAccount()
{
    QRegExp mailRegex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    QRegExp port("[0-9]{2,5}");

    mailRegex.setCaseSensitivity(Qt::CaseInsensitive);
    mailRegex.setPatternSyntax(QRegExp::RegExp);
    port.setPatternSyntax(QRegExp::RegExp);
    QString issues ;

    if (!mailRegex.exactMatch(ui->mailAccount->text()))
    {
        issues.append("- L'adresse mail est invalide.\n") ;
    }
    if (!port.exactMatch(ui->imapPort->text()))
    {
        issues.append("- Le port IMAP est invalide.\n") ;
    }
    if (!port.exactMatch(ui->smtpPort->text()))
    {
        issues.append("- Le port SMTP est invalide.\n") ;
    }
    if (issues.length() != 0)
    {
        HandleIssues *box = new HandleIssues(this, issues, "account");
        box->show();
    }
    else
    {
        Config_manager* new_account = new Config_manager();
        new_account->setup_accout(
                    "",
                    ui->imapServer->text().toStdString(),
                    ui->imapPort->text().toStdString(),
                    ui->smtpServer->text().toStdString(),
                    ui->smtpPort->text().toStdString(),
                    ui->name->text().toStdString(),
                    "", // !!!!!!!! TO FIX !!!!!!!! (email address)
                    ui->mailAccount->text().toStdString(),
                    ui->password->text().toStdString()
                );
        currentAccount = accountListSize;
        movie->start();
        QtConcurrent::run(this, &MailBox::accountConnector);
        toggleAccountFields(false);
        accountOptions();
        ui->submitAccount->setVisible(false);
    }
}

void MailBox::on_actionSupprimer_le_compte_triggered()
{
    delAccount();
}

void MailBox::delAccount()
{
    QString str = "Souhaitez-vous retirer le compte de votre supervision ?" ;
    HandleIssues *box = new HandleIssues(this, str, "delAccount");
    box->show();
}

void MailBox::delAccountTriggered()
{

}

void MailBox::submitAccountRequisite(QString)
{
    if(ui->smtpServer->text() != ""
            && ui->smtpPort->text() != ""
            && ui->imapServer->text() != ""
            && ui->imapPort->text() != ""
            && ui->name->text() != ""
            && ui->mailAccount->text() != ""
            && ui->password->text() != "")
        ui->submitAccount->setVisible(true);
    else ui->submitAccount->setVisible(false);
}
/** ~~ Account monitoring functions ~~ **/


/** ++ Envoi ++ **/
void MailBox::on_sendButton_clicked()
{
    on_actionAlert_triggered() ;
}

void MailBox::on_actionEnvoyer_triggered()
{
    on_actionAlert_triggered();
}

void MailBox::on_actionAlert_triggered()
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
/** ~~ Envoi ~~ **/


/** ++ Gestion des pièces jointes ++ **/
void MailBox::on_actionAttacher_des_pi_ces_jointes_triggered()
{
    openAttachFileWindow();
}

void MailBox::openAttachFileWindow()
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

void MailBox::addFile(QString filepath)
{
    QStringList parts = filepath.split("\\");
    QString file = parts.last();
    ui->deleteFile->setVisible(true);
    ui->actionSupprimer_la_pi_ce_jointe->setVisible(true);
    ui->attachedFileList->setVisible(true);
    ui->actionSupprimer->setVisible(true);
    ui->deleteButton->setVisible(true);
    QListWidgetItem *item = new QListWidgetItem(ui->attachedFileList);
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);
    item->setText(file);
}

void MailBox::on_actionSupprimer_la_pi_ce_jointe_triggered()
{
    deleteFileAction();
}

void MailBox::deleteFileAction()
{
    int x = 0 ;
    while(x < ui->attachedFileList->count())
    {
        QListWidgetItem *file = ui->attachedFileList->item(x) ;
        if (file->checkState() == Qt::Checked)
        {
            delete file ;
            x = 0;
        }
        else x++ ;
    }

    if (ui->attachedFileList->count() == 0)
    {
        ui->attachedFileList->setVisible(false);
        ui->deleteFile->setVisible(false);
    }
}
/** ~~ Gestion des pièces jointes ~~ **/


/** ++ Gestion du carnet d'adresses ++ **/
void MailBox::loadAddressFile()
{
    QString path = QDir::homePath();
    path.append("/.config/muami/address_book.txt");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);
    QString line = in.readLine(); // Retire le titre
    line = in.readLine();
    addressesBook.clear();
    while(!line.isNull())
    {
        addressesBook.append(line.split(" ; ").at(0));
        line = in.readLine();
    }
    file.close();

    QCompleter *completer = new QCompleter(addressesBook, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->to->setCompleter(completer);
    ui->cc->setCompleter(completer);
    ui->bcc->setCompleter(completer);
}

void MailBox::getAddressesListFromBook(QStringList addressesList)
{
    addressesBook = addressesList ;

    QCompleter *completer = new QCompleter(addressesBook, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->to->setCompleter(completer);
    ui->cc->setCompleter(completer);
    ui->bcc->setCompleter(completer);
    WriteMail *child = this->findChild<WriteMail *>();
    if(child)
    {
        child->getAddressesListFromMailBox(addressesBook);
    }
}

void MailBox::getAddressesListFromNewMail(QStringList addressesList)
{
    addressesBook = addressesList ;

    QCompleter *completer = new QCompleter(addressesBook, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->to->setCompleter(completer);
    ui->cc->setCompleter(completer);
    ui->bcc->setCompleter(completer);
}

void MailBox::showAddressBook()
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

void MailBox::addToAddressField(QString address)
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
/** ~~ Gestion du carnet d'adresses ~~ **/


/** ++ Gestion de l'affichage ++ **/
void MailBox::toggleMailFields(bool n)
{
    //Mail fields
    ui->title->setVisible(n);
    ui->to->setVisible(n);
    ui->cc->setVisible(n);
    ui->bcc->setVisible(n);
    ui->addFileButton_2->setVisible(n);
    ui->addressBook_2->setVisible(n);
}

void MailBox::toggleAccountFields(bool n)
{
    //Account fields
    ui->imapServer->setVisible(n);
    ui->imapPort->setVisible(n);
    ui->smtpServer->setVisible(n);
    ui->smtpPort->setVisible(n);
    ui->name->setVisible(n);
    ui->mailAccount->setVisible(n);
    ui->password->setVisible(n);
}

void MailBox::toggleButtons(bool n)
{
    ui->isolateButton->setVisible(n);
    ui->actionIsoler->setVisible(n);
    ui->repButton->setVisible(n);
    ui->actionR_pondre->setVisible(n);
    ui->repAllButton->setVisible(n);
    ui->actionR_pondre_tous->setVisible(n);
    ui->transferButton->setVisible(n);
    ui->actionTransf_rer->setVisible(n);
    ui->actionSupprimer->setVisible(n);
    ui->sendButton->setVisible(n);
    ui->actionEnvoyer->setVisible(n);
    ui->actionAttacher_des_pi_ces_jointes->setVisible(n);
    ui->cancelButton->setVisible(n);
}

void MailBox::toggleAccountButtons(bool n)
{
    ui->submitAccount->setVisible(n);
    ui->cancelAccount->setVisible(n);
    ui->addAccount->setVisible(n);
    ui->delAccount->setVisible(n);
}

void MailBox::openedMailButtons()
{
    ui->isolateButton->setVisible(true);
    ui->actionIsoler->setVisible(true);
    ui->deleteButton->setVisible(true);
    ui->actionSupprimer->setVisible(true);
    ui->sendButton->setVisible(true);
    ui->actionEnvoyer->setVisible(true);
    ui->actionAttacher_des_pi_ces_jointes->setVisible(true);
    ui->cancelButton->setVisible(true);
    ui->addFileButton_2->setVisible(true);
    ui->addressBook_2->setVisible(true);
}

void MailBox::inboxButtonsStyle()
{
    QList<QPushButton*> inboxButtons ;
    inboxButtons << ui->previousAccount
                 << ui->addAccount
                 << ui->delAccount
                 << ui->nextAccount
                 << ui->refreshButton
                 << ui->submitAccount
                 << ui->cancelAccount
                 << ui->accountMenuBtn;
    foreach(QPushButton *button, inboxButtons)
    {
        button->setStyleSheet("border:0px; "
                              "border-right:1px solid qlineargradient"
                                          "(spread:pad, x1:0 y1:0, x2:1 y2:0,"
                                          "stop:0 rgba(38, 124, 153, 255), "
                                          "stop:1 rgba(38, 124, 153, 255));"
                              "border-top:1px solid qlineargradient"
                                          "(spread:pad, x1:0 y1:0, x2:1 y2:0,"
                                          "stop:0 rgba(38, 124, 153, 255), "
                                          "stop:1 rgba(38, 124, 153, 255));"
                              "font-weight:600;");
    }

    ui->nextAccount->setStyleSheet("border-right:0px; border-bottom:0px;");
}

void MailBox::groupBoxButtonStyle()
{
    QList<QPushButton*> groupBoxButtons ;
    groupBoxButtons << ui->newButton
                    << ui->isolateButton
                    << ui->cancelButton
                    << ui->deleteButton
                    << ui->repAllButton
                    << ui->repButton
                    << ui->sendButton
                    << ui->transferButton
                    << ui->deleteFile
                    << ui->addFileButton_2
                    << ui->addressBook_2
                    << ui->refreshButton;

    foreach(QPushButton *button, groupBoxButtons)
    {
        button->setStyleSheet("border:0px; "
                              "border-bottom:1px solid qlineargradient"
                                          "(spread:pad, x1:0 y1:0, x2:1 y2:0,"
                                          "stop:0 rgba(38, 124, 153, 255), "
                                          "stop:1 rgba(38, 124, 153, 255));"
                              "border-left:1px solid qlineargradient"
                                          "(spread:pad, x1:0 y1:0, x2:0 y2:1,"
                                          "stop:0 rgba(38, 124, 153, 255), "
                                          "stop:1 rgba(38, 124, 153, 255));"
                              "border-right:1px solid qlineargradient"
                                          "(spread:pad, x1:0 y1:0, x2:0 y2:1,"
                                          "stop:0 rgba(38, 124, 153, 255), "
                                          "stop:1 rgba(38, 124, 153, 255));"
                              "font-weight:600;");
    }
}

void MailBox::listStyle()
{
    ui->displayer->setStyleSheet("background-color: #FFFFFF;\
                                  border:0px;\
                                  border-left:1px solid qlineargradient"
                                      "(spread:pad, x1:0 y1:0, x2:1 y2:0,"
                                      "stop:0 rgba(139, 153, 153, 255), "
                                      "stop:1 rgba(139, 153, 153, 255));");

    ui->mailList->setStyleSheet("background-color: #FFFFFF;"
                                "color:#252b2b;\
                                 font-weight:600;\
                                 border:0px;");

    QString style = "background-color: #FFFFFF;\
                        border:0px;\
                        border-left:1px solid qlineargradient"
                           "(spread:pad, x1:0 y1:0, x2:1 y2:0,"
                           "stop:0 rgba(139, 153, 153, 255), "
                           "stop:1 rgba(139, 153, 153, 255));"
                       "border-bottom:1px solid qlineargradient"
                           "(spread:pad, x1:0 y1:0, x2:1 y2:0,"
                           "stop:0 rgba(139, 153, 153, 255), "
                           "stop:1 rgba(139, 153, 153, 255));";
    ui->cc->setStyleSheet(style);
    ui->bcc->setStyleSheet(style);
    ui->title->setStyleSheet(style);
    ui->to->setStyleSheet(style);
    ui->imapServer->setStyleSheet("background-color: #FFFFFF;\
                                  border:0px;\
                                  border-top:1px solid qlineargradient"
                                     "(spread:pad, x1:0 y1:0, x2:1 y2:0,"
                                     "stop:0 rgba(38, 124, 153, 255), "
                                     "stop:1 rgba(38, 124, 153, 255));"
                                 "border-bottom:1px solid qlineargradient"
                                     "(spread:pad, x1:0 y1:0, x2:1 y2:0,"
                                     "stop:0 rgba(38, 124, 153, 255), "
                                     "stop:1 rgba(38, 124, 153, 255));");
}
/** ~~ Gestion de l'affichage ~~ **/

void MailBox::connectWidgets()
{
    connect(ui->delAccount,
            SIGNAL(clicked()),
            SLOT(delAccount()));

    connect(ui->previousAccount,
            SIGNAL(clicked()),
            SLOT(previousAccount()));

    connect(ui->nextAccount,
            SIGNAL(clicked()),
            SLOT(nextAccount())),

    connect(ui->mailList,
            SIGNAL(customContextMenuRequested(const QPoint &)),
            SLOT(showMailMenu(const QPoint &)));

    connect(ui->mailList,
            SIGNAL(itemClicked(QListWidgetItem*)),
            SLOT(showMailContent(QListWidgetItem*)));

    connect(ui->addFileButton_2,
            SIGNAL(clicked()),
            SLOT(openAttachFileWindow()));

    connect(ui->deleteFile,
            SIGNAL(clicked()),
            SLOT(deleteFileAction()));

    connect(ui->mailField,
            SIGNAL(textChanged(QString)),
            SLOT(findMail(QString)));

    connect(ui->addressBook_2,
            SIGNAL(clicked()),
            SLOT(showAddressBook()));

    connect(ui->cancelAccount,
            SIGNAL(clicked()),
            SLOT(accountOptions()));

    connect(ui->accountMenuBtn,
            SIGNAL(clicked()),
            SLOT(accountOptions()));

    connect(ui->addAccount,
            SIGNAL(clicked()),
            SLOT(displayAccountFields()));

    connect(ui->imapPort,
            SIGNAL(textChanged(QString)),
            SLOT(submitAccountRequisite(QString)));

    connect(ui->imapServer,
            SIGNAL(textChanged(QString)),
            SLOT(submitAccountRequisite(QString)));

    connect(ui->smtpPort,
            SIGNAL(textChanged(QString)),
            SLOT(submitAccountRequisite(QString)));

    connect(ui->smtpServer,
            SIGNAL(textChanged(QString)),
            SLOT(submitAccountRequisite(QString)));

    connect(ui->name,
            SIGNAL(textChanged(QString)),
            SLOT(submitAccountRequisite(QString)));

    connect(ui->mailAccount,
            SIGNAL(textChanged(QString)),
            SLOT(submitAccountRequisite(QString)));

    connect(ui->password,
            SIGNAL(textChanged(QString)),
            SLOT(submitAccountRequisite(QString)));

    connect(ui->submitAccount,
            SIGNAL(clicked()),
            SLOT(addNewAccount()));
}
