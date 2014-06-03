#include "circleinsquare.h"
#include"drawarea.h"
CircleInSquare::CircleInSquare():circle(),square(){
    setColorInner(DrawArea::getBgColor());

}
CircleInSquare::CircleInSquare(double X, double Y, int Size, QColor Color1, QColor Color2):entity(X,Y,Size,Color1){
    setColorInner(Color2);

}

CircleInSquare::CircleInSquare(double X, double Y, int Size):entity(X,Y,Size){
    setColorInner(DrawArea::getBgColor());
}

QColor CircleInSquare::getColorInner(){
    return ColorInner;
}


void CircleInSquare::setColorInner(QColor c){
    ColorInner=c;
}

void CircleInSquare::setSizeInner(int r){
    SizeInner=r;
}

int CircleInSquare::getSizeInner(){
    return SizeInner;
}
void CircleInSquare::paint(QPainter*painter, const QStyleOptionGraphicsItem* o, QWidget* w){

         painter->save();
         painter->setBrush(QBrush(color));
         square::paint(painter,o,w);
         painter->setBrush(QBrush(ColorInner));
         painter->drawEllipse(entity::x-SizeInner/2,entity::y-SizeInner/2,SizeInner,SizeInner);
         painter->restore();
 }
QPainterPath CircleInSquare::shape()const{
   return square::shape();
}
 QRectF CircleInSquare::boundingRect()const{
     return square::boundingRect();
 }


