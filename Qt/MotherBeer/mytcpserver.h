#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>
#include <QSignalMapper>
#include <QtCore>
#include <QtNetwork>
class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = 0);
    ~MyTcpServer();

signals:

public slots:
    void newConnection();
    void clientReadyRead();
    void startServer();
    void stopServer();

private:
    QTcpServer *m_tcpServer;
    QList<QTcpSocket*> m_clientConnections;
    QSignalMapper *m_signalMapper;
    QMap<QTcpSocket*,QString> m_clientIDs;
};

#endif // MYTCPSERVER_H
