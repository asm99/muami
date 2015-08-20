#include <QDir>
#include <QDesktopWidget>
#include <QWidget>
#include <QMouseEvent>
#include "ui_mailbox.h"
#include "src/gui/mailbox.h"
#include "src/gui/writemail.h"
#include "src/gui/addaccount.h"
#include "src/gui/handleissues.h"
#include "src/gui/attachfilewindow.h"
#include "src/gui/addressbook.h"
#include "my_qlabel.h"

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

    ui->infoLabel->setAttribute(Qt::WA_Hover);
    ui->infoLabel->setMouseTracking(true);

    toggleFields(false) ;
    toggleButtons(false) ;
    toggleNakedApp(false);

    accountRegistered();

    inboxButtonsStyle();
    groupBoxButtonStyle();
    listStyle();

    ui->inbox->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->inbox,
            SIGNAL(customContextMenuRequested(const QPoint &)),
            SLOT(showFolderMenu(const QPoint &)));

    connect(ui->inbox,
            SIGNAL(itemClicked(QListWidgetItem*)),
            SLOT(showFolderContent(QListWidgetItem*)));

    connect(ui->delAccount,
            SIGNAL(clicked()),
            SLOT(delAccount()));

    connect(ui->previousAccount,
            SIGNAL(clicked()),
            SLOT(previousAccount()));

    connect(ui->nextAccount,
            SIGNAL(clicked()),
            SLOT(nextAccount())),

    ui->mailList->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->mailList,
            SIGNAL(customContextMenuRequested(const QPoint &)),
            SLOT(showMailMenu(const QPoint &)));

    connect(ui->mailList,
            SIGNAL(itemClicked(QListWidgetItem*)),
            SLOT(showMailContent(QListWidgetItem*)));

    connect(ui->mailList,
           SIGNAL(itemChanged(QListWidgetItem*)),
           SLOT(changeBackgroundColor(QListWidgetItem*)));

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
            SLOT(openAddressBook()));

    connect(ui->infoLabel,
            SIGNAL(mouseHover()),
            SLOT(showInfo()));

    connect(ui->infoLabel,
            SIGNAL(mouseNotHover()),
            SLOT(hideInfo()));

    connect(ui->infoLabel,
            SIGNAL(mouseClick()),
            SLOT(inboxBarInfo1()));
}



MailBox::~MailBox()
{
    delete ui;
}

void MailBox::on_inboxButton_clicked()
{
    if (ui->inbox->isVisible())
    {
        toggleAccountPanel(false);
        ui->groupInbox->setVisible(false);
    }
    else
    {
        ui->groupInbox->setVisible(true);
        toggleAccountPanel(true);
    }
}

/** ++ Gestion des dossiers + leur contenu ++ **/
void MailBox::addChildren(QTreeWidgetItem *item, QString filePath)
{
    QDir* rootDir = new QDir(filePath);
    QFileInfoList filesList = rootDir->entryInfoList();

    foreach(QFileInfo fileInfo, filesList)
    {
        if(fileInfo.isDir())
        {
            QTreeWidgetItem* child = new QTreeWidgetItem(item);
            child->setText(0,fileInfo.fileName());
            child->setWhatsThis(0, fileInfo.filePath());
        }
    }
}

void MailBox::showFolderMenu(const QPoint &pos)
{/*
    QPoint globalPos = ui->inbox->mapToGlobal(pos);
    QMenu myMenu;
    myMenu.addAction("Créer un dossier");
    myMenu.addAction("Supprimer le dossier");
    myMenu.addSeparator();
    myMenu.addAction("Ajouter un compte",
                     this,
                     SLOT(on_actionAdd_triggered()));
    myMenu.addAction("Supprimer le compte",
                     this,
                     SLOT(delAccount()));

    QAction *selectedItem = myMenu.exec(globalPos);*/
}

