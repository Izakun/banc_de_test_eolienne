#include "addeolienne.h"
#include "ui_addeolienne.h"

addEolienne::addEolienne(QSqlDatabase *db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addEolienne)
{
    ui->setupUi(this);
    this->db = db;
}

addEolienne::~addEolienne()
{
    delete ui;
}

void addEolienne::on_pushButton_clicked()
{
    eolienne = new Ceolienne(ui->txt_model->text(), ui->txt_type->text(),ui->txt_fab->text(),ui->txt_doc->text());
    eolienne->insertDB(*db);
}
