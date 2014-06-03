#ifndef ENTITY_H
#define ENTITY_H
#include <QWidget>
typedef double (*fun_t)(double);

class entity{

protected:
        int size;
        double x,y,speed;
        QColor color;
        fun_t function;
        entity();
        entity(double X, double Y);
        entity(double X, double Y, int Size);
        entity(double X, double Y, int Size, QColor Color);
public:
    double getX();
    double getY();
    int getSize();
    fun_t getFunction();
    QColor getColor();
    double getSpeed();
    void setX(double);
    void setY(double);
    void setSize(int);
    void setColor(QColor);
    void setFunction(fun_t);
    void setSpeed(double);

    void next();
    ~entity();

};


#endif // ENTITY_H