void MailBox::showFolderContent(QListWidgetItem* item)
{
    ui->mailList->clear();
    ui->actionTransf_rer->setVisible(false);
    ui->actionR_pondre->setVisible(false);
    ui->actionIsoler->setVisible(false);
    ui->actionSupprimer->setVisible(false);
    ui->mailField->setVisible(true);

    QString str = item->whatsThis() ;
    QDir *path = new QDir(str) ;
    QFileInfoList filesList = path->entryInfoList();
    filesList.removeFirst();    // Vire le .
    filesList.removeFirst();    // et .. des listes
    foreach(QFileInfo fileInfo, filesList)
    {
        if (!fileInfo.isDir())
        {
            QString date = fileInfo.fileName() ;
            date.append("\nSubject\n") ;
            date.append(fileInfo.created().toString()) ;
            QListWidgetItem *item = new QListWidgetItem(ui->mailList);
            item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
            item->setCheckState(Qt::Unchecked);
            item->setWhatsThis(fileInfo.filePath());
            item->setText(date);
            ui->mailList->addItem(item);
        }
    }
}

void MailBox::changeBackgroundColor(QListWidgetItem* item)
{
    if(item->checkState() == Qt::Checked)
    {

    }
}

void MailBox::showMailMenu(const QPoint &pos)
{/*
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
        QAction *selectedItem = myMenu.exec(globalPos);*/
}

void MailBox::showMailContent(QListWidgetItem* mail)
{
    ui->actionTransf_rer->setVisible(true);
    ui->actionR_pondre->setVisible(true);
    ui->actionIsoler->setVisible(false);
    toggleAccountPanel(false);

    QString letter = mail->whatsThis() ;
    QFile email(letter) ;
    if (!email.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream in(&email);
    QString doc = in.readAll() ;
    ui->displayer->setText(doc);
    ui->displayer->setReadOnly(true);
    ui->deleteButton->setVisible(true);
    ui->actionSupprimer->setVisible(true);
    toggleFields(false) ;
    toggleButtons(true) ;
    ui->sendButton->setVisible(false);
    ui->actionEnvoyer->setVisible(false);
    ui->actionAttacher_des_pi_ces_jointes->setVisible(false);
    ui->cancelButton->setVisible(false);
    ui->groupInbox->setVisible(false);
}
/** ~~ Gestion des dossiers + leur contenu ~~ **/


/** ++ Créer un courrier ++ **/
void MailBox::on_newButton_clicked()
{
    on_actionNouveau_courrier_triggered();
}

void MailBox::on_actionNouveau_courrier_triggered()
{
    WriteMail *new_mail = new WriteMail(this) ;
    new_mail->show();
    toggleFields(false) ;
}
/** ~~ Créer un courrier ~~ **/


/** ++ Supprimer le courrier ++ **/
void MailBox::on_deleteButton_clicked()
{
    on_actionSupprimer_triggered();
}

void MailBox::on_actionSupprimer_triggered()
{
    int checked = 0 ;
    for(int x = 0; x < ui->mailList->count(); x++)
    {
        QListWidgetItem *mail = ui->mailList->item(x) ;
        if (mail->checkState() == Qt::Checked) checked++ ;
    }
    if (checked > 1)
    {
        QString str = "Voulez-vous supprimer ces courriers ?" ;
        HandleIssues *box = new HandleIssues(this, str, "deleteFromBox") ;
        box->show();
    }

    else if (checked == 1)
    {
        QString str = "Voulez-vous supprimer ce courrier ?" ;
        HandleIssues *box = new HandleIssues(this, str, "deleteFromBox") ;
        box->show();
    }
}

void MailBox::deleteItem()       // ENVOI A LA CORBEILLE, VOIR AVEC MM SI
{                                // LA FONCTION A ETE IMPLEMENTE
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
    ui->mailField->clear();
}
/** ~~ Supprimer le courrier ~~ **/


/** ++ Annulation ++ **/
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
    //ui->attachedLabel->setVisible(false);
    ui->deleteFile->setVisible(false);
    ui->actionSupprimer_la_pi_ce_jointe->setVisible(false);
    ui->actionAttacher_des_pi_ces_jointes->setVisible(false);
}
/** ~~ Annulation ~~ **/


/** ++ Répondre ++ **/
void MailBox::on_repButton_clicked()
{
    on_actionR_pondre_triggered();
}

