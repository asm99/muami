/********************************************************************************
** Form generated from reading UI file 'attachfilewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTACHFILEWINDOW_H
#define UI_ATTACHFILEWINDOW_H

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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AttachFileWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *pathAccessor;
    QListWidget *folderList;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *goButton;
    QPushButton *backButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLineEdit *findFile;
    QListWidget *contentList;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *leaveButton;
    QTextEdit *fileDetails;

    void setupUi(QMainWindow *AttachFileWindow)
    {
        if (AttachFileWindow->objectName().isEmpty())
            AttachFileWindow->setObjectName(QStringLiteral("AttachFileWindow"));
        AttachFileWindow->resize(800, 600);
        centralwidget = new QWidget(AttachFileWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pathAccessor = new QLineEdit(layoutWidget);
        pathAccessor->setObjectName(QStringLiteral("pathAccessor"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pathAccessor->sizePolicy().hasHeightForWidth());
        pathAccessor->setSizePolicy(sizePolicy);
        pathAccessor->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(pathAccessor);

        folderList = new QListWidget(layoutWidget);
        folderList->setObjectName(QStringLiteral("folderList"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(folderList->sizePolicy().hasHeightForWidth());
        folderList->setSizePolicy(sizePolicy1);
        folderList->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(folderList);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        goButton = new QPushButton(layoutWidget);
        goButton->setObjectName(QStringLiteral("goButton"));
        sizePolicy.setHeightForWidth(goButton->sizePolicy().hasHeightForWidth());
        goButton->setSizePolicy(sizePolicy);
        goButton->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(goButton);

        backButton = new QPushButton(layoutWidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        sizePolicy.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy);
        backButton->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(backButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        findFile = new QLineEdit(layoutWidget1);
        findFile->setObjectName(QStringLiteral("findFile"));

        verticalLayout->addWidget(findFile);

        contentList = new QListWidget(layoutWidget1);
        contentList->setObjectName(QStringLiteral("contentList"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(contentList->sizePolicy().hasHeightForWidth());
        contentList->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(contentList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addButton = new QPushButton(layoutWidget1);
        addButton->setObjectName(QStringLiteral("addButton"));
        sizePolicy.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(addButton);

        leaveButton = new QPushButton(layoutWidget1);
        leaveButton->setObjectName(QStringLiteral("leaveButton"));
        sizePolicy.setHeightForWidth(leaveButton->sizePolicy().hasHeightForWidth());
        leaveButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(leaveButton);


        verticalLayout->addLayout(horizontalLayout);

        splitter->addWidget(layoutWidget1);
        fileDetails = new QTextEdit(splitter);
        fileDetails->setObjectName(QStringLiteral("fileDetails"));
        splitter->addWidget(fileDetails);

        horizontalLayout_3->addWidget(splitter);

        AttachFileWindow->setCentralWidget(centralwidget);

        retranslateUi(AttachFileWindow);

        QMetaObject::connectSlotsByName(AttachFileWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AttachFileWindow)
    {
        AttachFileWindow->setWindowTitle(QApplication::translate("AttachFileWindow", "MainWindow", 0));
        pathAccessor->setText(QString());
        pathAccessor->setPlaceholderText(QApplication::translate("AttachFileWindow", "Chemin d'acc\303\250s", 0));
        goButton->setText(QApplication::translate("AttachFileWindow", "Parcourir", 0));
        backButton->setText(QApplication::translate("AttachFileWindow", "Revenir", 0));
        findFile->setPlaceholderText(QApplication::translate("AttachFileWindow", "Recherche", 0));
        addButton->setText(QApplication::translate("AttachFileWindow", "Ajouter", 0));
        leaveButton->setText(QApplication::translate("AttachFileWindow", "Quitter", 0));
    } // retranslateUi

};

namespace Ui {
    class AttachFileWindow: public Ui_AttachFileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTACHFILEWINDOW_H
