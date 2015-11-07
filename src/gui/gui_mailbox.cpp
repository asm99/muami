/** Ajouter un bouton qui ne s'affiche que s'il y a une P.A
 * Mettre en place le refresh forcé
 * */

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

    QString moviePath = ":/icon/res/spinner.gif";
    movie = new QMovie(moviePath);
    ui->spinner->setAttribute(Qt::WA_NoSystemBackground);
    ui->spinner->setMovie(movie);
    movie->start();

    inboxButtonsStyle();
    groupBoxButtonStyle();
    listStyle();
    loadAddressFile();
    connectWidgets();

    try {
            currentAccount = 0;
            offsetPerAcc.push_back(1);
            offsetPerAcc.push_back(0);
            displayedEmailsPerAcc.push_back(10);
            displayedEmailsPerAcc.push_back(0);
            QtConcurrent::run(this, &MailBox::accountConnector);
            /** Repasser cm en globale lorsque la commande NOOP sera implémentée
             * ça permet de maintenir les sockets, ne nécessitant plus la
             * création de cm à la demande
             */
        }
        catch (const exception& e) {
            cerr << e.what() << endl;
        }

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

    if(accountListSize > 0)
    {
        for(int x = 0; x < accountListSize; x++)
        {
            if (displayedEmailsPerAcc[x] == 0)
            {
                displayedEmailsPerAcc[x] = 10;
                displayedEmailsPerAcc.push_back(0);
                offsetPerAcc[x] = 1;
                offsetPerAcc.push_back(0);
            }
        }

        Account* acc = cm->get_account_at_index(currentAccount);

        acc->connect();
        acc->login();
        acc->list_mboxes();
        acc->select_mbox("INBOX");
        acc->fetch_emails_list(displayedEmailsPerAcc[currentAccount], 1);

        ui->mailList->clear();

        cout << "nb of emails: " << acc->cur_mbox()->emails().size() << endl;

        for (int i = acc->cur_mbox()->emails().size()-1; i > -1; i--)
        {
            acc->fetch_email_parts(i);
            displayMailSubject(acc->cur_mbox()->emails()[i]);
        }

        acc->logout();
    }

    if(accountListSize > 1)
    {
        ui->previousAccount->setVisible(true);
        ui->nextAccount->setVisible(true);

        ui->accountMenuBtn->setVisible(true);
        ui->cancelAccount->setVisible(false);
        ui->delAccount->setVisible(false);
        ui->addAccount->setVisible(false);
    }
    else if(accountListSize == 1)
    {
        ui->previousAccount->setVisible(false);
        ui->nextAccount->setVisible(false);

        ui->refreshButton->setEnabled(true);
        ui->deleteButton->setEnabled(true);
        ui->newButton->setEnabled(true);
    }
    else if(accountListSize == 0)
    {
        ui->previousAccount->setVisible(false);
        ui->nextAccount->setVisible(false);
        ui->accountMenuBtn->setVisible(false);
        ui->delAccount->setVisible(false);
        ui->refreshButton->setEnabled(false);
        ui->deleteButton->setEnabled(false);
        ui->newButton->setEnabled(false);
        ui->cancelAccount->setVisible(false);

        ui->mailList->clear();
        ui->addAccount->setVisible(true);
    }

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

void MailBox::showMailContent(QListWidgetItem*)
{
    ui->displayer->setReadOnly(true);
    ui->displayer->clear();
    ui->actionTransf_rer->setVisible(true);
    ui->actionR_pondre->setVisible(true);
    ui->actionIsoler->setVisible(false);
    toggleMailFields(false) ;

    details = fillMailFields("ALL");
    unchangedBody = ui->displayer->toPlainText();
    ui->title->setVisible(true);
    ui->title->setReadOnly(true);
    ui->to->setVisible(true);
    ui->to->setReadOnly(true);
    ui->cc->setReadOnly(true);
    ui->bcc->setReadOnly(true);
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

    toggleButtons(true) ;
    ui->cancelButton->setVisible(false);
    ui->sendButton->setVisible(false);
    ui->actionEnvoyer->setVisible(false);
    ui->actionAttacher_des_pi_ces_jointes->setVisible(false);
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

void MailBox::runRefreshThread()
{
    QtConcurrent::run(this, &MailBox::showMoreEmails);
}

void MailBox::showMoreEmails()
{
    offsetPerAcc[currentAccount] += 10;
    displayedEmailsPerAcc[currentAccount] += 10;

    ui->spinner->show();
    Config_manager *conf = new Config_manager(); // A virer pour utiliser le cm global
    Account* acc = conf->get_account_at_index(currentAccount); // mettre cm
    acc->connect();
    acc->login();
    acc->list_mboxes();
    acc->select_mbox("INBOX");
    acc->fetch_emails_list(10, offsetPerAcc[currentAccount]);

    cout << "nb of emails: " << acc->cur_mbox()->emails().size() << endl;

    for (int i = 9; i > -1; i--)
    {
        acc->fetch_email_parts(i);
        displayMailSubject(acc->cur_mbox()->emails()[i]);
    }
    acc->logout();
    ui->spinner->hide();
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

void MailBox::on_actionR_pondre_triggered()
{
    if(ui->mailList->currentItem())
    {
        ui->displayer->setReadOnly(false);
        QString writter = details;
        QString old = emailFormatting(ui->displayer->toPlainText());
        QTextCursor cursor = ui->displayer->textCursor() ;
        cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor,1);
        ui->displayer->setTextCursor(cursor);
        writter.append(old);
        ui->displayer->clear();
        ui->displayer->setText(writter);
        toggleMailFields(true) ;
        toggleButtons(false) ;
        openedMailButtons() ;
    }
}

void MailBox::on_repAllButton_clicked()
{
    on_actionR_pondre_tous_triggered();
}

void MailBox::on_actionR_pondre_tous_triggered()
{
    if(ui->mailList->currentItem())
    {
        ui->displayer->setReadOnly(false);
        QString writter = details;
        QString old = emailFormatting(ui->displayer->toPlainText());
        writter.append(old);
        ui->displayer->clear();
        ui->displayer->setText(writter);
        QTextCursor cursor = ui->displayer->textCursor() ;
        cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor,1);
        ui->displayer->setTextCursor(cursor);
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
        ui->to->setReadOnly(false);
        ui->to->clear();
        ui->cc->setReadOnly(false);
        ui->cc->clear();
        ui->bcc->setReadOnly(false);
        ui->displayer->setReadOnly(false);
        QString writter = details;
        QString old = emailFormatting(ui->displayer->toPlainText());
        writter.append(old);
        ui->displayer->clear();
        ui->displayer->setText(writter);
        QTextCursor cursor = ui->displayer->textCursor() ;
        cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor,1);
        ui->displayer->setTextCursor(cursor);
        toggleMailFields(true) ;
        toggleButtons(false) ;
        openedMailButtons() ;
    }
}
/** ~~ Reply ~~ **/

