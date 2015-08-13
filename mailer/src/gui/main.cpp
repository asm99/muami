#include <QApplication>
#include "src/gui/mainwindow.h"
#include "src/gui/mailbox.h"
#include "src/gui/login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(
        "QMainWindow    {background-color: #566469;\
                            border-radius:5px}\
\
        QMainWindow    {background: qlineargradient"
                                    "(spread:pad, x1:0 y1:0, x2:1 y2:0, "
                                    "stop:0 rgba(74, 89, 102, 255), "
                                    "stop:1 rgba(226, 236, 243, 255));\
                            border-radius:5px}\
\
        QDialog     {background: qlineargradient"
                                    "(spread:pad, x1:0 y1:0, x2:1 y2:1, "
                                    "stop:0 rgba(84, 90, 95, 255), "
                                    "stop:1 rgba(116, 147, 168, 255));\
                    border:1px solid gray; \
                    border-radius:3px; \
                    color:#DCE0E3;}\
\
        QPushButton {background: qlineargradient"
                                 "(spread:pad, x1:0 y1:0, x2:1 y2:1, "
                                 "stop:0 rgba(135, 139, 143, 255), "
                                 "stop:1 rgba(183, 196, 204, 255));\
                        border:1px solid black;\
                        border-radius:3px;\
                        color:#333536;}\
\
        QListWidget {background-color: #FFFFFF;\
                        border-top:1px solid qlineargradient"
                                      "(spread:pad, x1:0 y1:0, x2:1 y2:0, "
                                      "stop:0 rgba(0, 0, 0, 255), "
                                      "stop:1 rgba(255, 255, 255, 255));\
                        border-left:1px solid qlineargradient"
                                         "(spread:pad, x1:0 y1:0, x2:0 y2:1,"
                                         "stop:0 rgba(0, 0, 0, 255), "
                                         "stop:1 rgba(255, 255, 255, 255));\
                        border-right:1px solid qlineargradient"
                                     "(spread:pad, x1:1 y1:1, x2:1 y2:0.7, "
                                     "stop:0 rgba(0, 0, 0, 255), "
                                     "stop:1 rgba(255, 255, 255, 255));\
                        border-bottom:1px solid qlineargradient"
                                        "(spread:pad, x1:1 y1:1, x2:0.3 y2:1,"
                                        "stop:0 rgba(0, 0, 0, 255), "
                                        "stop:1 rgba(255, 255, 255, 255));\
                        border-radius:1px}\
\
        QTabWidget  {background-color: #DCE0E3;\
                        border:1px solid gray;\
                        border-radius:3px}\
\
        QTreeWidget {background-color: #FFFFFF;\
                        border:1px solid gray;\
                        border-radius:3px}\
\
        QTextEdit   {background-color: #FFFFFF;\
                        border:1px solid gray;\
                        border-radius:3px}\
\
        QLineEdit   {background-color: #FFFFFF;\
                        border:1px solid gray;\
                        border-radius:3px}\
\
        QLabel  {color: #000000}\
\
        QCheckBox   {color: #DCE0E3}\
\
        QPushButton:hover   {background-color: "
                                "qlineargradient"
                                   "(spread:pad, x1:0 y1:0, x2:1 y2:1, "
                                   "stop:0 rgba(148, 161, 168, 255), "
                                   "stop:1 rgba(135, 139, 143, 255));\
                                color: #000000}\
\
        QListWidget::item   {border-bottom: 1px solid qlineargradient"
                                           "(spread:pad, x1:0 y1:0, x2:0.5 y2:0,"
                                           "stop:0 rgba(95, 112, 122, 255), "
                                           "stop:1 rgba(237, 242, 245, 255));}\
\
        QListWidget::item:hover {background-color: "
                                   "qlineargradient"
                                      "(spread:pad, x1:0 y1:0, x2:0.6 y2:0.3, "
                                      "stop:0 rgba(183, 196, 204, 255), "
                                      "stop:1 rgba(255, 255, 255, 255));\
                                 color: #333536}\
\
        QListWidget::item:selected {background-color: #333536;\
                                    color: #FFFFFF;}\
\
        QListWidget::item:selected:hover {background-color: #DCE0E3;\
                                    color: #333536;}\
\
        QTreeWidget::itemBelow:hover {background-color: white;\
                                        color: #333536}");

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
    MailBox w;
    w.show();
    return a.exec();
}
