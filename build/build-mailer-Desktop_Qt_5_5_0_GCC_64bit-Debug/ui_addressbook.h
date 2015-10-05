/********************************************************************************
** Form generated from reading UI file 'addressbook.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRESSBOOK_H
#define UI_ADDRESSBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddressBook
{
public:
    QAction *actionAjouter_une_adresse;
    QAction *actionSupprimer_l_adresse;
    QAction *actionQuitter;
    QAction *actionFermet_le_carnet;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *addressesTree;
    QLineEdit *addressField;
    QVBoxLayout *verticalLayout;
    QPushButton *closeButton;
    QPushButton *saveButton;
    QPushButton *addToListButton;
    QPushButton *deleteButton;
    QPushButton *addToMailButton;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *AddressBook)
    {
        if (AddressBook->objectName().isEmpty())
            AddressBook->setObjectName(QStringLiteral("AddressBook"));
        AddressBook->resize(500, 728);
        actionAjouter_une_adresse = new QAction(AddressBook);
        actionAjouter_une_adresse->setObjectName(QStringLiteral("actionAjouter_une_adresse"));
        actionSupprimer_l_adresse = new QAction(AddressBook);
        actionSupprimer_l_adresse->setObjectName(QStringLiteral("actionSupprimer_l_adresse"));
        actionQuitter = new QAction(AddressBook);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionFermet_le_carnet = new QAction(AddressBook);
        actionFermet_le_carnet->setObjectName(QStringLiteral("actionFermet_le_carnet"));
        centralwidget = new QWidget(AddressBook);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        addressesTree = new QTreeWidget(centralwidget);
        addressesTree->headerItem()->setText(0, QString());
        addressesTree->setObjectName(QStringLiteral("addressesTree"));
        addressesTree->header()->setVisible(false);

        verticalLayout_2->addWidget(addressesTree);

        addressField = new QLineEdit(centralwidget);
        addressField->setObjectName(QStringLiteral("addressField"));

        verticalLayout_2->addWidget(addressField);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/res/browser-close-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon);
        closeButton->setIconSize(QSize(35, 35));

        verticalLayout->addWidget(closeButton);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        sizePolicy.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy);
        saveButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/res/stiffy.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon1);
        saveButton->setIconSize(QSize(35, 35));

        verticalLayout->addWidget(saveButton);

        addToListButton = new QPushButton(centralwidget);
        addToListButton->setObjectName(QStringLiteral("addToListButton"));
        sizePolicy.setHeightForWidth(addToListButton->sizePolicy().hasHeightForWidth());
        addToListButton->setSizePolicy(sizePolicy);
        addToListButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/res/user-4-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addToListButton->setIcon(icon2);
        addToListButton->setIconSize(QSize(35, 35));

        verticalLayout->addWidget(addToListButton);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
        deleteButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/res/user-4-remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon3);
        deleteButton->setIconSize(QSize(35, 35));

        verticalLayout->addWidget(deleteButton);

        addToMailButton = new QPushButton(centralwidget);
        addToMailButton->setObjectName(QStringLiteral("addToMailButton"));
        sizePolicy.setHeightForWidth(addToMailButton->sizePolicy().hasHeightForWidth());
        addToMailButton->setSizePolicy(sizePolicy);
        addToMailButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/res/mail-incoming.png"), QSize(), QIcon::Normal, QIcon::Off);
        addToMailButton->setIcon(icon4);
        addToMailButton->setIconSize(QSize(35, 35));

        verticalLayout->addWidget(addToMailButton);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        AddressBook->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(AddressBook);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 500, 25));
        AddressBook->setMenuBar(menuBar);

        retranslateUi(AddressBook);

        QMetaObject::connectSlotsByName(AddressBook);
    } // setupUi

    void retranslateUi(QMainWindow *AddressBook)
    {
        AddressBook->setWindowTitle(QApplication::translate("AddressBook", "MainWindow", 0));
        actionAjouter_une_adresse->setText(QApplication::translate("AddressBook", "Ajouter une adresse", 0));
        actionSupprimer_l_adresse->setText(QApplication::translate("AddressBook", "Supprimer l'adresse", 0));
        actionQuitter->setText(QApplication::translate("AddressBook", "Quitter", 0));
        actionFermet_le_carnet->setText(QApplication::translate("AddressBook", "Fermer", 0));
        QTreeWidgetItem *___qtreewidgetitem = addressesTree->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("AddressBook", "Pr\303\251nom", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("AddressBook", "Nom", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("AddressBook", "Addresse", 0));
        addressField->setPlaceholderText(QApplication::translate("AddressBook", "Recherche", 0));
        closeButton->setText(QString());
        saveButton->setText(QString());
        addToListButton->setText(QString());
        deleteButton->setText(QString());
        addToMailButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddressBook: public Ui_AddressBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRESSBOOK_H
