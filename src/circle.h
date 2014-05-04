#ifndef CIRCLE_H
#define CIRCLE_H
#include"entity.h"
#include <QGraphicsItem>
typedef double (*fun_t)(double);
class circle :  public  entity,public  QGraphicsItem{
public:
    circle();
    circle(entity&);
    circle(int X, int Y);
    circle(int X, int Y, int Size);
    circle(int X, int Y, int Size, QColor Color);
    ~circle();
    int getX();
    int getY();
    int getSize();
    QColor getColor();
    fun_t getFunction();
    int getSpeed();
    void setFunction(fun_t);
    void setSpeed(int);
    void setX(int a);
    void setY(int a);
    void setSize(int);
    void setColor(QColor);
    QPainterPath draw();
    QRectF boundingRect() const;//Жадный прямоугольник фигуры
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);//отрисовка
    void next();
    QPainterPath shape() const;//Точное очертание фигуры для коллизий
};

#endif // CIRCLE_H
