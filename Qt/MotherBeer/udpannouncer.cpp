#include "udpannouncer.h"

UdpAnnouncer::UdpAnnouncer(QObject *parent) : QObject(parent)
{
    m_isBroadcasting = false;
    m_txTimer = new QTimer(this);
    m_udpSocket = new QUdpSocket(this);
    connect(m_txTimer,&QTimer::timeout,this,&UdpAnnouncer::transmitMsg);
}

UdpAnnouncer::~UdpAnnouncer()
{

}

bool UdpAnnouncer::isBroadcasting() const
{
    return m_isBroadcasting;
}

void UdpAnnouncer::stopBroadcasting()
{
    setIsBroadcasting(true);
    qDebug() << "Stop broadcasting server on IP:" << getLocalIp();
    m_txTimer->stop();
}

void UdpAnnouncer::startBroadcasting()
{
    setIsBroadcasting(false);
    qDebug() << "Start broadcasting server on IP:" << getLocalIp();
    m_txTimer->start(1000);
}

void UdpAnnouncer::setIsBroadcasting(bool arg)
{
    if (m_isBroadcasting == arg)
        return;

    m_isBroadcasting = arg;
    emit isBroadcastingChanged(arg);
}

void UdpAnnouncer::transmitMsg()
{
    QString localIP = getLocalIp();
    if(localIP.length() > 0)
    {
        QByteArray datagram(localIP.toUtf8());
        m_udpSocket->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 45454);
    }
}

QString UdpAnnouncer::getLocalIp()
{
    QTcpSocket socket;
    socket.connectToHost("8.8.8.8", 53); // google DNS, or something else reliable
    if (socket.waitForConnected()) {
        return socket.localAddress().toString();
    } else {
        qWarning()
            << "could not determine local IPv4 address:"
            << socket.errorString();
        return "";
    }
}

