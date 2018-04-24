#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtTest/QtTest>

#include <QMainWindow>
#include <QtSql>
#include <QTimer>
#include <QVector>
#include "execscenario.h"
#include "addeolienne.h"
#include "createscenario.h"
#include "csocketclient.h"

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
    void on_horizontalSlider_valueChanged(int value);
    void actu();

private:
    Ui::MainWindow *ui;
    QSqlDatabase *db;
    execScenario *exec;
    addEolienne *add;
    createScenario *create;
    csocketClient *socket;
    QTimer *timer;
};

#endif // MAINWINDOW_H
