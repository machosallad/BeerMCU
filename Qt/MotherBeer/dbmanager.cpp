#include "dbmanager.h"
#include <QSqlError>

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

    if(checkIfTableExists("Timestamps"))
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
    bool res = query.exec("CREATE TABLE Timestamps "
                "("
                "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                "name TEXT NOT NULL, "
                "time DATETIME DEFAULT CURRENT_TIMESTAMP"
                ");"
               );

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
