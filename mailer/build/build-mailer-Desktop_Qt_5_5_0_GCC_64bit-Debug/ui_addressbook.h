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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
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
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QStatusBar *statusbar;
    QToolBar *toolBar;

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
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout->addWidget(treeWidget);

        AddressBook->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddressBook);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 25));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        AddressBook->setMenuBar(menubar);
        statusbar = new QStatusBar(AddressBook);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AddressBook->setStatusBar(statusbar);
        toolBar = new QToolBar(AddressBook);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        AddressBook->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionAjouter_une_adresse);
        menuFichier->addAction(actionSupprimer_l_adresse);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        toolBar->addAction(actionAjouter_une_adresse);
        toolBar->addAction(actionSupprimer_l_adresse);
        toolBar->addAction(actionFermet_le_carnet);

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
        menuFichier->setTitle(QApplication::translate("AddressBook", "Fichier", 0));
        toolBar->setWindowTitle(QApplication::translate("AddressBook", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class AddressBook: public Ui_AddressBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRESSBOOK_H
