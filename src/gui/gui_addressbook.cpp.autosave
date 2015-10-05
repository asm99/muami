#include "src/gui/gui_addressbook.h"
#include "src/gui/gui_handleissues.h"
#include "src/gui/gui_writemail.h"
#include "ui_addressbook.h"

AddressBook::AddressBook(QWidget *parent, QString addressBook) :
    QMainWindow(parent),
    ui(new Ui::AddressBook)
{
    ui->setupUi(this);
    this->setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignRight,
                    this->size(),
                    qApp->desktop()->availableGeometry()
                    )
                ) ;
    this->setGeometry(800,0,830,400);
    ui->addressesTree->setColumnWidth(0, 60);
    ui->addressesTree->setColumnWidth(1, 275);
    ui->addressesTree->setColumnWidth(2, 225);
    ui->addressesTree->setColumnWidth(3, 225);
    ui->addressesTree->setHeaderHidden(false);
    //ui->menuBar->hide();

    addressBookPath = addressBook ;
    modified = false ;

    loadAddressFile(addressBookPath);

    connect(ui->addToListButton,
            SIGNAL(clicked()),
            SLOT(addAddressToBook()));

    connect(ui->addressField,
            SIGNAL(returnPressed()),
            SLOT(addAddressToBook()));

    connect(ui->addressField,
            SIGNAL(textChanged(QString)),
            SLOT(findAddress(QString)));

    connect(ui->addressesTree,
            SIGNAL(itemChanged(QTreeWidgetItem*,int)),
            SLOT(modificationAdded(QTreeWidgetItem*, int)));

    connect(ui->addToMailButton,
            SIGNAL(clicked()),
            SLOT(clickToAdd()));

    connect(this,
            SIGNAL(addToMail(QString)),
            this->parentWidget(),
            SLOT(addToAddressField(QString)));

    connect(ui->deleteButton,
            SIGNAL(clicked()),
            SLOT(deleteAddress()));

    connect(ui->closeButton,
            SIGNAL(clicked()),
            SLOT(checkBeforeClose()));

    connect(ui->addressesTree,
            SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)),
            SLOT(forceAddAddress(QTreeWidgetItem*, int)));

    connect(this,
            SIGNAL(sendAddressesList(QStringList)),
            this->parentWidget(),
            SLOT(getAddressesListFromBook(QStringList)));

    connect(ui->saveButton,
            SIGNAL(clicked()),
            SLOT(saveModification()));
}

AddressBook::~AddressBook()
{
    delete ui;
}

void AddressBook::checkBeforeClose()
{
    if(modified)
    {
        QFile file(addressBookPath);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return;
        }

        QTextStream in(&file);
        QString line = in.readLine(); // Retire le titre
        line = in.readLine();
        addresses.clear();
        while(!line.isNull())
        {
            addresses.append(line);
            line = in.readLine();
        }
        file.close();

        QStringList currentTree;
        for(int x = 0; x < ui->addressesTree->topLevelItemCount(); x++)
        {
            QString row ;
            row = ui->addressesTree->topLevelItem(x)->text(1);
            row += " ; ";
            row += ui->addressesTree->topLevelItem(x)->text(2);
            row += " ; ";
            row += ui->addressesTree->topLevelItem(x)->text(3);
            currentTree.append(row);
        }
        bool close = true ;
        for(int x = 0; x < currentTree.count(); x++)
        {
            if(addresses.at(x) != currentTree.at(x))
            {
                close = false ;
                QString str = "Des modifications ont été apportées.\n "
                              "Souhaitez-vous les conserver ?";
                HandleIssues *confirm = new HandleIssues(this, str, "confirmModifAddBook");
                confirm->show();
                break;
            }
        }
        if(close) this->close();
    }
    else this->close();
}

void AddressBook::addAddressToBook()
{
    QRegExp mailRegex("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b") ;
    mailRegex.setCaseSensitivity(Qt::CaseInsensitive);
    mailRegex.setPatternSyntax(QRegExp::RegExp);

    if (!mailRegex.exactMatch(ui->addressField->text()))
    {
        ui->addressField->clear();
        ui->addressField->setPlaceholderText("L'adresse n'est pas valable");
    }
    else
    {
        QFile file(addressBookPath);
        if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            return;
        }

        QTextStream in(&file);
        QString line = in.readLine(); // Retire le titre
        addresses.clear();
        line = in.readLine();
        while(!line.isNull())
        {
            addresses.append(line);
            line = in.readLine();
        }
        QString newAddress = ui->addressField->text();
        in << newAddress << " ;  ;  \n";
        addresses.append(newAddress);
        file.close();

        std::sort(addresses.begin(), addresses.end()) ;
        ui->addressesTree->clear();

        loadAddressFile(addressBookPath);

        ui->addressField->clear();
        ui->addressField->setPlaceholderText("L'adresse a été ajoutée");

        emit sendAddressesList(addresses);
    }
}

