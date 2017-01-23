#include "mytcpserver.h"

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    m_tcpServer = new QTcpServer(this);
    connect(m_tcpServer,SIGNAL(newConnection()),this,SLOT(newConnection()));

    if(!m_tcpServer->listen(QHostAddress::Any,45455))
    {
        qDebug() << "Unable to start server!";
    }
    else
    {
        qDebug() << "Started TCP server!";
    }
}

MyTcpServer::~MyTcpServer()
{

}

void MyTcpServer::newConnection()
{
    QTcpSocket *socket = m_tcpServer->nextPendingConnection();
    qDebug() << "Got a new connection!";
    socket->write("Welcome client\r\n");
    socket->flush();

    socket->waitForBytesWritten(3000);
    //socket->close();
}

