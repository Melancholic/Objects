#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include<QTimer>
#include<utility>
#include<cstdlib>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTimer *timer;
    int timer_delay;
    QGraphicsScene *scene;
    bool fullMode;
    int index;
    void addObjects();
    Ui::MainWindow *ui;
    std::pair<double,double> getRandXY();
    void setItemsSpeed(int);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);

private slots:
    void on_run_pause_but_clicked();

    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_select_bg_clr_clicked();
    void next_step();

    void on_speed_slider_rangeChanged(int min, int max);

    void fullScreenArea();

};

#endif // MAINWINDOW_H
