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
    if(scene()){
        scene()->setSceneRect(QRect(QPoint(-evnt->size().width()/2,-evnt->size().height()/2),evnt->size()));

    }
    fitInView(scene()->sceneRect(),Qt::KeepAspectRatio);
qDebug()<<"res:  "<<scene()->sceneRect().width()<<" "<<scene()->sceneRect().height();
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
