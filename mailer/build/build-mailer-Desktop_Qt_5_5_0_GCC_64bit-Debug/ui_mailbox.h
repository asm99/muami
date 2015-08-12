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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QSplitter *splitter_2;
    QTabWidget *multiBox;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QListWidget *inbox;
    QHBoxLayout *horizontalLayout;
    QPushButton *addAccount;
    QPushButton *delAccount;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *inboxButton;
    QPushButton *newButton;
    QPushButton *repButton;
    QPushButton *repAllButton;
    QPushButton *transferButton;
    QPushButton *isolateButton;
    QPushButton *attachButton;
    QPushButton *deleteFile;
    QPushButton *sendButton;
    QPushButton *cancelButton;
    QPushButton *deleteButton;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *emptyLabel;
    QLabel *emptyLabel_2;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *mailField;
    QListWidget *mailList;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *toLabel;
    QLineEdit *to;
    QLabel *ccLabel;
    QLineEdit *cc;
    QLabel *bccLabel;
    QLineEdit *bcc;
    QLabel *titleLabel;
    QLineEdit *title;
    QListWidget *attachedFileList;
    QLabel *attachedLabel;
    QTextEdit *displayer;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QToolBar *toolBar;
    QStatusBar *statusBar;

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
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        multiBox = new QTabWidget(splitter_2);
        multiBox->setObjectName(QStringLiteral("multiBox"));
        multiBox->setMaximumSize(QSize(220, 16777215));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_6 = new QVBoxLayout(tab_3);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        inbox = new QListWidget(tab_3);
        inbox->setObjectName(QStringLiteral("inbox"));
        inbox->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(inbox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addAccount = new QPushButton(tab_3);
        addAccount->setObjectName(QStringLiteral("addAccount"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(addAccount->sizePolicy().hasHeightForWidth());
        addAccount->setSizePolicy(sizePolicy1);
        addAccount->setMaximumSize(QSize(16777215, 27));

        horizontalLayout->addWidget(addAccount);

        delAccount = new QPushButton(tab_3);
        delAccount->setObjectName(QStringLiteral("delAccount"));
        sizePolicy1.setHeightForWidth(delAccount->sizePolicy().hasHeightForWidth());
        delAccount->setSizePolicy(sizePolicy1);
        delAccount->setMaximumSize(QSize(16777215, 27));

        horizontalLayout->addWidget(delAccount);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_6->addLayout(verticalLayout);

        multiBox->addTab(tab_3, QString());
        splitter_2->addWidget(multiBox);
        groupBox = new QGroupBox(splitter_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMaximumSize(QSize(98, 16777215));
        groupBox->setFlat(false);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        inboxButton = new QPushButton(groupBox);
        inboxButton->setObjectName(QStringLiteral("inboxButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(inboxButton->sizePolicy().hasHeightForWidth());
        inboxButton->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(inboxButton);

        newButton = new QPushButton(groupBox);
        newButton->setObjectName(QStringLiteral("newButton"));
        sizePolicy3.setHeightForWidth(newButton->sizePolicy().hasHeightForWidth());
        newButton->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(newButton);

        repButton = new QPushButton(groupBox);
        repButton->setObjectName(QStringLiteral("repButton"));
        sizePolicy3.setHeightForWidth(repButton->sizePolicy().hasHeightForWidth());
        repButton->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(repButton);

        repAllButton = new QPushButton(groupBox);
        repAllButton->setObjectName(QStringLiteral("repAllButton"));
        sizePolicy3.setHeightForWidth(repAllButton->sizePolicy().hasHeightForWidth());
        repAllButton->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(repAllButton);

        transferButton = new QPushButton(groupBox);
        transferButton->setObjectName(QStringLiteral("transferButton"));
        sizePolicy3.setHeightForWidth(transferButton->sizePolicy().hasHeightForWidth());
        transferButton->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(transferButton);

        isolateButton = new QPushButton(groupBox);
        isolateButton->setObjectName(QStringLiteral("isolateButton"));
        sizePolicy3.setHeightForWidth(isolateButton->sizePolicy().hasHeightForWidth());
        isolateButton->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(isolateButton);

        attachButton = new QPushButton(groupBox);
        attachButton->setObjectName(QStringLiteral("attachButton"));
        sizePolicy3.setHeightForWidth(attachButton->sizePolicy().hasHeightForWidth());
        attachButton->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(attachButton);

        deleteFile = new QPushButton(groupBox);
        deleteFile->setObjectName(QStringLiteral("deleteFile"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(deleteFile->sizePolicy().hasHeightForWidth());
        deleteFile->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(deleteFile);

        sendButton = new QPushButton(groupBox);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sizePolicy3.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(sendButton);

        cancelButton = new QPushButton(groupBox);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        sizePolicy4.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy4);

        verticalLayout_2->addWidget(cancelButton);

        deleteButton = new QPushButton(groupBox);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        sizePolicy3.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(deleteButton);

        splitter_2->addWidget(groupBox);

        horizontalLayout_4->addWidget(splitter_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        emptyLabel = new QLabel(centralwidget);
        emptyLabel->setObjectName(QStringLiteral("emptyLabel"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(1);
        sizePolicy5.setHeightForWidth(emptyLabel->sizePolicy().hasHeightForWidth());
        emptyLabel->setSizePolicy(sizePolicy5);

        horizontalLayout_2->addWidget(emptyLabel);

        emptyLabel_2 = new QLabel(centralwidget);
        emptyLabel_2->setObjectName(QStringLiteral("emptyLabel_2"));
        sizePolicy5.setHeightForWidth(emptyLabel_2->sizePolicy().hasHeightForWidth());
        emptyLabel_2->setSizePolicy(sizePolicy5);

        horizontalLayout_2->addWidget(emptyLabel_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(1);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy6);
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        mailField = new QLineEdit(layoutWidget);
        mailField->setObjectName(QStringLiteral("mailField"));
        mailField->setEnabled(true);
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(1);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(mailField->sizePolicy().hasHeightForWidth());
        mailField->setSizePolicy(sizePolicy7);

        verticalLayout_4->addWidget(mailField);

        mailList = new QListWidget(layoutWidget);
        mailList->setObjectName(QStringLiteral("mailList"));
        mailList->setMinimumSize(QSize(0, 0));
        mailList->setBaseSize(QSize(0, 0));

        verticalLayout_4->addWidget(mailList);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(3);
        formLayout->setVerticalSpacing(0);
        toLabel = new QLabel(layoutWidget1);
        toLabel->setObjectName(QStringLiteral("toLabel"));
        QPalette palette;
        QBrush brush(QColor(220, 224, 227, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush1(QColor(159, 158, 158, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        toLabel->setPalette(palette);

        formLayout->setWidget(0, QFormLayout::LabelRole, toLabel);

        to = new QLineEdit(layoutWidget1);
        to->setObjectName(QStringLiteral("to"));

        formLayout->setWidget(0, QFormLayout::FieldRole, to);

        ccLabel = new QLabel(layoutWidget1);
        ccLabel->setObjectName(QStringLiteral("ccLabel"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        ccLabel->setPalette(palette1);

        formLayout->setWidget(1, QFormLayout::LabelRole, ccLabel);

        cc = new QLineEdit(layoutWidget1);
        cc->setObjectName(QStringLiteral("cc"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cc);

        bccLabel = new QLabel(layoutWidget1);
        bccLabel->setObjectName(QStringLiteral("bccLabel"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        bccLabel->setPalette(palette2);

        formLayout->setWidget(2, QFormLayout::LabelRole, bccLabel);

        bcc = new QLineEdit(layoutWidget1);
        bcc->setObjectName(QStringLiteral("bcc"));

        formLayout->setWidget(2, QFormLayout::FieldRole, bcc);

        titleLabel = new QLabel(layoutWidget1);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        titleLabel->setPalette(palette3);

        formLayout->setWidget(3, QFormLayout::LabelRole, titleLabel);

        title = new QLineEdit(layoutWidget1);
        title->setObjectName(QStringLiteral("title"));

        formLayout->setWidget(3, QFormLayout::FieldRole, title);

        attachedFileList = new QListWidget(layoutWidget1);
        attachedFileList->setObjectName(QStringLiteral("attachedFileList"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy8.setHorizontalStretch(1);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(attachedFileList->sizePolicy().hasHeightForWidth());
        attachedFileList->setSizePolicy(sizePolicy8);
        attachedFileList->setMinimumSize(QSize(80, 27));
        attachedFileList->setMaximumSize(QSize(16777215, 82));

        formLayout->setWidget(4, QFormLayout::FieldRole, attachedFileList);

        attachedLabel = new QLabel(layoutWidget1);
        attachedLabel->setObjectName(QStringLiteral("attachedLabel"));
        attachedLabel->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, attachedLabel);


        verticalLayout_3->addLayout(formLayout);

        displayer = new QTextEdit(layoutWidget1);
        displayer->setObjectName(QStringLiteral("displayer"));
        displayer->setMinimumSize(QSize(0, 0));
        displayer->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_3->addWidget(displayer);

        splitter->addWidget(layoutWidget1);

        horizontalLayout_3->addWidget(splitter);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        MailBox->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MailBox);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1024, 25));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        MailBox->setMenuBar(menubar);
        toolBar = new QToolBar(MailBox);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MailBox->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(MailBox);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MailBox->setStatusBar(statusBar);

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
        toolBar->addAction(actionNouveau_courrier);
        toolBar->addAction(actionSupprimer);
        toolBar->addAction(actionR_pondre);
        toolBar->addAction(actionTransf_rer);
        toolBar->addAction(actionIsoler);
        toolBar->addAction(actionQuitter);
        toolBar->addAction(actionAdd);

        retranslateUi(MailBox);

        multiBox->setCurrentIndex(0);


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
        addAccount->setToolTip(QApplication::translate("MailBox", "<html><head/><body><p><span style=\" font-weight:600;\">Cliquez pour ajouter un compte</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        addAccount->setText(QApplication::translate("MailBox", "Ajouter", 0));
        delAccount->setText(QApplication::translate("MailBox", "Supprimer", 0));
        multiBox->setTabText(multiBox->indexOf(tab_3), QApplication::translate("MailBox", "Tab 1", 0));
        groupBox->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        inboxButton->setToolTip(QApplication::translate("MailBox", "<html><head/><body><p>Affiche/cache les boites de courriers</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        inboxButton->setText(QApplication::translate("MailBox", "Boite", 0));
#ifndef QT_NO_TOOLTIP
        newButton->setToolTip(QApplication::translate("MailBox", "<html><head/><body><p>Cr\303\251er un nouveau courrier</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        newButton->setText(QApplication::translate("MailBox", "Nouveau", 0));
#ifndef QT_NO_TOOLTIP
        repButton->setToolTip(QApplication::translate("MailBox", "<html><head/><body><p>R\303\251pondre \303\240 l'exp\303\251diteur du courrier en surbrillance</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        repButton->setText(QApplication::translate("MailBox", "R\303\251pondre", 0));
#ifndef QT_NO_TOOLTIP
        repAllButton->setToolTip(QApplication::translate("MailBox", "<html><head/><body><p>R\303\251pondre \303\240 l'exp\303\251diteur du courrier en surbrillance ainsi que tous les destinataires de ce courrier</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        repAllButton->setText(QApplication::translate("MailBox", "R\303\251pondre\n"
"\303\240 tous", 0));
#ifndef QT_NO_TOOLTIP
        transferButton->setToolTip(QApplication::translate("MailBox", "<html><head/><body><p>Envoyer le courrier en surbrillance \303\240 quelqu'un d'autre</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        transferButton->setText(QApplication::translate("MailBox", "Transf\303\251rer", 0));
#ifndef QT_NO_TOOLTIP
        isolateButton->setToolTip(QApplication::translate("MailBox", "<html><head/><body><p>Isoler le courrier en surbrillance dans une fen\303\252tre s\303\251par\303\251e</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        isolateButton->setText(QApplication::translate("MailBox", "Isoler", 0));
#ifndef QT_NO_TOOLTIP
        attachButton->setToolTip(QApplication::translate("MailBox", "<html><head/><body><p>Envoyer le courrier </p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        attachButton->setText(QApplication::translate("MailBox", "Attacher\n"
"pi\303\250ce\n"
"jointe", 0));
        deleteFile->setText(QApplication::translate("MailBox", "Supprimer\n"
"pi\303\250ce\n"
"jointe", 0));
#ifndef QT_NO_TOOLTIP
        sendButton->setToolTip(QApplication::translate("MailBox", "<html><head/><body><p>Envoyer le courrier </p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sendButton->setText(QApplication::translate("MailBox", "Envoyer", 0));
#ifndef QT_NO_TOOLTIP
        cancelButton->setToolTip(QApplication::translate("MailBox", "<html><head/><body><p>Annuler les modifications</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        cancelButton->setText(QApplication::translate("MailBox", "Annuler", 0));
#ifndef QT_NO_TOOLTIP
        deleteButton->setToolTip(QApplication::translate("MailBox", "<html><head/><body><p>Supprimer d\303\251finitivement le courrier en surbrillance</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        deleteButton->setText(QApplication::translate("MailBox", "Supprimer", 0));
        emptyLabel->setText(QString());
        emptyLabel_2->setText(QString());
#ifndef QT_NO_TOOLTIP
        mailList->setToolTip(QApplication::translate("MailBox", "<html><head/><body><p>Ceci est la liste des courriers de votre boite de r\303\251ception</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        toLabel->setText(QApplication::translate("MailBox", "<html><head/><body><p align=\"right\"><span style=\" font-weight:600;\">\303\240 :</span></p></body></html>", 0));
        to->setPlaceholderText(QString());
        ccLabel->setText(QApplication::translate("MailBox", "<html><head/><body><p align=\"right\"><span style=\" font-weight:600;\">cc :</span></p></body></html>", 0));
        cc->setPlaceholderText(QString());
        bccLabel->setText(QApplication::translate("MailBox", "<html><head/><body><p align=\"right\"><span style=\" font-weight:600;\">bcc :</span></p></body></html>", 0));
        bcc->setPlaceholderText(QString());
        titleLabel->setText(QApplication::translate("MailBox", "<html><head/><body><p align=\"right\"><span style=\" font-weight:600;\">objet :</span></p></body></html>", 0));
        title->setPlaceholderText(QString());
        attachedLabel->setText(QApplication::translate("MailBox", "Pi\303\250ces jointes :", 0));
#ifndef QT_NO_TOOLTIP
        displayer->setToolTip(QApplication::translate("MailBox", "<html><head/><body><p>Ceci est le contenu du courrier en surbrillance</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        menuFichier->setTitle(QApplication::translate("MailBox", "Fichier", 0));
        toolBar->setWindowTitle(QApplication::translate("MailBox", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MailBox: public Ui_MailBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAILBOX_H
