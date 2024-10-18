#include "regdialog.h"
#include "ui_regdialog.h"
#include "global.h"

regDialog::regDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::regDialog)
{
    ui->setupUi(this);
    ui->pass_lineEdit->setEchoMode(QLineEdit::Password);
    ui->rpasslineEdit->setEchoMode(QLineEdit::Password);
    ui->err_tip->setProperty("state","normal");
    repolish(ui->err_tip);
}

regDialog::~regDialog()
{
    delete ui;
}

void regDialog::on_get_Button_clicked()
{
    auto email = ui->email_lineEdit->text();
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch();
    if(match){
        //发送验证码
    }else{
        showTips(tr("邮箱地址不正确"),false);
    }
}

void regDialog::showTips(QString str, bool b_ok)
{
    if(b_ok){
        ui->err_tip->setProperty("state","normal");
    }else{
        ui->err_tip->setProperty("state","error");
    }
    ui->err_tip->setText(str);
    repolish(ui->err_tip);
}




