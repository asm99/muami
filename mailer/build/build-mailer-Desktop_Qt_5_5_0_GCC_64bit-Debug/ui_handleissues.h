/********************************************************************************
** Form generated from reading UI file 'handleissues.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDLEISSUES_H
#define UI_HANDLEISSUES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HandleIssues
{
public:
    QAction *actionOui;
    QAction *actionNon;
    QAction *actionOk;
    QAction *actionSave;
    QVBoxLayout *verticalLayout;
    QLabel *issueLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *okButton;
    QPushButton *ouiButton;
    QPushButton *nonButton;
    QPushButton *saveButton;

    void setupUi(QDialog *HandleIssues)
    {
        if (HandleIssues->objectName().isEmpty())
            HandleIssues->setObjectName(QStringLiteral("HandleIssues"));
        HandleIssues->resize(485, 178);
        actionOui = new QAction(HandleIssues);
        actionOui->setObjectName(QStringLiteral("actionOui"));
        actionNon = new QAction(HandleIssues);
        actionNon->setObjectName(QStringLiteral("actionNon"));
        actionOk = new QAction(HandleIssues);
        actionOk->setObjectName(QStringLiteral("actionOk"));
        actionSave = new QAction(HandleIssues);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        verticalLayout = new QVBoxLayout(HandleIssues);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        issueLabel = new QLabel(HandleIssues);
        issueLabel->setObjectName(QStringLiteral("issueLabel"));
        issueLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(issueLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(9);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        okButton = new QPushButton(HandleIssues);
        okButton->setObjectName(QStringLiteral("okButton"));

        horizontalLayout->addWidget(okButton);

        ouiButton = new QPushButton(HandleIssues);
        ouiButton->setObjectName(QStringLiteral("ouiButton"));

        horizontalLayout->addWidget(ouiButton);

        nonButton = new QPushButton(HandleIssues);
        nonButton->setObjectName(QStringLiteral("nonButton"));

        horizontalLayout->addWidget(nonButton);

        saveButton = new QPushButton(HandleIssues);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout->addWidget(saveButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(HandleIssues);

        QMetaObject::connectSlotsByName(HandleIssues);
    } // setupUi

    void retranslateUi(QDialog *HandleIssues)
    {
        HandleIssues->setWindowTitle(QApplication::translate("HandleIssues", "Dialog", 0));
        actionOui->setText(QApplication::translate("HandleIssues", "oui", 0));
        actionNon->setText(QApplication::translate("HandleIssues", "non", 0));
        actionOk->setText(QApplication::translate("HandleIssues", "ok", 0));
        actionSave->setText(QApplication::translate("HandleIssues", "save", 0));
        issueLabel->setText(QString());
        okButton->setText(QApplication::translate("HandleIssues", "OK", 0));
        ouiButton->setText(QApplication::translate("HandleIssues", "Oui", 0));
        nonButton->setText(QApplication::translate("HandleIssues", "Non", 0));
        saveButton->setText(QApplication::translate("HandleIssues", "Sauvegarder", 0));
    } // retranslateUi

};

namespace Ui {
    class HandleIssues: public Ui_HandleIssues {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDLEISSUES_H
