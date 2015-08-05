#include <QDir>
#include <QDesktopWidget>
#include <QPixmap>
#include "src/gui/mailbox.h"
#include "ui_mailbox.h"
#include "src/gui/writemail.h"
#include "src/gui/addaccount.h"
#include "src/gui/handleissues.h"
#include "src/gui/attachfilewindow.h"

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

    ui->multiBox->setVisible(false);
    ui->multiBox->resize(this->width()/4, this->height());
    ui->inbox->setColumnCount(1);
    ui->mailList->resize(this->width()/4, this->height());
    ui->splitter->resize(this->width()/10, this->height());

    ui->toolBar->setVisible(false);
    ui->deleteFile->setVisible(false);
    ui->attachedLabel->setVisible(false);
    ui->attachedFileList->setVisible(false);

    toggleNakedApp(false);

    ui->displayer->setReadOnly(true);
    ui->displayer->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

    toggleFields(false) ;
    toggleButtons(false) ;

    QDir *path = new QDir("/home");             // Compte principal

    QFileInfoList filesList = path->entryInfoList();
    ui->multiBox->setTabText(0, "Inbox");

    foreach(QFileInfo fileInfo, filesList)
    {
        if (fileInfo.isDir())
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(ui->inbox) ;
            item->setText(0,fileInfo.fileName());
            item->setWhatsThis(0, fileInfo.filePath());
            addChildren(item,fileInfo.filePath());
        }
    }
    ui->inbox->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->inbox,
            SIGNAL(customContextMenuRequested(const QPoint &)),
            SLOT(showFolderMenu(const QPoint &)));

    connect(ui->inbox,
            SIGNAL(itemClicked(QTreeWidgetItem*,int)),
            SLOT(showFolderContent(QTreeWidgetItem*, int)));

    connect(ui->delAccount,
            SIGNAL(clicked()),
            SLOT(delAccount()));

    ui->mailList->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->mailList,
            SIGNAL(customContextMenuRequested(const QPoint &)),
            SLOT(showMailMenu(const QPoint &)));

    connect(ui->mailList,
            SIGNAL(itemClicked(QListWidgetItem*)),
            SLOT(showMailContent(QListWidgetItem*)));


    connect(ui->attachButton,
            SIGNAL(clicked()),
            SLOT(openAttachFileWindow()));

    connect(ui->deleteFile,
            SIGNAL(clicked()),
            SLOT(deleteFileAction()));
}



MailBox::~MailBox()
{
    delete ui;
}

