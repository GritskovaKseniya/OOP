#include "FilledTriangle.h"

FilledTriangle::FilledTriangle(int c, int x, int y, int length, int alfa, int f):Triangle(c, x, y, length, alfa){
    this->f = f;
}

FilledTriangle::~FilledTriangle(){

}

void FilledTriangle::setFillColor(int f){

}
    
void FilledTriangle::setBorderColor(int c){
    // Если цвет границ и заполнения не равны, меняем его.
    if(c != this->f){
        c = f;
    }

}