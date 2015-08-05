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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddAccount
{
public:
    QPushButton *cancelButton;
    QPushButton *okButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *tabName;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *accountName;

    void setupUi(QDialog *AddAccount)
    {
        if (AddAccount->objectName().isEmpty())
            AddAccount->setObjectName(QStringLiteral("AddAccount"));
        AddAccount->resize(471, 168);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddAccount->sizePolicy().hasHeightForWidth());
        AddAccount->setSizePolicy(sizePolicy);
        AddAccount->setLayoutDirection(Qt::LeftToRight);
        cancelButton = new QPushButton(AddAccount);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(100, 120, 99, 27));
        okButton = new QPushButton(AddAccount);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setGeometry(QRect(250, 120, 99, 27));
        widget = new QWidget(AddAccount);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 451, 29));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        tabName = new QLineEdit(widget);
        tabName->setObjectName(QStringLiteral("tabName"));

        horizontalLayout->addWidget(tabName);

        widget1 = new QWidget(AddAccount);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 60, 451, 29));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        accountName = new QLineEdit(widget1);
        accountName->setObjectName(QStringLiteral("accountName"));

        horizontalLayout_2->addWidget(accountName);


        retranslateUi(AddAccount);

        QMetaObject::connectSlotsByName(AddAccount);
    } // setupUi

    void retranslateUi(QDialog *AddAccount)
    {
        AddAccount->setWindowTitle(QApplication::translate("AddAccount", "Dialog", 0));
        cancelButton->setText(QApplication::translate("AddAccount", "Cancel", 0));
        okButton->setText(QApplication::translate("AddAccount", "OK", 0));
        label->setText(QApplication::translate("AddAccount", "Nom de l'onglet", 0));
        label_2->setText(QApplication::translate("AddAccount", "Nom du compte", 0));
    } // retranslateUi

};

namespace Ui {
    class AddAccount: public Ui_AddAccount {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDACCOUNT_H
