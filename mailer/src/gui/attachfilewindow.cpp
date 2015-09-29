#include <QDir>
#include "ui_attachfilewindow.h"
#include "src/gui/attachfilewindow.h"
#include "src/gui/writemail.h"
#include "src/gui/handleissues.h"

AttachFileWindow::AttachFileWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AttachFileWindow)
{
    ui->setupUi(this);

    ui->fileDetails->setReadOnly(true);
    ui->fileDetails->setVisible(true);

    ui->infoLabel->setVisible(false); //INFO LABEL

    displayHelper();

    objStyle();

    QString way = "/home";
    QDir *path = new QDir("/home");             // Compte principal

    QFileInfoList filesList = path->entryInfoList();

    foreach(QFileInfo fileInfo, filesList)
    {
        if (fileInfo.isDir())
        {
            QListWidgetItem *item = new QListWidgetItem(ui->folderList) ;
            item->setText(fileInfo.fileName());
            item->setWhatsThis(fileInfo.filePath());
        }
    }

    ui->pathAccessor->setText(way);

    connect(ui->pathAccessor,
            SIGNAL(returnPressed()),
            SLOT(accessToFolder())) ;

    connect(ui->findFile,
            SIGNAL(textChanged(QString)),
            SLOT(findFile(QString)));

    connect(ui->contentList,
            SIGNAL(itemClicked(QListWidgetItem*)),
            SLOT(showDetails(QListWidgetItem*)));

    connect(ui->addButton,
            SIGNAL(clicked()),
            SLOT(addFile())) ;

    connect(this,
            SIGNAL(sendFileToMail(QString)),
            this->parentWidget(),
            SLOT(addFile(QString)));

    connect(ui->leaveButton,
            SIGNAL(clicked()),
            SLOT(close()));

    connect(ui->leaveButton,
            SIGNAL(clicked()),
            this->parentWidget(),
            SLOT(openAttachFileWindow()));

    connect(ui->backButton,
            SIGNAL(clicked()),
            SLOT(onBackButtonClicked()));

    connect(ui->goButton,
            SIGNAL(clicked()),
            SLOT(onGoButtonClicked()));

    connect(ui->infoLabel,
            SIGNAL(mouseHover()),
            SLOT(showInfo()));

    connect(ui->infoLabel,
            SIGNAL(mouseNotHover()),
            SLOT(hideInfo()));

    connect(ui->infoLabel,
            SIGNAL(mouseClick()),
            SLOT(infoButton()));
}

AttachFileWindow::~AttachFileWindow()
{
    delete ui;
}

/** ++ Volet des dossiers ++ **/
void AttachFileWindow::on_folderList_itemDoubleClicked(QListWidgetItem *item)
{
    QString str = item->whatsThis() ;
    QDir *path = new QDir(str) ;
    QFileInfoList filesList = path->entryInfoList();

    ui->folderList->clear();
    ui->fileDetails->clear();
    displayHelper();

    foreach(QFileInfo fileInfo, filesList)
    {
        if (fileInfo.isDir())
        {
            QListWidgetItem *item = new QListWidgetItem(ui->folderList) ;
            item->setText(fileInfo.fileName());
            item->setWhatsThis(fileInfo.filePath());
        }
    }
    ui->pathAccessor->setText(str);
}

void AttachFileWindow::on_folderList_itemClicked(QListWidgetItem *item)
{
    QString str = item->whatsThis() ;
    QDir *path = new QDir(str) ;
    QFileInfoList filesList = path->entryInfoList();

    ui->contentList->clear();
    ui->fileDetails->clear();

    displayHelper();

    foreach(QFileInfo fileInfo, filesList)
    {
        if (!fileInfo.isDir())
        {
            QString file = fileInfo.fileName() ;
            QListWidgetItem *item = new QListWidgetItem(ui->contentList) ;
            item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
            item->setCheckState(Qt::Unchecked);
            item->setText(file);

            QString details = "Chemin du fichier :\n";
            details.append(fileInfo.filePath());
            details.append("\n\nDate de création :\n");
            details.append(fileInfo.created().toString());
            details.append("\n\nDate de dernière modification :\n");
            details.append(fileInfo.lastModified().toString());
            details.append("\n\nType de fichier :\n");
            details.append(fileInfo.suffix());

            item->setWhatsThis(details);
        }
    }
}

