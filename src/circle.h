#ifndef CIRCLE_H
#define CIRCLE_H
#include"entity.h"
#include <QGraphicsItem>
typedef double (*fun_t)(double);
class circle :  public  virtual entity,public  virtual QGraphicsItem{
public:
    circle();
    circle(entity&);
    circle(double X, double Y);
    circle(double X, double Y, int Size);
    circle(double X, double Y, int Size, QColor Color);
    ~circle();
     /*double getX();
     double getY();
    int getSize();
    QColor getColor();
     fun_t getFunction();
     double getSpeed();
     void setFunction(fun_t);
     void setSpeed(double);
     void setX(double a);
     void setY(double a);
    void setSize(int);
    void setColor(QColor);*/
    //QPainterPath draw();
    QRectF boundingRect() const;//Жадный прямоугольник фигуры
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);//отрисовка
    // void next();
    QPainterPath shape() const;//Точное очертание фигуры для коллизий
};

#endif // CIRCLE_H
