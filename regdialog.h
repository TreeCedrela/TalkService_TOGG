#ifndef REGDIALOG_H
#define REGDIALOG_H

#include <QDialog>

namespace Ui {
class regDialog;
}

class regDialog : public QDialog
{
    Q_OBJECT

public:
    explicit regDialog(QWidget *parent = nullptr);
    ~regDialog();

private slots:
    void on_get_Button_clicked();

private:
    void showTips(QString str, bool b_ok);
    Ui::regDialog *ui;
};

#endif // REGDIALOG_H
