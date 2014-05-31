#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include<QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTimer *timer;
    int timer_delay;
    QGraphicsScene *scene;
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

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
