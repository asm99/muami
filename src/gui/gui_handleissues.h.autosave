#ifndef HANDLEISSUES_H
#define HANDLEISSUES_H

#include <QDialog>
#include <QDesktopWidget>

namespace Ui {
class HandleIssues;
}

class HandleIssues : public QDialog
{
    Q_OBJECT

public:
    explicit HandleIssues(QWidget *parent = 0,
                          QString str = "",
                          QString type = "");
    ~HandleIssues();

private slots:
    void on_ouiButton_clicked();
    void on_okButton_clicked();
    void on_nonButton_clicked();

private:
    Ui::HandleIssues *ui;
};

#endif // HANDLEISSUES_H