/** ++ Fill functions ++ **/
QString MailBox::fillMailFields(QString reply)
{
    Config_manager *conf = new Config_manager(); // A virer
    Account *acc = conf->get_account_at_index(currentAccount); // mettre cm
    acc->connect();
    acc->login();
    acc->list_mboxes();
    acc->select_mbox("INBOX");
    acc->fetch_emails_list(displayedEmailsPerAcc[currentAccount], 1);

    QStringList details;

    int rank = 0;
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
            ui->to->setReadOnly(false);
            ui->cc->setReadOnly(false);
            ui->bcc->setReadOnly(false);

            details.append(QString::fromStdString(em->envelope().from()->name()));
            QStringList dateLine = QString::fromStdString(em->internaldate()).split(" ");
            details.append(dateLine[0]);
            details.append(dateLine[1]);

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

            string body = acc->fetch_email_text(rank);
            ui->displayer->setText(QString::fromStdString(body));
            break;
        }
        else
        {
            rank += 1;
        }
    }
    acc->logout();
    QString writter = "\n\nLe " + details[1] + " à " + details[2] + ", " +
                        details[0] + " a écrit :\n";
    return writter;
}

QString MailBox::emailFormatting(QString old)
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
    if (ui->displayer->isReadOnly())
    {
        new_mail = new WriteMail(this, false, details, unchangedBody) ;
    }
    else if (!ui->displayer->isReadOnly())
    {
        new_mail = new WriteMail(this, true, "", unchangedBody) ;
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

    ui->addAccount->setVisible(false);
    ui->delAccount->setVisible(false);
}

void MailBox::on_actionAdd()
{
    displayAccountFields();
}

/*
 * FIXME: add email variable of account->conf()
 * "from" is now only the wanted username   "FROM" (<email@address.com>)
 * "email" is the e-mail address, ie: email@address.com
 */
void MailBox::addNewAccount()
{
    QRegExp mailRegex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");

    mailRegex.setCaseSensitivity(Qt::CaseInsensitive);
    mailRegex.setPatternSyntax(QRegExp::RegExp);
    QString issues ;

    if (!mailRegex.exactMatch(ui->mailAccount->text()))
    {
        issues.append("- L'adresse mail est invalide.\n") ;
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
                    ui->name->text().toStdString(),
                    ui->password->text().toStdString()
                );
        currentAccount = accountListSize;
        movie->start();
        QtConcurrent::run(this, &MailBox::accountConnector);
        toggleAccountFields(false);
        accountOptions();

        ui->accountMenuBtn->setVisible(true);
        ui->addAccount->setVisible(false);
        ui->cancelAccount->setVisible(false);
        ui->delAccount->setVisible(false);
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
    /* Ne gère que la suppression du fichier account à cause du one-shot.
     * A terme, le compte doit être supprimer de cm global.
     */
    QString str = QDir::homePath(); //User path
    str.append("/.config/muami/accounts/"); //Path to accounts folder
    QDir *path = new QDir(str);
    QFileInfoList filesList = path->entryInfoList();
    QString accountToDelete = filesList[currentAccount+2].fileName();
    str.append(accountToDelete);
    QFile::remove(str);
    offsetPerAcc.erase(offsetPerAcc.begin()+currentAccount);
    displayedEmailsPerAcc.erase(displayedEmailsPerAcc.begin()+currentAccount);
    accountListSize -= 1 ;
    currentAccount = 0 ;
    QtConcurrent::run(this, &MailBox::accountConnector);
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


/** ++ Send ++ **/
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

    for(unsigned int mails_list = 0; mails_list < lists.size(); mails_list++)
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

void MailBox::sendConfirmed()
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

    for(unsigned int email = 0; email < emails.size(); email++)
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
    showMailContent(ui->mailList->item(0));
}

/** ~~ Send ~~ **/


/** ++ Attached files functions ++ **/
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
/** ~~ Attached files functions ~~ **/


/** ++ Address Book functions ++ **/
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
/** ~~ Address Book functions ~~ **/


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

    connect(ui->imapServer,
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

    connect(ui->refreshButton,
            SIGNAL(clicked()),
            SLOT(runRefreshThread()));
}
