#ifndef TRINAGLEINARC_H
#define TRINAGLEINARC_H
#include"circleinsquare.h"
#include"triangle.h"
class TrinagleInArc: public CircleInSquare, public  triangle{
    QColor ColorInner;
    int SizeInner;
public:
    TrinagleInArc();
    TrinagleInArc(double X, double Y, int Size, QColor Color1, QColor Color2);
    TrinagleInArc(double X, double Y, int Size);
    QColor getColorInner();
    void setColorInner(QColor);
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);//отрисовка
    void setSizeInner(int);
    int getSizeInner();
    QPainterPath shape()const ;
    QRectF boundingRect()const;


};
#endif // TRINAGLEINARC_H
