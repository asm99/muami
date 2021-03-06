#include "ui_gui_attachfilewindow.h"
#include "src/gui/gui_attachfilewindow.h"
#include "src/gui/gui_writemail.h"
#include "src/gui/gui_handleissues.h"

AttachFileWindow::AttachFileWindow(QWidget *parent,
                                   QString windowType,
                                   QStringList mailDetails) :
    QMainWindow(parent),
    ui(new Ui::AttachFileWindow)
{
    ui->setupUi(this);

    type = windowType;
    mail = mailDetails; /* Structure : subject, body, sender name
                         * mailbox, host, cc, internal date, uid */

    ui->fileDetails->setReadOnly(true);
    ui->fileDetails->setVisible(true);

    if(type =="Attach") displayHelper();

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
    HandleIssues *child = this->findChild<HandleIssues *>();
    if(child) child->close();

    delete ui;
}

void AttachFileWindow::closeMe()
{
    HandleIssues *child = this->findChild<HandleIssues *>();
    if(child) delete child;

    close();
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

    if(type == "Attach") displayHelper();

    foreach(QFileInfo fileInfo, filesList)
    {
        if (!fileInfo.isDir())
        {
            QString file = fileInfo.fileName() ;
            QListWidgetItem *item = new QListWidgetItem(ui->contentList) ;
            if(type == "Attach")
            {
                item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
                item->setCheckState(Qt::Unchecked);
            }
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
    if(type == "Attach")
    {
        if (item->checkState() == Qt::Unchecked) item->setCheckState(Qt::Checked);
        else item->setCheckState(Qt::Unchecked);
    }
}

void AttachFileWindow::displayName(QListWidgetItem *)
{
    ui->findFile->setText(ui->contentList->currentItem()->text());
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

void AttachFileWindow::saveConfirmed()
{
    QString fileName = ui->pathAccessor->text();
    fileName.append("/");
    fileName.append(ui->findFile->text());

    QStringList extension = fileName.split(".");
    if(extension.at(extension.size()-1) != "mail")
        fileName.append(".mail");

    QStringList files;
    for(int x = 0; x < ui->contentList->count(); x++)
    {
        files.append(ui->contentList->item(x)->text());
    }

    if(!files.contains(ui->findFile->text()))
    {
        QFile file(fileName);
        if(file.open(QIODevice::ReadWrite))
        {
            QTextStream out(&file);

            QStringList dateLine = mail[6].split(" ");
            QString date = dateLine.at(0) + " - " + dateLine.at(1);

            out << "From : " << mail[2] << "<" << mail[3] << "@" << mail[4] << ">\n"
                << "Date : " << date << "\n\n"
                << "Subject : " << mail[0] << "\n\n"
                << mail[1];

            file.close();
        }
        displayPathContent(ui->pathAccessor->text());
    }
    else if(files.contains(ui->findFile->text()))
    {
        QString str = "Impossible de sauvegarder car un fichier "
                      "portant le même nom existe déjà.";
        HandleIssues *box = new HandleIssues(this, str, "denySave");
        box->show();
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

void AttachFileWindow::onFileDoubleClicked(QListWidgetItem *itm)
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
    ui->findFile->setStyleSheet("background-color: #FFFFFF;"
                                "border:0px;"
                                "border-top:1px solid qlineargradient"
                                  "(spread:pad, x1:0 y1:0, x2:0 y2:1,"
                                      "stop:0 rgba(139, 153, 153, 255), "
                                      "stop:1 rgba(139, 153, 153, 255));"
                                "border-right:1px solid qlineargradient"
                                  "(spread:pad, x1:0 y1:0, x2:0 y2:1,"
                                      "stop:0 rgba(139, 153, 153, 255), "
                                      "stop:1 rgba(139, 153, 153, 255));");

    ui->pathAccessor->setStyleSheet("background-color: #FFFFFF;"
                                    "border:0px;"
                                    "border-left:1px solid qlineargradient"
                                      "(spread:pad, x1:0 y1:0, x2:0 y2:1,"
                                          "stop:0 rgba(139, 153, 153, 255),"
                                          "stop:1 rgba(139, 153, 153, 255));");

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

    if(type == "Save")
    {
        ui->addButton->setVisible(false);
        ui->saveButton->setVisible(true);
    }

    else if(type == "Attach")
    {
        ui->addButton->setVisible(true);
        ui->saveButton->setVisible(false);
    }
}

void AttachFileWindow::connectWidgets()
{
    connect(ui->pathAccessor,
            SIGNAL(returnPressed()),
            SLOT(accessToFolder())) ;

    connect(ui->contentList,
            SIGNAL(itemClicked(QListWidgetItem*)),
            SLOT(showDetails(QListWidgetItem*)));

    connect(ui->leaveButton,
            SIGNAL(clicked()),
            SLOT(closeMe()));

    connect(ui->leaveButton,
            SIGNAL(clicked()),
            this->parentWidget(),
            SLOT(openAttachFileWindow()));

    if(type == "Attach")
    {
        connect(this,
                SIGNAL(sendFileToMail(QString)),
                this->parentWidget(),
                SLOT(addFile(QString)));

        connect(ui->addButton,
                SIGNAL(clicked()),
                SLOT(addFile())) ;

        connect(ui->contentList,
                SIGNAL(itemDoubleClicked(QListWidgetItem*)),
                SLOT(onFileDoubleClicked(QListWidgetItem*)));

        connect(ui->findFile,
                SIGNAL(textChanged(QString)),
                SLOT(findFile(QString)));
    }

    if(type == "Save")
    {
        connect(ui->findFile,
                SIGNAL(returnPressed()),
                SLOT(saveConfirmed()));

        connect(ui->contentList,
                SIGNAL(itemClicked(QListWidgetItem*)),
                SLOT(displayName(QListWidgetItem*)));
    }
}
