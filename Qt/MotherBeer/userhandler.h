#ifndef USERHANDLER_H
#define USERHANDLER_H

#include <QObject>
#include <QDebug>
#include "user.h"
#include "dbmanager.h"

class UserHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(NodeUser usrOne READ usrOne CONSTANT)
    Q_PROPERTY(NodeUser usrTwo READ usrTwo CONSTANT)
    Q_PROPERTY(NodeUser usrTen READ usrTen CONSTANT)

public:
    explicit UserHandler(DbManager *dbManager,QObject *parent = 0);
    ~UserHandler();

    NodeUser* usrOne() const;
    NodeUser* usrTwo() const;
    NodeUser* usrTen() const;

signals:

public slots:
    void newUser(int id);
    void clientLost(int id);
    void userCommand(QString cmd);

private:
    void setUserStatus(int id, bool status);
    NodeUser* m_usrOne;
    NodeUser* m_usrTwo;
    NodeUser* m_usrTen;
    QHash <int,NodeUser*> m_userHash;
    void handleCommand(int id, int cmd, int val);
    DbManager* m_dbHandle;
};



#endif // USERHANDLER_H
