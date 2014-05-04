#include"drawarea.h"
#include<cstdlib>
#include<QPainter>
#include<iostream>
#include<circle.h>
#include <QPaintEvent>
#include<cmath>

double q(double x){
    return 2*x;
}
DrawArea::DrawArea(QGraphicsScene* sc):QGraphicsView(sc){

}
DrawArea::DrawArea(QWidget *parent) : QGraphicsView ( parent ) {
    fullMode = false;
    width = 500;
    height = 500;
   // scene=new (QRectF(0,0,500,500));



    circle *obj=new circle();
    circle *obj1=new circle();
    obj1->setX(10);obj1->setY(20);
    circle *obj2=new circle(5,55);
    obj->setColor(Qt::white);
    obj1->setColor(Qt::green);
    obj2->setColor(Qt::red);
    obj1->setSize(100);
    obj->setFunction(q);
    obj1->setFunction(sin);
    obj2->setFunction(sqrt);
    obj2->setSpeed(10);
    obj1->setSpeed(-2);
    obj->setSpeed(5);
    objcts.push_back(obj);
    objcts.push_back(obj1);
        objcts.push_back(obj2);
/*scene->addItem(obj);
scene->addItem(obj2);
scene->addItem(obj1);
    setScene(scene);*/


}

void DrawArea::next_step(){
;
    for(std::vector<entity*>::iterator i=objcts.begin();i!=objcts.end();++i){
            std::cerr<<"X: "<<(*i)->getX()<<"\t"<<"Y: "<<(*i)->getY()<<"COLOR: "<<(*i)->getColor().red()<<(*i)->getColor().green()<<(*i)->getColor().blue()<<std::endl;
            (*i)->next();
    }
    viewport()->update();
  //  std::cerr<<"size: "<<scene->items().size();
}

void DrawArea::setBgColor(QColor color){
    bgColor=color;
}

QColor DrawArea::getBgColor(){
    return bgColor;
}

void DrawArea::paintEvent(QPaintEvent* event)
{
  /*   QPainter *painter=new QPainter(this);
     painter->fillRect(event->rect(),QBrush(bgColor));
    for(std::vector<entity*>::iterator i=objcts.begin();i!=objcts.end();++i){
        painter->setPen(QPen((*i)->getColor()));
        ((circle)(*(*i))).paint(painter,NULL,this);
        if(((circle)(*(*i))).scene()->collidingItems((circle*)(*i)).isEmpty() ){
            std::cerr<<"\nКоллизий нет";
        }
    }
    delete painter;*/
}
void DrawArea::drawBackground ( QPainter * painter, const QRectF & rect ){
    std::cerr<<"i called";
        painter->save();
    painter->fillRect(QRectF(0,0,500,500),QBrush(Qt::black));
        painter->fillRect(rect,QBrush(Qt::black));
           painter->restore();
}

DrawArea::~DrawArea(){
    objcts.clear();
}
