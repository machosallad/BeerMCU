#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "udpannouncer.h"
#include "mytcpserver.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    UdpAnnouncer *udpAnnouncer = new UdpAnnouncer();
    MyTcpServer *tcpServer = new MyTcpServer();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //qmlRegisterUncreatableType<UdpAnnouncer>("machosallad", 1, 0, "UdpAnnouncer", "Not allowed to create");
    engine.rootContext()->setContextProperty("udpAnnouncer", udpAnnouncer);
    engine.rootContext()->setContextProperty("tcpServer", tcpServer);

    return app.exec();
}
