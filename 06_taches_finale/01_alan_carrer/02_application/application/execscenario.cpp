#include "execscenario.h"
#include "ui_execscenario.h"

execScenario::execScenario(QSqlDatabase *db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::execScenario)
{
    ui->setupUi(this);

    socket = new csocketClient();

    ui->comboBox->clear();
    this->db = db;
    query.prepare("SELECT * FROM scenario");
    query.exec();
    if(query.size()>0) while(query.next()) ui->comboBox->addItem(query.value("nom").toString().toUtf8().constData(), query.value("id")); //currentData to select id
}

execScenario::~execScenario()
{
    delete ui;
}

void execScenario::on_btn_exec_clicked()
{
    QString value = ui->comboBox->currentData().toString();
    socket->send(value, 0);
}
