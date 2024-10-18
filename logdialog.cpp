#include "logdialog.h"
#include "ui_logdialog.h"

logDialog::logDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::logDialog)
{
    ui->setupUi(this);
    connect(ui->reg_btn, &QPushButton::clicked, this, &logDialog::swtichreg);
}

logDialog::~logDialog()
{
    delete ui;
}
