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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
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
    QPushButton *btn_execScenario;
    QSlider *horizontalSlider;
    QLabel *lbl_puissance;
    QLabel *lbl_puissanceEolienne;
    QLabel *label;
    QLCDNumber *power_soufflerie;
    QLCDNumber *power_eolienne;
    QLCDNumber *power_wind;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(665, 130);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_createScenario = new QPushButton(centralWidget);
        btn_createScenario->setObjectName(QStringLiteral("btn_createScenario"));
        btn_createScenario->setGeometry(QRect(130, 90, 101, 21));
        btn_addEolienne = new QPushButton(centralWidget);
        btn_addEolienne->setObjectName(QStringLiteral("btn_addEolienne"));
        btn_addEolienne->setGeometry(QRect(540, 90, 101, 21));
        btn_execScenario = new QPushButton(centralWidget);
        btn_execScenario->setObjectName(QStringLiteral("btn_execScenario"));
        btn_execScenario->setGeometry(QRect(20, 90, 101, 21));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 20, 621, 22));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        lbl_puissance = new QLabel(centralWidget);
        lbl_puissance->setObjectName(QStringLiteral("lbl_puissance"));
        lbl_puissance->setGeometry(QRect(20, 50, 151, 16));
        lbl_puissanceEolienne = new QLabel(centralWidget);
        lbl_puissanceEolienne->setObjectName(QStringLiteral("lbl_puissanceEolienne"));
        lbl_puissanceEolienne->setGeometry(QRect(240, 50, 141, 16));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(490, 50, 111, 16));
        power_soufflerie = new QLCDNumber(centralWidget);
        power_soufflerie->setObjectName(QStringLiteral("power_soufflerie"));
        power_soufflerie->setGeometry(QRect(170, 50, 41, 23));
        power_soufflerie->setStyleSheet(QStringLiteral("background-color: black;"));
        power_soufflerie->setDigitCount(3);
        power_eolienne = new QLCDNumber(centralWidget);
        power_eolienne->setObjectName(QStringLiteral("power_eolienne"));
        power_eolienne->setGeometry(QRect(380, 50, 71, 23));
        power_eolienne->setStyleSheet(QStringLiteral("background-color: black;"));
        power_eolienne->setDigitCount(6);
        power_wind = new QLCDNumber(centralWidget);
        power_wind->setObjectName(QStringLiteral("power_wind"));
        power_wind->setGeometry(QRect(600, 50, 41, 23));
        power_wind->setStyleSheet(QStringLiteral("background-color: black;"));
        power_wind->setDigitCount(3);
        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(horizontalSlider, btn_execScenario);
        QWidget::setTabOrder(btn_execScenario, btn_createScenario);
        QWidget::setTabOrder(btn_createScenario, btn_addEolienne);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), power_soufflerie, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btn_createScenario->setText(QApplication::translate("MainWindow", "Cr\303\251e scenario", Q_NULLPTR));
        btn_addEolienne->setText(QApplication::translate("MainWindow", "Ajouter eolienne", Q_NULLPTR));
        btn_execScenario->setText(QApplication::translate("MainWindow", "Executer scenario", Q_NULLPTR));
        lbl_puissance->setText(QApplication::translate("MainWindow", "Puissance de la soufflerie (%) : ", Q_NULLPTR));
        lbl_puissanceEolienne->setText(QApplication::translate("MainWindow", "Puissance de l'eolienne (W) :", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Force du vent (Km/h) :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
