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
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *leaveButton;
    QPushButton *infoButton;
    QPushButton *addButton;
    QPushButton *backButton;
    QPushButton *goButton;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QListWidget *folderList;
    QLineEdit *pathAccessor;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_3;
    QListWidget *contentList;
    QLineEdit *findFile;
    QTextEdit *fileDetails;

    void setupUi(QMainWindow *AttachFileWindow)
    {
        if (AttachFileWindow->objectName().isEmpty())
            AttachFileWindow->setObjectName(QStringLiteral("AttachFileWindow"));
        AttachFileWindow->resize(886, 549);
        centralwidget = new QWidget(AttachFileWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        leaveButton = new QPushButton(centralwidget);
        leaveButton->setObjectName(QStringLiteral("leaveButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leaveButton->sizePolicy().hasHeightForWidth());
        leaveButton->setSizePolicy(sizePolicy);
        leaveButton->setMaximumSize(QSize(90, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/res/browser-close-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        leaveButton->setIcon(icon);
        leaveButton->setIconSize(QSize(35, 35));

        verticalLayout->addWidget(leaveButton);

        infoButton = new QPushButton(centralwidget);
        infoButton->setObjectName(QStringLiteral("infoButton"));
        sizePolicy.setHeightForWidth(infoButton->sizePolicy().hasHeightForWidth());
        infoButton->setSizePolicy(sizePolicy);
        infoButton->setMaximumSize(QSize(90, 16777215));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/res/info-outline.png"), QSize(), QIcon::Normal, QIcon::Off);
        infoButton->setIcon(icon1);
        infoButton->setIconSize(QSize(35, 35));

        verticalLayout->addWidget(infoButton);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        sizePolicy.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy);
        addButton->setMaximumSize(QSize(90, 16777215));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/res/document-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon2);
        addButton->setIconSize(QSize(35, 35));

        verticalLayout->addWidget(addButton);

        backButton = new QPushButton(centralwidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        sizePolicy.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy);
        backButton->setMaximumSize(QSize(90, 16777215));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/res/out.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon3);
        backButton->setIconSize(QSize(35, 35));

        verticalLayout->addWidget(backButton);

        goButton = new QPushButton(centralwidget);
        goButton->setObjectName(QStringLiteral("goButton"));
        sizePolicy.setHeightForWidth(goButton->sizePolicy().hasHeightForWidth());
        goButton->setSizePolicy(sizePolicy);
        goButton->setMaximumSize(QSize(90, 16777215));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/res/in.png"), QSize(), QIcon::Normal, QIcon::Off);
        goButton->setIcon(icon4);
        goButton->setIconSize(QSize(35, 35));

        verticalLayout->addWidget(goButton);


        horizontalLayout->addLayout(verticalLayout);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(2);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        folderList = new QListWidget(widget);
        folderList->setObjectName(QStringLiteral("folderList"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(folderList->sizePolicy().hasHeightForWidth());
        folderList->setSizePolicy(sizePolicy1);
        folderList->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(folderList);

        pathAccessor = new QLineEdit(widget);
        pathAccessor->setObjectName(QStringLiteral("pathAccessor"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pathAccessor->sizePolicy().hasHeightForWidth());
        pathAccessor->setSizePolicy(sizePolicy2);
        pathAccessor->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(pathAccessor);

        splitter->addWidget(widget);
        widget1 = new QWidget(splitter);
        widget1->setObjectName(QStringLiteral("widget1"));
        verticalLayout_3 = new QVBoxLayout(widget1);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        contentList = new QListWidget(widget1);
        contentList->setObjectName(QStringLiteral("contentList"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(contentList->sizePolicy().hasHeightForWidth());
        contentList->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(contentList);

        findFile = new QLineEdit(widget1);
        findFile->setObjectName(QStringLiteral("findFile"));

        verticalLayout_3->addWidget(findFile);

        splitter->addWidget(widget1);
        fileDetails = new QTextEdit(splitter);
        fileDetails->setObjectName(QStringLiteral("fileDetails"));
        splitter->addWidget(fileDetails);

        horizontalLayout->addWidget(splitter);


        horizontalLayout_2->addLayout(horizontalLayout);

        AttachFileWindow->setCentralWidget(centralwidget);
        splitter->raise();
        goButton->raise();
        backButton->raise();
        addButton->raise();
        backButton->raise();
        goButton->raise();

        retranslateUi(AttachFileWindow);

        QMetaObject::connectSlotsByName(AttachFileWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AttachFileWindow)
    {
        AttachFileWindow->setWindowTitle(QApplication::translate("AttachFileWindow", "MainWindow", 0));
        leaveButton->setText(QString());
        infoButton->setText(QString());
        addButton->setText(QString());
        backButton->setText(QString());
        goButton->setText(QString());
        pathAccessor->setText(QString());
        pathAccessor->setPlaceholderText(QApplication::translate("AttachFileWindow", "Chemin d'acc\303\250s", 0));
        findFile->setPlaceholderText(QApplication::translate("AttachFileWindow", "Recherche", 0));
    } // retranslateUi

};

namespace Ui {
    class AttachFileWindow: public Ui_AttachFileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTACHFILEWINDOW_H
