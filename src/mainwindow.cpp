#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include <QColorDialog>
#include"circle.h"
#include"arc.h"
#include"square.h"
#include <QGraphicsView>
#include<QtGui>
#include<QDebug>
#include<QGraphicsRectItem>
#include"functions.h"
#include"circleinsquare.h"
#include"triangle.h"
#include <functional>
#include"trinagleincircle.h"
#include"trinagleinarc.h"
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),  ui(new Ui::MainWindow){
    ui->setupUi(this);
    timer = new QTimer(this);
    timer_delay=1000/33;
    connect(timer, SIGNAL(timeout()), this, SLOT(next_step()));
     ui->run_pause_but->setText("Run");
     scene= new QGraphicsScene(this);
     ui->area->scale(1,-1);
     QRect vis_rect(-ui->area->width(),-ui->area->height(),ui->area->width()*2,ui->area->height()*2);
    scene->setSceneRect(vis_rect);
     scene->setBackgroundBrush(QBrush(Qt::black));
     addObjects();
     scene->addRect(scene->sceneRect(),QPen(Qt::red));
     ui -> area -> setRenderHints ( QPainter :: Antialiasing
             |  QPainter :: SmoothPixmapTransform
             |  QPainter :: TextAntialiasing );
     ui->area->setScene(scene);
     ui->area->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
     ui->area->setCacheMode(QGraphicsView::CacheBackground);
     ui->area->setRenderHint(QPainter::Antialiasing,false);
     ui->area->setInteractive(true);
     connect(ui->area, SIGNAL(doubleClick()), this, SLOT(fullScreenArea()));
    fullMode=false;

}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete scene;
}
std::pair<double,double>MainWindow::getRandXY(){
    qsrand(time(0));
    return std::make_pair(qrand()%(ui->area->width()),qrand()%(ui->area->height()));
}

