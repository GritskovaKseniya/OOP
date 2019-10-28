#include "Figure.h"

Figure::Figure(int c, int x, int y){
    this->c = c;
    this->x = x;
    this->y = y;
    visible = false;
}

void Figure::move(int dx, int dy){
    /// Если фигура видимая - сдвигаем параметры на дельту и рисуем, иначе просто сдвигаем параметры и запоминаем их.
    x+= dx;
    y+= dy;
    if(visible == true){
        draw();
    }
}

void Figure::setBorderColor(int c){
    /// Если фигура видимая - сохраняем значение и вызываем метод draw.
    this->c = c;
    if(visible == true){ 
        draw();
    }
}

int Figure::getBorderColor() const{
    return c;
}

void Figure::setVisible(bool isVisible = true){
    bool oldVisible = visible;
    visible = isVisible;
    // Если старое состояние видимости "не видимый", а новое "видимый" вызываем метод draw.
    if(isVisible == true && oldVisible == false){ 
        draw();
    }
}

bool Figure::isVisible() const{
    return visible;
}

