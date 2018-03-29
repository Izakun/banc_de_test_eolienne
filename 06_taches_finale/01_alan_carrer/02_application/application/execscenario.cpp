#include "execscenario.h"
#include "ui_execscenario.h"

execScenario::execScenario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::execScenario)
{
    ui->setupUi(this);
}

execScenario::~execScenario()
{
    delete ui;
}
