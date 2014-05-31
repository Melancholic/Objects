#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include <QColorDialog>
#include"circle.h"
#include"arc.h"
#include<cmath>
#include <QGraphicsView>
#include<QtGui>
#include<QDebug>
double s(double x){
    return 1*x;
}

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),  ui(new Ui::MainWindow){
    ui->setupUi(this);
    timer = new QTimer(this);
    timer_delay=50;
    connect(timer, SIGNAL(timeout()), this, SLOT(next_step()));
   //     connect(timer, SIGNAL(timeout()), this, SLOT(advance()));
     ui->run_pause_but->setText("Run");
     scene= new QGraphicsScene(ui->area);
     ui->area->scale(1,-1);
    // QRect vis_rect(0,0,250,250);
    // scene->setSceneRect(vis_rect);
     scene->setBackgroundBrush(QBrush(Qt::black));
     circle *obj=new circle(50,50);
     arc *obj1=new arc();
     obj1->setX(200);obj1->setY(200);
     obj1->setSize(11);
     circle *obj2=new circle(5,55);
     obj->setColor(Qt::white);
     obj1->setColor(Qt::green);
     obj2->setColor(Qt::red);
     obj1->setSize(50);
     obj->setFunction(s);
     obj1->setFunction(s);
     obj2->setFunction(s);
     obj2->setSpeed(10);
     obj1->setSpeed(1);
     obj->setSpeed(10);
     obj->setSize(50);
     obj->setFlag(QGraphicsItem::ItemIsMovable);
     obj1->setFlag(QGraphicsItem::ItemIsMovable);
     obj2->setFlag(QGraphicsItem::ItemIsMovable);
     scene->addItem(obj);
     scene->addItem(obj2);
     scene->addItem(obj1);
     ui -> area -> setRenderHints ( QPainter :: Antialiasing
             |  QPainter :: SmoothPixmapTransform
             |  QPainter :: TextAntialiasing );
     ui->area->setScene(scene);
     ui->area->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
     ui->area->setCacheMode(QGraphicsView::CacheBackground);
     ui->area->setRenderHint(QPainter::Antialiasing,false);
     ui->area->setInteractive(true);

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
    qDebug()<<"OK!";
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    timer_delay=(100-arg1);
    if(timer->isActive()){
        timer->stop();
        timer->start(timer_delay);
    }

}

void MainWindow::on_select_bg_clr_clicked()
{
    QColor c = QColorDialog::getColor(ui->area->backgroundBrush().color());
    if(c.isValid()){
       DrawArea::setBgColor(c);
       ui->area->setBackgroundBrush(QBrush(c));

    }
}
void MainWindow::next_step(){
qDebug()<<"1: "<<ui->area->sceneRect().height()<<" "<<ui->area->sceneRect().width()<<"\n";

    QList<QGraphicsItem *> items=scene->items();
    for(int i=0;i<items.size();++i){
       entity *e = dynamic_cast<entity*>(items.at(i));
        foreach (QGraphicsItem* citm, scene->collidingItems(items.at(i))) {
            if(items.at(i)!=citm){
            qDebug()<<"YYY";
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
        qDebug()<<"X: "<<item->pos().x()<<"Y:  "<<item->pos().y()<<"\n";
         entity *e = dynamic_cast<entity*>(item);
         qDebug()<<"\t2: "<<ui->area->mapFromScene(item->pos()).x()<<" "<<ui->area->mapFromScene(item->pos()).y()<<"\n";

         if(!(ui->area->sceneRect().contains((ui->area->mapFromScene(item->boundingRect())).boundingRect()))){
                     qDebug()<<"\nSCENE RECT:: "<<ui->area->sceneRect().x()<<" "<<ui->area->sceneRect().y()<<"\t\t"<<ui->area->mapFromScene(item->boundingRect()).boundingRect().x()<<" "<<ui->area->mapFromScene(item->boundingRect()).boundingRect().y();
             // item->rotate(270);
             if(e){
                e->setSpeed(-1*e->getSpeed());
             }
         }

        if (e){
            e->next();

        }
    }




    ui->area->viewport()->repaint();
    /*for(std::vector<entity*>::iterator i=objcts.begin();i!=objcts.end();++i){
            qDebug()<<"X: "<<(*i)->getX()<<"\t"<<"Y: "<<(*i)->getY()<<"COLOR: "<<(*i)->getColor().red()<<(*i)->getColor().green()<<(*i)->getColor().blue()<<std::endl;
            (*i)->next();
    }*/
    //ui->area->viewport()->update();
}

void MainWindow::on_speed_slider_rangeChanged(int min, int max)
{

}
void MainWindow::showEvent(QShowEvent *) {
 //   qDebug()<<"OQOQOQ";
 //   ui->area->fitInView(scene->sceneRect(),Qt::KeepAspectRatioByExpanding);
}