void MailBox::on_actionR_pondre_triggered()  // REMPLIR LES CHAMPS TO, CC, ETC
{
    if(ui->mailList->currentItem())
    {
        ui->displayer->setReadOnly(false);
        QTextCursor cursor = ui->displayer->textCursor() ;
        cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor,1);
        ui->displayer->setTextCursor(cursor);
        QString old = ui->displayer->toPlainText() ;
        QString newline = "\n\n_______________________________________________\n\n\n";
        newline.append(old);
        ui->displayer->setText(newline);

        toggleFields(true) ;
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
    ui->displayer->setReadOnly(false);
        QTextCursor cursor = ui->displayer->textCursor() ;
        cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor,1);
        ui->displayer->setTextCursor(cursor);
        QString old = ui->displayer->toPlainText() ;
        QString newline = "\n\n_______________________________________________\n\n\n";
        newline.append(old);
        ui->displayer->setText(newline);

        toggleFields(true) ;
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
        ui->displayer->setReadOnly(false);
        QTextCursor cursor = ui->displayer->textCursor() ;
        cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor,1);
        ui->displayer->setTextCursor(cursor);
        QString old = ui->displayer->toPlainText() ;
        QString newline = "\n\n_______________________________________________\n\n\n";
        newline.append(old);
        ui->displayer->setText(newline);

        toggleFields(true) ;
        toggleButtons(false) ;
        openedMailButtons() ;
    }
}
/** ~~ Répondre ~~ **/


/** ++ Isoler ++ **/
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
    if (!ui->displayer->isReadOnly())
    {
        QString to = ui->to->text() ;
        QString cc = ui->cc->text() ;
        QString bcc = ui->bcc->text() ;
        QString title = ui->title->text() ;
        QString content = ui->displayer->toPlainText() ;
        QStringList list ;
        list << to << cc << bcc << title << content ;

        WriteMail *new_mail = new WriteMail(this, true) ;
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
    }

    else if (ui->displayer->isReadOnly())
    {
        QString to = ui->to->text() ;
        QString cc = ui->cc->text() ;
        QString bcc = ui->bcc->text() ;
        QString title = ui->title->text() ;
        QString content = ui->displayer->toPlainText() ;
        QStringList list ;
        list << to << cc << bcc << title << content ;

        WriteMail *new_mail = new WriteMail(this, false) ;
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
    }

    int resizer = ui->mailList->width()
                + ui->displayer->width()
                + ui->attachedFileList->width() ;

    showMailContent(ui->mailList->currentItem()) ;
    ui->attachedFileList->clear();
    ui->attachedFileList->setVisible(false);
    //ui->attachedLabel->setVisible(false);
    ui->deleteFile->setVisible(false);
    ui->actionSupprimer_la_pi_ce_jointe->setVisible(false);
    ui->mailList->setVisible(true);
    ui->mailField->setVisible(true);
    ui->mailList->resize(resizer/2, ui->mailList->height());
    ui->displayer->resize(resizer/2, ui->displayer->height());
}
/** ~~ Isoler ~~ **/

/*
void MailBox::mousePressEvent(QMouseEvent *e)
{
    clickPos = e->pos();
}

void MailBox::mouseMoveEvent(QMouseEvent *e)
{
    move(e->globalPos() - clickPos);
}
*/


/** ++ Recherche & info ++ **/
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

void MailBox::showInfo()
{
    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();
    foreach(QPushButton *button, buttons)
    {
        button->setIcon(QIcon());
    }
    ui->previousAccount->setIcon(QIcon(":/icon/res/arrow-left.png"));
    ui->nextAccount->setIcon(QIcon(":/icon/res/arrow-right.png"));
    ui->addAccount->setIcon(QIcon(":/icon/res/user-4-add.png"));
    ui->delAccount->setIcon(QIcon(":/icon/res/user-4-remove.png"));
    ui->inboxButton->setText("Boite de\nréception");
    ui->sendButton->setText("Envoyer");
    ui->repButton->setText("Répondre");
    ui->repAllButton->setText("Répondre à\ntous");
    ui->transferButton->setText("Transférer");
    ui->newButton->setText("Nouveau\ncourrier");
    ui->isolateButton->setText("Isoler le\ncourrier");
    ui->deleteButton->setText("Supprimer le\ncourrier");
    ui->cancelButton->setText("Annuler les\nmodifications");
}

