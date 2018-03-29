#ifndef EXECSCENARIO_H
#define EXECSCENARIO_H

#include <QWidget>

namespace Ui {
class execScenario;
}

class execScenario : public QWidget
{
    Q_OBJECT

public:
    explicit execScenario(QWidget *parent = 0);
    ~execScenario();

private:
    Ui::execScenario *ui;
};

#endif // EXECSCENARIO_H
