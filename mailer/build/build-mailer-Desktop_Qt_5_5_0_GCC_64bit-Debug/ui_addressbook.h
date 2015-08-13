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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
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
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *addToMailButton;
    QPushButton *deleteButton;
    QPushButton *closeButton;
    QListWidget *addressList;
    QVBoxLayout *verticalLayout;
    QLineEdit *addressField;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addToListButton;

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
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addToMailButton = new QPushButton(centralwidget);
        addToMailButton->setObjectName(QStringLiteral("addToMailButton"));

        horizontalLayout->addWidget(addToMailButton);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout->addWidget(deleteButton);

        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout_2->addLayout(horizontalLayout);

        addressList = new QListWidget(centralwidget);
        addressList->setObjectName(QStringLiteral("addressList"));

        verticalLayout_2->addWidget(addressList);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        addressField = new QLineEdit(centralwidget);
        addressField->setObjectName(QStringLiteral("addressField"));

        verticalLayout->addWidget(addressField);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        addToListButton = new QPushButton(centralwidget);
        addToListButton->setObjectName(QStringLiteral("addToListButton"));

        horizontalLayout_2->addWidget(addToListButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(verticalLayout_2);

        AddressBook->setCentralWidget(centralwidget);

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
        addToMailButton->setText(QApplication::translate("AddressBook", "Ajouter au courrier", 0));
        deleteButton->setText(QApplication::translate("AddressBook", "Supprimer ", 0));
        closeButton->setText(QApplication::translate("AddressBook", "Fermer", 0));
        addToListButton->setText(QApplication::translate("AddressBook", "Ajouter au carnet", 0));
    } // retranslateUi

};

namespace Ui {
    class AddressBook: public Ui_AddressBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRESSBOOK_H
