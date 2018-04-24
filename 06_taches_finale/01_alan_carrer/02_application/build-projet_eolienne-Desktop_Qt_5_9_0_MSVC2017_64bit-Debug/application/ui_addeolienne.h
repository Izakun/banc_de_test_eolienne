/********************************************************************************
** Form generated from reading UI file 'addeolienne.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEOLIENNE_H
#define UI_ADDEOLIENNE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addEolienne
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *txt_fab;
    QLineEdit *txt_type;
    QLineEdit *txt_model;
    QPushButton *pushButton;
    QToolButton *toolButton;

    void setupUi(QWidget *addEolienne)
    {
        if (addEolienne->objectName().isEmpty())
            addEolienne->setObjectName(QStringLiteral("addEolienne"));
        addEolienne->resize(230, 161);
        label = new QLabel(addEolienne);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 51, 16));
        label_2 = new QLabel(addEolienne);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 40, 51, 16));
        label_3 = new QLabel(addEolienne);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 70, 51, 16));
        label_4 = new QLabel(addEolienne);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 100, 81, 16));
        txt_fab = new QLineEdit(addEolienne);
        txt_fab->setObjectName(QStringLiteral("txt_fab"));
        txt_fab->setGeometry(QRect(100, 70, 111, 20));
        txt_fab->setCursorPosition(0);
        txt_type = new QLineEdit(addEolienne);
        txt_type->setObjectName(QStringLiteral("txt_type"));
        txt_type->setGeometry(QRect(100, 40, 111, 20));
        txt_type->setCursorPosition(0);
        txt_model = new QLineEdit(addEolienne);
        txt_model->setObjectName(QStringLiteral("txt_model"));
        txt_model->setGeometry(QRect(100, 10, 111, 20));
        pushButton = new QPushButton(addEolienne);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 130, 75, 23));
        toolButton = new QToolButton(addEolienne);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(100, 100, 31, 19));
        QWidget::setTabOrder(txt_model, txt_type);
        QWidget::setTabOrder(txt_type, txt_fab);
        QWidget::setTabOrder(txt_fab, toolButton);
        QWidget::setTabOrder(toolButton, pushButton);

        retranslateUi(addEolienne);

        QMetaObject::connectSlotsByName(addEolienne);
    } // setupUi

    void retranslateUi(QWidget *addEolienne)
    {
        addEolienne->setWindowTitle(QApplication::translate("addEolienne", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("addEolienne", "Model :", Q_NULLPTR));
        label_2->setText(QApplication::translate("addEolienne", "Type :", Q_NULLPTR));
        label_3->setText(QApplication::translate("addEolienne", "Fabricant :", Q_NULLPTR));
        label_4->setText(QApplication::translate("addEolienne", "Documentation :", Q_NULLPTR));
        pushButton->setText(QApplication::translate("addEolienne", "Ajouter", Q_NULLPTR));
        toolButton->setText(QApplication::translate("addEolienne", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class addEolienne: public Ui_addEolienne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEOLIENNE_H
