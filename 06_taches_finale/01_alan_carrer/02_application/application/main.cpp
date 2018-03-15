#include "mainwindow.h"
#include <QApplication>
#include "connector.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    connector C;

    C.test();

    w.show();

    return a.exec();
}
