#include "trinagleincircle.h"
#include"drawarea.h"

TrinagleInCircle::TrinagleInCircle():circle(),triangle(){
    setColorInner(DrawArea::getBgColor());

}
TrinagleInCircle::TrinagleInCircle(double X, double Y, int Size, QColor Color1, QColor Color2):entity(X,Y,Size,Color1){
    setColorInner(Color2);

}

TrinagleInCircle::TrinagleInCircle(double X, double Y, int Size):entity(X,Y,Size){
    setColorInner(DrawArea::getBgColor());
}

QColor TrinagleInCircle::getColorInner(){
    return ColorInner;
}


void TrinagleInCircle::setColorInner(QColor c){
    ColorInner=c;
}

void TrinagleInCircle::setSizeInner(int r){
    SizeInner=r;
}

int TrinagleInCircle::getSizeInner(){
    return SizeInner;
}



void TrinagleInCircle::paint(QPainter*painter, const QStyleOptionGraphicsItem* o, QWidget* w){
    if(ColorInner!=DrawArea::getBgColor()){
        ColorInner=DrawArea::getBgColor();
    }
    double tmp =size;
    painter->save();
    painter->setBrush(QBrush(color));
    circle::paint(painter,o,w);
    triangle::setSize(SizeInner);
    painter->fillPath(triangle::shape(),QBrush(ColorInner));
    setSize(tmp);
    painter->restore();
 }
QPainterPath TrinagleInCircle::shape()const{
   return triangle::shape();
}
 QRectF TrinagleInCircle::boundingRect()const{
     return triangle::boundingRect();
 }


