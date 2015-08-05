#include <QApplication>
#include "src/gui/mainwindow.h"
#include "src/gui/mailbox.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(
        "QMainWindow    {background-color: #333536;\
                            border-radius:5px}\
\
        QDialog {background-color: #333536;\
                    border:1px solid gray; \
                    border-radius:3px; \
                    color:#DCE0E3;}\
\
        QPushButton {background-color: #DCE0E3;\
                        border:1px solid gray;\
                        border-radius:3px;\
                        color:#333536;}\
\
        QListWidget {background-color: #DCE0E3;\
                        border:1px solid gray;\
                        border-radius:3px}\
\
        QTabWidget  {background-color: #DCE0E3;\
                        border:1px solid gray;\
                        border-radius:3px}\
\
        QTreeWidget {background-color: #DCE0E3;\
                        border:1px solid gray;\
                        border-radius:3px}\
\
        QTextEdit   {background-color: #DCE0E3;\
                        border:1px solid gray;\
                        border-radius:3px}\
\
        QLineEdit   {background-color: #DCE0E3;\
                        border:1px solid gray;\
                        border-radius:3px}\
\
        QLabel  {color: #DCE0E3}\
\
        QDoubleSpinBox {background-color: #DCE0E3;\
                        border:1px solid gray;\
                        border-radius:5px}\
\
        QFontComboBox  {background-color: #DCE0E3;\
                        border:1px solid gray;\
                        border-radius:5px}\
\
        QCheckBox   {color: #DCE0E3}\
\
        QPushButton:hover   {background-color: #333536;\
                                color: #DCE0E3}\
\
        QListWidget::item:hover {background-color: white;\
                                    color: #333536}\
\
        QListWidget::item:selected {background-color: white;\
                                    color: #333536;}\
\
        QTreeWidget::itemBelow:hover {background-color: white;\
                                        color: #333536}");

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf8"));
    MailBox w;
    w.show();
    return a.exec();
}
