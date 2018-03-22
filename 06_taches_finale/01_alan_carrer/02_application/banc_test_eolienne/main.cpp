#include <QApplication>
#include <QtSql>
#include <QtCore>
#include <iostream>
#include "mainwindow.h"
#include "ceolienne.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // initialization database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost"); // localhost | 127.0.0.1 | 10.16.2.147
    db.setPort(3306);
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("");

    if(db.isValid()) std::cout << "valid" << std::endl;
    else std::cout << "unvalid" << std::endl;

    if(db.open()) std::cout << "open" << std::endl;
    else std::cout << "close" << std::endl;

    Ceolienne e1("test","test1","test2","test3");
    e1.insertDB(db);

    w.show();

    return a.exec();
}
