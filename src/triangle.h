#ifndef TRIANGLE_H
#define TRIANGLE_H
#include"entity.h"
#include"QGraphicsItem"
class triangle:  public virtual entity,public virtual  QGraphicsItem{
public:
    triangle();
    triangle(entity&);
    triangle(double X, double Y);
    triangle(double X, double Y, int Size);
    triangle(double X, double Y, int Size, QColor Color);
    ~triangle();
    QRectF boundingRect() const;//Жадный прямоугольник фигуры
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);//отрисовка
   QPainterPath shape() const;//Точное очертание фигуры для коллизий
};
#endif // TRIANGLE_H
