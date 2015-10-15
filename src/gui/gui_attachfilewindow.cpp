#include "ui_gui_attachfilewindow.h"
#include "src/gui/gui_attachfilewindow.h"
#include "src/gui/gui_writemail.h"
#include "src/gui/gui_handleissues.h"

AttachFileWindow::AttachFileWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AttachFileWindow)
{
    ui->setupUi(this);

    ui->fileDetails->setReadOnly(true);
    ui->fileDetails->setVisible(true);

    displayHelper();
    objStyle();
    connectWidgets();

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
    delete ui->folderList->item(0);
    ui->pathAccessor->setText(way);
}

AttachFileWindow::~AttachFileWindow()
{
    delete ui;
}

/** ++ Volet des dossiers ++ **/
void AttachFileWindow::on_folderList_itemDoubleClicked(QListWidgetItem *item)
{
    QString str = item->whatsThis();
    QStringList test = str.split("/");
    test.removeFirst();
    if(test[test.size()-1] == "..")
    {
        QString newPath = "";
        for(int n = 0; n < test.size()-2; n++)
        {
            newPath.append("/");
            newPath.append(test[n]);
        }
        ui->pathAccessor->setText(newPath);
        str = newPath ;
    }
    else
    {
        ui->pathAccessor->setText(str);
    }

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
    delete ui->folderList->item(0);
}


void AttachFileWindow::on_folderList_itemClicked(QListWidgetItem *item)
{
    QString str = item->whatsThis();
    QStringList test = str.split("/");
    test.removeFirst();
    if(test[test.size()-1] == "..")
    {
        QString newPath = "";
        for(int n = 0; n < test.size()-2; n++)
        {
            newPath.append("/");
            newPath.append(test[n]);
        }
        ui->pathAccessor->setText(newPath);
        str = newPath ;
    }
    else
    {
        ui->pathAccessor->setText(str);
    }

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
affiche son contenu dans le volet central. Double-cliquez \
pour rentrer dans un dossier, Double-cliquez sur '..' pour \
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

void AttachFileWindow::objStyle()
{
    QString style = "background-color: #FFFFFF;\
                        border:0px;";
    ui->findFile->setStyleSheet(style);
    ui->pathAccessor->setStyleSheet(style);

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

void AttachFileWindow::connectWidgets()
{
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
}
