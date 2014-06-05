#include"trinagleinarc.h"
#include"drawarea.h"

TrinagleInArc::TrinagleInArc():CircleInSquare(),triangle(){
    setColorInner(DrawArea::getBgColor());

}
TrinagleInArc::TrinagleInArc(double X, double Y, int Size, QColor Color1, QColor Color2):entity(X,Y,Size,Color1){
    setColorInner(Color2);

}

TrinagleInArc::TrinagleInArc(double X, double Y, int Size):entity(X,Y,Size){
    setColorInner(DrawArea::getBgColor());
}

QColor TrinagleInArc::getColorInner(){
    return ColorInner;
}


void TrinagleInArc::setColorInner(QColor c){
    ColorInner=c;
}

void TrinagleInArc::setSizeInner(int r){
    SizeInner=r;
}

int TrinagleInArc::getSizeInner(){
    return SizeInner;
}



void TrinagleInArc::paint(QPainter*painter, const QStyleOptionGraphicsItem* o, QWidget* w){
    if(ColorInner!=DrawArea::getBgColor()){
        ColorInner=DrawArea::getBgColor();
    }
    double tmp =size;
    painter->save();
    painter->setBrush(QBrush(color));
    CircleInSquare::paint(painter,o,w);
    triangle::setSize(SizeInner);
    painter->fillPath(triangle::shape(),QBrush(ColorInner));
    setSize(tmp);
    painter->restore();
 }
QPainterPath TrinagleInArc::shape()const{
   return triangle::shape();
}
 QRectF TrinagleInArc::boundingRect()const{
     return triangle::boundingRect();
 }


