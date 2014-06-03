#ifndef CIRCLEINSQUARE_H
#define CIRCLEINSQUARE_H
#include <QGraphicsItem>
#include"circle.h"
#include"square.h"
class CircleInSquare: public circle, public  square{
    QColor ColorInner;
    int SizeInner;
public:
    CircleInSquare();
    CircleInSquare(double X, double Y, int Size, QColor Color1, QColor Color2);
    CircleInSquare(double X, double Y, int Size);
    QColor getColorInner();
    void setColorInner(QColor);
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);//отрисовка
    void setSizeInner(int);
    int getSizeInner();
    QPainterPath shape()const ;
     QRectF boundingRect()const;

};

#endif // CIRCLEINSQUARE_H
