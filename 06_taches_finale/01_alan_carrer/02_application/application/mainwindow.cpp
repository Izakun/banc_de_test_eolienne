#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QSqlDatabase *db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->db = db;

    exec = new execScenario();
    add = new addEolienne(db);
    create = new createScenario(db);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_execScenario_clicked()
{
    exec->show();
}

void MainWindow::on_btn_addEolienne_clicked()
{
    add->show();
}

void MainWindow::on_btn_createScenario_clicked()
{
    create->show();
}