void MailBox::on_inboxButton_clicked()
{
    if (ui->multiBox->isVisible())
        ui->multiBox->setVisible(false);
    else ui->multiBox->setVisible(true);
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
{
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

    QAction *selectedItem = myMenu.exec(globalPos);
}

void MailBox::showFolderContent(QTreeWidgetItem* item, int n)
{
    ui->mailList->clear();
    ui->actionTransf_rer->setVisible(false);
    ui->actionR_pondre->setVisible(false);
    ui->actionIsoler->setVisible(false);
    ui->actionSupprimer->setVisible(false);

    QString str = item->whatsThis(0) ;
    QDir *path = new QDir(str) ;
    QFileInfoList filesList = path->entryInfoList();
    filesList.removeFirst();    // Vire le .
    filesList.removeFirst();    // et .. des listes
    int bit = 0 ;
    foreach(QFileInfo fileInfo, filesList)
    {
//        item->setText(0,fileInfo.fileName());
        QString date = fileInfo.fileName() ;
        date.append("\nSubject\n") ;
        date.append(fileInfo.created().toString()) ;
//        QString date = fileInfo.created().toString();
        QListWidgetItem *item = new QListWidgetItem(ui->mailList) ;
        item->setWhatsThis(fileInfo.filePath());
        item->setText(date);
        ui->mailList->addItem(item);
        if (bit == 0)
        {
            item->setBackgroundColor("#C7D1D6");
            bit = 1 ;
        }
        else if (bit == 1)
        {
            item->setBackgroundColor("#DCE0E3");
            bit = 0 ;
        }
    }

    ui->multiBox->setVisible(false);
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

void MailBox::showMailContent(QListWidgetItem* mail)
{
    ui->actionTransf_rer->setVisible(true);
    ui->actionR_pondre->setVisible(true);
    ui->actionIsoler->setVisible(false);
    ui->actionSupprimer->setVisible(true);
    ui->multiBox->setVisible(false);

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
    toggleFields(false) ;
    toggleButtons(true) ;
    ui->sendButton->setVisible(false);
    ui->attachButton->setVisible(false);
    ui->cancelButton->setVisible(false);
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
    if (ui->mailList->currentItem())
    {
        QString str = "Voulez-vous supprimer ce courrier ?" ;
        HandleIssues *box = new HandleIssues(this, str, "deleteFromBox") ;
        box->show();
    }
}

void MailBox::deleteItem()       // ENVOI A LA CORBEILLE, VOIR AVEC MM SI
{                                // LA FONCTION A ETE IMPLEMENTE
    delete ui->mailList->currentItem();
    showMailContent(ui->mailList->currentItem());
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
    ui->attachedFileList->setVisible(false);
    ui->attachedLabel->setVisible(false);
    ui->deleteFile->setVisible(false);
    ui->attachButton->setVisible(false);
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

void MailBox::on_repAllButton_clicked()     // REMPLIR LES CHAMPS TO, CC, ETC
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
void MailBox::on_mailList_itemDoubleClicked(QListWidgetItem *item)
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
    ui->attachedLabel->setVisible(false);
    ui->deleteFile->setVisible(false);
    ui->mailList->setVisible(true);
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
    if(ui->multiBox->tabText(0) == "")
    {
        ui->multiBox->removeTab(0);
    }

    toggleNakedApp(false);
    QTabWidget *tab = new QTabWidget() ;
    ui->multiBox->addTab(tab, tabName);

    QTreeWidget *tree = new QTreeWidget(tab) ;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tree);
    tab->setLayout(layout);
    tree->setColumnCount(1);
    QHBoxLayout *hLayout = new QHBoxLayout;
    QPushButton *addButton = new QPushButton(this);
    addButton->setText("Ajouter");
    layout->addWidget(addButton);
    QPushButton *delButton = new QPushButton(this);
    delButton->setText("Supprimer");
    hLayout->addWidget(addButton);
    hLayout->addWidget(delButton);
    layout->addLayout(hLayout);

    QDir *path = new QDir(accountName);

    QFileInfoList filesList = path->entryInfoList();

    foreach(QFileInfo fileInfo, filesList)
    {
        if (fileInfo.isDir())
        {
            QTreeWidgetItem *item = new QTreeWidgetItem(tree) ;
            item->setText(0,fileInfo.fileName());
            item->setWhatsThis(0, fileInfo.filePath());
            addChildren(item,fileInfo.filePath());
        }
    }

    tree->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(tree,
            SIGNAL(customContextMenuRequested(const QPoint &)),
            SLOT(showFolderMenu(const QPoint &)));

    connect(tree,
            SIGNAL(itemClicked(QTreeWidgetItem*,int)),
            SLOT(showFolderContent(QTreeWidgetItem*, int)));

    connect(ui->mailList,
            SIGNAL(itemClicked(QListWidgetItem*)),
            SLOT(showMailContent(QListWidgetItem*)));

    connect(addButton,
            SIGNAL(clicked()),
            SLOT(on_addAccount_clicked()));

    connect(delButton,
            SIGNAL(clicked()),
            SLOT(delAccount()));
}
/** ~~ Ajout de comptes ~~ **/


/** ++ Suppression de comptes ++ **/
void MailBox::delAccount()
{
    QString str = "Souhaitez-vous retirer le compte "\
                    +ui->multiBox->tabText(ui->multiBox->currentIndex())\
                    +" de votre supervision ?" ;
    HandleIssues *box = new HandleIssues(this, str, "delAccount");
    box->show();
}

void MailBox::delAccountTriggered()
{
    ui->multiBox->removeTab(ui->multiBox->currentIndex());
    toggleFields(false);
    toggleButtons(false);
    ui->mailList->clear();
    ui->displayer->clear() ;

    if(ui->multiBox->count() == 0)
    {
        QTabWidget *tab = new QTabWidget() ;
        ui->multiBox->addTab(tab, "");

        QVBoxLayout *layout = new QVBoxLayout;

        QString string = "Aucun compte de messagerie n'est actuellement associé\
 à l'application.\n\nPour associer un compte de messagerie à l'application et\
 vous permettre de traiter votre courrier électronique, cliquez sur \
\"Ajouter\"";
        QLabel *str = new QLabel(tab);
        str->setStyleSheet("color:#333536; background-color:#FFFFFF");
        str->setText(string) ;
        str->setWordWrap(true);
        str->resize(tab->width(), (tab->height())/2);

        QLabel *img = new QLabel(tab) ;
        img->resize(tab->width(), (tab->height())/2);

        QPixmap pixmap(":res/arrow_down.png");
        img->setPixmap(pixmap.scaled(img->width(), img->height(), Qt::KeepAspectRatio));
        img->setScaledContents(true);

        QPushButton *addButton = new QPushButton(this) ;
        addButton->setText("Ajouter");

        layout->addWidget(str);
        layout->addWidget(img);
        layout->addWidget(addButton);
        tab->setLayout(layout);

        toggleNakedApp(true) ;

        connect(addButton,
                SIGNAL(clicked()),
                SLOT(on_addAccount_clicked()));
    }
}
/** ~~ Suppression de comptes ~~ **/


/** ++ Envoi ++ **/
void MailBox::on_sendButton_clicked()
{
    on_actionAlert_triggered() ;
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
void MailBox::openAttachFileWindow()
{
    AttachFileWindow *box = new AttachFileWindow(this);
    box->show();
}

void MailBox::addFile(QString filepath)
{
    QStringList parts = filepath.split("\\");
    QString file = parts.last();
    ui->deleteFile->setVisible(true);
    ui->attachedLabel->setVisible(true);
    ui->attachedFileList->setVisible(true);
    ui->deleteButton->setVisible(true);
    ui->mailList->setVisible(false);
    QListWidgetItem *item = new QListWidgetItem(ui->attachedFileList);
    item->setText(file);
}

void MailBox::deleteFileAction()
{
    if (ui->attachedFileList->currentItem())
    {
        delete ui->attachedFileList->currentItem();
    }
}
/** ~~ Gestion des pièces jointes ~~ **/


/** ++ Gestion de l'affichage ++ **/
void MailBox::toggleFields(bool n)
{
    if (n == true) ui->verticalLayout_3->setSpacing(6);
    else ui->verticalLayout_3->setSpacing(0);
    ui->title->setVisible(n);
    ui->titleLabel->setVisible(n);
    ui->to->setVisible(n);
    ui->toLabel->setVisible(n);
    ui->cc->setVisible(n);
    ui->ccLabel->setVisible(n);
    ui->bcc->setVisible(n);
    ui->bccLabel->setVisible(n);
}

void MailBox::toggleButtons(bool n)
{
    ui->isolateButton->setVisible(n);
    ui->repButton->setVisible(n);
    ui->repAllButton->setVisible(n);
    ui->transferButton->setVisible(n);
    ui->deleteButton->setVisible(n);
    ui->sendButton->setVisible(n);
    ui->attachButton->setVisible(n);
    ui->cancelButton->setVisible(n);
}

void MailBox::openedMailButtons()
{
    ui->isolateButton->setVisible(true);
    ui->deleteButton->setVisible(true);
    ui->sendButton->setVisible(true);
    ui->attachButton->setVisible(true);
    ui->cancelButton->setVisible(true);
}

void MailBox::toggleNakedApp(bool n)
{
    if (n)
    {
        QList<int> sizes ;
        sizes << (ui->mailList->width())*2
              << (ui->mailList->height())*2 ;

        ui->emptyLabel->setVisible(n);
        ui->emptyLabel->setStyleSheet("background-color:#DCE0E3;\
                                        color:#333536;\
                                        border:1px solid gray;\
                                        border-radius:3px");
        ui->emptyLabel->setWordWrap(true);
        ui->emptyLabel->resize(sizes[0]/2, sizes[1]/2);

        ui->emptyLabel_2->setVisible(n);
        ui->emptyLabel_2->setStyleSheet("background-color:#DCE0E3;\
                                        color:#333536;\
                                        border:1px solid gray;\
                                        border-radius:3px");
        ui->emptyLabel_2->resize(sizes[0]/2, sizes[1]/2);
        ui->emptyLabel_2->setWordWrap(true);

        ui->displayer->setVisible(!n);
        ui->mailList->setVisible(!n);
        ui->attachedFileList->setVisible(!n);
        ui->attachedLabel->setVisible(!n);

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
        QList<int> sizes ;
        sizes << (ui->mailList->width())*2
              << (ui->mailList->height())*2 ;

        ui->emptyLabel->setVisible(n);
        ui->emptyLabel_2->setVisible(n);
        ui->mailList->resize(sizes[0]/2, sizes[1]/2);
        ui->displayer->resize(sizes[0]/2, sizes[1]/2);
        ui->mailList->setVisible(!n);
        ui->displayer->setVisible(!n);
    }
}
/** ~~ Gestion de l'affichage ~~ **/
