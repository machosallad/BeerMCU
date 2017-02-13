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
    void userConnected(int id);
    void newUserData(QString data);

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
    int m_counter;
};

#endif // MYTCPSERVER_H
