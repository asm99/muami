/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNouveau_courrier;
    QAction *actionQuitter;
    QAction *actionBoite_de_r_ception;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *mailBox;
    QPushButton *newMail;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuA_propos;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(265, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(150, 150));
        MainWindow->setAutoFillBackground(false);
        actionNouveau_courrier = new QAction(MainWindow);
        actionNouveau_courrier->setObjectName(QStringLiteral("actionNouveau_courrier"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionBoite_de_r_ception = new QAction(MainWindow);
        actionBoite_de_r_ception->setObjectName(QStringLiteral("actionBoite_de_r_ception"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        mailBox = new QPushButton(centralWidget);
        mailBox->setObjectName(QStringLiteral("mailBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(mailBox->sizePolicy().hasHeightForWidth());
        mailBox->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(mailBox);

        newMail = new QPushButton(centralWidget);
        newMail->setObjectName(QStringLiteral("newMail"));
        sizePolicy1.setHeightForWidth(newMail->sizePolicy().hasHeightForWidth());
        newMail->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(newMail);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 265, 25));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuA_propos = new QMenu(menuBar);
        menuA_propos->setObjectName(QStringLiteral("menuA_propos"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuA_propos->menuAction());
        menuFichier->addAction(actionNouveau_courrier);
        menuFichier->addAction(actionBoite_de_r_ception);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionNouveau_courrier->setText(QApplication::translate("MainWindow", "Nouveau courrier", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        actionBoite_de_r_ception->setText(QApplication::translate("MainWindow", "Boite de r\303\251ception", 0));
        mailBox->setText(QApplication::translate("MainWindow", "Consulter\n"
"mes courriers", 0));
        newMail->setText(QApplication::translate("MainWindow", "Ecrire un\n"
"courrier", 0));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuA_propos->setTitle(QApplication::translate("MainWindow", "A propos", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
