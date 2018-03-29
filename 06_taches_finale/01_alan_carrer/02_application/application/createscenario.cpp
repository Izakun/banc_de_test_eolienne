#include "createscenario.h"
#include "ui_createscenario.h"

createScenario::createScenario(QSqlDatabase *db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createScenario)
{
    ui->setupUi(this);
    this->db = db;
}

createScenario::~createScenario()
{
    delete ui;
}

void createScenario::on_btn_create_clicked()
{
    scenario = new CScenario(ui->txt_scenario->text());
    scenario->insertDB(*db);
    ui->combo_scenario->addItem(ui->txt_scenario->text());
}

void createScenario::on_btn_add_clicked()
{
    phase = new Cphase(ui->nb_time->value(),ui->nb_power->value());
    phase->insertDB(*db);
}
