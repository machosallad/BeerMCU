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
    Q_PROPERTY(bool isDiscovering READ isDiscovering WRITE setIsDiscovering NOTIFY isDiscoveringChanged)
    Q_PROPERTY(DbManager* dbManager READ dbManager CONSTANT)
public:
    explicit Backend(QObject *parent = 0);

    bool isRunnning() const;
    DbManager *dbManager() const;

    UserHandler *userHandler() const;

    bool isDiscovering() const;

signals:
    void isRunnningChanged(bool isRunnning);
    void isDiscoveringChanged(bool arg);

public slots:
    void setIsRunnning(bool isRunnning);
    void startStopServer();
    void startStopDiscover();
    void setIsDiscovering(bool arg);

private:
    UdpAnnouncer *m_udpAnnouncer;
    MyTcpServer *m_tcpServer;
    DbManager *m_dbManager;
    UserHandler *m_userHandler;
    bool m_isRunnning;
    bool m_isDiscovering;
};

#endif // BACKEND_H
