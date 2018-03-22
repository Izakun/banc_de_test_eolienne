/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_createScenario;
    QPushButton *btn_addEolienne;
    QComboBox *comboBox_scenario;
    QPushButton *btn_execScenario;
    QSlider *horizontalSlider;
    QLabel *lbl_puissance;
    QLabel *lbl_puissanceEolienne;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(665, 154);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_createScenario = new QPushButton(centralWidget);
        btn_createScenario->setObjectName(QStringLiteral("btn_createScenario"));
        btn_createScenario->setGeometry(QRect(540, 100, 91, 21));
        btn_addEolienne = new QPushButton(centralWidget);
        btn_addEolienne->setObjectName(QStringLiteral("btn_addEolienne"));
        btn_addEolienne->setGeometry(QRect(440, 100, 91, 21));
        comboBox_scenario = new QComboBox(centralWidget);
        comboBox_scenario->setObjectName(QStringLiteral("comboBox_scenario"));
        comboBox_scenario->setGeometry(QRect(30, 100, 141, 22));
        btn_execScenario = new QPushButton(centralWidget);
        btn_execScenario->setObjectName(QStringLiteral("btn_execScenario"));
        btn_execScenario->setGeometry(QRect(190, 100, 101, 21));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(30, 30, 601, 22));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        lbl_puissance = new QLabel(centralWidget);
        lbl_puissance->setObjectName(QStringLiteral("lbl_puissance"));
        lbl_puissance->setGeometry(QRect(30, 60, 151, 16));
        lbl_puissanceEolienne = new QLabel(centralWidget);
        lbl_puissanceEolienne->setObjectName(QStringLiteral("lbl_puissanceEolienne"));
        lbl_puissanceEolienne->setGeometry(QRect(210, 60, 141, 16));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(390, 60, 111, 16));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btn_createScenario->setText(QApplication::translate("MainWindow", "Cr\303\251e scenario", Q_NULLPTR));
        btn_addEolienne->setText(QApplication::translate("MainWindow", "Ajouter eolienne", Q_NULLPTR));
        btn_execScenario->setText(QApplication::translate("MainWindow", "Executer scenario", Q_NULLPTR));
        lbl_puissance->setText(QApplication::translate("MainWindow", "Puissance de la soufflerie : 0%", Q_NULLPTR));
        lbl_puissanceEolienne->setText(QApplication::translate("MainWindow", "Puissance de l'eolienne : 0W", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Force du vent : 0km/h", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
