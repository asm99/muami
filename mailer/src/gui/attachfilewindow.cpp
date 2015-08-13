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
    ui->folderList->setStyleSheet("QListWidget::item{border-bottom:0px}");
    ui->contentList->setStyleSheet("QListWidget::item{border-bottom:0px}");
    ui->fileDetails->setReadOnly(true);

    displayHelper();

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
