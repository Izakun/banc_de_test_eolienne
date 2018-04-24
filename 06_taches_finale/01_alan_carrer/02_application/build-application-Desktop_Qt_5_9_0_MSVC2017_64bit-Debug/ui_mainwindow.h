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
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QLCDNumber *lcdNumber_3;

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
        lbl_puissance->setGeometry(QRect(20, 50, 131, 16));
        lbl_puissanceEolienne = new QLabel(centralWidget);
        lbl_puissanceEolienne->setObjectName(QStringLiteral("lbl_puissanceEolienne"));
        lbl_puissanceEolienne->setGeometry(QRect(260, 50, 121, 16));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(490, 50, 81, 16));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(150, 50, 61, 23));
        lcdNumber->setStyleSheet(QStringLiteral("background-color: black;"));
        lcdNumber_2 = new QLCDNumber(centralWidget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(380, 50, 64, 23));
        lcdNumber_2->setStyleSheet(QStringLiteral("background-color: black;"));
        lcdNumber_3 = new QLCDNumber(centralWidget);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));
        lcdNumber_3->setGeometry(QRect(570, 50, 64, 23));
        lcdNumber_3->setStyleSheet(QStringLiteral("background-color: black;"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(sliderMoved(int)), lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btn_createScenario->setText(QApplication::translate("MainWindow", "Cr\303\251e scenario", Q_NULLPTR));
        btn_addEolienne->setText(QApplication::translate("MainWindow", "Ajouter eolienne", Q_NULLPTR));
        btn_execScenario->setText(QApplication::translate("MainWindow", "Executer scenario", Q_NULLPTR));
        lbl_puissance->setText(QApplication::translate("MainWindow", "Puissance de la soufflerie : ", Q_NULLPTR));
        lbl_puissanceEolienne->setText(QApplication::translate("MainWindow", "Puissance de l'eolienne :", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Force du vent :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
