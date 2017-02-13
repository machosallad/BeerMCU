#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class DbManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool dbOpen READ dbOpen WRITE setDbOpen NOTIFY dbOpenChanged)
    Q_PROPERTY(QString dbPath READ dbPath WRITE setDbPath NOTIFY dbPathChanged)

public:
    explicit DbManager(QString path, QObject *parent = 0);
    ~DbManager();

    bool dbOpen() const;
    QString dbPath() const;

signals:
    void dbOpenChanged(bool dbOpen);
    void dbPathChanged(QString dbPath);

public slots:
    void setDbOpen(bool dbOpen);
    void setDbPath(QString dbPath);

    QString SQLQuery(const QString &sqlquery);
    bool InsertRecord(QString name);
private:
    QSqlDatabase m_db;
    bool m_dbOpen;
    QString m_dbPath;
    bool checkIfTableExists(QString table);
    bool createTable();
};



#endif // DBMANAGER_H
