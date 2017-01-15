#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QTimer>
#include <QTextStream>
#include <vector>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
     int iImage;
    Ui::MainWindow *ui;
    QTimer *readTimer;
    QTimer *countTimer;
    QString trainNum;
    QTextStream out;

};

#endif // MAINWINDOW_H
