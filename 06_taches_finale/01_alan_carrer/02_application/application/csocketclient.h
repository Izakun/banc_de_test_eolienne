#ifndef CSOCKETCLIENT_H
#define CSOCKETCLIENT_H
#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class csocketClient: public QObject
{
private:
    QTcpSocket *socket;

public:
    explicit csocketClient(QObject *parent = 0);
    bool connected();
    void send(QString s, int type);
};

#endif // CSOCKETCLIENT_H
