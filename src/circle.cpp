#include "circle.h"
#include "entity.h"
#include<QPainter>
#include<iostream>
#include<QDebug>


circle::circle():entity(0,0){
}

circle::circle(double X, double Y):entity(X,Y){

}
circle::circle(entity& arg){
     entity::setX(arg.getX());
     entity::setY(arg.getY());
     entity::size=arg.getSize();
     entity::color=arg.getColor();
     setFlag(ItemIsMovable,true);
}

circle::circle(double X, double Y, int Size):entity(X,Y,Size){
}
circle::circle(double X, double Y, int Size, QColor Color):entity(X,Y,Size,Color){
}

circle::~circle(){
}


QRectF circle::boundingRect() const{
    return QRect(entity::x-entity::size/2,entity::y-entity::size/2,entity::size,entity::size);
}

void circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *,QWidget *){
     painter->save();
     painter->setBrush(QBrush(entity::color));
     painter->drawEllipse(entity::x-entity::size/2,entity::y-entity::size/2,entity::size,entity::size);
     painter->restore();
}


 QPainterPath  circle::shape() const{
     QPainterPath path;
     path.addEllipse(boundingRect());
     return path;
 }
