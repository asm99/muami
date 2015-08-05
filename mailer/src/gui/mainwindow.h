#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_mailBox_clicked();

    void on_newMail_clicked();

    void on_actionQuitter_triggered();

    void on_actionNouveau_courrier_triggered();

    void on_actionBoite_de_r_ception_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
