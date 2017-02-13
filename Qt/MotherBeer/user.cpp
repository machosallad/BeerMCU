#include "user.h"

NodeUser::NodeUser(int id, QObject *parent) : QObject(parent)
{
    m_id = id;
    m_userName = "";
    m_connected = false;
    m_counter = 0;
}

NodeUser::~NodeUser()
{

}

QString NodeUser::userName() const
{
    return m_userName;
}

bool NodeUser::connected() const
{
    return m_connected;
}

int NodeUser::id() const
{
    return m_id;
}

int NodeUser::counter() const
{
    return m_counter;
}

void NodeUser::setUserName(QString arg)
{
    if (m_userName == arg)
        return;

    qDebug() <<"New name:" << arg;

    m_userName = arg;
    emit userNameChanged(arg);
}

void NodeUser::setConnected(bool arg)
{
    if (m_connected == arg)
        return;

    m_connected = arg;
    emit connectedChanged(arg);
}

void NodeUser::setId(int arg)
{
    if (m_id == arg)
        return;

    m_id = arg;
    emit idChanged(arg);
}

void NodeUser::setCounter(int arg)
{
    if (m_counter == arg)
        return;

    m_counter = arg;
    emit counterChanged(arg);
}

