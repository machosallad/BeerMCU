#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>
#include <QQmlEngine>
#include <QQuickItem>
#include <QtQml>

#include "backend.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Backend *backend = new Backend();

    QQmlApplicationEngine engine;

    qmlRegisterUncreatableType<DbManager>("machosallad", 1, 0, "DbManager", "Not allowed to create");
    qmlRegisterUncreatableType<NodeUser>("machosallad", 1, 0, "NodeUser", "Not allowed to create");
    qmlRegisterUncreatableType<UserHandler>("machosallad", 1, 0, "UserHandler", "Not allowed to create");

    engine.rootContext()->setContextProperty("backend", backend);
    engine.rootContext()->setContextProperty("userHandler",backend->userHandler());
    engine.rootContext()->setContextProperty("usrOne",backend->userHandler()->usrOne());
    engine.rootContext()->setContextProperty("usrTwo",backend->userHandler()->usrTwo());
    engine.rootContext()->setContextProperty("usrThree",backend->userHandler()->usrThree());
    engine.rootContext()->setContextProperty("usrFour",backend->userHandler()->usrFour());
    engine.rootContext()->setContextProperty("usrFive",backend->userHandler()->usrFive());
    engine.rootContext()->setContextProperty("usrSix",backend->userHandler()->usrSix());
    engine.rootContext()->setContextProperty("usrSeven",backend->userHandler()->usrSeven());
    engine.rootContext()->setContextProperty("usrEight",backend->userHandler()->usrEight());
    engine.rootContext()->setContextProperty("usrNine",backend->userHandler()->usrNine());
    engine.rootContext()->setContextProperty("usrTen",backend->userHandler()->usrTen());
    engine.rootContext()->setContextProperty("usrEleven",backend->userHandler()->usrEleven());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
