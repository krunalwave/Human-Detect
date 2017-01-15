#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <vector>
#include <qextserialenumerator.h>
#include "qextserialport.h"
#include <QDebug>
#include <QMessageBox>
#include <QThread>
#include <QByteArray>
#include "gpio.h"
#include "gpio_monitor.h"
#include <fcntl.h>
#include <stdio.h>
#include <poll.h>
#include <errno.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    iImage =1;
    ui->setupUi(this);
    ui->image->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
