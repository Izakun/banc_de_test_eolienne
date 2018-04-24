#include "cthread.h"
#include <QThread>
#include <QDebug>

CThread::CThread()
{
    // create a timer
        timer = new QTimer(this);

        // setup signal and slot
        connect(timer, SIGNAL(timeout()),
              this, SLOT(MyTimerSlot()));

        // msec
        timer->start(1000);
}

void CThread::MyTimerSlot()
{
    qDebug() << "Timer...";
}
