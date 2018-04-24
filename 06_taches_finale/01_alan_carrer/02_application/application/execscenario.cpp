#include "execscenario.h"
#include "ui_execscenario.h"

execScenario::execScenario(QSqlDatabase *db, QWidget *parent) : QWidget(parent), ui(new Ui::execScenario)
{
    ui->setupUi(this);
    this->setWindowTitle("Banc de test eolienne | Executer scenario");

    socket = new csocketClient();

    ui->comboEolienne->clear();
    ui->comboScenario->clear();
    this->db = db;
    query.prepare("SELECT * FROM scenario");
    query.exec();
    if(query.size()>0) while(query.next()) ui->comboScenario->addItem(query.value("nom").toString().toUtf8().constData(), query.value("id"));

    query.prepare("SELECT * FROM eolienne");
    query.exec();
    if(query.size()>0) while(query.next()) ui->comboEolienne->addItem(query.value("model").toString().toUtf8().constData(), query.value("id"));
}

void execScenario::on_btn_exec_clicked()
{
    QString value = "id" + ui->comboScenario->currentData().toString() + "/" + ui->comboEolienne->currentData().toString();
    socket->send(value);
    qDebug() << value;
}

execScenario::~execScenario()
{
    delete ui;
}
