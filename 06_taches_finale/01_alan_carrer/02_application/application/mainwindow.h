#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include "execscenario.h"
#include "addeolienne.h"
#include "createscenario.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QSqlDatabase *db, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_execScenario_clicked();

    void on_btn_addEolienne_clicked();

    void on_btn_createScenario_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase *db;
    execScenario *exec;
    addEolienne *add;
    createScenario *create;
};

#endif // MAINWINDOW_H
