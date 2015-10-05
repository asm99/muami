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
#include <my_qlabel.h>

QT_BEGIN_NAMESPACE

class Ui_AttachFileWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QPushButton *leaveButton;
    QPushButton *addButton;
    QPushButton *backButton;
    QPushButton *goButton;
    QSplitter *splitter_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QListWidget *folderList;
    QLineEdit *pathAccessor;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *contentList;
    QHBoxLayout *horizontalLayout;
    QLineEdit *findFile;
    my_qlabel *infoLabel;
    QTextEdit *fileDetails;

    void setupUi(QMainWindow *AttachFileWindow)
    {
        if (AttachFileWindow->objectName().isEmpty())
            AttachFileWindow->setObjectName(QStringLiteral("AttachFileWindow"));
        AttachFileWindow->resize(975, 549);
        centralwidget = new QWidget(AttachFileWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
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
        leaveButton->setMinimumSize(QSize(50, 0));
        leaveButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/res/browser-close-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        leaveButton->setIcon(icon);
        leaveButton->setIconSize(QSize(40, 40));

        verticalLayout->addWidget(leaveButton);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        sizePolicy.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy);
        addButton->setMinimumSize(QSize(50, 0));
        addButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/res/document-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addButton->setIcon(icon1);
        addButton->setIconSize(QSize(40, 40));

        verticalLayout->addWidget(addButton);

        backButton = new QPushButton(centralwidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        sizePolicy.setHeightForWidth(backButton->sizePolicy().hasHeightForWidth());
        backButton->setSizePolicy(sizePolicy);
        backButton->setMinimumSize(QSize(50, 0));
        backButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/res/out.png"), QSize(), QIcon::Normal, QIcon::Off);
        backButton->setIcon(icon2);
        backButton->setIconSize(QSize(40, 40));

        verticalLayout->addWidget(backButton);

        goButton = new QPushButton(centralwidget);
        goButton->setObjectName(QStringLiteral("goButton"));
        sizePolicy.setHeightForWidth(goButton->sizePolicy().hasHeightForWidth());
        goButton->setSizePolicy(sizePolicy);
        goButton->setMinimumSize(QSize(50, 0));
        goButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/res/in.png"), QSize(), QIcon::Normal, QIcon::Off);
        goButton->setIcon(icon3);
        goButton->setIconSize(QSize(40, 40));

        verticalLayout->addWidget(goButton);


        horizontalLayout_3->addLayout(verticalLayout);

        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_2->setHandleWidth(2);
        layoutWidget = new QWidget(splitter_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        folderList = new QListWidget(layoutWidget);
        folderList->setObjectName(QStringLiteral("folderList"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(folderList->sizePolicy().hasHeightForWidth());
        folderList->setSizePolicy(sizePolicy1);
        folderList->setMaximumSize(QSize(16777215, 16777215));
        folderList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_2->addWidget(folderList);

        pathAccessor = new QLineEdit(layoutWidget);
        pathAccessor->setObjectName(QStringLiteral("pathAccessor"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pathAccessor->sizePolicy().hasHeightForWidth());
        pathAccessor->setSizePolicy(sizePolicy2);
        pathAccessor->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(pathAccessor);

        splitter_2->addWidget(layoutWidget);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(2);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        contentList = new QListWidget(widget);
        contentList->setObjectName(QStringLiteral("contentList"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(contentList->sizePolicy().hasHeightForWidth());
        contentList->setSizePolicy(sizePolicy3);
        contentList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        contentList->setFlow(QListView::TopToBottom);
        contentList->setViewMode(QListView::ListMode);
        contentList->setModelColumn(0);

        horizontalLayout_2->addWidget(contentList);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        findFile = new QLineEdit(widget);
        findFile->setObjectName(QStringLiteral("findFile"));

        horizontalLayout->addWidget(findFile);

        infoLabel = new my_qlabel(widget);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(infoLabel->sizePolicy().hasHeightForWidth());
        infoLabel->setSizePolicy(sizePolicy4);
        infoLabel->setMaximumSize(QSize(25, 25));
        infoLabel->setMouseTracking(true);
        infoLabel->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/info-outline.png")));
        infoLabel->setScaledContents(true);

        horizontalLayout->addWidget(infoLabel);


        verticalLayout_3->addLayout(horizontalLayout);

        splitter->addWidget(widget);
        fileDetails = new QTextEdit(splitter);
        fileDetails->setObjectName(QStringLiteral("fileDetails"));
        fileDetails->setMaximumSize(QSize(220, 16777215));
        fileDetails->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        splitter->addWidget(fileDetails);
        splitter_2->addWidget(splitter);

        horizontalLayout_3->addWidget(splitter_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        AttachFileWindow->setCentralWidget(centralwidget);

        retranslateUi(AttachFileWindow);

        QMetaObject::connectSlotsByName(AttachFileWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AttachFileWindow)
    {
        AttachFileWindow->setWindowTitle(QApplication::translate("AttachFileWindow", "MainWindow", 0));
        leaveButton->setText(QString());
        addButton->setText(QString());
        backButton->setText(QString());
        goButton->setText(QString());
        pathAccessor->setText(QString());
        pathAccessor->setPlaceholderText(QApplication::translate("AttachFileWindow", "Chemin d'acc\303\250s", 0));
        findFile->setPlaceholderText(QApplication::translate("AttachFileWindow", "Recherche", 0));
#ifndef QT_NO_TOOLTIP
        infoLabel->setToolTip(QApplication::translate("AttachFileWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Cliquez-moi pour afficher le volet des d\303\251tails de fichier</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        infoLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AttachFileWindow: public Ui_AttachFileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTACHFILEWINDOW_H
