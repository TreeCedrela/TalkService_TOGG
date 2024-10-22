#ifndef REGDIALOG_H
#define REGDIALOG_H

#include <QDialog>
#include "global.h"

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
    void slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err);
private:
    void initHttpHandlers();
    void showTips(QString str, bool b_ok);
    Ui::regDialog *ui;
    QMap<ReqId, std::function<void(const QJsonObject&)>> _handlers;
};

#endif // REGDIALOG_H
