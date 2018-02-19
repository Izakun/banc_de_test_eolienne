#include <QCoreApplication>
#include <QtSql>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Creation de la connexion a la base de donnée
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("test");

    if(db.open())
        cout << "connexion reussite" << endl;
    else
        cout << "connexion echoue" << endl;

    string id;

    QSqlQuery query(db);
    query.exec("SELECT * FROM test");

    if(query.size()>0){
        while (query.next()) {
            id = query.value("nom").toString().toUtf8().constData();

            cout << id << endl;
        }
    }
    else
        cout << "pas de données dans la base";

    return a.exec();
}
