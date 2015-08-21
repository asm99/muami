/********************************************************************************
** Form generated from reading UI file 'writemail.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WRITEMAIL_H
#define UI_WRITEMAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WriteMail
{
public:
    QAction *actionCopier;
    QAction *actionColler;
    QAction *actionCouper;
    QAction *actionSupprimer;
    QAction *actionSend;
    QAction *actionReply;
    QAction *actionReplyAll;
    QAction *actionTransfer;
    QAction *actionDelete;
    QAction *actionCancel;
    QAction *actionSave;
    QAction *actionClose;
    QAction *actionAttach;
    QAction *actionEnvoyer;
    QAction *actionR_pondre;
    QAction *actionR_pondre_tous;
    QAction *actionTransf_rer;
    QAction *actionAttacher_des_pi_ces_jointes;
    QAction *actionFermer;
    QAction *actionDeleteAddedFile;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *closeButton;
    QPushButton *saveButton;
    QPushButton *sendButton;
    QPushButton *replyButton;
    QPushButton *replyAllButton;
    QPushButton *transferButton;
    QPushButton *cancelButton;
    QPushButton *deleteButton;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *to;
    QLineEdit *cc;
    QLineEdit *bcc;
    QLineEdit *title;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addressBookButton;
    QPushButton *attachButton;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *attachedFiles;
    QPushButton *deleteFile;
    QTextEdit *message;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuEdition;

    void setupUi(QMainWindow *WriteMail)
    {
        if (WriteMail->objectName().isEmpty())
            WriteMail->setObjectName(QStringLiteral("WriteMail"));
        WriteMail->resize(810, 609);
        actionCopier = new QAction(WriteMail);
        actionCopier->setObjectName(QStringLiteral("actionCopier"));
        actionColler = new QAction(WriteMail);
        actionColler->setObjectName(QStringLiteral("actionColler"));
        actionCouper = new QAction(WriteMail);
        actionCouper->setObjectName(QStringLiteral("actionCouper"));
        actionSupprimer = new QAction(WriteMail);
        actionSupprimer->setObjectName(QStringLiteral("actionSupprimer"));
        actionSend = new QAction(WriteMail);
        actionSend->setObjectName(QStringLiteral("actionSend"));
        actionReply = new QAction(WriteMail);
        actionReply->setObjectName(QStringLiteral("actionReply"));
        actionReplyAll = new QAction(WriteMail);
        actionReplyAll->setObjectName(QStringLiteral("actionReplyAll"));
        actionTransfer = new QAction(WriteMail);
        actionTransfer->setObjectName(QStringLiteral("actionTransfer"));
        actionDelete = new QAction(WriteMail);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionCancel = new QAction(WriteMail);
        actionCancel->setObjectName(QStringLiteral("actionCancel"));
        actionSave = new QAction(WriteMail);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionClose = new QAction(WriteMail);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionAttach = new QAction(WriteMail);
        actionAttach->setObjectName(QStringLiteral("actionAttach"));
        actionEnvoyer = new QAction(WriteMail);
        actionEnvoyer->setObjectName(QStringLiteral("actionEnvoyer"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        actionEnvoyer->setFont(font);
        actionR_pondre = new QAction(WriteMail);
        actionR_pondre->setObjectName(QStringLiteral("actionR_pondre"));
        actionR_pondre->setFont(font);
        actionR_pondre_tous = new QAction(WriteMail);
        actionR_pondre_tous->setObjectName(QStringLiteral("actionR_pondre_tous"));
        actionR_pondre_tous->setFont(font);
        actionTransf_rer = new QAction(WriteMail);
        actionTransf_rer->setObjectName(QStringLiteral("actionTransf_rer"));
        actionTransf_rer->setFont(font);
        actionAttacher_des_pi_ces_jointes = new QAction(WriteMail);
        actionAttacher_des_pi_ces_jointes->setObjectName(QStringLiteral("actionAttacher_des_pi_ces_jointes"));
        actionAttacher_des_pi_ces_jointes->setFont(font);
        actionFermer = new QAction(WriteMail);
        actionFermer->setObjectName(QStringLiteral("actionFermer"));
        actionDeleteAddedFile = new QAction(WriteMail);
        actionDeleteAddedFile->setObjectName(QStringLiteral("actionDeleteAddedFile"));
        actionDeleteAddedFile->setFont(font);
        centralwidget = new QWidget(WriteMail);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout_4 = new QHBoxLayout(centralwidget);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(closeButton->sizePolicy().hasHeightForWidth());
        closeButton->setSizePolicy(sizePolicy);
        closeButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/res/browser-close-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon);
        closeButton->setIconSize(QSize(40, 40));

        verticalLayout_3->addWidget(closeButton);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        sizePolicy.setHeightForWidth(saveButton->sizePolicy().hasHeightForWidth());
        saveButton->setSizePolicy(sizePolicy);
        saveButton->setMaximumSize(QSize(50, 16777215));
        QPalette palette;
        QBrush brush(QColor(220, 224, 227, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush1(QColor(159, 158, 158, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        saveButton->setPalette(palette);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icon/res/stiffy.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveButton->setIcon(icon1);
        saveButton->setIconSize(QSize(40, 40));

        verticalLayout_3->addWidget(saveButton);

        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sizePolicy.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy);
        sendButton->setMaximumSize(QSize(50, 16777215));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        sendButton->setPalette(palette1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icon/res/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendButton->setIcon(icon2);
        sendButton->setIconSize(QSize(40, 40));

        verticalLayout_3->addWidget(sendButton);

        replyButton = new QPushButton(centralwidget);
        replyButton->setObjectName(QStringLiteral("replyButton"));
        sizePolicy.setHeightForWidth(replyButton->sizePolicy().hasHeightForWidth());
        replyButton->setSizePolicy(sizePolicy);
        replyButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icon/res/reply.png"), QSize(), QIcon::Normal, QIcon::Off);
        replyButton->setIcon(icon3);
        replyButton->setIconSize(QSize(40, 40));

        verticalLayout_3->addWidget(replyButton);

        replyAllButton = new QPushButton(centralwidget);
        replyAllButton->setObjectName(QStringLiteral("replyAllButton"));
        sizePolicy.setHeightForWidth(replyAllButton->sizePolicy().hasHeightForWidth());
        replyAllButton->setSizePolicy(sizePolicy);
        replyAllButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icon/res/reply-all.png"), QSize(), QIcon::Normal, QIcon::Off);
        replyAllButton->setIcon(icon4);
        replyAllButton->setIconSize(QSize(40, 40));

        verticalLayout_3->addWidget(replyAllButton);

        transferButton = new QPushButton(centralwidget);
        transferButton->setObjectName(QStringLiteral("transferButton"));
        sizePolicy.setHeightForWidth(transferButton->sizePolicy().hasHeightForWidth());
        transferButton->setSizePolicy(sizePolicy);
        transferButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icon/res/transfer.png"), QSize(), QIcon::Normal, QIcon::Off);
        transferButton->setIcon(icon5);
        transferButton->setIconSize(QSize(40, 40));

        verticalLayout_3->addWidget(transferButton);

        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        sizePolicy.setHeightForWidth(cancelButton->sizePolicy().hasHeightForWidth());
        cancelButton->setSizePolicy(sizePolicy);
        cancelButton->setMaximumSize(QSize(50, 16777215));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        cancelButton->setPalette(palette2);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icon/res/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancelButton->setIcon(icon6);
        cancelButton->setIconSize(QSize(40, 40));

        verticalLayout_3->addWidget(cancelButton);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);
        deleteButton->setMaximumSize(QSize(50, 16777215));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icon/res/bin-3.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteButton->setIcon(icon7);
        deleteButton->setIconSize(QSize(40, 40));

        verticalLayout_3->addWidget(deleteButton);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        to = new QLineEdit(centralwidget);
        to->setObjectName(QStringLiteral("to"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(to->sizePolicy().hasHeightForWidth());
        to->setSizePolicy(sizePolicy1);
        to->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(to);

        cc = new QLineEdit(centralwidget);
        cc->setObjectName(QStringLiteral("cc"));
        sizePolicy1.setHeightForWidth(cc->sizePolicy().hasHeightForWidth());
        cc->setSizePolicy(sizePolicy1);
        cc->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(cc);

        bcc = new QLineEdit(centralwidget);
        bcc->setObjectName(QStringLiteral("bcc"));
        sizePolicy1.setHeightForWidth(bcc->sizePolicy().hasHeightForWidth());
        bcc->setSizePolicy(sizePolicy1);
        bcc->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(bcc);

        title = new QLineEdit(centralwidget);
        title->setObjectName(QStringLiteral("title"));
        sizePolicy1.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy1);
        title->setMaximumSize(QSize(16777215, 25));

        verticalLayout->addWidget(title);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        addressBookButton = new QPushButton(centralwidget);
        addressBookButton->setObjectName(QStringLiteral("addressBookButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(addressBookButton->sizePolicy().hasHeightForWidth());
        addressBookButton->setSizePolicy(sizePolicy2);
        addressBookButton->setMaximumSize(QSize(50, 50));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icon/res/address-book-2.png"), QSize(), QIcon::Normal, QIcon::Off);
        addressBookButton->setIcon(icon8);
        addressBookButton->setIconSize(QSize(35, 35));

        verticalLayout_2->addWidget(addressBookButton);

        attachButton = new QPushButton(centralwidget);
        attachButton->setObjectName(QStringLiteral("attachButton"));
        sizePolicy2.setHeightForWidth(attachButton->sizePolicy().hasHeightForWidth());
        attachButton->setSizePolicy(sizePolicy2);
        attachButton->setMaximumSize(QSize(50, 50));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icon/res/document-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        attachButton->setIcon(icon9);
        attachButton->setIconSize(QSize(35, 35));

        verticalLayout_2->addWidget(attachButton);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        attachedFiles = new QListWidget(centralwidget);
        attachedFiles->setObjectName(QStringLiteral("attachedFiles"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(attachedFiles->sizePolicy().hasHeightForWidth());
        attachedFiles->setSizePolicy(sizePolicy3);
        attachedFiles->setMinimumSize(QSize(0, 50));
        attachedFiles->setMaximumSize(QSize(16777215, 100));
        attachedFiles->setSizeIncrement(QSize(0, 25));

        horizontalLayout_2->addWidget(attachedFiles);

        deleteFile = new QPushButton(centralwidget);
        deleteFile->setObjectName(QStringLiteral("deleteFile"));
        sizePolicy2.setHeightForWidth(deleteFile->sizePolicy().hasHeightForWidth());
        deleteFile->setSizePolicy(sizePolicy2);
        deleteFile->setMaximumSize(QSize(50, 50));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icon/res/document-remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteFile->setIcon(icon10);
        deleteFile->setIconSize(QSize(35, 35));

        horizontalLayout_2->addWidget(deleteFile);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_4);

        message = new QTextEdit(centralwidget);
        message->setObjectName(QStringLiteral("message"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(message->sizePolicy().hasHeightForWidth());
        message->setSizePolicy(sizePolicy4);

        verticalLayout_5->addWidget(message);


        horizontalLayout_3->addLayout(verticalLayout_5);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        WriteMail->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WriteMail);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 810, 25));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuEdition = new QMenu(menubar);
        menuEdition->setObjectName(QStringLiteral("menuEdition"));
        WriteMail->setMenuBar(menubar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuEdition->menuAction());
        menuFichier->addAction(actionR_pondre);
        menuFichier->addAction(actionR_pondre_tous);
        menuFichier->addAction(actionTransf_rer);
        menuFichier->addAction(actionEnvoyer);
        menuFichier->addSeparator();
        menuFichier->addAction(actionAttacher_des_pi_ces_jointes);
        menuFichier->addAction(actionDeleteAddedFile);
        menuFichier->addSeparator();
        menuFichier->addAction(actionFermer);
        menuEdition->addAction(actionCopier);
        menuEdition->addAction(actionCouper);
        menuEdition->addAction(actionColler);
        menuEdition->addAction(actionSupprimer);

        retranslateUi(WriteMail);

        QMetaObject::connectSlotsByName(WriteMail);
    } // setupUi

    void retranslateUi(QMainWindow *WriteMail)
    {
        WriteMail->setWindowTitle(QApplication::translate("WriteMail", "MainWindow", 0));
        actionCopier->setText(QApplication::translate("WriteMail", "Copier", 0));
        actionColler->setText(QApplication::translate("WriteMail", "Coller", 0));
        actionCouper->setText(QApplication::translate("WriteMail", "Couper", 0));
        actionSupprimer->setText(QApplication::translate("WriteMail", "Supprimer", 0));
        actionSend->setText(QApplication::translate("WriteMail", "send", 0));
        actionReply->setText(QApplication::translate("WriteMail", "reply", 0));
        actionReplyAll->setText(QApplication::translate("WriteMail", "replyAll", 0));
        actionTransfer->setText(QApplication::translate("WriteMail", "transfer", 0));
        actionDelete->setText(QApplication::translate("WriteMail", "delete", 0));
        actionCancel->setText(QApplication::translate("WriteMail", "cancel", 0));
        actionSave->setText(QApplication::translate("WriteMail", "save", 0));
        actionClose->setText(QApplication::translate("WriteMail", "close", 0));
        actionAttach->setText(QApplication::translate("WriteMail", "attach", 0));
        actionEnvoyer->setText(QApplication::translate("WriteMail", "Envoyer", 0));
        actionEnvoyer->setShortcut(QApplication::translate("WriteMail", "Ctrl+E", 0));
        actionR_pondre->setText(QApplication::translate("WriteMail", "R\303\251pondre", 0));
        actionR_pondre->setShortcut(QApplication::translate("WriteMail", "Ctrl+R", 0));
        actionR_pondre_tous->setText(QApplication::translate("WriteMail", "R\303\251pondre \303\240 tous", 0));
        actionR_pondre_tous->setShortcut(QApplication::translate("WriteMail", "Ctrl+Shift+R", 0));
        actionTransf_rer->setText(QApplication::translate("WriteMail", "Transf\303\251rer", 0));
        actionTransf_rer->setShortcut(QApplication::translate("WriteMail", "Ctrl+T", 0));
        actionAttacher_des_pi_ces_jointes->setText(QApplication::translate("WriteMail", "Attacher des pi\303\250ces jointes", 0));
        actionAttacher_des_pi_ces_jointes->setShortcut(QApplication::translate("WriteMail", "Ctrl+A", 0));
        actionFermer->setText(QApplication::translate("WriteMail", "Fermer", 0));
        actionDeleteAddedFile->setText(QApplication::translate("WriteMail", "Supprimer la pi\303\250ce jointe", 0));
        closeButton->setText(QString());
        closeButton->setShortcut(QApplication::translate("WriteMail", "Ctrl+Q", 0));
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>Sauvegarder une copie du courrier</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QString());
        saveButton->setShortcut(QApplication::translate("WriteMail", "Ctrl+S", 0));
#ifndef QT_NO_TOOLTIP
        sendButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>Envoyer le courrier aux destinataires</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sendButton->setText(QString());
        sendButton->setShortcut(QApplication::translate("WriteMail", "Ctrl+Shift+S", 0));
#ifndef QT_NO_TOOLTIP
        replyButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>R\303\251pondre \303\240 l'exp\303\251diteur du courrier</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        replyButton->setText(QString());
        replyButton->setShortcut(QApplication::translate("WriteMail", "Ctrl+R", 0));
#ifndef QT_NO_TOOLTIP
        replyAllButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>R\303\251pondre \303\240 l'exp\303\251diteur ainsi qu'\303\240 tous les destinataires en copie du courrier</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        replyAllButton->setText(QString());
        replyAllButton->setShortcut(QApplication::translate("WriteMail", "Ctrl+Shift+R", 0));
#ifndef QT_NO_TOOLTIP
        transferButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>Transmettre le courrier \303\240 quelqu'un d'autre que l'exp\303\251diteur</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        transferButton->setText(QString());
        transferButton->setShortcut(QApplication::translate("WriteMail", "Ctrl+T", 0));
#ifndef QT_NO_TOOLTIP
        cancelButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>Annuler les modifications et revenir \303\240 la boite</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        cancelButton->setText(QString());
        cancelButton->setShortcut(QApplication::translate("WriteMail", "Esc", 0));
#ifndef QT_NO_TOOLTIP
        deleteButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>Supprimer le courrier</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        deleteButton->setText(QString());
        deleteButton->setShortcut(QApplication::translate("WriteMail", "Ctrl+D", 0));
        to->setPlaceholderText(QApplication::translate("WriteMail", "Destinataire", 0));
        cc->setPlaceholderText(QApplication::translate("WriteMail", "Destinataire en copie", 0));
        bcc->setPlaceholderText(QApplication::translate("WriteMail", "Destinataire cach\303\251", 0));
        title->setPlaceholderText(QApplication::translate("WriteMail", "Objet", 0));
#ifndef QT_NO_TOOLTIP
        addressBookButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>Ouvre le carnet d'adresses</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        addressBookButton->setText(QString());
#ifndef QT_NO_TOOLTIP
        attachButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>Attacher un fichier au courrier \303\240 exp\303\251dier</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        attachButton->setText(QString());
        deleteFile->setText(QString());
        menuFichier->setTitle(QApplication::translate("WriteMail", "Fichier", 0));
        menuEdition->setTitle(QApplication::translate("WriteMail", "Edition", 0));
    } // retranslateUi

};

namespace Ui {
    class WriteMail: public Ui_WriteMail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRITEMAIL_H
