#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QSqlDatabase *db, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Banc de test eolienne | Commande directe");

    this->db = db;

    exec = new execScenario(db);
    add = new addEolienne(db);
    create = new createScenario(db);
    socket = new csocketClient();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(actu()));
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    timer->stop();
    QString percent = "%:" + QString::number(value);
    if(socket->getIsConnected())
    {
        socket->send(percent);
        timer->start(1000);
    }
    else qDebug("Connection failed"); // show this if the connection failed
}

void MainWindow::actu(){
    socket->Write("getWP"); // write on the sever
    QStringList test;
    test = socket->read();
    QVector<QString> vect = test.toVector();
    if(!vect.last().isEmpty()){
        if (!vect.isEmpty()){
            ui->power_wind->display(vect.at(0).toDouble());
            ui->power_eolienne->display(vect.at(1).toDouble()*100);
        }
    }
    qDebug() << vect;
    if(vect.at(0).toDouble() != 0 && vect.at(1).toDouble()*100 != 0) timer->start(1000);
    else timer->stop();
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
