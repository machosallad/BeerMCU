#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include "udpannouncer.h"
#include "mytcpserver.h"
#include "dbmanager.h"
class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isRunnning READ isRunnning WRITE setIsRunnning NOTIFY isRunnningChanged)
    Q_PROPERTY(DbManager* dbManager READ dbManager CONSTANT)
public:
    explicit Backend(QObject *parent = 0);

    bool isRunnning() const;

    DbManager *dbManager() const;

signals:
    void isRunnningChanged(bool isRunnning);

public slots:

    void setIsRunnning(bool isRunnning);
    void startStopServer();

private:
    UdpAnnouncer *m_udpAnnouncer;
    MyTcpServer *m_tcpServer;
    DbManager *m_dbManager;
    bool m_isRunnning;
};

#endif // BACKEND_H
