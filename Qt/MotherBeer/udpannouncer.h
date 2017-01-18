#ifndef UDPANNOUNCER_H
#define UDPANNOUNCER_H

#include <QObject>
#include <QUdpSocket>
#include <QTimer>
#include <QTcpSocket>

class UdpAnnouncer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isBroadcasting READ isBroadcasting WRITE setIsBroadcasting NOTIFY isBroadcastingChanged)
public:
    explicit UdpAnnouncer(QObject *parent = 0);
    ~UdpAnnouncer();

    bool isBroadcasting() const;

signals:
    void isBroadcastingChanged(bool arg);

public slots:
    void startBroadcasting();
    void setIsBroadcasting(bool arg);

private:
    void transmitMsg();
    QString getLocalIp();
    QTimer *m_txTimer;
    QUdpSocket *m_udpSocket;
    bool m_isBroadcasting;
};

#endif // UDPANNOUNCER_H
