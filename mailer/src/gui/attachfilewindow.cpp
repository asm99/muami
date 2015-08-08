#include "src/gui/attachfilewindow.h"
#include "ui_attachfilewindow.h"
#include "src/gui/writemail.h"
#include "src/gui/handleissues.h"
#include <QDir>

AttachFileWindow::AttachFileWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AttachFileWindow)
{
    ui->setupUi(this);
    ui->fileDetails->setReadOnly(true);

    QRect *rect = new QRect(0, 0, 50, 50) ;
    QRegion *region = new QRegion(*rect, QRegion::Ellipse);
    ui->help->setMask(*region);

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

    connect(ui->help,
            SIGNAL(clicked()),
            SLOT(openHelper()));

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

    foreach(QFileInfo fileInfo, filesList)
    {
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

void AttachFileWindow::showDetails(QListWidgetItem *item)
{
    ui->fileDetails->clear();
    ui->fileDetails->setText(item->whatsThis());
}
/** ~~ Volet des fichiers + description ~~ **/


/** ++ Ajout de pièces jointes ++ **/
void AttachFileWindow::addFile()
{
    if (ui->contentList->currentItem())
    {
        QString item = ui->contentList->currentItem()->whatsThis();
        QStringList pieces = item.split("\n");
        QString filepath = pieces[1] ;
        emit sendFileToMail(filepath) ;
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

/** Helper **/
void AttachFileWindow::openHelper()
{
    QString help = "Astuces :\nDouble-cliquez sur les dossiers pour les \
parcourir.\nDouble-cliquez sur un fichier pour l'ajouter en tant que \
pièce jointe.";
    HandleIssues *helper = new HandleIssues(this, help, "helper");
    helper->show();
}

/** Helper **/
