#ifndef DRAWAREA_H
#define DRAWAREA_H
#include <QWidget>
#include<vector>
#include<entity.h>
#include<QGraphicsScene>
#include<QGraphicsView>
class DrawArea :  public QGraphicsView{
    Q_OBJECT
    static QColor BgColor;
public:
    void resizeEvent( QResizeEvent*);
    DrawArea(QWidget* par);
    static void setBgColor(QColor);
    static QColor getBgColor();
};
#endif // DRAWAREA_H
