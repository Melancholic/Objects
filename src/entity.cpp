#include "entity.h"
#include<QDebug>

entity::entity(){
   /* x=0;
    y=0;
    size=10;
    color=Qt::white;*/
}

entity::~entity(){

}

entity::entity(double X, double Y){
    x=X;
    y=Y;
    size=10;
    color=Qt::white;
}
entity::entity(double X, double Y, int Size){
    x=X;
    y=Y;
    size=Size;
    color=Qt::white;
}

entity::entity(double X, double Y, int Size, QColor Color){
    x=X;
    y=Y;
    size=Size;
    color=Color;
}
double entity::getX(){
    return x;
}

double entity::getY(){
    return y;
}

int entity::getSize(){
    return size;
}

fun_t entity::getFunction(){
    return function;
}

QColor entity::getColor(){
    return color;
}

double entity::getSpeed(){
    return speed;
}

void entity::setX(double a){
    x=a;
}

void entity::setY(double a){
    y=a;
}
void entity::setSize(int a){
    size=a;
}
void entity::setColor(QColor a){
    color=a;
}
void entity::setFunction(fun_t f){
    function=f;
}
void entity::setSpeed(double a){
    speed= a;
}

void entity::next(){
    x+=speed;
    y=function(x);
}

