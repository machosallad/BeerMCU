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
    Q_PROPERTY(NodeUser usrThree READ usrThree CONSTANT)
    Q_PROPERTY(NodeUser usrFour READ usrFour CONSTANT)
    Q_PROPERTY(NodeUser usrFive READ usrFive CONSTANT)
    Q_PROPERTY(NodeUser usrSix READ usrSix CONSTANT)
    Q_PROPERTY(NodeUser usrSeven READ usrSeven CONSTANT)
    Q_PROPERTY(NodeUser usrEight READ usrEight CONSTANT)
    Q_PROPERTY(NodeUser usrNine READ usrNine CONSTANT)
    Q_PROPERTY(NodeUser usrTen READ usrTen CONSTANT)
    Q_PROPERTY(NodeUser usrEleven READ usrEleven CONSTANT)

public:
    explicit UserHandler(DbManager *dbManager,QObject *parent = 0);
    ~UserHandler();

    NodeUser* usrOne() const;
    NodeUser* usrTwo() const;
    NodeUser* usrTen() const;
    NodeUser* usrThree() const;
    NodeUser* usrFour() const;
    NodeUser* usrFive() const;
    NodeUser* usrSix() const;
    NodeUser* usrSeven() const;
    NodeUser* usrEight() const;
    NodeUser* usrNine() const;
    NodeUser* usrEleven() const;

signals:

public slots:
    void newUser(int id);
    void clientLost(int id);
    void userCommand(QString cmd);

private:
    void setUserStatus(int id, bool status);
    QHash <int,NodeUser*> m_userHash;
    void handleCommand(int id, int cmd, int val);
    DbManager* m_dbHandle;
};



#endif // USERHANDLER_H
