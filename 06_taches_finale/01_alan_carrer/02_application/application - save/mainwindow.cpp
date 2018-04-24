#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QSqlDatabase *db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->db = db;

    exec = new execScenario(db);
    add = new addEolienne(db);
    create = new createScenario(db);
    socket = new csocketClient();
    // create a timer
    timer = new QTimer(this);

    // setup signal and slot
    connect(timer, SIGNAL(timeout()),
          this, SLOT(actu()));


    // msec
    //timer->start(1000);
}

MainWindow::~MainWindow()
{
    socket->close();
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

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    timer->stop();
    QString percent = "%:" + QString::number(value);
    socket->send(percent);

    timer->start(1000);
}

void MainWindow::actu(){
    QStringList test;
    test = socket->read();
    QVector<QString> vect = test.toVector();
    if(!vect.last().isEmpty()){
        if (!vect.isEmpty()){
            ui->power_wind->display(vect.at(0).toDouble());
            ui->power_eolienne->display(vect.at(1).toDouble()*100);
        }
    }
    else
        qDebug("vector vide ou erreur de lecture");
    qDebug() << vect;
    timer->start(1000);
}
