#include "regdialog.h"
#include "ui_regdialog.h"
#include "global.h"
#include "httpmgr.h"

regDialog::regDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::regDialog)
{
    ui->setupUi(this);
    ui->pass_lineEdit->setEchoMode(QLineEdit::Password);
    ui->rpasslineEdit->setEchoMode(QLineEdit::Password);
    ui->err_tip->setProperty("state","normal");
    repolish(ui->err_tip);
    connect(Httpmgr::GetInstance().get(), &Httpmgr::sig_reg_mod_finish, this, &regDialog::slot_reg_mod_finish);
    initHttpHandlers();
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

void regDialog::slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err)
{
    if(err != ErrorCodes::SUCCESS){
        showTips(tr("网络请求错误"), false);
        return;
    }

    //解析Json字符串 res转化为QByteArray
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    if(jsonDoc.isNull()){
        showTips(tr("json解析失败"), false);
        return;
    }
    if(!jsonDoc.isObject()){
        showTips(tr("json解析失败"), false);
        return;
    }

    _handlers[id](jsonDoc.object());
    return;
}

void regDialog::initHttpHandlers()
{
    //注册获取验证码回调函数
    _handlers.insert(ReqId::ID_GET_VERIFY_CODE, [this](const QJsonObject& jsobj){
        int err = jsobj["error"].toInt();
        if(err != ErrorCodes::SUCCESS){
            showTips(tr("参数错误"), false);
            return;
        }

        auto email = jsobj["email"].toString();
        showTips(tr("验证码已发送到邮箱，注意查收"), true);
        qDebug() << "email is" << email;
    });
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




