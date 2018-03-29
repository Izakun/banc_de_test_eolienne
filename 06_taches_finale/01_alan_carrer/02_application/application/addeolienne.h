#ifndef ADDEOLIENNE_H
#define ADDEOLIENNE_H

#include <QWidget>
#include "ceolienne.h"

namespace Ui {
class addEolienne;
}

class addEolienne : public QWidget
{
    Q_OBJECT

public:
    explicit addEolienne(QSqlDatabase *db, QWidget *parent = 0);
    ~addEolienne();

private slots:

    void on_pushButton_clicked();

private:
    Ui::addEolienne *ui;
    Ceolienne *eolienne;
    QSqlDatabase *db;
};

#endif // ADDEOLIENNE_H
