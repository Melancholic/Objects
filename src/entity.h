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
    virtual double getX()=0;
    virtual double getY()=0;
    virtual int getSize()=0;
    virtual fun_t getFunction()=0;
    virtual QColor getColor()=0;
    virtual double getSpeed()=0;
    virtual void setX(double)=0;
    virtual void setY(double)=0;
    virtual void setSize(int)=0;
    virtual void setColor(QColor)=0;
    virtual void setFunction(fun_t)=0;
    virtual void setSpeed(double)=0;

    virtual void next()=0;
    virtual ~entity();

};


#endif // ENTITY_H
