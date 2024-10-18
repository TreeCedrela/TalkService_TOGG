#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logdialog.h"
#include "regdialog.h"
/******************************************************************************
 *
 * @file       mainwindow.h
 * @brief      主窗口
 *
 * @author     树椿千代
 * @date       2024/10/13
 * @history
 *****************************************************************************/
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void slotswitchreg();
private:
    Ui::MainWindow *ui;
    logDialog *_login_dlg;
    regDialog *_reg_dlg;
};
#endif // MAINWINDOW_H
