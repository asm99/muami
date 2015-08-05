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
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *pathAccessor;
    QPushButton *help;
    QListWidget *folderList;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *goButton;
    QPushButton *backButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
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
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pathAccessor = new QLineEdit(widget);
        pathAccessor->setObjectName(QStringLiteral("pathAccessor"));

        horizontalLayout_3->addWidget(pathAccessor);

        help = new QPushButton(widget);
        help->setObjectName(QStringLiteral("help"));
        help->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(help->sizePolicy().hasHeightForWidth());
        help->setSizePolicy(sizePolicy);
        help->setMinimumSize(QSize(50, 50));
        help->setMaximumSize(QSize(50, 50));

        horizontalLayout_3->addWidget(help);


        verticalLayout_2->addLayout(horizontalLayout_3);

        folderList = new QListWidget(widget);
        folderList->setObjectName(QStringLiteral("folderList"));

        verticalLayout_2->addWidget(folderList);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        goButton = new QPushButton(widget);
        goButton->setObjectName(QStringLiteral("goButton"));

        horizontalLayout_2->addWidget(goButton);

        backButton = new QPushButton(widget);
        backButton->setObjectName(QStringLiteral("backButton"));

        horizontalLayout_2->addWidget(backButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        splitter->addWidget(widget);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        contentList = new QListWidget(layoutWidget);
        contentList->setObjectName(QStringLiteral("contentList"));

        verticalLayout->addWidget(contentList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);

        leaveButton = new QPushButton(layoutWidget);
        leaveButton->setObjectName(QStringLiteral("leaveButton"));

        horizontalLayout->addWidget(leaveButton);


        verticalLayout->addLayout(horizontalLayout);

        splitter->addWidget(layoutWidget);
        fileDetails = new QTextEdit(splitter);
        fileDetails->setObjectName(QStringLiteral("fileDetails"));
        splitter->addWidget(fileDetails);

        verticalLayout_3->addWidget(splitter);

        AttachFileWindow->setCentralWidget(centralwidget);

        retranslateUi(AttachFileWindow);

        QMetaObject::connectSlotsByName(AttachFileWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AttachFileWindow)
    {
        AttachFileWindow->setWindowTitle(QApplication::translate("AttachFileWindow", "MainWindow", 0));
        pathAccessor->setText(QString());
        pathAccessor->setPlaceholderText(QApplication::translate("AttachFileWindow", "Chemin d'acc\303\250s", 0));
        help->setText(QApplication::translate("AttachFileWindow", "?", 0));
        goButton->setText(QApplication::translate("AttachFileWindow", "Parcourir", 0));
        backButton->setText(QApplication::translate("AttachFileWindow", "Revenir", 0));
        addButton->setText(QApplication::translate("AttachFileWindow", "Ajouter", 0));
        leaveButton->setText(QApplication::translate("AttachFileWindow", "Quitter", 0));
        fileDetails->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class AttachFileWindow: public Ui_AttachFileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTACHFILEWINDOW_H
