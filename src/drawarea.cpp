#include"drawarea.h"
#include<cstdlib>
#include<QPainter>
#include<iostream>
#include<circle.h>
#include <QPaintEvent>
#include<cmath>
#include<QDebug>
QColor DrawArea::BgColor;


void DrawArea::resizeEvent(QResizeEvent *evnt)
{
    qDebug()<<"resize from "<<scene()->sceneRect().width()<<" "<<scene()->sceneRect().height();
   /* if(scene()){
        scene()->setSceneRect(QRect(QPoint(0,0),evnt->size()));

    }*/
    fitInView(scene()->sceneRect(),Qt::KeepAspectRatio);
  // scale(evnt->size().width()/scene()->sceneRect().width(),evnt->size().width()/scene()->sceneRect().width());
  // setSceneRect(scene()->sceneRect());
qDebug()<<"res:  "<<scene()->sceneRect().width()<<" "<<scene()->sceneRect().height();
    //scene()->addRect(scene()->sceneRect(),QPen(Qt::red));
    QGraphicsView::resizeEvent(evnt);
}

DrawArea::DrawArea(QWidget* par):QGraphicsView(par){
}
void DrawArea::setBgColor(QColor Color){
    DrawArea::BgColor=Color;
}

QColor DrawArea::getBgColor(){
    return DrawArea::BgColor;
}
void DrawArea::mouseDoubleClickEvent(QMouseEvent* /*event*/)
{
    doubleClick();
}