void AttachFileWindow::onBackButtonClicked()
{
    QString path = ui->pathAccessor->text();
    QStringList split_path = path.split("/");
    split_path.removeLast();
    path = split_path.join("/");

    QDir *new_path = new QDir(path) ;
    QFileInfoList filesList = new_path->entryInfoList();

    ui->folderList->clear();
    ui->contentList->clear();
    ui->fileDetails->clear();

    foreach(QFileInfo fileInfo, filesList)
    {
        if (fileInfo.isDir())
        {
            QListWidgetItem *item = new QListWidgetItem(ui->folderList) ;
            item->setText(fileInfo.fileName());
            item->setWhatsThis(fileInfo.filePath());
        }

        if (!fileInfo.isDir())
        {
            QString file = fileInfo.fileName() ;
            QListWidgetItem *item = new QListWidgetItem(ui->contentList) ;
            item->setText(fileInfo.fileName());

            QString details = "Chemin du fichier :\n";
            details.append(fileInfo.filePath());
            details.append("\n\nDate de création :\n");
            details.append(fileInfo.created().toString());
            details.append("\n\nDate de dernière modification :\n");
            details.append(fileInfo.lastModified().toString());
            details.append("\n\nType de fichier :\n");
            details.append(fileInfo.suffix());

            item->setWhatsThis(details);
        }
    }
    ui->pathAccessor->setText(path);
}

void AttachFileWindow::onGoButtonClicked()
{
    if(ui->folderList->currentItem())
    {
        on_folderList_itemDoubleClicked(ui->folderList->currentItem());
    }

    displayHelper();
}

void AttachFileWindow::accessToFolder()
{
    QString path = ui->pathAccessor->text() ;
    emit displayPathContent(path) ;
}
/** ~~ Volet des dossiers ~~ **/


/** ++ Volet des fichiers + description ++ **/
void AttachFileWindow::displayPathContent(QString str)
{
    QDir *path = new QDir(str) ;
    QFileInfoList filesList = path->entryInfoList();

    ui->folderList->clear();
    ui->contentList->clear();

    foreach(QFileInfo fileInfo, filesList)
    {
        if (fileInfo.isDir())
        {
            QListWidgetItem *item = new QListWidgetItem(ui->folderList) ;
            item->setText(fileInfo.fileName());
            item->setWhatsThis(fileInfo.filePath());
        }

        else
        {
            QString file = fileInfo.fileName() ;
            QListWidgetItem *item = new QListWidgetItem(ui->contentList) ;
            item->setText(fileInfo.fileName());

            QString details = "Chemin du fichier :\n";
            details.append(fileInfo.filePath());
            details.append("\n\nDate de création :\n");
            details.append(fileInfo.created().toString());
            details.append("\n\nDate de dernière modification :\n");
            details.append(fileInfo.lastModified().toString());
            details.append("\n\nType de fichier :\n");
            details.append(fileInfo.suffix());

            item->setWhatsThis(details);
        }
    }
}

void AttachFileWindow::displayHelper()
{
    if(!ui->contentList->currentItem())
    {
        QString help = "Vous pouvez spécifier le chemin d'accès aux fichiers \
que vous souhaitez joindre au courrier en tapant le chemin dans la barre de \
recherche en haut à gauche.\n\nLe volet de gauche affiche les dossiers du \
répertoire dans lequel vous vous trouvez. Cliquer une fois sur un dossier \
affiche son contenu dans le volet central. Double-cliquez ou cliquez sur \
\"Parcourir\" pour rentrer dans un dossier, cliquez sur \"Revenir\" pour \
revenir dans le dossier parent.\n\nLe volet central affiche les fichiers \
contenus dans le dossier en cours. Pour ajouter un fichier au courrier, \
doublez-cliquez dessus ou sélectionner le fichier puis cliquez sur \"Ajouter\"\
. Vous pouvez ajouter plusieurs fichiers d'un coup en cochant la case \
correspondante à chaque fichier puis en cliquant sur \"Ajouter\".\n\nCe volet \
affiche les détails du fichier sélectionné.";
        ui->fileDetails->setText(help);
    }
}

