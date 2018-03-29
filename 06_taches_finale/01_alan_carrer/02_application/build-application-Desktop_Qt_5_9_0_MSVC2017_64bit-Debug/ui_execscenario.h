/********************************************************************************
** Form generated from reading UI file 'execscenario.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXECSCENARIO_H
#define UI_EXECSCENARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_execScenario
{
public:
    QPushButton *btn_exec;
    QComboBox *comboBox;
    QLabel *label;

    void setupUi(QWidget *execScenario)
    {
        if (execScenario->objectName().isEmpty())
            execScenario->setObjectName(QStringLiteral("execScenario"));
        execScenario->resize(289, 41);
        btn_exec = new QPushButton(execScenario);
        btn_exec->setObjectName(QStringLiteral("btn_exec"));
        btn_exec->setGeometry(QRect(190, 10, 81, 23));
        comboBox = new QComboBox(execScenario);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(70, 10, 111, 22));
        label = new QLabel(execScenario);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 51, 16));

        retranslateUi(execScenario);

        QMetaObject::connectSlotsByName(execScenario);
    } // setupUi

    void retranslateUi(QWidget *execScenario)
    {
        execScenario->setWindowTitle(QApplication::translate("execScenario", "Form", Q_NULLPTR));
        btn_exec->setText(QApplication::translate("execScenario", "Executer", Q_NULLPTR));
        label->setText(QApplication::translate("execScenario", "Scenario :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class execScenario: public Ui_execScenario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXECSCENARIO_H
