#ifndef ATTACHFILEWINDOW_H
#define ATTACHFILEWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QListWidget>
#include <QDir>
#include <QtGui>
#include <QtCore>

namespace Ui {
class AttachFileWindow;
}

class AttachFileWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AttachFileWindow(QWidget *parent = 0,
                              QString windowType = "",
                              QStringList mailDetails = {""});
    ~AttachFileWindow();

public slots:
    void closeMe();

private:
    QString type;
    QStringList mail;

signals:
    void sendFileToMail(QString);

private slots:
    void on_folderList_itemDoubleClicked(QListWidgetItem *item);
    void on_folderList_itemClicked(QListWidgetItem *item);
    void accessToFolder();
    void findFile(QString);
    void displayName(QListWidgetItem *);
    void displayPathContent(QString str);
    void displayHelper();
    void showDetails(QListWidgetItem *item);
    void objStyle();
    void addFile();
    void saveConfirmed();
    void onFileDoubleClicked(QListWidgetItem *item);
    void connectWidgets();

private:
    Ui::AttachFileWindow *ui;
};

#endif // ATTACHFILEWINDOW_H
