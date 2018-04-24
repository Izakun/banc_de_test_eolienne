/********************************************************************************
** Form generated from reading UI file 'createscenario.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESCENARIO_H
#define UI_CREATESCENARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QColumnView>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createScenario
{
public:
    QLabel *label;
    QPushButton *btn_create;
    QLineEdit *txt_scenario;
    QGroupBox *groupBox;
    QLabel *label_2;
    QComboBox *combo_scenario;
    QLabel *label_3;
    QLineEdit *txt_phase;
    QColumnView *tab_bdd;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *nb_power;
    QSpinBox *nb_time;
    QPushButton *btn_add;

    void setupUi(QWidget *createScenario)
    {
        if (createScenario->objectName().isEmpty())
            createScenario->setObjectName(QStringLiteral("createScenario"));
        createScenario->resize(400, 320);
        label = new QLabel(createScenario);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 51, 16));
        btn_create = new QPushButton(createScenario);
        btn_create->setObjectName(QStringLiteral("btn_create"));
        btn_create->setGeometry(QRect(190, 10, 75, 23));
        txt_scenario = new QLineEdit(createScenario);
        txt_scenario->setObjectName(QStringLiteral("txt_scenario"));
        txt_scenario->setGeometry(QRect(70, 10, 111, 20));
        groupBox = new QGroupBox(createScenario);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 381, 271));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 91, 16));
        combo_scenario = new QComboBox(groupBox);
        combo_scenario->setObjectName(QStringLiteral("combo_scenario"));
        combo_scenario->setGeometry(QRect(110, 20, 131, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 50, 81, 16));
        txt_phase = new QLineEdit(groupBox);
        txt_phase->setObjectName(QStringLiteral("txt_phase"));
        txt_phase->setGeometry(QRect(112, 50, 131, 20));
        tab_bdd = new QColumnView(groupBox);
        tab_bdd->setObjectName(QStringLiteral("tab_bdd"));
        tab_bdd->setGeometry(QRect(10, 110, 361, 151));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(260, 20, 61, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(260, 50, 47, 13));
        nb_power = new QSpinBox(groupBox);
        nb_power->setObjectName(QStringLiteral("nb_power"));
        nb_power->setGeometry(QRect(321, 20, 51, 22));
        nb_time = new QSpinBox(groupBox);
        nb_time->setObjectName(QStringLiteral("nb_time"));
        nb_time->setGeometry(QRect(321, 50, 51, 22));
        btn_add = new QPushButton(groupBox);
        btn_add->setObjectName(QStringLiteral("btn_add"));
        btn_add->setGeometry(QRect(150, 80, 75, 23));

        retranslateUi(createScenario);

        QMetaObject::connectSlotsByName(createScenario);
    } // setupUi

    void retranslateUi(QWidget *createScenario)
    {
        createScenario->setWindowTitle(QApplication::translate("createScenario", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("createScenario", "Scenario :", Q_NULLPTR));
        btn_create->setText(QApplication::translate("createScenario", "Cr\303\251er", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("createScenario", "Ajouter phase", Q_NULLPTR));
        label_2->setText(QApplication::translate("createScenario", "Choix du scenario :", Q_NULLPTR));
        label_3->setText(QApplication::translate("createScenario", "Nom de phase :", Q_NULLPTR));
        label_4->setText(QApplication::translate("createScenario", "Puissance :", Q_NULLPTR));
        label_5->setText(QApplication::translate("createScenario", "Temps :", Q_NULLPTR));
        btn_add->setText(QApplication::translate("createScenario", "Ajouter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class createScenario: public Ui_createScenario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESCENARIO_H
