#include <QApplication>
#include "src/gui/mailbox.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(
        "QMainWindow    {background:#636b6b;}\
\
         QPushButton {background:#3eacd1;\
                        color:#FFFFFF;\
                        border:0px;\
                        border-bottom:1px solid qlineargradient"
                                     "(spread:pad, x1:0 y1:0, x2:1 y2:0,"
                                     "stop:0 rgba(38, 124, 153, 255), "
                                     "stop:1 rgba(38, 124, 153, 255));}\
\
        QListWidget {background-color: #FFFFFF;"
                    "color:#252b2b;\
                     font-weight:600;\
                         border:0px;\
                         border-bottom:1px solid qlineargradient"
                                         "(spread:pad, x1:0 y1:0, x2:1 y2:0,"
                                         "stop:0 rgba(38, 124, 153, 255), "
                                         "stop:1 rgba(38, 124, 153, 255));}\
\
        QTabWidget  {background-color: #DCE0E3;}\
\
        QTreeWidget {background-color: #FFFFFF;}\
\
        QTextEdit   {background-color: #FFFFFF;\
                        border:0px;\
                        border-bottom:1px solid qlineargradient"
                                        "(spread:pad, x1:0 y1:0, x2:1 y2:0,"
                                        "stop:0 rgba(38, 124, 153, 255), "
                                        "stop:1 rgba(38, 124, 153, 255));}\
\
        QLineEdit   {background-color: #FFFFFF;\
                        border:0px;\
                        border-bottom:1px solid qlineargradient"
                                     "(spread:pad, x1:0 y1:0, x2:1 y2:0,"
                                     "stop:0 rgba(38, 124, 153, 255), "
                                     "stop:1 rgba(38, 124, 153, 255));}\
\
        QLabel  {color: #000000}\
\
        QCheckBox   {color: #DCE0E3}\
\
        QPushButton:hover   {background-color:#8fbac9;\
                                color: #000000}\
\
        QListWidget::item   {border-bottom: 1px solid qlineargradient"
                                           "(spread:pad, x1:0 y1:0, x2:0.8 y2:0,"
                                           "stop:0 rgba(99, 107, 107, 255), "
                                           "stop:1 rgba(99, 107, 107, 255));}\
\
        QListWidget::item:hover {background-color:#8fbac9;\
                                 color: #333536}\
\
        QListWidget::item:selected {background-color: #3eacd1;\
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
