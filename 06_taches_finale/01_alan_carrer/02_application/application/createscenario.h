#ifndef CREATESCENARIO_H
#define CREATESCENARIO_H

#include <QWidget>
#include "cscenario.h"
#include "cphase.h"

namespace Ui {
class createScenario;
}

class createScenario : public QWidget
{
    Q_OBJECT

public:
    explicit createScenario(QSqlDatabase *db, QWidget *parent = 0);
    ~createScenario();

private slots:
    void on_btn_create_clicked();
    void on_btn_add_clicked();

private:
    Ui::createScenario *ui;
    CScenario *scenario;
    Cphase *phase;
    QSqlDatabase *db;
};

#endif // CREATESCENARIO_H
