#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>
class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = 0);
    ~MyTcpServer();

signals:

public slots:
    void newConnection();

private:
    QTcpServer *m_tcpServer;
    QList<*QTcpSocket> m_clientConnections;
};

#endif // MYTCPSERVER_H