void MainWindow::addObjects(){
    std::pair<double,double> xy;

    xy=getRandXY();
    circle *Circle = new circle(0,0);
    Circle->setFunction(functions::xx);
    Circle->setSize(75);
    scene->addItem(Circle);

   xy=getRandXY();
    arc *Arc = new arc(0,0,80);
    Arc->setColor(Qt::blue);
    Arc->setFunction(functions::minus);
    Arc->setSizeInner(60);
    scene->addItem(Arc);

    square *Square = new square(0,0,50,Qt::green);
    Square->setFunction(functions::parabol);
    scene->addItem(Square);

    CircleInSquare *CIS = new CircleInSquare(0,0,110);
    CIS->setSizeInner(80);
    CIS->setColor(Qt::red);
    CIS->setFunction(functions::x);
    scene->addItem(CIS);

    triangle *Triangle = new triangle(0,0,60,Qt::gray);
    Triangle->setFunction(functions::arc);
    scene->addItem(Triangle);


    TrinagleInCircle *TIC = new TrinagleInCircle(0,0,110);
    TIC->setSizeInner(80);
    TIC->setColor(Qt::yellow);
    TIC->setFunction(functions::cos);
    scene->addItem(TIC);

   /* TrinagleInArc *TIA = new TrinagleInArc(0,0,90);
    TIA->setSizeInner(50);
    TIA->setColor(Qt::gray);
    TIA->setFunction(functions::x2);
    scene->addItem(TIA);*/


    setItemsSpeed(ui->spinBox->value());
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
void MainWindow::setItemsSpeed(int arg){
    QList<QGraphicsItem *> items=scene->items();
    for(int i=0;i<items.size();++i){
        entity *e = dynamic_cast<entity*>(items.at(i));
        if(e){
            double speed= (((double)(4))/(11-arg));
            e->setSpeed((e->getSpeed()<0)?-speed:speed);
        }
    }
}

void MainWindow::on_spinBox_valueChanged(int arg)
{
    timer_delay=1000/33/*20+2*(100-arg1)*/;
    setItemsSpeed(arg);
    if(timer->isActive()){
        timer->stop();
        timer->start(timer_delay);
    }

}

void MainWindow::fullScreenArea(){
    if(!fullMode)
    {
        index = ui->horizontalLayout_2->indexOf(ui->area);
        ui->area->setParent(0);
        this->hide();
        ui->area->showFullScreen();
        fullMode = true;
    }
    else
    {
        ui->horizontalLayout_2->insertWidget(index, ui->area);
        this->show();
        fullMode = false;
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
    QList<QGraphicsItem *> items=scene->items();
    for(int i=0;i<items.size();++i){
       /*entity *e = dynamic_cast<entity*>(items.at(i));
        foreach (QGraphicsItem* citm, scene->collidingItems(items.at(i))) {
            if(items.at(i)!=citm){
         //   qDebug()<<"YYY";
            entity *ce = dynamic_cast<entity*>(citm);
            if(ce&&e){
            ce->setSpeed(-1*ce->getSpeed());
            ce->next();
           e->setSpeed(-1*e->getSpeed());
            e->next();
            }
        }
        }
    }*/
    foreach (QGraphicsItem* item, items) {
         entity *e = dynamic_cast<entity*>(item);
         if((ui->area->mapToScene(ui->area->sceneRect().toRect()).boundingRect().contains(ui->area->mapToScene(item->boundingRect().toRect()).boundingRect()))){
                     qDebug()<<ui->area->sceneRect().width()<<" "<<ui->area->sceneRect().height() << "     "\
                              <<ui->area->mapFromScene(item->shape()).boundingRect().x()<<"  " <<item->boundingRect().y();

         }else{
             QRect SceneBound=ui->area->sceneRect().toRect();
             double xmax=e->getX()+e->getSize()/2;
             double xmin=e->getX()-e->getSize()/2;
             double ymax=e->getY()+e->getSize()/2;
             double ymin=e->getY()-e->getSize()/2;
             qDebug()<<"*********";
             qDebug()<< xmin << xmax ;
             qDebug()<< ymin << ymax ;
              qDebug()<<"==========";
              qDebug()<< SceneBound.x() << SceneBound.x()+ SceneBound.size().width() ;
              qDebug()<< SceneBound.y() << SceneBound.y()+ SceneBound.size().height() ;
              qDebug()<<"*********";
             if(e){
             if (xmin < SceneBound.x())
                 e->setX(SceneBound.x()+1+e->getSize()/2);
             else if (xmax>  SceneBound.x()+ SceneBound.size().width())
                 e->setX(SceneBound.x()+ SceneBound.size().width()-1-e->getSize()/2);

             if (ymin <  SceneBound.y())
                 e->setY(SceneBound.y()+1+e->getSize()/2);
             else if (ymax >  SceneBound.y()+ SceneBound.size().height()){
                 qDebug()<<"qq";
               //  e->setY(SceneBound.y()+ SceneBound.size().height()-e->getSize()/2);
                 e->setY(50);
             }
            qDebug()<<"HERE";
                e->setSpeed(-1*e->getSpeed());

             }
         }

        if (e){
            e->next();

        }
    }
    }




  //  ui->area->viewport()->repaint();
    /*for(std::vector<entity*>::iterator i=objcts.begin();i!=objcts.end();++i){
            qDebug()<<"X: "<<(*i)->getX()<<"\t"<<"Y: "<<(*i)->getY()<<"COLOR: "<<(*i)->getColor().red()<<(*i)->getColor().green()<<(*i)->getColor().blue()<<std::endl;
            (*i)->next();
    }*/
    ui->area->viewport()->update();
}

void MainWindow::on_speed_slider_rangeChanged(int min, int max)
{

}
void MainWindow::showEvent(QShowEvent *) {
 //   qDebug()<<"OQOQOQ";
 //   ui->area->fitInView(scene->sceneRect(),Qt::KeepAspectRatioByExpanding);
}

