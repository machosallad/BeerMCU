#include "backend.h"
#include <QDir>
#include "httplistener.h"
#include "requestmapper.h"

/** Search the configuration file */
QString searchConfigFile()
{
    QString binDir=QCoreApplication::applicationDirPath();
    QString appName=QCoreApplication::applicationName();
    QString fileName(appName+".ini");

    QStringList searchList;
    searchList.append(binDir);
    searchList.append(binDir+"/etc");
    searchList.append(binDir+"/../etc");
    searchList.append(binDir+"/../../etc"); // for development without shadow build
    searchList.append(binDir+"/../"+appName+"/etc"); // for development with shadow build
    searchList.append(binDir+"/../../"+appName+"/etc"); // for development with shadow build
    searchList.append(binDir+"/../../../"+appName+"/etc"); // for development with shadow build
    searchList.append(binDir+"/../../../../"+appName+"/etc"); // for development with shadow build
    searchList.append(binDir+"/../../../../../"+appName+"/etc"); // for development with shadow build
    searchList.append(QDir::rootPath()+"etc/opt");
    searchList.append(QDir::rootPath()+"etc");

    foreach (QString dir, searchList)
    {
        QFile file(dir+"/"+fileName);
        if (file.exists())
        {
            // found
            fileName=QDir(file.fileName()).canonicalPath();
            qDebug("Using config file %s",qPrintable(fileName));
            return fileName;
        }
    }

    // not found
    foreach (QString dir, searchList)
    {
        qWarning("%s/%s not found",qPrintable(dir),qPrintable(fileName));
    }
    qFatal("Cannot find config file %s",qPrintable(fileName));
    return 0;
}

Backend::Backend(QObject *parent) : QObject(parent)
{
    m_isDiscovering = true;
    m_udpAnnouncer = new UdpAnnouncer();
    m_tcpServer = new MyTcpServer();
    m_isRunnning = false;
    m_dbManager = new DbManager(qApp->applicationDirPath()+"/"+"motherbeer.db");
    m_userHandler = new UserHandler(m_dbManager);

//    connect(sender, &Sender::valueChanged, receiver, &Receiver::updateValue );
    connect(m_tcpServer,&MyTcpServer::userConnected,m_userHandler,&UserHandler::newUser);
    connect(m_tcpServer,&MyTcpServer::newUserData,m_userHandler,&UserHandler::userCommand);

    // Find the configuration file
    QString configFileName=searchConfigFile();

    // Configure and start the TCP listener
    QSettings* listenerSettings=new QSettings(configFileName,QSettings::IniFormat,qApp);
    listenerSettings->beginGroup("listener");
    new HttpListener(listenerSettings,new RequestMapper(m_dbManager,qApp),qApp);

    qWarning("Application has started");


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

void Backend::startStopDiscover()
{
    setIsDiscovering(!m_isDiscovering);
}

void Backend::setIsDiscovering(bool arg)
{
    if (m_isDiscovering == arg)
        return;

    m_userHandler->setDiscoverMode(arg);

    m_isDiscovering = arg;
    emit isDiscoveringChanged(arg);
}
UserHandler *Backend::userHandler() const
{
    return m_userHandler;
}

bool Backend::isDiscovering() const
{
    return m_isDiscovering;
}

DbManager *Backend::dbManager() const
{
    return m_dbManager;
}
