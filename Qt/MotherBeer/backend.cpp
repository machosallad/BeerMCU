#include "backend.h"

Backend::Backend(QObject *parent) : QObject(parent)
{
    m_udpAnnouncer = new UdpAnnouncer();
    m_tcpServer = new MyTcpServer();
    m_isRunnning = false;
}

bool Backend::isRunnning() const
{
    return m_isRunnning;
}

void Backend::setIsRunnning(bool isRunnning)
{
    if (m_isRunnning == isRunnning)
        return;

    m_isRunnning = isRunnning;
    emit isRunnningChanged(isRunnning);
}

void Backend::startStopServer()
{
    if(m_isRunnning)
    {
        setIsRunnning(false);
        m_udpAnnouncer->stopBroadcasting();
        m_tcpServer->stopServer();
    }
    else
    {
        setIsRunnning(true);
        m_udpAnnouncer->startBroadcasting();
        m_tcpServer->startServer();
    }
}
