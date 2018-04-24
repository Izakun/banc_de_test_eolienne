#ifndef EXECSCENARIO_H
#define EXECSCENARIO_H

#include <QWidget>
#include <QDebug>
#include "cscenario.h"
#include "cphase.h"
#include "csocketclient.h"

namespace Ui {
class execScenario;
}

class execScenario : public QWidget
{
    Q_OBJECT

public:
    explicit execScenario(QSqlDatabase *db, QWidget *parent = 0);
    ~execScenario();

private slots:
    void on_btn_exec_clicked();

private:
    Ui::execScenario *ui;
    QSqlDatabase *db;
    QSqlQuery query;
    QString value;
    csocketClient *socket;
};

#endif // EXECSCENARIO_H
