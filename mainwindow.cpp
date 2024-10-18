#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _login_dlg = new logDialog(this);
    setCentralWidget(_login_dlg);

    //创建注册和登录界面的连接
    connect(_login_dlg, &logDialog::swtichreg, this, &MainWindow::slotswitchreg);
    _reg_dlg = new regDialog(this);

    _login_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    _reg_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    _reg_dlg->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotswitchreg()
{
    setCentralWidget(_reg_dlg);
    _login_dlg->hide();
    _reg_dlg->show();
}
