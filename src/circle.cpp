#include "circle.h"
#include "entity.h"
#include<QPainter>
#include<iostream>


circle::circle():entity(){
    setFlag(ItemIsMovable,true);
}

circle::circle(int X, int Y):entity(X,Y){

}
circle::circle(entity& arg){
     entity::x= arg.getX();
     entity::y=arg.getY();
     entity::size=arg.getSize();
     entity::color=arg.getColor();
     setFlag(ItemIsMovable,true);
}

circle::circle(int X, int Y, int Size):entity(X,Y,Size){
    setFlag(ItemIsMovable,true);
}
circle::circle(int X, int Y, int Size, QColor Color):entity(X,Y,Size,Color){
    setFlag(ItemIsMovable,true);
}

circle::~circle(){
}
int circle::getX(){
    return  entity::x;
}
int circle::getY(){
    return  entity::y;
}

int circle::getSize(){
    return  entity::size;
}

QColor circle::getColor(){

    return  entity::color;
}

fun_t circle::getFunction(){
    return entity::function;
}

int circle::getSpeed(){
    return entity::speed;
}


void circle::setX(int a){
     entity::x=a;
}

void circle::setY(int a){
     entity::y=a;
}
void circle::setSize(int a){
     entity::size=a;
}

void circle::setColor(QColor a){

     entity::color=a;
}

void circle::setFunction(fun_t f){
    entity::function=f;
}
void circle::setSpeed(int a){
    entity::speed=a;
}

QPainterPath  circle::draw(){
    QPainterPath painter;
    painter.addEllipse(entity::x+entity::size/2,entity::y+entity::size/2,entity::size,entity::size);
    return painter;
}
QRectF circle::boundingRect() const{
    return QRectF(entity::x+entity::size/2,entity::y+entity::size/2,entity::size,entity::size);
}

void circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                QWidget *){
     painter->save();
     painter->setBrush(QBrush(entity::color));
    painter->drawEllipse(entity::x+entity::size/2,entity::y+entity::size/2,entity::size,entity::size);
     painter->restore();
}

void circle::next(){
    entity::x+=entity::speed;
    entity::y=entity::function(entity::x);
}

 QPainterPath  circle::shape() const{
     QPainterPath path;
     path.addEllipse(boundingRect());
     return path;
 }
