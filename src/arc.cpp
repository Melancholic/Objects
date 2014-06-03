#include "arc.h"
#include"drawarea.h"
#include<iostream>
#include<QDebug>
arc::arc():entity(){
    setColorInner(DrawArea::getBgColor());
}
arc::arc(double X, double Y, int Size, QColor Color1, QColor Color2):entity(X,Y,Size,Color1){
    setColorInner(Color2);

}

arc::arc(double X, double Y, int Size):entity(X,Y,Size){

    setColorInner(DrawArea::getBgColor());

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
         painter->setBrush(QBrush(color));
         circle::paint(painter,o,w);
         painter->setBrush(QBrush(ColorInner));
         painter->drawEllipse(entity::x-SizeInner/2,entity::y-SizeInner/2,SizeInner,SizeInner);
         painter->restore();
 }