void MailBox::inboxBarInfo1()
{
    ui->previousAccount->setIcon(QIcon(":/icon/res/arrow-left.png"));
    ui->previousAccount->setText("Accéder au\ncompte précédent");
    ui->previousAccount->setVisible(true);
    ui->addAccount->setVisible(false);
    ui->delAccount->setVisible(false);
    ui->nextAccount->setVisible(false);
    QTimer::singleShot(1000, this, SLOT(inboxBarInfo2()));
}

void MailBox::inboxBarInfo2()
{
    ui->delAccount->setIcon(QIcon(":/icon/res/user-4-remove.png"));
    ui->delAccount->setText("Supprimer\nle compte");
    ui->previousAccount->setVisible(false);
    ui->addAccount->setVisible(false);
    ui->delAccount->setVisible(true);
    ui->nextAccount->setVisible(false);
    QTimer::singleShot(1000, this, SLOT(inboxBarInfo3()));
}

void MailBox::inboxBarInfo3()
{
    ui->nextAccount->setIcon(QIcon(":/icon/res/arrow-right.png"));
    ui->nextAccount->setText("Accéder au\ncompte suivant");
    ui->previousAccount->setVisible(false);
    ui->addAccount->setVisible(false);
    ui->delAccount->setVisible(false);
    ui->nextAccount->setVisible(true);
    QTimer::singleShot(1000, this, SLOT(inboxBarInfo4()));
}

void MailBox::inboxBarInfo4()
{
    ui->addAccount->setIcon(QIcon(":/icon/res/user-4-add.png"));
    ui->addAccount->setText("Ajouter\nun compte");
    ui->previousAccount->setVisible(false);
    ui->addAccount->setVisible(true);
    ui->delAccount->setVisible(false);
    ui->nextAccount->setVisible(false);
    QTimer::singleShot(1000, this, SLOT(hideInfo()));
}

void MailBox::hideInfo()
{
    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();
    foreach(QPushButton *button, buttons)
    {
        button->setText("");
    }
    ui->previousAccount->setVisible(true);
    ui->addAccount->setVisible(true);
    ui->delAccount->setVisible(true);
    ui->nextAccount->setVisible(true);
    ui->inboxButton->setIcon(QIcon(":/icon/res/inbox-2.png"));
    ui->sendButton->setIcon(QIcon(":/icon/res/send.png"));
    ui->repButton->setIcon(QIcon(":/icon/res/reply.png"));
    ui->repAllButton->setIcon(QIcon(":/icon/res/reply-all.png"));
    ui->transferButton->setIcon(QIcon(":/icon/res/transfer.png"));
    ui->newButton->setIcon(QIcon(":/icon/res/compose-4.png"));
    ui->isolateButton->setIcon(QIcon(":/icon/res/windows.png"));
    ui->deleteButton->setIcon(QIcon(":/icon/res/bin-3.png"));
    ui->previousAccount->setIcon(QIcon(":/icon/res/arrow-left.png"));
    ui->nextAccount->setIcon(QIcon(":/icon/res/arrow-right.png"));
    ui->addAccount->setIcon(QIcon(":/icon/res/user-4-add.png"));
    ui->delAccount->setIcon(QIcon(":/icon/res/user-4-remove.png"));
    ui->addFileButton_2->setIcon(QIcon(":/icon/res/document-add.png"));
    ui->addressBook_2->setIcon(QIcon(":/icon/res/address-book-2.png"));
    ui->deleteFile->setIcon(QIcon(":/icon/res/document-remove.png"));
    ui->cancelButton->setIcon(QIcon(":/icon/res/delete.png"));
}
/** ~~ Recherche ~~ **/


/** ++ Quitter l'appli ++ **/
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
/** ~~ Quitter l'appli ~~ **/


/** ++ Présence de comptes ++ **/
void MailBox::accountRegistered()
{
    ui->actionNouveau_courrier->setVisible(false);
    ui->actionSupprimer_le_compte->setVisible(false);
    toggleNakedApp(true) ;
}

void MailBox::previousAccount()
{
    QString currentAccount = ui->inbox->whatsThis();
    for(int x = 0; x < accountList.count(); x++)
    {
        QString tabName = accountList.at(x).at(0);
        if(tabName == currentAccount)
        {
            if(x-1 < 0)
            {
                QString tabName = accountList.last().at(0);
                QString accountName = accountList.last().at(1);
                showAccount(tabName, accountName);
            }
            else
            {
                QString tabName = accountList.at(x-1).at(0);
                QString accountName = accountList.at(x-1).at(1);
                showAccount(tabName, accountName);
            }
            break;
        }
    }
}

