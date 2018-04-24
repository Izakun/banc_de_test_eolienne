#include "csocketclient.h"

csocketClient::csocketClient(QObject *parent) :
    QObject(parent)
{
}

bool csocketClient::connected()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("10.16.37.122", 2018); // 127.0.0.1 | 10.16.37.122
    return socket->waitForConnected(3000);
}

void csocketClient::send(QString s)
{
    // Convert to char
    char * tab = (char*)malloc(255*sizeof(char));
    strcpy(tab, s.toStdString().c_str());

    qDebug() << tab;
    if(connected())
    {
        // send
        socket->write(tab); // write this on the client
        socket->waitForBytesWritten(1000);
    }
    else
        qDebug("Connection failed"); // show this if the connection failed
}

QStringList csocketClient::read(){
    socket->waitForReadyRead(3000);
    QRegExp separator("/");
    return QString::QString(socket->readAll()).split(separator);
}

void csocketClient::close(){
    socket->close();
}
