#ifndef USER_H
#define USER_H

#include <QObject>
#include <QDebug>

class NodeUser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    Q_PROPERTY(bool connected READ connected WRITE setConnected NOTIFY connectedChanged)
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(int counter READ counter WRITE setCounter NOTIFY counterChanged)
    Q_PROPERTY(bool light READ light WRITE setLight NOTIFY lightChanged)

public:
    explicit NodeUser(int id, QObject *parent = 0);
    ~NodeUser();

    QString userName() const;
    bool connected() const;
    int id() const;
    int counter() const;

    bool light() const;

signals:

    void userNameChanged(QString arg);
    void connectedChanged(bool arg);
    void idChanged(int arg);
    void counterChanged(int arg);

    void lightChanged(bool arg);

public slots:
    void setUserName(QString arg);
    void setConnected(bool arg);
    void setId(int arg);

    void setCounter(int arg);

    void setLight(bool arg);

private:
    QString m_userName;
    bool m_connected;
    int m_id;
    int m_counter;
    bool m_light;
};

#endif // USER_H
