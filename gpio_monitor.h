
#ifndef GPIO_MONITOR_H
#define GPIO_MONITOR_H

#include "gpio.h"

#include <QThread>
#include <QObject>
#include <QList>

class gpio_monitor : public QThread
{
    Q_OBJECT
public:
    gpio_monitor(QObject *parent);
    ~gpio_monitor();
    void stop();
    bool add(gpio* gpi);

protected:
    void run();

private:
    QList<gpio*> gpioList;
    volatile bool stopped;

signals :
    void RaisingEdge(QString, int);
    void FallingEdge(QString, int);

};

#endif // GPIO_MONITOR_H
