#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include "udpannouncer.h"
#include "mytcpserver.h"
#include "dbmanager.h"
#include "userhandler.h"
class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isRunnning READ isRunnning WRITE setIsRunnning NOTIFY isRunnningChanged)
    Q_PROPERTY(DbManager* dbManager READ dbManager CONSTANT)
public:
    explicit Backend(QObject *parent = 0);

    bool isRunnning() const;
    DbManager *dbManager() const;

    UserHandler *userHandler() const;

signals:
    void isRunnningChanged(bool isRunnning);

public slots:
    void setIsRunnning(bool isRunnning);
    void startStopServer();

private:
    UdpAnnouncer *m_udpAnnouncer;
    MyTcpServer *m_tcpServer;
    DbManager *m_dbManager;
    UserHandler *m_userHandler;
    bool m_isRunnning;
};

#endif // BACKEND_H
