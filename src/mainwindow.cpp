#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include <QColorDialog>
#include"circle.h"
#include<cmath>
double s(double x){
    return x;
}

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),  ui(new Ui::MainWindow){
    ui->setupUi(this);
    timer = new QTimer(this);
    timer_delay=50;
    connect(timer, SIGNAL(timeout()), this, SLOT(next_step()));
     ui->run_pause_but->setText("Run");
     scene= new QGraphicsScene(this);
     scene->setSceneRect(0,0,500,500);
     scene->setBackgroundBrush(QBrush(Qt::black));
     circle *obj=new circle(400,400);
     circle *obj1=new circle();
     obj1->setX(10);obj1->setY(20);
     circle *obj2=new circle(5,55);
     obj->setColor(Qt::white);
     obj1->setColor(Qt::green);
     obj2->setColor(Qt::red);
     obj1->setSize(100);
     obj->setFunction(log);
     obj1->setFunction(s);
     obj2->setFunction(s);
     obj2->setSpeed(10);
     obj1->setSpeed(-2);
     obj->setSpeed(5);
     obj->setSize(50);
     scene->addItem(obj);
     scene->addItem(obj2);
     scene->addItem(obj1);

     ui->area->setScene(scene);
     //ui->area->show();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete scene;
}

void MainWindow::on_run_pause_but_clicked()
{
    static bool status=true;
    status=!status;
    if(!status){
        ui->run_pause_but->setText("Pause");
        timer->start(timer_delay);

    }else{
        ui->run_pause_but->setText("Run");
        timer->stop();
    }
    std::cerr<<"OK!";
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    timer_delay=2*(100-arg1);
    if(timer->isActive()){
        timer->stop();
        timer->start(timer_delay);
    }

}

void MainWindow::on_select_bg_clr_clicked()
{
    QColor c = QColorDialog::getColor(ui->area->backgroundBrush().color());
    if(c.isValid()){
        ui->area->setBackgroundBrush(QBrush(c));
    }
}
void MainWindow::next_step(){

    QList<QGraphicsItem *> items=scene->items();
    for(int i=0;i<items.size();++i){
       entity *e = dynamic_cast<entity*>(items.at(i));
        foreach (QGraphicsItem* citm, scene->collidingItems(items.at(i))) {
            if(items.at(i)!=citm){
            std::cerr<<"YYY";
            entity *ce = dynamic_cast<entity*>(citm);
            if(ce&&e){
            ce->setSpeed(-1*ce->getSpeed());
            ce->next();
           e->setSpeed(-1*e->getSpeed());
            e->next();
            }
        }
        }
    }
    foreach (QGraphicsItem* item, items) {
         entity *e = dynamic_cast<entity*>(item);
         if(!(ui->area->sceneRect().contains((ui->area->mapFromScene(item->shape())).boundingRect ()))){
            // item->rotate(270);
             if(e){
                e->setSpeed(-1*e->getSpeed());
             }
         }

        if (e){
            e->next();

        }
    }




 //   ui->area->viewport()->repaint();
    /*for(std::vector<entity*>::iterator i=objcts.begin();i!=objcts.end();++i){
            std::cerr<<"X: "<<(*i)->getX()<<"\t"<<"Y: "<<(*i)->getY()<<"COLOR: "<<(*i)->getColor().red()<<(*i)->getColor().green()<<(*i)->getColor().blue()<<std::endl;
            (*i)->next();
    }*/
    ui->area->viewport()->update();
}

void MainWindow::on_speed_slider_rangeChanged(int min, int max)
{

}
