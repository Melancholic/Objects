#ifndef DRAWAREA_H
#define DRAWAREA_H
#include <QWidget>
#include<vector>
#include<entity.h>
#include<QGraphicsScene>
#include<QGraphicsView>
class DrawArea :  public QGraphicsView{
    Q_OBJECT
private:
       int  width, height;
       QColor bgColor;
       bool fullMode;
       std::vector<entity*> objcts;
       QGraphicsScene *scene;
public:
    DrawArea (QWidget *parent);
    DrawArea (QGraphicsScene*);
    ~DrawArea();
    void paintEvent(QPaintEvent *event);
    void setBgColor(QColor color);
    QColor getBgColor();
    void drawBackground ( QPainter * painter, const QRectF & rect );
public slots:
   void next_step();


};
#endif // DRAWAREA_H