void MailBox::nextAccount()
{
    QString currentAccount = ui->inbox->whatsThis();
    for(int x = 0; x < accountList.count(); x++)
    {
        QString tabName = accountList.at(x).at(0);
        if(tabName == currentAccount)
        {
            if(x+1 == accountList.count())
            {
                QString tabName = accountList.first().at(0);
                QString accountName = accountList.first().at(1);
                showAccount(tabName, accountName);
            }
            else
            {
                QString tabName = accountList.at(x+1).at(0);
                QString accountName = accountList.at(x+1).at(1);
                showAccount(tabName, accountName);
            }
            break;
        }
    }
}

void MailBox::showAccount(QString tabName, QString accountName)
{
    ui->inbox->clear();
    ui->inbox->setWhatsThis(tabName);
    QDir *path = new QDir(accountName);

    QFileInfoList filesList = path->entryInfoList();

    foreach(QFileInfo fileInfo, filesList)
    {
        if (fileInfo.isDir())
        {
            QListWidgetItem *item = new QListWidgetItem(ui->inbox);
            item->setText(fileInfo.fileName());
            item->setWhatsThis(fileInfo.filePath());
            item->setSizeHint(QSize(item->sizeHint().width(), 30));
        }
    }
}
/** ~~ Présence de comptes ~~ **/


/** ++ Ajout de comptes ++ **/
void MailBox::on_addAccount_clicked()
{
    on_actionAdd_triggered() ;
}

void MailBox::on_actionAdd_triggered()
{
    AddAccount *box = new AddAccount(this) ;
    box->show();
}

void MailBox::addNewAccount(QString tabName, QString accountName) // MODIFIER LE POPUP POUR AJOUTER LES CHAMPS NECESSAIRES
{                                                                 // A LA PRISE EN CHARGE D'UN NOUVEAU COMPTE
    toggleNakedApp(false);

    QStringList account ;
    account.append(tabName);
    account.append(accountName);

    accountList.append(account);

    ui->inbox->clear();
    ui->inbox->setWhatsThis(tabName);
    QDir *path = new QDir(accountName);

    QFileInfoList filesList = path->entryInfoList();

    foreach(QFileInfo fileInfo, filesList)
    {
        if (fileInfo.isDir())
        {
            QListWidgetItem *item = new QListWidgetItem(ui->inbox);
            item->setText(fileInfo.fileName());
            item->setWhatsThis(fileInfo.filePath());
            item->setSizeHint(QSize(item->sizeHint().width(), 30));
        }
    }
}
/** ~~ Ajout de comptes ~~ **/


/** ++ Suppression de comptes ++ **/
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
    QString currentAccount = ui->inbox->whatsThis();
    for(int x = 0; x < accountList.count(); x++)
    {
        QString tabName = accountList.at(x).at(0);
        if(tabName == currentAccount)
        {
            accountList.removeAt(x);
            break;
        }
    }

    toggleFields(false);
    toggleButtons(false);
    ui->mailList->clear();
    ui->displayer->clear() ;

    if(accountList.count() != 0)
    {
        QString tabName = accountList.first().at(0);
        QString accountName = accountList.first().at(1);
        showAccount(tabName, accountName);
    }
    else accountRegistered();
}
/** ~~ Suppression de comptes ~~ **/


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


/** ++ Gestion des pièces jointes et carnet d'adresses ++ **/
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

    ui->deleteFile->setText("Supprimer\npièce\njointe");

    if (ui->attachedFileList->count() == 0)
    {
        ui->attachedFileList->setVisible(false);
        ui->deleteFile->setVisible(false);
        //ui->attachedLabel->setVisible(false);
    }
}

void MailBox::openAddressBook()
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

/** ~~ Gestion des pièces jointes et carnet d'adresses ~~ **/


