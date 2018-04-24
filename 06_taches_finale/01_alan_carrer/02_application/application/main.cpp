#include <QApplication>
#include <QtSql>
#include <QtCore>
#include <iostream>
// windows interfaces declaration
#include "mainwindow.h"
#include "addeolienne.h"
#include "execscenario.h"
#include "createscenario.h"
// class declaration
#include "ceolienne.h"
#include "cscenario.h"
#include "cphase.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // initialization database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1"); // 10.16.37.120
    db.setPort(3306);
    db.setDatabaseName("soufflerie");
    db.setUserName("root");
    db.setPassword("");
    db.open();

    MainWindow w(&db);
    w.show();

    return a.exec();
}
