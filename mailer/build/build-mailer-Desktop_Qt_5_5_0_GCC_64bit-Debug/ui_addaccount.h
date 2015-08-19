/********************************************************************************
** Form generated from reading UI file 'addaccount.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDACCOUNT_H
#define UI_ADDACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddAccount
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *tabName;
    QLineEdit *accountName;
    QWidget *buttonWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *okButton;

    void setupUi(QDialog *AddAccount)
    {
        if (AddAccount->objectName().isEmpty())
            AddAccount->setObjectName(QStringLiteral("AddAccount"));
        AddAccount->resize(471, 127);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddAccount->sizePolicy().hasHeightForWidth());
        AddAccount->setSizePolicy(sizePolicy);
        AddAccount->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_2 = new QHBoxLayout(AddAccount);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabName = new QLineEdit(AddAccount);
        tabName->setObjectName(QStringLiteral("tabName"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabName->sizePolicy().hasHeightForWidth());
        tabName->setSizePolicy(sizePolicy1);
        tabName->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(tabName);

        accountName = new QLineEdit(AddAccount);
        accountName->setObjectName(QStringLiteral("accountName"));
        sizePolicy1.setHeightForWidth(accountName->sizePolicy().hasHeightForWidth());
        accountName->setSizePolicy(sizePolicy1);
        accountName->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(accountName);


        verticalLayout_2->addLayout(verticalLayout);

        buttonWidget = new QWidget(AddAccount);
        buttonWidget->setObjectName(QStringLiteral("buttonWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonWidget->sizePolicy().hasHeightForWidth());
        buttonWidget->setSizePolicy(sizePolicy2);
        buttonWidget->setMaximumSize(QSize(16777215, 50));
        horizontalLayout = new QHBoxLayout(buttonWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cancelButton = new QPushButton(buttonWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        sizePolicy1.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy1);
        cancelButton->setMaximumSize(QSize(16777215, 50));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/res/close-circle-outline.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon);
        cancelButton->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(cancelButton);

        okButton = new QPushButton(buttonWidget);
        okButton->setObjectName(QStringLiteral("okButton"));
        sizePolicy1.setHeightForWidth(okButton->sizePolicy().hasHeightForWidth());
        okButton->setSizePolicy(sizePolicy1);
        okButton->setMaximumSize(QSize(16777215, 50));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/res/checkbox-marked-circle-outline.png"), QSize(), QIcon::Normal, QIcon::Off);
        okButton->setIcon(icon1);
        okButton->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(okButton);


        verticalLayout_2->addWidget(buttonWidget);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(AddAccount);

        QMetaObject::connectSlotsByName(AddAccount);
    } // setupUi

    void retranslateUi(QDialog *AddAccount)
    {
        AddAccount->setWindowTitle(QApplication::translate("AddAccount", "Dialog", 0));
        tabName->setPlaceholderText(QApplication::translate("AddAccount", "Nom du compte", 0));
        accountName->setPlaceholderText(QApplication::translate("AddAccount", "Adresse du compte", 0));
        cancelButton->setText(QString());
        okButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddAccount: public Ui_AddAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDACCOUNT_H
