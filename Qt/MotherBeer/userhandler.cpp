#include "userhandler.h"

UserHandler::UserHandler(DbManager *dbManager, QObject *parent) : QObject(parent)
{
    m_userHash[1] = new NodeUser(1);
    m_userHash[2] = new NodeUser(2);
    m_userHash[3] = new NodeUser(3);
    m_userHash[4] = new NodeUser(4);
    m_userHash[5] = new NodeUser(5);
    m_userHash[6] = new NodeUser(6);
    m_userHash[7] = new NodeUser(7);
    m_userHash[8] = new NodeUser(8);
    m_userHash[9] = new NodeUser(9);
    m_userHash[10] = new NodeUser(10);
    m_userHash[11] = new NodeUser(11);

    m_dbHandle = dbManager;
    updateLogFile();
    updateCountFile();
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

NodeUser* UserHandler::usrThree() const
{
    return m_userHash[3];
}

NodeUser* UserHandler::usrFour() const
{
    return m_userHash[4];
}

NodeUser* UserHandler::usrFive() const
{
    return m_userHash[5];
}

NodeUser* UserHandler::usrSix() const
{
    return m_userHash[6];
}

NodeUser* UserHandler::usrSeven() const
{
    return m_userHash[7];
}

NodeUser* UserHandler::usrEight() const
{
    return m_userHash[8];
}

NodeUser* UserHandler::usrNine() const
{
    return m_userHash[9];
}

NodeUser* UserHandler::usrTen() const
{
    return m_userHash[10];
}

NodeUser* UserHandler::usrEleven() const
{
    return m_userHash[11];
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
    if(cmd == 4)
    {
        if(val == 0)
        {
            m_userHash[id]->setCounter(m_userHash[id]->counter() + 1);
            if(m_userHash[id]->userName().length() > 0) // Store only when the user has a "valid" name (longer than zero)
                m_dbHandle->InsertRecord(m_userHash[id]->userName().toUpper());

            updateLogFile();
        }
    }
}

void UserHandler::updateLogFile()
{
    //Get number of drinks per person (Jesper: 10, Affe: 12 etc.)
    QString q = "SELECT user, count(user) AS count FROM Drinkstamps GROUP by user";
    QString res = m_dbHandle->SQLQuery(q);

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8(),&err);
    QJsonArray jsonArray = doc.array();

    //Write result to file.
    QFile beerFile("beerList.txt");
    beerFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    if(!beerFile.isOpen()){
        qDebug() << "- Error, unable to open" << "beerList.txt" << "for output";
    }
    else
    {
        QTextStream outStream(&beerFile);
        QString line;

        foreach (const QJsonValue &value, jsonArray) {
            QJsonObject obj = value.toObject();
            line += obj["user"].toString() +": " + QString::number(obj["count"].toInt()) + ", ";
        }
        line.chop(2);
        outStream << line;
        beerFile.close();
    }
}

void UserHandler::updateCountFile()
{
    //Get number of drinks per person (Jesper: 10, Affe: 12 etc.)
    QString q = "SELECT time, count(time) AS total FROM Drinkstamps";
    QString res = m_dbHandle->SQLQuery(q);

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(res.toUtf8(),&err);
    QJsonArray jsonArray = doc.array();

    //Write result to file.
    QFile beerFile("totalBeerList.txt");
    beerFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
    if(!beerFile.isOpen()){
        qDebug() << "- Error, unable to open" << "beerList.txt" << "for output";
    }
    else
    {
        QTextStream outStream(&beerFile);
        QString line;

        foreach (const QJsonValue &value, jsonArray) {
            QJsonObject obj = value.toObject();
            line += QString::number(obj["total"].toInt());
        }
        outStream << line;
        beerFile.close();
    }
}

void UserHandler::setUserStatus(int id, bool status)
{
    m_userHash[id]->setConnected(status);
}
