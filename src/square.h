#ifndef SQUARE_H
#define SQUARE_H
#include"entity.h"
#include <QGraphicsItem>

class square:  public  virtual entity,public virtual  QGraphicsItem
{
public:
    square();
    square(entity&);
    square(double X, double Y);
    square(double X, double Y, int Size);
    square(double X, double Y, int Size, QColor Color);
    ~square();
    QRectF boundingRect() const;//Жадный прямоугольник фигуры
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);//отрисовка
   QPainterPath shape() const;//Точное очертание фигуры для коллизий
};

#endif // SQUARE_H
