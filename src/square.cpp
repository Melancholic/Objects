#include "square.h"
#include "entity.h"
#include<QPainter>
#include<iostream>
#include<QDebug>


square::square():entity(0,0){
}

square::square(double X, double Y):entity(X,Y){

}
square::square(entity& arg){
     entity::setX(arg.getX());
     entity::setY(arg.getY());
     entity::size=arg.getSize();
     entity::color=arg.getColor();
}

square::square(double X, double Y, int Size):entity(X,Y,Size){
}
square::square(double X, double Y, int Size, QColor Color):entity(X,Y,Size,Color){
}

square::~square(){
}


QRectF square::boundingRect() const{
    return QRect(entity::x-entity::size/2,entity::y-entity::size/2,entity::size,entity::size);
}

void square::paint(QPainter *painter, const QStyleOptionGraphicsItem *,QWidget *){
     painter->save();
     painter->setBrush(QBrush(entity::color));
     painter->drawRect(boundingRect());
     painter->restore();
}


 QPainterPath  square::shape() const{
     QPainterPath path;
     path.addRect(boundingRect());
     return path;
 }


