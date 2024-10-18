#ifndef LOGDIALOG_H
#define LOGDIALOG_H

#include <QDialog>

namespace Ui {
class logDialog;
}

class logDialog : public QDialog
{
    Q_OBJECT

public:
    explicit logDialog(QWidget *parent = nullptr);
    ~logDialog();

private:
    Ui::logDialog *ui;

signals:
    void swtichreg();
};

#endif // LOGDIALOG_H
