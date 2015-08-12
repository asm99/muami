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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *attachedLabel;
    QListWidget *attachedFiles;
    QVBoxLayout *verticalLayout_2;
    QPushButton *addressBookButton;
    QPushButton *closeAddressBook;
    QPushButton *attachButton;
    QPushButton *deleteFile;
    QFormLayout *formLayout;
    QLabel *toLabel;
    QLineEdit *to;
    QLabel *ccLabel;
    QLineEdit *cc;
    QLabel *bccLabel;
    QLineEdit *bcc;
    QLabel *titleLabel;
    QLineEdit *title;
    QLabel *messageLabel;
    QTextEdit *message;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *sendButton;
    QPushButton *replyButton;
    QPushButton *replyAllButton;
    QPushButton *transferButton;
    QPushButton *deleteButton;
    QPushButton *cancelButton;
    QPushButton *saveButton;
    QPushButton *closeButton;
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
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        attachedLabel = new QLabel(centralwidget);
        attachedLabel->setObjectName(QStringLiteral("attachedLabel"));
        attachedLabel->setMinimumSize(QSize(0, 0));
        attachedLabel->setMaximumSize(QSize(50, 16777215));
        attachedLabel->setFont(font);

        horizontalLayout->addWidget(attachedLabel);

        attachedFiles = new QListWidget(centralwidget);
        attachedFiles->setObjectName(QStringLiteral("attachedFiles"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(30);
        sizePolicy.setHeightForWidth(attachedFiles->sizePolicy().hasHeightForWidth());
        attachedFiles->setSizePolicy(sizePolicy);
        attachedFiles->setMinimumSize(QSize(0, 30));
        attachedFiles->setMaximumSize(QSize(16777215, 120));

        horizontalLayout->addWidget(attachedFiles);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        addressBookButton = new QPushButton(centralwidget);
        addressBookButton->setObjectName(QStringLiteral("addressBookButton"));
        addressBookButton->setMaximumSize(QSize(226, 16777215));

        verticalLayout_2->addWidget(addressBookButton);

        closeAddressBook = new QPushButton(centralwidget);
        closeAddressBook->setObjectName(QStringLiteral("closeAddressBook"));
        closeAddressBook->setMaximumSize(QSize(226, 16777215));

        verticalLayout_2->addWidget(closeAddressBook);

        attachButton = new QPushButton(centralwidget);
        attachButton->setObjectName(QStringLiteral("attachButton"));
        attachButton->setMaximumSize(QSize(226, 16777215));

        verticalLayout_2->addWidget(attachButton);

        deleteFile = new QPushButton(centralwidget);
        deleteFile->setObjectName(QStringLiteral("deleteFile"));
        deleteFile->setMaximumSize(QSize(226, 16777215));

        verticalLayout_2->addWidget(deleteFile);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        toLabel = new QLabel(centralwidget);
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

        to = new QLineEdit(centralwidget);
        to->setObjectName(QStringLiteral("to"));

        formLayout->setWidget(0, QFormLayout::FieldRole, to);

        ccLabel = new QLabel(centralwidget);
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

        cc = new QLineEdit(centralwidget);
        cc->setObjectName(QStringLiteral("cc"));

        formLayout->setWidget(1, QFormLayout::FieldRole, cc);

        bccLabel = new QLabel(centralwidget);
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

        bcc = new QLineEdit(centralwidget);
        bcc->setObjectName(QStringLiteral("bcc"));

        formLayout->setWidget(2, QFormLayout::FieldRole, bcc);

        titleLabel = new QLabel(centralwidget);
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

        formLayout->setWidget(11, QFormLayout::LabelRole, titleLabel);

        title = new QLineEdit(centralwidget);
        title->setObjectName(QStringLiteral("title"));

        formLayout->setWidget(11, QFormLayout::FieldRole, title);

        messageLabel = new QLabel(centralwidget);
        messageLabel->setObjectName(QStringLiteral("messageLabel"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        messageLabel->setPalette(palette4);

        formLayout->setWidget(12, QFormLayout::LabelRole, messageLabel);

        message = new QTextEdit(centralwidget);
        message->setObjectName(QStringLiteral("message"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(message->sizePolicy().hasHeightForWidth());
        message->setSizePolicy(sizePolicy1);

        formLayout->setWidget(12, QFormLayout::FieldRole, message);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        sendButton->setPalette(palette5);

        horizontalLayout_2->addWidget(sendButton);

        replyButton = new QPushButton(centralwidget);
        replyButton->setObjectName(QStringLiteral("replyButton"));

        horizontalLayout_2->addWidget(replyButton);

        replyAllButton = new QPushButton(centralwidget);
        replyAllButton->setObjectName(QStringLiteral("replyAllButton"));

        horizontalLayout_2->addWidget(replyAllButton);

        transferButton = new QPushButton(centralwidget);
        transferButton->setObjectName(QStringLiteral("transferButton"));

        horizontalLayout_2->addWidget(transferButton);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout_2->addWidget(deleteButton);

        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        cancelButton->setPalette(palette6);

        horizontalLayout_2->addWidget(cancelButton);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        saveButton->setPalette(palette7);

        horizontalLayout_2->addWidget(saveButton);

        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout_2->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout_2);

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
        attachedLabel->setText(QApplication::translate("WriteMail", "Pi\303\250ces\n"
"jointes", 0));
#ifndef QT_NO_TOOLTIP
        addressBookButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>Ouvre le carnet d'adresses</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        addressBookButton->setText(QApplication::translate("WriteMail", "Carnet d'adresses", 0));
        closeAddressBook->setText(QApplication::translate("WriteMail", "Fermer le carnet", 0));
#ifndef QT_NO_TOOLTIP
        attachButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>Attacher un fichier au courrier \303\240 exp\303\251dier</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        attachButton->setText(QApplication::translate("WriteMail", "Attacher une pi\303\250ce jointe", 0));
        deleteFile->setText(QApplication::translate("WriteMail", "Supprimer la pi\303\250ce jointe", 0));
        toLabel->setText(QApplication::translate("WriteMail", "<html><head/><body><p align=\"right\"><span style=\" font-weight:600;\">\303\240 :</span></p></body></html>", 0));
        to->setPlaceholderText(QString());
        ccLabel->setText(QApplication::translate("WriteMail", "<html><head/><body><p align=\"right\"><span style=\" font-weight:600;\">cc :</span></p></body></html>", 0));
        cc->setPlaceholderText(QString());
        bccLabel->setText(QApplication::translate("WriteMail", "<html><head/><body><p align=\"right\"><span style=\" font-weight:600;\">bcc :</span></p></body></html>", 0));
        bcc->setPlaceholderText(QString());
        titleLabel->setText(QApplication::translate("WriteMail", "<html><head/><body><p align=\"right\"><span style=\" font-weight:600;\">objet :</span></p></body></html>", 0));
        title->setPlaceholderText(QString());
        messageLabel->setText(QApplication::translate("WriteMail", "<html><head/><body><p align=\"right\"><span style=\" font-weight:600;\">corps :</span></p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        sendButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>Envoyer le courrier aux destinataires</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        sendButton->setText(QApplication::translate("WriteMail", "Envoyer", 0));
#ifndef QT_NO_TOOLTIP
        replyButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>R\303\251pondre \303\240 l'exp\303\251diteur du courrier</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        replyButton->setText(QApplication::translate("WriteMail", "R\303\251pondre", 0));
#ifndef QT_NO_TOOLTIP
        replyAllButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>R\303\251pondre \303\240 l'exp\303\251diteur ainsi qu'\303\240 tous les destinataires en copie du courrier</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        replyAllButton->setText(QApplication::translate("WriteMail", "Rep. \303\240 tous", 0));
#ifndef QT_NO_TOOLTIP
        transferButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>Transmettre le courrier \303\240 quelqu'un d'autre que l'exp\303\251diteur</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        transferButton->setText(QApplication::translate("WriteMail", "Transf\303\251rer", 0));
#ifndef QT_NO_TOOLTIP
        deleteButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>Supprimer le courrier</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        deleteButton->setText(QApplication::translate("WriteMail", "Supprimer", 0));
#ifndef QT_NO_TOOLTIP
        cancelButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>Annuler les modifications et revenir \303\240 la boite</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        cancelButton->setText(QApplication::translate("WriteMail", "Annuler", 0));
#ifndef QT_NO_TOOLTIP
        saveButton->setToolTip(QApplication::translate("WriteMail", "<html><head/><body><p>Sauvegarder une copie du courrier</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        saveButton->setText(QApplication::translate("WriteMail", "Sauvegarder", 0));
        closeButton->setText(QApplication::translate("WriteMail", "Fermer", 0));
        menuFichier->setTitle(QApplication::translate("WriteMail", "Fichier", 0));
        menuEdition->setTitle(QApplication::translate("WriteMail", "Edition", 0));
    } // retranslateUi

};

namespace Ui {
    class WriteMail: public Ui_WriteMail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WRITEMAIL_H
