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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *direct;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QLabel *label_4;
    QWidget *scenario;
    QGroupBox *groupBox;
    QLabel *label_9;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_2;
    QLabel *label_10;
    QComboBox *comboBox;
    QLabel *label_11;
    QComboBox *comboBox_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_3;
    QLabel *label_12;
    QComboBox *comboBox_3;
    QLabel *label_13;
    QLineEdit *lineEdit_5;
    QLabel *label_14;
    QSpinBox *spinBox;
    QLabel *label_15;
    QSpinBox *spinBox_2;
    QPushButton *pushButton_4;
    QLabel *label_16;
    QComboBox *comboBox_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_17;
    QComboBox *comboBox_5;
    QTableView *tableView;
    QWidget *eolienne;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(671, 426);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 671, 411));
        direct = new QWidget();
        direct->setObjectName(QStringLiteral("direct"));
        label_3 = new QLabel(direct);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 131, 16));
        horizontalSlider = new QSlider(direct);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(140, 10, 160, 16));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(direct);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(310, 10, 47, 13));
        tabWidget->addTab(direct, QString());
        scenario = new QWidget();
        scenario->setObjectName(QStringLiteral("scenario"));
        groupBox = new QGroupBox(scenario);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 221, 81));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 20, 91, 16));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(100, 20, 113, 21));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 50, 80, 21));
        groupBox_2 = new QGroupBox(scenario);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(240, 0, 421, 80));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 20, 51, 16));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(60, 20, 141, 22));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(220, 20, 51, 16));
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(270, 20, 141, 22));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 50, 80, 21));
        groupBox_3 = new QGroupBox(scenario);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 90, 651, 291));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 20, 51, 16));
        comboBox_3 = new QComboBox(groupBox_3);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(60, 20, 131, 22));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 50, 61, 16));
        lineEdit_5 = new QLineEdit(groupBox_3);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(70, 50, 121, 21));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 80, 101, 16));
        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(120, 80, 71, 22));
        spinBox->setMaximum(100);
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 110, 101, 16));
        spinBox_2 = new QSpinBox(groupBox_3);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(110, 110, 71, 22));
        pushButton_4 = new QPushButton(groupBox_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(60, 140, 80, 21));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 170, 41, 16));
        comboBox_4 = new QComboBox(groupBox_3);
        comboBox_4->setObjectName(QStringLiteral("comboBox_4"));
        comboBox_4->setGeometry(QRect(50, 170, 141, 22));
        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(60, 200, 80, 21));
        pushButton_6 = new QPushButton(groupBox_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(60, 260, 80, 21));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 230, 51, 16));
        comboBox_5 = new QComboBox(groupBox_3);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));
        comboBox_5->setGeometry(QRect(60, 230, 131, 22));
        tableView = new QTableView(groupBox_3);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(200, 20, 441, 261));
        tabWidget->addTab(scenario, QString());
        eolienne = new QWidget();
        eolienne->setObjectName(QStringLiteral("eolienne"));
        label_5 = new QLabel(eolienne);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 41, 16));
        label_6 = new QLabel(eolienne);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 40, 31, 16));
        label_7 = new QLabel(eolienne);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 70, 51, 16));
        label_8 = new QLabel(eolienne);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 100, 81, 16));
        lineEdit = new QLineEdit(eolienne);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(62, 10, 121, 21));
        lineEdit_2 = new QLineEdit(eolienne);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(62, 40, 121, 21));
        lineEdit_3 = new QLineEdit(eolienne);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(62, 70, 121, 21));
        pushButton = new QPushButton(eolienne);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 100, 80, 21));
        tabWidget->addTab(eolienne, QString());
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 410, 121, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 410, 81, 16));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Puissance de la soufflerie :", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "- %", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(direct), QApplication::translate("MainWindow", "Commande directe", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Cr\303\251er scenario", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Nom du scenario :", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Cr\303\251er", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Executer scenario", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Scenario :", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Eolienne :", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Executer", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Editer scenario", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Scenario :", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "Nom phase :", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Puissance soufflerie :", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Temps de la phase :", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Phase :", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Scenario :", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(scenario), QApplication::translate("MainWindow", "Gestion scenarios", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Model :", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Type :", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Fabricant :", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Documentation :", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Parcourir (QFileDialog)", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(eolienne), QApplication::translate("MainWindow", "Ajouter eolienne", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Puissance de l'eolienne :", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Force du vent :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
