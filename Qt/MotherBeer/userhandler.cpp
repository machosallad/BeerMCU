#include "userhandler.h"

UserHandler::UserHandler(DbManager *dbManager, QObject *parent) : QObject(parent)
{
    m_userHash[1] = new NodeUser(1);;
    m_userHash[2] = new NodeUser(2);;
    m_userHash[10] = new NodeUser(10);;

    m_dbHandle = dbManager;
}

UserHandler::~UserHandler()
{

}

NodeUser* UserHandler::usrOne() const
{
    return m_userHash[1];
}

NodeUser* UserHandler::usrTwo() const
{
    return m_userHash[2];
}

NodeUser* UserHandler::usrTen() const
{
    return m_userHash[10];
}

void UserHandler::newUser(int id)
{
    qDebug() << "UserHandler: New connection with ID:" << id;
    setUserStatus(id,true);
}

void UserHandler::clientLost(int id)
{
    setUserStatus(id,false);
}

void UserHandler::userCommand(QString cmd)
{
    QStringList parts = cmd.split(':');

    if(parts.length() == 4)
    {
        qDebug() << "Received Command:" << cmd;
//        parts[0] == "ID"
//        parts[1] == ID_NR
//        parts[2] == KEY_NR
//        parts[3] == KEY_VAL

        handleCommand(parts[1].toInt(),parts[2].toInt(),parts[3].toInt());
    }
}

void UserHandler::handleCommand(int id, int cmd, int val)
{
    if(cmd == 2)
    {
        if(val == 0)
        {
            m_userHash[id]->setCounter(m_userHash[id]->counter() + 1);
            m_dbHandle->InsertRecord(m_userHash[id]->userName());
        }
    }
}

void UserHandler::setUserStatus(int id, bool status)
{
    m_userHash[id]->setConnected(status);
}
