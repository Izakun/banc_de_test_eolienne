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
    bool isConnected;

public:
    explicit csocketClient(QObject *parent = 0);
    bool connectToServer();
    void send(QString s);
    QStringList read();
    void close();
    bool getIsConnected() {return isConnected;}
    void Write(QString type);
};

#endif // CSOCKETCLIENT_H
