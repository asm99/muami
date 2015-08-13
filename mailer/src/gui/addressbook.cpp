#include <QDesktopWidget>
#include "src/gui/addressbook.h"
#include "src/gui/handleissues.h"
#include "src/gui/writemail.h"
#include "ui_addressbook.h"

AddressBook::AddressBook(QWidget *parent) :
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
    this->setGeometry(800,0,400,600);

    connect(ui->addToListButton,
            SIGNAL(clicked()),
            SLOT(addToBook()));

    connect(ui->addressField,
            SIGNAL(returnPressed()),
            SLOT(addToBook()));

    connect(ui->addressField,
            SIGNAL(textChanged(QString)),
            SLOT(findAddress(QString)));

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
            SLOT(close()));

    connect(ui->closeButton,
            SIGNAL(clicked()),
            this->parentWidget(),
            SLOT(openAddressBook()));

    connect(ui->addressList,
            SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            SLOT(forceAddAddress(QListWidgetItem*)));
}

AddressBook::~AddressBook()
{
    delete ui;
}

void AddressBook::addToBook()
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
        QListWidgetItem *item = new QListWidgetItem(ui->addressList);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
        item->setText(ui->addressField->text());
        ui->addressList->addItem(item);
        ui->addressField->clear();
        ui->addressField->setPlaceholderText("L'adresse a été ajoutée");
    }
}

void AddressBook::findAddress(QString address)
{
    QRegExp finder(".*"+address+".*") ;
    finder.setCaseSensitivity(Qt::CaseInsensitive);
    finder.setPatternSyntax(QRegExp::RegExp);

    for(int x = 0; x < ui->addressList->count(); x++)
    {
        QListWidgetItem *item = ui->addressList->item(x);
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

void AddressBook::clickToAdd()
{
    for(int x = 0; x < ui->addressList->count(); x++)
    {
        QListWidgetItem *item = ui->addressList->item(x);
        if(item->checkState() == Qt::Checked)
        {
            emit addToMail(item->text());
            item->setCheckState(Qt::Unchecked);
        }
    }
}

void AddressBook::forceAddAddress(QListWidgetItem *item)
{
    emit addToMail(item->text());
}

void AddressBook::deleteAddress()
{
    int checked = 0 ;
    for(int x = 0; x < ui->addressList->count(); x++)
    {
        QListWidgetItem *address = ui->addressList->item(x) ;
        if (address->checkState() == Qt::Checked) checked++ ;
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
    int x = 0 ;
    while(x < ui->addressList->count())
    {
        QListWidgetItem *address = ui->addressList->item(x) ;
        if (address->checkState() == Qt::Checked)
        {
            delete address ;
            x = 0;
        }
        else x++ ;
    }
    ui->addressField->clear();
    ui->addressField->setPlaceholderText("");
}