void AttachFileWindow::showDetails(QListWidgetItem *item)
{
    ui->fileDetails->clear();
    ui->fileDetails->setText(item->whatsThis());
    if (item->checkState() == Qt::Unchecked) item->setCheckState(Qt::Checked);
    else item->setCheckState(Qt::Unchecked);
}

void AttachFileWindow::findFile(QString toFind)
{
    QRegExp finder(".*"+toFind+".*") ;
    finder.setCaseSensitivity(Qt::CaseInsensitive);
    finder.setPatternSyntax(QRegExp::RegExp);

    for(int x = 0; x < ui->contentList->count(); x++)
    {
        QListWidgetItem *item = ui->contentList->item(x);
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

void AttachFileWindow::infoButton()
{
    if(ui->fileDetails->isVisible())
        ui->fileDetails->setVisible(false);
    else ui->fileDetails->setVisible(true);
}

void AttachFileWindow::showInfo()
{
    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();
    foreach(QPushButton *button, buttons)
    {
        button->setIcon(QIcon());
    }

    ui->addButton->setText("Ajouter\nun fichier");
    ui->backButton->setText("Remonter\nl'arborescence");
    ui->goButton->setText("Descendre\nl'arborescence");
    ui->leaveButton->setText("Fermer");
}

void AttachFileWindow::hideInfo()
{
    QList<QPushButton*> buttons = this->findChildren<QPushButton*>();
    foreach(QPushButton *button, buttons)
    {
        button->setText("");
    }
    ui->addButton->setIcon(QIcon(":/icon/res/document-add.png"));
    ui->backButton->setIcon(QIcon(":/icon/res/out.png"));
    ui->goButton->setIcon(QIcon(":/icon/res/in.png"));
    ui->leaveButton->setIcon(QIcon(":/icon/res/browser-close-2.png"));
}

/** ~~ Volet des fichiers + description ~~ **/


/** ++ Ajout de pièces jointes ++ **/
void AttachFileWindow::addFile()
{
    for(int x = 0; x < ui->contentList->count(); x++)
    {
        QListWidgetItem *file = ui->contentList->item(x);
        if(file->checkState() == Qt::Checked)
        {
            QString item = file->whatsThis();
            QStringList pieces = item.split("\n");
            QString filepath = pieces[1] ;
            emit sendFileToMail(filepath) ;
            file->setCheckState(Qt::Unchecked);
        }
    }
}

void AttachFileWindow::on_contentList_itemDoubleClicked(QListWidgetItem *itm)
{
    QString item = itm->whatsThis();
    QStringList pieces = item.split("\n");
    QString filepath = pieces[1] ;
    emit sendFileToMail(filepath) ;
}
/** ~~ Ajout de pièces jointes ~~ **/

void AttachFileWindow::objStyle()
{
    QString style = "background-color: #FFFFFF;\
                        border:0px;";
    ui->findFile->setStyleSheet(style);
    ui->pathAccessor->setStyleSheet(style);
    ui->infoLabel->setStyleSheet("border:0px");

    ui->fileDetails->setStyleSheet("background-color:#252b2b;"
                                   "color:#9fabaa;"
                                   "border:0px;\
                                    border-left:1px solid qlineargradient"
                                      "(spread:pad, x1:0 y1:0, x2:0 y2:1,"
                                      "stop:0 rgba(139, 153, 153, 255), "
                                      "stop:1 rgba(139, 153, 153, 255));");

    ui->contentList->setStyleSheet("background-color: #FFFFFF;"
                                   "color:#252b2b;\
                                    font-weight:600;\
                                    border:0px;");

    ui->folderList->setStyleSheet("background-color:#252b2b;"
                                  "color:#9fabaa;"
                                  "border:0px;");
}
