#include "mainwindow.h"
#include <QApplication>
#include "ceolienne.h"
#include "cscenario.h"
#include "cphase.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // initialization database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setPort(3306);
    db.setHostName("localhost"); // localhost | 127.0.0.1 | 10.16.2.147
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("");
    db.driver();
    if(db.isValid()) qDebug() << "valid";
    else qDebug() << "not valid";

    Ceolienne e1("test","test1","test2","test3");
    e1.insertDB(db);

    w.show();

    return a.exec();
}
