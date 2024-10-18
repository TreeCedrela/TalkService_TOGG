#ifndef HTTPMGR_H
#define HTTPMGR_H
#include "singleton.h"
#include <QString>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>

class Httpmgr:public QObject, public Singleton<Httpmgr>, std::enable_shared_from_this<Httpmgr>
{
    Q_OBJECT
public:
    ~Httpmgr();
private:
    friend class Singleton<Httpmgr>;
    Httpmgr();
    QNetworkAccessManager _manager;
    void PostHttpReq(QUrl url, QJsonObject json, RedId req_id, Modules mod);
private slots:
    void slot_http_finish(RedId id, QString res, ErrorCodes err, Modules mod);
signals:
    void sig_http_finish(RedId id, QString res, ErrorCodes err, Modules mod);
};

#endif // HTTPMGR_H
