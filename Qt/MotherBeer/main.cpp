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
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    qmlRegisterUncreatableType<DbManager>("machosallad", 1, 0, "DbManager", "Not allowed to create");
    qmlRegisterUncreatableType<NodeUser>("machosallad", 1, 0, "NodeUser", "Not allowed to create");
    qmlRegisterUncreatableType<UserHandler>("machosallad", 1, 0, "UserHandler", "Not allowed to create");

    engine.rootContext()->setContextProperty("backend", backend);
    engine.rootContext()->setContextProperty("userHandler",backend->userHandler());
    engine.rootContext()->setContextProperty("usrTen",backend->userHandler()->usrTen());


    return app.exec();
}
