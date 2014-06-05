#ifndef TRINAGLEINCIRCLE_H
#define TRINAGLEINCIRCLE_H
#include"circle.h"
#include"triangle.h"
class TrinagleInCircle : public circle, public  triangle{
    QColor ColorInner;
    int SizeInner;
public:
    TrinagleInCircle();
    TrinagleInCircle(double X, double Y, int Size, QColor Color1, QColor Color2);
    TrinagleInCircle(double X, double Y, int Size);
    QColor getColorInner();
    void setColorInner(QColor);
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);//отрисовка
    void setSizeInner(int);
    int getSizeInner();
    QPainterPath shape()const ;
    QRectF boundingRect()const;


};
#endif // TRINAGLEINCIRCLE_H
