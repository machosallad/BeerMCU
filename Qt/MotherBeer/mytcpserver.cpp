#include "mytcpserver.h"
#include <QDebug>

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent)
{
    m_tcpServer = new QTcpServer(this);
    m_signalMapper = new QSignalMapper(this);
    connect(m_tcpServer,SIGNAL(newConnection()),this,SLOT(newConnection()));
    m_counter = 0;
}

MyTcpServer::~MyTcpServer()
{

}

void MyTcpServer::newConnection()
{
    QTcpSocket *client = m_tcpServer->nextPendingConnection();
    qDebug() << "Got a new connection from: " << client->peerAddress().toString();

    // Add the socket to the list of connected clients
    m_clientConnections.append(client);

    // Connect apppropiate signals/slots
    connect(client, SIGNAL(disconnected()), client, SLOT(deleteLater()));
    connect(client,SIGNAL(readyRead()),this,SLOT(clientReadyRead()));
}

/**
 * @brief Read incomming data from a connected client
 */
void MyTcpServer::clientReadyRead()
{
    qDebug() << "Got data from a client!";

    // Get the socket handle
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    char buffer[1024] = {0};

    // Read data from the socket using the handle
    clientSocket->read(buffer,clientSocket->bytesAvailable());
    qDebug() << buffer << endl;

    QString cmd(buffer);
    QStringList parts = cmd.split(':');

    if(parts.length() == 2)
    {
        qDebug() << "New client added with ID:" << parts[1];
        m_clientIDs.insert(clientSocket,parts[1]);

        emit userConnected(parts[1].toInt());
    }
    else
    {
        emit newUserData(cmd);
    }
}

/**
 * @brief Server should be stopped. Handles all neccesery steps to do it
 */
void MyTcpServer::stopServer()
{
    qDebug() << "TCP Server stopped";
    m_tcpServer->close();

    // Close each socket since we have stopped the server
    foreach (QTcpSocket *client, m_clientConnections) {
        client->close();
        client->deleteLater();
    }
    m_clientConnections.clear();
}

void MyTcpServer::startServer()
{
    if(!m_tcpServer->listen(QHostAddress::Any,45455))
    {
        qDebug() << "Unable to start server!";
    }
    else
    {
        qDebug() << "Started TCP server!";
    }
}

