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
#include <QtWidgets/QTreeWidget>
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
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QSplitter *splitter_2;
    QTabWidget *multiBox;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QTreeWidget *inbox;
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
    QListWidget *mailList;
    QWidget *layoutWidget;
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
    QVBoxLayout *verticalLayout_4;
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
        actionAlert = new QAction(MailBox);
        actionAlert->setObjectName(QStringLiteral("actionAlert"));
        actionCancel_confirmed = new QAction(MailBox);
        actionCancel_confirmed->setObjectName(QStringLiteral("actionCancel_confirmed"));
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
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_6 = new QVBoxLayout(tab_3);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        inbox = new QTreeWidget(tab_3);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        inbox->setHeaderItem(__qtreewidgetitem);
        inbox->setObjectName(QStringLiteral("inbox"));

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

        horizontalLayout->addWidget(addAccount);

        delAccount = new QPushButton(tab_3);
        delAccount->setObjectName(QStringLiteral("delAccount"));
        sizePolicy1.setHeightForWidth(delAccount->sizePolicy().hasHeightForWidth());
        delAccount->setSizePolicy(sizePolicy1);

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
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        emptyLabel = new QLabel(centralwidget);
        emptyLabel->setObjectName(QStringLiteral("emptyLabel"));

        horizontalLayout_2->addWidget(emptyLabel);

        emptyLabel_2 = new QLabel(centralwidget);
        emptyLabel_2->setObjectName(QStringLiteral("emptyLabel_2"));

        horizontalLayout_2->addWidget(emptyLabel_2);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        mailList = new QListWidget(splitter);
        mailList->setObjectName(QStringLiteral("mailList"));
        splitter->addWidget(mailList);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setVerticalSpacing(2);
        toLabel = new QLabel(layoutWidget);
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

        to = new QLineEdit(layoutWidget);
        to->setObjectName(QStringLiteral("to"));

        formLayout->setWidget(0, QFormLayout::FieldRole, to);

        ccLabel = new QLabel(layoutWidget);
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

        cc = new QLineEdit(layoutWidget);
        cc->setObjectName(QStringLiteral("cc"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cc);

        bccLabel = new QLabel(layoutWidget);
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

        bcc = new QLineEdit(layoutWidget);
        bcc->setObjectName(QStringLiteral("bcc"));

        formLayout->setWidget(2, QFormLayout::FieldRole, bcc);

        titleLabel = new QLabel(layoutWidget);
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

        title = new QLineEdit(layoutWidget);
        title->setObjectName(QStringLiteral("title"));

        formLayout->setWidget(3, QFormLayout::FieldRole, title);

        attachedFileList = new QListWidget(layoutWidget);
        attachedFileList->setObjectName(QStringLiteral("attachedFileList"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(attachedFileList->sizePolicy().hasHeightForWidth());
        attachedFileList->setSizePolicy(sizePolicy5);
        attachedFileList->setMinimumSize(QSize(80, 27));
        attachedFileList->setMaximumSize(QSize(500, 82));

        formLayout->setWidget(4, QFormLayout::FieldRole, attachedFileList);

        attachedLabel = new QLabel(layoutWidget);
        attachedLabel->setObjectName(QStringLiteral("attachedLabel"));
        attachedLabel->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, attachedLabel);


        verticalLayout_3->addLayout(formLayout);

        displayer = new QTextEdit(layoutWidget);
        displayer->setObjectName(QStringLiteral("displayer"));
        displayer->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse|Qt::TextBrowserInteraction|Qt::TextEditable|Qt::TextEditorInteraction|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout_3->addWidget(displayer);

        splitter->addWidget(layoutWidget);

        horizontalLayout_3->addWidget(splitter);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));

        horizontalLayout_3->addLayout(verticalLayout_4);


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
        menuFichier->addAction(actionTransf_rer);
        menuFichier->addAction(actionSupprimer);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
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
        actionAdd->setText(QApplication::translate("MailBox", "Ajouter", 0));
#ifndef QT_NO_TOOLTIP
        actionAdd->setToolTip(QApplication::translate("MailBox", "Ajouter un compte ", 0));
#endif // QT_NO_TOOLTIP
        actionAdd->setShortcut(QApplication::translate("MailBox", "Ctrl+A", 0));
        actionAlert->setText(QApplication::translate("MailBox", "alert", 0));
        actionCancel_confirmed->setText(QApplication::translate("MailBox", "cancel_confirmed", 0));
#ifndef QT_NO_TOOLTIP
        inbox->setToolTip(QApplication::translate("MailBox", "<html><head/><body><p>Ceci est votre boite de r\303\251ception</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
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
        repAllButton->setText(QApplication::translate("MailBox", "R\303\251p \303\240 tous", 0));
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