void AddressBook::findAddress(QString address)
{
    QRegExp finder(".*"+address+".*") ;
    finder.setCaseSensitivity(Qt::CaseInsensitive);
    finder.setPatternSyntax(QRegExp::RegExp);

    for(int x = 0; x < ui->addressesTree->topLevelItemCount(); x++)
    {
        QTreeWidgetItem *item = ui->addressesTree->topLevelItem(x);
        QString match = item->text(1);
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

void AddressBook::loadAddressFile(QString addressBook)
{
    QFile file(addressBook);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);
    QString line = in.readLine(); // Retire le titre
    line = in.readLine();
    addresses.clear();
    while(!line.isNull())
    {
        addresses.append(line);
        line = in.readLine();
    }
    file.close();
    std::sort(addresses.begin(), addresses.end()) ;

    foreach(QString address, addresses)
    {
        QTreeWidgetItem *itm = new QTreeWidgetItem(ui->addressesTree);
        QStringList addressInfo = address.split(" ; ");
        itm->setText(1, addressInfo.at(0));
        itm->setText(2, addressInfo.at(1));
        itm->setText(3, addressInfo.at(2));
        itm->setFlags(itm->flags() | Qt::ItemIsUserCheckable | Qt::ItemIsEditable);
        itm->setCheckState(0, Qt::Unchecked);
        ui->addressesTree->addTopLevelItem(itm);
    }
}

void AddressBook::clickToAdd()
{
    for(int x = 0; x < ui->addressesTree->topLevelItemCount(); x++)
    {
        QTreeWidgetItem *item = ui->addressesTree->topLevelItem(x);
        if(item->checkState(0) == Qt::Checked)
        {
            emit addToMail(item->text(1));
            item->setCheckState(0, Qt::Unchecked);
        }
    }
}

void AddressBook::forceAddAddress(QTreeWidgetItem *item, int n)
{
    //emit addToMail(item->text(1));
}

void AddressBook::deleteAddress()
{
    int checked = 0 ;
    for(int x = 0; x < ui->addressesTree->topLevelItemCount(); x++)
    {
        QTreeWidgetItem *address = ui->addressesTree->topLevelItem(x) ;
        if (address->checkState(0) == Qt::Checked) checked++ ;
    }
    if (checked > 1)
    {
        QString str = "Voulez-vous supprimer ces adresses ?" ;
        HandleIssues *box = new HandleIssues(this, str, "deleteAddress") ;
        box->show();
    }

    else if (checked == 1)
    {
        QString str = "Voulez-vous supprimer cette adresse ?" ;
        HandleIssues *box = new HandleIssues(this, str, "deleteAddress") ;
        box->show();
    }
}

void AddressBook::confirmDelete()
{    
    QFile file(addressBookPath);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        return;
    }
    addresses.clear();
    QStringList addressesTempList ;
    QTextStream in(&file);
    QString line = in.readLine(); // Retire le titre
    line = in.readLine();
    while(!line.isNull())
    {
        addresses.append(line);
        addressesTempList.append((line.split(" ; ")).at(0));
        line = in.readLine();
    }

    int x = 0 ;
    while(x < ui->addressesTree->topLevelItemCount())
    {
        QTreeWidgetItem *address = ui->addressesTree->topLevelItem(x) ;
        if (address->checkState(0) == Qt::Checked)
        {
            address->setCheckState(0, Qt::Unchecked);
            QString toDelete = address->text(1) ;

            int addressesLength = addresses.length();
            for(int y = 0; y < addressesLength; y++)
            {
                if(toDelete == addressesTempList.at(y))
                {
                    addresses.removeAt(y);
                    break;
                }
            }
            x = 0;
        }
        else x++ ;
    }
    file.resize(0);
    in << "Carnet d'adresses\n" ;
    x = 0 ;
    while(x < addresses.count())
    {
        in << addresses.at(x) << "\n";
        x++;
    }
    file.close();
    ui->addressesTree->clear();
    loadAddressFile(addressBookPath);

    ui->addressField->clear();
    ui->addressField->setPlaceholderText("");

    emit sendAddressesList(addresses);
}

void AddressBook::saveModification()
{
    QFile file(addressBookPath);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        return;
    }
    QTextStream in(&file);
    file.resize(0);
    in << "Carnet d'adresses\n" ;

    for(int x = 0; x < ui->addressesTree->topLevelItemCount(); x++)
    {
        QTreeWidgetItem *address = ui->addressesTree->topLevelItem(x) ;
        in  << address->text(1)
            << " ; "
            << address->text(2)
            << " ; "
            << address->text(3)
            << "\n";
    }
    file.close();
}

void AddressBook::modificationAdded(QTreeWidgetItem* item,int n)
{
    modified = true ;
}
