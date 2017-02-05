#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>
#include "backend.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Backend *backend = new Backend();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    qmlRegisterUncreatableType<DbManager>("machosallad", 1, 0, "DbManager", "Not allowed to create");
    engine.rootContext()->setContextProperty("backend", backend);

    return app.exec();
}
