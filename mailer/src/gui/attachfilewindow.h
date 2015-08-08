#ifndef ATTACHFILEWINDOW_H
#define ATTACHFILEWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QListWidget>
#include <QtGui>
#include <QtCore>

namespace Ui {
class AttachFileWindow;
}

class AttachFileWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AttachFileWindow(QWidget *parent = 0);
    ~AttachFileWindow();

signals:
    void sendFileToMail(QString);

private slots:
    void on_folderList_itemDoubleClicked(QListWidgetItem *item);

    void on_folderList_itemClicked(QListWidgetItem *item);

    void onBackButtonClicked();

    void onGoButtonClicked();

    void accessToFolder();

    void displayPathContent(QString str);

    void showDetails(QListWidgetItem *item);

    void addFile();

    void on_contentList_itemDoubleClicked(QListWidgetItem *item);

    void openHelper();

private:
    Ui::AttachFileWindow *ui;
};

#endif // ATTACHFILEWINDOW_H
