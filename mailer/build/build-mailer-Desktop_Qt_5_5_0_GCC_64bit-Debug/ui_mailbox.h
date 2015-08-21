/********************************************************************************
** Form generated from reading UI file 'mailbox.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAILBOX_H
#define UI_MAILBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <my_qlabel.h>

QT_BEGIN_NAMESPACE

class Ui_MailBox
{
public:
    QAction *actionNouveau_courrier;
    QAction *actionR_pondre;
    QAction *actionTransf_rer;
    QAction *actionSupprimer;
    QAction *actionQuitter;
    QAction *actionIsoler;
    QAction *actionAdd;
    QAction *actionAlert;
    QAction *actionCancel_confirmed;
    QAction *actionSupprimer_le_compte;
    QAction *actionR_pondre_tous;
    QAction *actionAttacher_des_pi_ces_jointes;
    QAction *actionSupprimer_la_pi_ce_jointe;
    QAction *actionEnvoyer;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QLabel *emptyLabel_3;
    QListWidget *inbox;
    QWidget *groupInbox;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *previousAccount;
    QPushButton *addAccount;
    QPushButton *delAccount;
    QPushButton *nextAccount;
    QSplitter *splitter_2;
    QWidget *groupBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *inboxButton;
    QPushButton *newButton;
    QPushButton *repButton;
    QPushButton *repAllButton;
    QPushButton *transferButton;
    QPushButton *isolateButton;
    QPushButton *sendButton;
    QPushButton *cancelButton;
    QPushButton *deleteButton;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *emptyLabel;
    QLabel *emptyLabel_2;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *mailField;
    my_qlabel *infoLabel;
    QListWidget *mailList;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *to;
    QLineEdit *cc;
    QLineEdit *bcc;
    QLineEdit *title;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_6;
    QPushButton *addressBook_2;
    QPushButton *addFileButton_2;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *attachedFileList;
    QPushButton *deleteFile;
    QTextEdit *displayer;
    QToolBar *toolBar;
    QStatusBar *statusBar;
    QMenuBar *menubar;
    QMenu *menuFichier;

    void setupUi(QMainWindow *MailBox)
    {
        if (MailBox->objectName().isEmpty())
            MailBox->setObjectName(QStringLiteral("MailBox"));
        MailBox->resize(1024, 728);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MailBox->sizePolicy().hasHeightForWidth());
        MailBox->setSizePolicy(sizePolicy);
        MailBox->setMinimumSize(QSize(1024, 728));
        actionNouveau_courrier = new QAction(MailBox);
        actionNouveau_courrier->setObjectName(QStringLiteral("actionNouveau_courrier"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        actionNouveau_courrier->setFont(font);
        actionR_pondre = new QAction(MailBox);
        actionR_pondre->setObjectName(QStringLiteral("actionR_pondre"));
        actionR_pondre->setFont(font);
        actionTransf_rer = new QAction(MailBox);
        actionTransf_rer->setObjectName(QStringLiteral("actionTransf_rer"));
        actionTransf_rer->setFont(font);
        actionSupprimer = new QAction(MailBox);
        actionSupprimer->setObjectName(QStringLiteral("actionSupprimer"));
        actionSupprimer->setFont(font);
        actionQuitter = new QAction(MailBox);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionQuitter->setFont(font);
        actionIsoler = new QAction(MailBox);
        actionIsoler->setObjectName(QStringLiteral("actionIsoler"));
        actionIsoler->setFont(font);
        actionAdd = new QAction(MailBox);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        actionAdd->setFont(font);
        actionAlert = new QAction(MailBox);
        actionAlert->setObjectName(QStringLiteral("actionAlert"));
        actionCancel_confirmed = new QAction(MailBox);
        actionCancel_confirmed->setObjectName(QStringLiteral("actionCancel_confirmed"));
        actionSupprimer_le_compte = new QAction(MailBox);
        actionSupprimer_le_compte->setObjectName(QStringLiteral("actionSupprimer_le_compte"));
        actionSupprimer_le_compte->setFont(font);
        actionR_pondre_tous = new QAction(MailBox);
        actionR_pondre_tous->setObjectName(QStringLiteral("actionR_pondre_tous"));
        actionR_pondre_tous->setFont(font);
        actionAttacher_des_pi_ces_jointes = new QAction(MailBox);
        actionAttacher_des_pi_ces_jointes->setObjectName(QStringLiteral("actionAttacher_des_pi_ces_jointes"));
        actionAttacher_des_pi_ces_jointes->setFont(font);
        actionSupprimer_la_pi_ce_jointe = new QAction(MailBox);
        actionSupprimer_la_pi_ce_jointe->setObjectName(QStringLiteral("actionSupprimer_la_pi_ce_jointe"));
        actionSupprimer_la_pi_ce_jointe->setFont(font);
        actionEnvoyer = new QAction(MailBox);
        actionEnvoyer->setObjectName(QStringLiteral("actionEnvoyer"));
        actionEnvoyer->setFont(font);
        centralwidget = new QWidget(MailBox);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_9 = new QHBoxLayout(centralwidget);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        emptyLabel_3 = new QLabel(centralwidget);
        emptyLabel_3->setObjectName(QStringLiteral("emptyLabel_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(emptyLabel_3->sizePolicy().hasHeightForWidth());
        emptyLabel_3->setSizePolicy(sizePolicy1);
        emptyLabel_3->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(emptyLabel_3);

        inbox = new QListWidget(centralwidget);
        inbox->setObjectName(QStringLiteral("inbox"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(inbox->sizePolicy().hasHeightForWidth());
        inbox->setSizePolicy(sizePolicy2);
        inbox->setMaximumSize(QSize(200, 16777215));

        verticalLayout->addWidget(inbox);

        groupInbox = new QWidget(centralwidget);
        groupInbox->setObjectName(QStringLiteral("groupInbox"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupInbox->sizePolicy().hasHeightForWidth());
        groupInbox->setSizePolicy(sizePolicy3);
        groupInbox->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_5 = new QHBoxLayout(groupInbox);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        previousAccount = new QPushButton(groupInbox);
        previousAccount->setObjectName(QStringLiteral("previousAccount"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(previousAccount->sizePolicy().hasHeightForWidth());
        previousAccount->setSizePolicy(sizePolicy4);
        previousAccount->setMinimumSize(QSize(0, 25));
        previousAccount->setMaximumSize(QSize(16777215, 25));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/res/arrow-left.png"), QSize(), QIcon::Normal, QIcon::Off);
        previousAccount->setIcon(icon);
        previousAccount->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(previousAccount);

        addAccount = new QPushButton(groupInbox);
        addAccount->setObjectName(QStringLiteral("addAccount"));
        sizePolicy4.setHeightForWidth(addAccount->sizePolicy().hasHeightForWidth());
        addAccount->setSizePolicy(sizePolicy4);
        addAccount->setMinimumSize(QSize(0, 25));
        addAccount->setMaximumSize(QSize(16777215, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/res/user-4-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addAccount->setIcon(icon1);
        addAccount->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(addAccount);

        delAccount = new QPushButton(groupInbox);
        delAccount->setObjectName(QStringLiteral("delAccount"));
        sizePolicy4.setHeightForWidth(delAccount->sizePolicy().hasHeightForWidth());
        delAccount->setSizePolicy(sizePolicy4);
        delAccount->setMinimumSize(QSize(0, 25));
        delAccount->setMaximumSize(QSize(16777215, 25));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/res/user-4-remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        delAccount->setIcon(icon2);
        delAccount->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(delAccount);

        nextAccount = new QPushButton(groupInbox);
        nextAccount->setObjectName(QStringLiteral("nextAccount"));
        sizePolicy4.setHeightForWidth(nextAccount->sizePolicy().hasHeightForWidth());
        nextAccount->setSizePolicy(sizePolicy4);
        nextAccount->setMinimumSize(QSize(0, 25));
        nextAccount->setMaximumSize(QSize(16777215, 25));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/res/arrow-right.png"), QSize(), QIcon::Normal, QIcon::Off);
        nextAccount->setIcon(icon3);
        nextAccount->setIconSize(QSize(20, 20));

        horizontalLayout_5->addWidget(nextAccount);


        verticalLayout->addWidget(groupInbox);


        horizontalLayout_8->addLayout(verticalLayout);

        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_2->setHandleWidth(1);
        groupBox = new QWidget(splitter_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMinimumSize(QSize(50, 0));
        groupBox->setMaximumSize(QSize(50, 16777215));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        inboxButton = new QPushButton(groupBox);
        inboxButton->setObjectName(QStringLiteral("inboxButton"));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(1);
        sizePolicy5.setHeightForWidth(inboxButton->sizePolicy().hasHeightForWidth());
        inboxButton->setSizePolicy(sizePolicy5);
        inboxButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/res/inbox-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        inboxButton->setIcon(icon4);
        inboxButton->setIconSize(QSize(40, 40));

        verticalLayout_2->addWidget(inboxButton);

        newButton = new QPushButton(groupBox);
        newButton->setObjectName(QStringLiteral("newButton"));
        sizePolicy5.setHeightForWidth(newButton->sizePolicy().hasHeightForWidth());
        newButton->setSizePolicy(sizePolicy5);
        newButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icon/res/compose-4.png"), QSize(), QIcon::Normal, QIcon::Off);
        newButton->setIcon(icon5);
        newButton->setIconSize(QSize(40, 40));

        verticalLayout_2->addWidget(newButton);

        repButton = new QPushButton(groupBox);
        repButton->setObjectName(QStringLiteral("repButton"));
        sizePolicy5.setHeightForWidth(repButton->sizePolicy().hasHeightForWidth());
        repButton->setSizePolicy(sizePolicy5);
        repButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icon/res/reply.png"), QSize(), QIcon::Normal, QIcon::Off);
        repButton->setIcon(icon6);
        repButton->setIconSize(QSize(40, 40));

        verticalLayout_2->addWidget(repButton);

        repAllButton = new QPushButton(groupBox);
        repAllButton->setObjectName(QStringLiteral("repAllButton"));
        sizePolicy5.setHeightForWidth(repAllButton->sizePolicy().hasHeightForWidth());
        repAllButton->setSizePolicy(sizePolicy5);
        repAllButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icon/res/reply-all.png"), QSize(), QIcon::Normal, QIcon::Off);
        repAllButton->setIcon(icon7);
        repAllButton->setIconSize(QSize(40, 40));

        verticalLayout_2->addWidget(repAllButton);

        transferButton = new QPushButton(groupBox);
        transferButton->setObjectName(QStringLiteral("transferButton"));
        sizePolicy5.setHeightForWidth(transferButton->sizePolicy().hasHeightForWidth());
        transferButton->setSizePolicy(sizePolicy5);
        transferButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icon/res/transfer.png"), QSize(), QIcon::Normal, QIcon::Off);
        transferButton->setIcon(icon8);
        transferButton->setIconSize(QSize(40, 40));

        verticalLayout_2->addWidget(transferButton);

        isolateButton = new QPushButton(groupBox);
        isolateButton->setObjectName(QStringLiteral("isolateButton"));
        sizePolicy5.setHeightForWidth(isolateButton->sizePolicy().hasHeightForWidth());
        isolateButton->setSizePolicy(sizePolicy5);
        isolateButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icon/res/windows.png"), QSize(), QIcon::Normal, QIcon::Off);
        isolateButton->setIcon(icon9);
        isolateButton->setIconSize(QSize(40, 40));

        verticalLayout_2->addWidget(isolateButton);

        sendButton = new QPushButton(groupBox);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sizePolicy5.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy5);
        sendButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icon/res/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendButton->setIcon(icon10);
        sendButton->setIconSize(QSize(40, 40));

        verticalLayout_2->addWidget(sendButton);

        cancelButton = new QPushButton(groupBox);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        sizePolicy5.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy5);
        cancelButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/icon/res/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon11);
        cancelButton->setIconSize(QSize(40, 40));

        verticalLayout_2->addWidget(cancelButton);

        deleteButton = new QPushButton(groupBox);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        sizePolicy5.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy5);
        deleteButton->setMaximumSize(QSize(50, 16777215));
        deleteButton->setToolTipDuration(-1);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/icon/res/bin-3.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon12);
        deleteButton->setIconSize(QSize(40, 40));

        verticalLayout_2->addWidget(deleteButton);

        splitter_2->addWidget(groupBox);

        horizontalLayout_8->addWidget(splitter_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        emptyLabel = new QLabel(centralwidget);
        emptyLabel->setObjectName(QStringLiteral("emptyLabel"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(1);
        sizePolicy6.setVerticalStretch(1);
        sizePolicy6.setHeightForWidth(emptyLabel->sizePolicy().hasHeightForWidth());
        emptyLabel->setSizePolicy(sizePolicy6);

        horizontalLayout_2->addWidget(emptyLabel);

        emptyLabel_2 = new QLabel(centralwidget);
        emptyLabel_2->setObjectName(QStringLiteral("emptyLabel_2"));
        sizePolicy6.setHeightForWidth(emptyLabel_2->sizePolicy().hasHeightForWidth());
        emptyLabel_2->setSizePolicy(sizePolicy6);

        horizontalLayout_2->addWidget(emptyLabel_2);


        horizontalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        mailField = new QLineEdit(centralwidget);
        mailField->setObjectName(QStringLiteral("mailField"));
        mailField->setEnabled(true);
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(1);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(mailField->sizePolicy().hasHeightForWidth());
        mailField->setSizePolicy(sizePolicy7);

        horizontalLayout_4->addWidget(mailField);

        infoLabel = new my_qlabel(centralwidget);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));
        sizePolicy.setHeightForWidth(infoLabel->sizePolicy().hasHeightForWidth());
        infoLabel->setSizePolicy(sizePolicy);
        infoLabel->setMaximumSize(QSize(27, 27));
        infoLabel->setMouseTracking(true);
        infoLabel->setFrameShadow(QFrame::Raised);
        infoLabel->setPixmap(QPixmap(QString::fromUtf8(":/icon/res/info-outline.png")));
        infoLabel->setScaledContents(true);

        horizontalLayout_4->addWidget(infoLabel);


        verticalLayout_4->addLayout(horizontalLayout_4);

        mailList = new QListWidget(centralwidget);
        mailList->setObjectName(QStringLiteral("mailList"));
        mailList->setMinimumSize(QSize(250, 0));
        mailList->setBaseSize(QSize(0, 0));
        mailList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mailList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout_4->addWidget(mailList);


        horizontalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy8);
        widget->setMaximumSize(QSize(16777215, 100));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        to = new QLineEdit(widget);
        to->setObjectName(QStringLiteral("to"));
        sizePolicy4.setHeightForWidth(to->sizePolicy().hasHeightForWidth());
        to->setSizePolicy(sizePolicy4);
        to->setMaximumSize(QSize(16777215, 27));

        verticalLayout_3->addWidget(to);

        cc = new QLineEdit(widget);
        cc->setObjectName(QStringLiteral("cc"));
        sizePolicy4.setHeightForWidth(cc->sizePolicy().hasHeightForWidth());
        cc->setSizePolicy(sizePolicy4);
        cc->setMaximumSize(QSize(16777215, 27));

        verticalLayout_3->addWidget(cc);

        bcc = new QLineEdit(widget);
        bcc->setObjectName(QStringLiteral("bcc"));
        sizePolicy4.setHeightForWidth(bcc->sizePolicy().hasHeightForWidth());
        bcc->setSizePolicy(sizePolicy4);
        bcc->setMaximumSize(QSize(16777215, 27));

        verticalLayout_3->addWidget(bcc);

        title = new QLineEdit(widget);
        title->setObjectName(QStringLiteral("title"));
        sizePolicy4.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy4);
        title->setMaximumSize(QSize(16777215, 27));
        QFont font1;
        font1.setKerning(true);
        title->setFont(font1);

        verticalLayout_3->addWidget(title);


        horizontalLayout->addWidget(widget);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        QSizePolicy sizePolicy9(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(widget1->sizePolicy().hasHeightForWidth());
        widget1->setSizePolicy(sizePolicy9);
        widget1->setMaximumSize(QSize(50, 100));
        verticalLayout_6 = new QVBoxLayout(widget1);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        addressBook_2 = new QPushButton(widget1);
        addressBook_2->setObjectName(QStringLiteral("addressBook_2"));
        sizePolicy.setHeightForWidth(addressBook_2->sizePolicy().hasHeightForWidth());
        addressBook_2->setSizePolicy(sizePolicy);
        addressBook_2->setMaximumSize(QSize(50, 50));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/icon/res/address-book-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        addressBook_2->setIcon(icon13);
        addressBook_2->setIconSize(QSize(35, 35));

        verticalLayout_6->addWidget(addressBook_2);

        addFileButton_2 = new QPushButton(widget1);
        addFileButton_2->setObjectName(QStringLiteral("addFileButton_2"));
        sizePolicy.setHeightForWidth(addFileButton_2->sizePolicy().hasHeightForWidth());
        addFileButton_2->setSizePolicy(sizePolicy);
        addFileButton_2->setMaximumSize(QSize(50, 50));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/icon/res/document-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addFileButton_2->setIcon(icon14);
        addFileButton_2->setIconSize(QSize(35, 35));

        verticalLayout_6->addWidget(addFileButton_2);


        horizontalLayout->addWidget(widget1);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        attachedFileList = new QListWidget(centralwidget);
        attachedFileList->setObjectName(QStringLiteral("attachedFileList"));
        QSizePolicy sizePolicy10(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy10.setHorizontalStretch(1);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(attachedFileList->sizePolicy().hasHeightForWidth());
        attachedFileList->setSizePolicy(sizePolicy10);
        attachedFileList->setMinimumSize(QSize(80, 27));
        attachedFileList->setMaximumSize(QSize(16777215, 82));

        horizontalLayout_3->addWidget(attachedFileList);

        deleteFile = new QPushButton(centralwidget);
        deleteFile->setObjectName(QStringLiteral("deleteFile"));
        QSizePolicy sizePolicy11(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy11.setHorizontalStretch(0);
        sizePolicy11.setVerticalStretch(1);
        sizePolicy11.setHeightForWidth(deleteFile->sizePolicy().hasHeightForWidth());
        deleteFile->setSizePolicy(sizePolicy11);
        deleteFile->setMaximumSize(QSize(50, 50));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/icon/res/document-remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteFile->setIcon(icon15);
        deleteFile->setIconSize(QSize(35, 35));

        horizontalLayout_3->addWidget(deleteFile);


        verticalLayout_5->addLayout(horizontalLayout_3);

        displayer = new QTextEdit(centralwidget);
        displayer->setObjectName(QStringLiteral("displayer"));
        displayer->setMinimumSize(QSize(0, 0));
        displayer->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        displayer->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_5->addWidget(displayer);


        horizontalLayout_6->addLayout(verticalLayout_5);


        horizontalLayout_7->addLayout(horizontalLayout_6);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        horizontalLayout_9->addLayout(horizontalLayout_8);

        MailBox->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MailBox);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MailBox->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MailBox);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setEnabled(true);
        QSizePolicy sizePolicy12(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(0);
        sizePolicy12.setHeightForWidth(statusBar->sizePolicy().hasHeightForWidth());
        statusBar->setSizePolicy(sizePolicy12);
        MailBox->setStatusBar(statusBar);
        menubar = new QMenuBar(MailBox);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 25));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        MailBox->setMenuBar(menubar);

        toolBar->addAction(actionNouveau_courrier);
        toolBar->addAction(actionSupprimer);
        toolBar->addAction(actionR_pondre);
        toolBar->addAction(actionTransf_rer);
        toolBar->addAction(actionIsoler);
        toolBar->addAction(actionQuitter);
        toolBar->addAction(actionAdd);
        menubar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionNouveau_courrier);
        menuFichier->addAction(actionR_pondre);
        menuFichier->addAction(actionR_pondre_tous);
        menuFichier->addAction(actionTransf_rer);
        menuFichier->addAction(actionSupprimer);
        menuFichier->addAction(actionIsoler);
        menuFichier->addAction(actionEnvoyer);
        menuFichier->addSeparator();
        menuFichier->addAction(actionAttacher_des_pi_ces_jointes);
        menuFichier->addAction(actionSupprimer_la_pi_ce_jointe);
        menuFichier->addSeparator();
        menuFichier->addAction(actionAdd);
        menuFichier->addAction(actionSupprimer_le_compte);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuFichier->addSeparator();

        retranslateUi(MailBox);

        QMetaObject::connectSlotsByName(MailBox);
    } // setupUi

    void retranslateUi(QMainWindow *MailBox)
    {
        MailBox->setWindowTitle(QApplication::translate("MailBox", "MainWindow", 0));
        actionNouveau_courrier->setText(QApplication::translate("MailBox", "Nouveau courrier", 0));
        actionNouveau_courrier->setShortcut(QApplication::translate("MailBox", "Ctrl+N", 0));
        actionR_pondre->setText(QApplication::translate("MailBox", "R\303\251pondre", 0));
        actionR_pondre->setShortcut(QApplication::translate("MailBox", "Ctrl+R", 0));
        actionTransf_rer->setText(QApplication::translate("MailBox", "Transf\303\251rer", 0));
        actionTransf_rer->setShortcut(QApplication::translate("MailBox", "Ctrl+T", 0));
        actionSupprimer->setText(QApplication::translate("MailBox", "Supprimer", 0));
        actionSupprimer->setShortcut(QApplication::translate("MailBox", "Del", 0));
        actionQuitter->setText(QApplication::translate("MailBox", "Quitter", 0));
        actionQuitter->setShortcut(QApplication::translate("MailBox", "Alt+Q", 0));
        actionIsoler->setText(QApplication::translate("MailBox", "Isoler", 0));
        actionIsoler->setShortcut(QApplication::translate("MailBox", "Ctrl+I", 0));
        actionAdd->setText(QApplication::translate("MailBox", "Ajouter un compte", 0));
#ifndef QT_NO_TOOLTIP
        actionAdd->setToolTip(QApplication::translate("MailBox", "Ajouter un compte ", 0));
#endif // QT_NO_TOOLTIP
        actionAdd->setShortcut(QApplication::translate("MailBox", "Ctrl+A", 0));
        actionAlert->setText(QApplication::translate("MailBox", "alert", 0));
        actionCancel_confirmed->setText(QApplication::translate("MailBox", "cancel_confirmed", 0));
        actionSupprimer_le_compte->setText(QApplication::translate("MailBox", "Supprimer le compte", 0));
        actionR_pondre_tous->setText(QApplication::translate("MailBox", "R\303\251pondre \303\240 tous", 0));
        actionR_pondre_tous->setShortcut(QApplication::translate("MailBox", "Ctrl+Shift+R", 0));
        actionAttacher_des_pi_ces_jointes->setText(QApplication::translate("MailBox", "Attacher des pi\303\250ces jointes", 0));
        actionAttacher_des_pi_ces_jointes->setShortcut(QApplication::translate("MailBox", "Ctrl+J", 0));
        actionSupprimer_la_pi_ce_jointe->setText(QApplication::translate("MailBox", "Supprimer la pi\303\250ce jointe", 0));
        actionEnvoyer->setText(QApplication::translate("MailBox", "Envoyer", 0));
        actionEnvoyer->setShortcut(QApplication::translate("MailBox", "Ctrl+E", 0));
#ifndef QT_NO_TOOLTIP
        emptyLabel_3->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        emptyLabel_3->setText(QString());
#ifndef QT_NO_TOOLTIP
        inbox->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        previousAccount->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        previousAccount->setText(QString());
        previousAccount->setShortcut(QApplication::translate("MailBox", "Ctrl+Left", 0));
#ifndef QT_NO_TOOLTIP
        addAccount->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        addAccount->setText(QString());
        addAccount->setShortcut(QApplication::translate("MailBox", "Ctrl+Shift+A", 0));
#ifndef QT_NO_TOOLTIP
        delAccount->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        delAccount->setText(QString());
        delAccount->setShortcut(QApplication::translate("MailBox", "Ctrl+Shift+S", 0));
#ifndef QT_NO_TOOLTIP
        nextAccount->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        nextAccount->setText(QString());
        nextAccount->setShortcut(QApplication::translate("MailBox", "Ctrl+Right", 0));
#ifndef QT_NO_TOOLTIP
        inboxButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        inboxButton->setText(QString());
        inboxButton->setShortcut(QApplication::translate("MailBox", "Ctrl+B", 0));
#ifndef QT_NO_TOOLTIP
        newButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        newButton->setText(QString());
        newButton->setShortcut(QApplication::translate("MailBox", "Ctrl+N", 0));
#ifndef QT_NO_TOOLTIP
        repButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        repButton->setText(QString());
        repButton->setShortcut(QApplication::translate("MailBox", "Ctrl+R", 0));
#ifndef QT_NO_TOOLTIP
        repAllButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        repAllButton->setText(QString());
        repAllButton->setShortcut(QApplication::translate("MailBox", "Ctrl+Shift+R", 0));
#ifndef QT_NO_TOOLTIP
        transferButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        transferButton->setText(QString());
        transferButton->setShortcut(QApplication::translate("MailBox", "Ctrl+T", 0));
#ifndef QT_NO_TOOLTIP
        isolateButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        isolateButton->setText(QString());
        isolateButton->setShortcut(QApplication::translate("MailBox", "Ctrl+I", 0));
#ifndef QT_NO_TOOLTIP
        sendButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        sendButton->setText(QString());
        sendButton->setShortcut(QApplication::translate("MailBox", "Ctrl+Shift+S", 0));
#ifndef QT_NO_TOOLTIP
        cancelButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        cancelButton->setText(QString());
        cancelButton->setShortcut(QApplication::translate("MailBox", "Esc", 0));
#ifndef QT_NO_TOOLTIP
        deleteButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        deleteButton->setText(QString());
        deleteButton->setShortcut(QApplication::translate("MailBox", "Ctrl+D", 0));
        emptyLabel->setText(QString());
        emptyLabel_2->setText(QString());
#ifndef QT_NO_TOOLTIP
        mailField->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        mailField->setPlaceholderText(QApplication::translate("MailBox", "Recherche", 0));
        infoLabel->setText(QString());
#ifndef QT_NO_TOOLTIP
        mailList->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        to->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        to->setPlaceholderText(QApplication::translate("MailBox", "Destinataire", 0));
#ifndef QT_NO_TOOLTIP
        cc->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        cc->setText(QString());
        cc->setPlaceholderText(QApplication::translate("MailBox", "Destinataire en copie", 0));
#ifndef QT_NO_TOOLTIP
        bcc->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        bcc->setPlaceholderText(QApplication::translate("MailBox", "Destinataire cach\303\251", 0));
#ifndef QT_NO_TOOLTIP
        title->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        title->setPlaceholderText(QApplication::translate("MailBox", "Objet", 0));
#ifndef QT_NO_TOOLTIP
        addressBook_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        addressBook_2->setText(QString());
        addressBook_2->setShortcut(QApplication::translate("MailBox", "Ctrl+Shift+B", 0));
#ifndef QT_NO_TOOLTIP
        addFileButton_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        addFileButton_2->setText(QString());
        addFileButton_2->setShortcut(QApplication::translate("MailBox", "Ctrl+Shift+F", 0));
#ifndef QT_NO_TOOLTIP
        attachedFileList->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        deleteFile->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        deleteFile->setText(QString());
#ifndef QT_NO_TOOLTIP
        displayer->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("MailBox", "toolBar", 0));
        menuFichier->setTitle(QApplication::translate("MailBox", "Fichier", 0));
    } // retranslateUi

};

namespace Ui {
    class MailBox: public Ui_MailBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAILBOX_H
