#ifndef ENTITY_H
#define ENTITY_H
#include <QWidget>
typedef double (*fun_t)(double);

class entity{

protected:
        int x,y,size,speed;
        QColor color;
        fun_t function;
        entity();
        entity(int X, int Y);
        entity(int X, int Y, int Size);
        entity(int X, int Y, int Size, QColor Color);
public:
    virtual int getX()=0;
    virtual int getY()=0;
    virtual int getSize()=0;
    virtual fun_t getFunction()=0;
    virtual QColor getColor()=0;
    virtual int getSpeed()=0;
    virtual void setX(int)=0;
    virtual void setY(int)=0;
    virtual void setSize(int)=0;
    virtual void setColor(QColor)=0;
    virtual void setFunction(fun_t)=0;
    virtual void setSpeed(int)=0;
    virtual QPainterPath draw()=0;
    virtual void next()=0;
    virtual ~entity();

};


#endif // ENTITY_H
