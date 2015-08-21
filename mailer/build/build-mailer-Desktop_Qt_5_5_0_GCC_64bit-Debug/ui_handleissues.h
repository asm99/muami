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
#include <QtWidgets/QWidget>

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
    QWidget *widget;
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
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HandleIssues->sizePolicy().hasHeightForWidth());
        HandleIssues->setSizePolicy(sizePolicy);
        actionOui = new QAction(HandleIssues);
        actionOui->setObjectName(QStringLiteral("actionOui"));
        actionNon = new QAction(HandleIssues);
        actionNon->setObjectName(QStringLiteral("actionNon"));
        actionOk = new QAction(HandleIssues);
        actionOk->setObjectName(QStringLiteral("actionOk"));
        actionSave = new QAction(HandleIssues);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        verticalLayout = new QVBoxLayout(HandleIssues);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        issueLabel = new QLabel(HandleIssues);
        issueLabel->setObjectName(QStringLiteral("issueLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(issueLabel->sizePolicy().hasHeightForWidth());
        issueLabel->setSizePolicy(sizePolicy1);
        issueLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(issueLabel);

        widget = new QWidget(HandleIssues);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMaximumSize(QSize(16777215, 30));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(widget);
        okButton->setObjectName(QStringLiteral("okButton"));
        sizePolicy2.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy2);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/res/checkbox-marked-circle-outline.png"), QSize(), QIcon::Normal, QIcon::Off);
        okButton->setIcon(icon);
        okButton->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(okButton);

        ouiButton = new QPushButton(widget);
        ouiButton->setObjectName(QStringLiteral("ouiButton"));
        sizePolicy2.setHeightForWidth(ouiButton->sizePolicy().hasHeightForWidth());
        ouiButton->setSizePolicy(sizePolicy2);
        ouiButton->setIcon(icon);
        ouiButton->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(ouiButton);

        nonButton = new QPushButton(widget);
        nonButton->setObjectName(QStringLiteral("nonButton"));
        sizePolicy2.setHeightForWidth(nonButton->sizePolicy().hasHeightForWidth());
        nonButton->setSizePolicy(sizePolicy2);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/res/close-circle-outline.png"), QSize(), QIcon::Normal, QIcon::Off);
        nonButton->setIcon(icon1);
        nonButton->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(nonButton);

        saveButton = new QPushButton(widget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        sizePolicy2.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy2);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/res/stiffy.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon2);
        saveButton->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(saveButton);


        verticalLayout->addWidget(widget);


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
        okButton->setText(QString());
        ouiButton->setText(QString());
        nonButton->setText(QString());
        saveButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HandleIssues: public Ui_HandleIssues {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDLEISSUES_H