/** ++ Gestion de l'affichage ++ **/
void MailBox::toggleFields(bool n)
{
    ui->title->setVisible(n);
    ui->to->setVisible(n);
    ui->cc->setVisible(n);
    ui->bcc->setVisible(n);
    ui->addFileButton_2->setVisible(n);
    ui->addressBook_2->setVisible(n);
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
    ui->deleteButton->setVisible(n);
    ui->actionSupprimer->setVisible(n);
    ui->sendButton->setVisible(n);
    ui->actionEnvoyer->setVisible(n);
    ui->actionAttacher_des_pi_ces_jointes->setVisible(n);
    ui->cancelButton->setVisible(n);
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

void MailBox::toggleNakedApp(bool n)
{
    if (n)
    {
        ui->emptyLabel->setVisible(n);
        ui->emptyLabel->setStyleSheet("background-color:#6b767a;\
                                        color:#FFFFFF;\
                                        border-width:1px solid gray;");
        ui->emptyLabel->setWordWrap(true);
        ui->emptyLabel->resize(this->width()/3, this->height());

        ui->emptyLabel_2->setVisible(n);
        ui->emptyLabel_2->setStyleSheet("background-color:#6b767a;\
                                        color:#FFFFFF;\
                                        border:1px solid gray;");
        ui->emptyLabel_2->resize(this->width()/3, this->height());
        ui->emptyLabel_2->setWordWrap(true);

        ui->emptyLabel_3->setVisible(n);
        ui->emptyLabel_3->setStyleSheet("background-color:#6b767a;\
                                        color:#FFFFFF;\
                                        border:1px solid gray;");
        ui->emptyLabel_3->resize(ui->emptyLabel_2->width(), this->height());
        ui->emptyLabel_3->setWordWrap(true);


        ui->displayer->setVisible(!n);
        ui->mailList->setVisible(!n);
        ui->mailField->setVisible(!n);
        ui->attachedFileList->setVisible(!n);
        ui->infoLabel->setVisible(!n);
        toggleAccountPanel(false);
        ui->addAccount->setVisible(true);
        ui->groupInbox->setVisible(true);
        ui->groupBox->setVisible(false);
        ui->groupInbox->setMaximumWidth(999999);

        QString account = "Aucun compte de messagerie n'est actuellement associé\
 à l'application.\n\nPour associer un compte de messagerie à l'application et\
 vous permettre de traiter votre courrier électronique, cliquez sur \
\"+\"";
        ui->emptyLabel_3->setText(account);

        QString contentDisplayer = "Ce volet affiche le contenu du dossier \
sélectionné dans le volet \"Boite\" sous forme d'une liste.\n\nPour afficher du\
 courrier, associez un compte de messagerie à l'application";
        ui->emptyLabel->setText(contentDisplayer);

        QString bodyDisplayer = "Cette partie affiche le contenu du courrier \
sélectionné dans la liste des courriers du volet à gauche";
        ui->emptyLabel_2->setText(bodyDisplayer);
    }
    else
    {
        ui->emptyLabel->setVisible(n);
        ui->emptyLabel_2->setVisible(n);
        ui->emptyLabel_3->setVisible(n);
        ui->infoLabel->setVisible(!n);
        ui->groupBox->setVisible(!n);
        ui->mailList->setVisible(!n);
        ui->displayer->setVisible(!n);
        toggleAccountPanel(true);
        ui->groupInbox->setMaximumWidth(200);
    }
}

void MailBox::toggleAccountPanel(bool n)
{
    ui->inbox->setVisible(n);
    ui->previousAccount->setVisible(n);
    ui->nextAccount->setVisible(n);
    ui->addAccount->setVisible(n);
    ui->delAccount->setVisible(n);
}

void MailBox::inboxButtonsStyle()
{
    QList<QPushButton*> inboxButtons ;
    inboxButtons << ui->previousAccount
                 << ui->addAccount
                 << ui->delAccount
                 << ui->nextAccount;
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
    groupBoxButtons << ui->inboxButton
                    << ui->newButton
                    << ui->isolateButton
                    << ui->cancelButton
                    << ui->deleteButton
                    << ui->repAllButton
                    << ui->repButton
                    << ui->sendButton
                    << ui->transferButton
                    << ui->deleteFile
                    << ui->addFileButton_2
                    << ui->addressBook_2;

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
    ui->inbox->setStyleSheet("background-color:#252b2b;"
                             "color:#9fabaa;"
                             "border:0px;");

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
}
/** ~~ Gestion de l'affichage ~~ **/
