#include "csocketclient.h"

csocketClient::csocketClient(QObject *parent) : QObject(parent)
{
    isConnected = connectToServer();
}

bool csocketClient::connectToServer()
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
    // send
    qDebug() << tab;
    socket->write(tab); // write this on the client
    socket->waitForBytesWritten(1000);
}

QStringList csocketClient::read(){
    socket->waitForReadyRead(3000);
    QRegExp separator("/");
    return QString::QString(socket->readAll()).split(separator);
}

void csocketClient::Write(QString values){
    const char* value = values.toStdString().c_str();
    socket->write(value);
}

void csocketClient::close(){
    socket->close();
}
