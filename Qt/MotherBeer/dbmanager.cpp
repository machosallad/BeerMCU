#include "dbmanager.h"
#include <QSqlError>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QSqlRecord>

DbManager::DbManager(QString path, QObject *parent) : QObject(parent)
{
    // Check if database is available, if not create!

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    setDbPath(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database fail";
        setDbOpen(false);
    }
    else
    {
        qDebug() << "Database: connection ok";
        setDbOpen(true);
    }

    if(checkIfTableExists("Drinkstamps"))
    {
        qDebug() << "Table: timestamps is found!";
    }
    else
    {
        qDebug() << "Table: timestamps not found, create it!";
        if(createTable())
            qDebug() << "Table created!";
        else
            qDebug() << "Unable to create table!";
    }

//    InsertRecord("Jesper");
//    InsertRecord("Jesper");
//    InsertRecord("Daniel");

    QString q = "SELECT name, count(name) FROM Drinkstamps GROUP by name";
    QString res = SQLQuery(q);
    qDebug() << res;
}

DbManager::~DbManager()
{

}

bool DbManager::dbOpen() const
{
    return m_dbOpen;
}

bool DbManager::checkIfTableExists(QString table)
{
    return m_db.tables().contains(QLatin1String(table.toUtf8()));
}

bool DbManager::createTable()
{
    QSqlQuery query;
//    bool res = query.exec("CREATE TABLE Drinkstamps "
//                          "("
//                          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
//                          "time DATETIME DEFAULT CURRENT_TIMESTAMP"
//                          ");"
//                          );

    bool res = query.exec("CREATE TABLE Drinkstamps "
                          "("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                          "name TEXT NOT NULL, "
                          "time DATETIME DEFAULT CURRENT_TIMESTAMP"
                          ");"
                          );

    qDebug() << "Query result:" << query.lastError().text();
    return res;
}

bool DbManager::InsertRecord(QString name)
{
    QSqlQuery query;

    QString queryString = "INSERT INTO Drinkstamps (name) VALUES (:user)";

    if( !query.prepare(queryString) )
    {
        qDebug() << "Prepare:" << query.lastError();
        return false;
    }

    query.bindValue(":user", name);

    bool res = query.exec();

    qDebug() << "Query result:" << query.lastError().text();
    return res;
}

void DbManager::setDbOpen(bool dbOpen)
{
    if (m_dbOpen == dbOpen)
        return;

    m_dbOpen = dbOpen;
    emit dbOpenChanged(dbOpen);
}

void DbManager::setDbPath(QString dbPath)
{
    if (m_dbPath == dbPath)
        return;

    m_dbPath = dbPath;
    emit dbPathChanged(dbPath);
}


QString DbManager::dbPath() const
{
    return m_dbPath;
}

QString DbManager::SQLQuery(const QString & sqlquery) {

    QSqlQuery query;
    query.setForwardOnly(true);
    if (!query.exec(sqlquery))return QString();

    QJsonDocument  json;
    QJsonArray     recordsArray;

    // Build the responce
    while(query.next())
    {
        QJsonObject recordObject;
        for(int x=0; x < query.record().count(); x++)
        {
            recordObject.insert( query.record().fieldName(x),QJsonValue::fromVariant(query.value(x)) );
        }
        recordsArray.push_back(recordObject);
    }
    json.setArray(recordsArray);

    qDebug() << "Query result:" << query.lastError().text();

    return json.toJson();
}
