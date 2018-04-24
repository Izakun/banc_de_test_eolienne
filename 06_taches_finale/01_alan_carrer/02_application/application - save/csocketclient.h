#ifndef CSOCKETCLIENT_H
#define CSOCKETCLIENT_H
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>

class csocketClient: public QObject
{
private:
    QTcpSocket *socket;
    QByteArray test;
    QStringList list;

public:
    explicit csocketClient(QObject *parent = 0);
    bool connected();
    void send(QString s);
    QStringList read();
    void close();
};

#endif // CSOCKETCLIENT_H
