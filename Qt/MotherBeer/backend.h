#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include "udpannouncer.h"
#include "mytcpserver.h"
class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isRunnning READ isRunnning WRITE setIsRunnning NOTIFY isRunnningChanged)
public:
    explicit Backend(QObject *parent = 0);

    bool isRunnning() const;

signals:
    void isRunnningChanged(bool isRunnning);

public slots:

    void setIsRunnning(bool isRunnning);
    void startStopServer();

private:
    UdpAnnouncer *m_udpAnnouncer;
    MyTcpServer *m_tcpServer;
    bool m_isRunnning;
};

#endif // BACKEND_H
