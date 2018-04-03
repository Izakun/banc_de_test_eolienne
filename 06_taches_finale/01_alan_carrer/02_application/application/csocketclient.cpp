#include "csocketclient.h"

csocketClient::csocketClient(QObject *parent) :
    QObject(parent)
{
}

bool csocketClient::connected()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("10.16.37.122", 2018); // 10.16.37.122
    return socket->waitForConnected(500);
}

void csocketClient::send(QString s, int type)
{
    /* Convert to char */
    char * tab = (char*)malloc(255*sizeof(char));
    strcpy(tab, s.toStdString().c_str());

    if(connected())
    {
        // send
        socket->write(tab); // write this on the client
        socket->waitForBytesWritten(500);
        socket->waitForReadyRead(500);
    }
    else
        qDebug("Connection faild"); // show this if the connection failed
}
