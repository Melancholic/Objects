#include "entity.h"
#include<QDebug>

entity::entity(){
    x=0;
    y=0;
    size=10;
    color=Qt::white;
}

entity::~entity(){

}

entity::entity(int X, int Y){
    x=X;
    y=Y;
    size=10;
    color=Qt::white;
}
entity::entity(int X, int Y, int Size){
    x=X;
    y=Y;
    size=Size;
    color=Qt::white;
}

entity::entity(int X, int Y, int Size, QColor Color){
    x=X;
    y=Y;
    size=Size;
    color=Color;
}
