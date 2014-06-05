#include "triangle.h"
#include<QPainterPath>
#include<QPainter>
triangle::triangle():entity(0,0){
}

triangle::triangle(double X, double Y):entity(X,Y){

}
triangle::triangle(entity& arg){
     entity::setX(arg.getX());
     entity::setY(arg.getY());
     entity::size=arg.getSize();
     entity::color=arg.getColor();
}

triangle::triangle(double X, double Y, int Size):entity(X,Y,Size){
}
triangle::triangle(double X, double Y, int Size, QColor Color):entity(X,Y,Size,Color){
}

triangle::~triangle(){
}


QRectF triangle::boundingRect() const{
    return QRect(entity::x-entity::size/2,entity::y-entity::size/2,entity::size,entity::size);
}

void triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *,QWidget *){
     painter->save();
    // painter->setBrush(QBrush(entity::color));
    /* QPainterPath path;
     path.moveTo(entity::x-entity::size/2,entity::y-entity::size/2);
     path.lineTo(entity::x+entity::size/2,entity::y-entity::size/2);
     path.lineTo(entity::x,entity::y+entity::size/2);
     path.lineTo(entity::x-entity::size/2,entity::y-entity::size/2);*/
     painter->fillPath(shape(),QBrush(entity::color));
     painter->restore();
}


 QPainterPath  triangle::shape() const{
     QPainterPath path;
     path.moveTo(entity::x-entity::size/2,entity::y-entity::size/2);
     path.lineTo(entity::x+entity::size/2,entity::y-entity::size/2);
     path.lineTo(entity::x,entity::y+entity::size/2);
     path.lineTo(entity::x-entity::size/2,entity::y-entity::size/2);
     return path;
 }



