#ifndef CTHREAD_H
#define CTHREAD_H
#include <QTimer>


class CThread : public QObject
{
public:
    CThread();
    QTimer *timer;
public slots:
    void MyTimerSlot();
};

#endif // CTHREAD_H
