#ifndef ARC_H
#define ARC_H
#include"circle.h"
#include <QGraphicsItem>
class arc: public  circle{
    QColor ColorInner;
    int SizeInner;
public:
    arc();
    arc(double X, double Y, int Size, QColor Color1, QColor Color2);
    QColor getColorInner();
    void setColorInner(QColor);
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);//отрисовка
    void next();
    void setSizeInner(int);
    int getSizeInner();

};

#endif // ARC_H
