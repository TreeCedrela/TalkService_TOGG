#include "mainwindow.h"
#include <QFile>
#include <QApplication>
#include "global.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/style/style/stylesheet.qss");
    if(qss.open(QFile::ReadOnly)){
        qDebug("Open success");
        QString style = qss.readAll();
        a.setStyleSheet(style);
        qss.close();
    }else{
        qDebug("Open failed");
    }

    QString filename = "config.ini";
    QString app_path = QCoreApplication::applicationDirPath();
    QString config_path = QDir::toNativeSeparators(app_path + QDir::separator() + "bin" + QDir::separator() + filename);
    QSettings settings(config_path, QSettings::IniFormat);
    QString gate_host = settings.value("GateServer/host").toString();
    QString gate_port = settings.value("GateServer/port").toString();
    gate_url_prefix = "http://" + gate_host + ":" + gate_port;

    MainWindow w;
    w.show();
    return a.exec();
}
