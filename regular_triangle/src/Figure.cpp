#include "Figure.h"

Figure::Figure(int c, int x, int y){
    this->c = c;
    this->x = x;
    this->y = y;
}

Figure::~Figure(){

}

void Figure::move(int dx, int dy){

}

void Figure::setBorderColor(int c){

}

int Figure::getBorderColor() const{

}

void Figure::setVisible( bool isVisible = true ){

}

bool Figure::isVisible() const{
    return visible;
}