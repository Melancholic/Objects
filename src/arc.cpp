#include "arc.h"
#include"drawarea.h"
#include<iostream>
#include<QDebug>
arc::arc():circle(){
    setColorInner(DrawArea::getBgColor());
    setSizeInner(20);
}
arc::arc(int X, int Y, int Size, QColor Color1, QColor Color2):circle(X,Y,Size,Color1){
    setColorInner(Color2);

}

QColor arc::getColorInner(){
    return ColorInner;
}

void arc::setColorInner(QColor c){
    ColorInner=c;
}

void arc::setSizeInner(int r){
    SizeInner=r;
}

int arc::getSizeInner(){
    return SizeInner;
}
void arc::paint(QPainter*painter, const QStyleOptionGraphicsItem* o, QWidget* w){

         painter->save();
         circle::paint(painter,o,w);
         painter->setBrush(QBrush(ColorInner));
         painter->drawEllipse(pos().x()-SizeInner/2,pos().y()-SizeInner/2,SizeInner,SizeInner);
         painter->restore();
         qDebug()<<"\nCHILD POS X "<<pos().x()<<" ROOT POS Y "<<pos().y();
 }
void arc::next(){
    circle::next();
}

