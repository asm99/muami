#include <QDesktopWidget>
#include "src/gui/addressbook.h"
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

    connect(ui->actionFermet_le_carnet,
            SIGNAL(triggered(bool)),
            this->parentWidget(),
            SLOT(setVisibleBookButton(bool)));

    connect(ui->actionFermet_le_carnet,
            SIGNAL(triggered(bool)),
            SLOT(close())) ;
}

AddressBook::~AddressBook()
{
    delete ui;
}

