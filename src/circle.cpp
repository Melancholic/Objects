#include "circle.h"
#include "entity.h"
#include<QPainter>
#include<iostream>
#include<QDebug>


circle::circle():entity(){
    setFlag(ItemIsMovable,true);
    setX(entity::x);
    setY(entity::x);
}

circle::circle(int X, int Y):entity(X,Y){
    setX(X);
    setY(Y);

}
circle::circle(entity& arg){
     setX(arg.getX());
     setY(arg.getY());
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
     this->setPos(a,entity::y);
}

void circle::setY(int a){
     entity::y=a;
     this->setPos(entity::x,a);
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

QRectF circle::boundingRect() const{
    return QRect(pos().x()-entity::size/2,pos().y()-entity::size/2,entity::size,entity::size);
}

void circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                QWidget *){
     painter->save();
     painter->setBrush(QBrush(entity::color));
     painter->drawEllipse(pos().x()-entity::size/2,pos().y()-entity::size/2,entity::size,entity::size);
     painter->restore();
     qDebug()<<"\nROOT POS X "<<pos().x()<<" ROOT POS Y "<<pos().y();
}

void circle::next(){
    entity::x+=entity::speed;
    entity::y=entity::function(entity::x);
    this->setPos(entity::x,entity::y);
}

 QPainterPath  circle::shape() const{
     QPainterPath path;
     path.addEllipse(boundingRect());
     return path;
 }
