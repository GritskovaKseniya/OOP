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

void FilledTriangle::draw() const {
    cout << " The FILLED TRIAHGLE draw " << endl;
    cout << " Center (x;y): (" << x << ";" << y << ") " << endl;
    cout << " The length of a side: " << getLength() << endl;
    cout << " Angle of rotation: " << getAlfa() << endl;
    cout << " Visible: " << isVisible() << endl;
    cout << " Border color: " << getBorderColor() << endl;
    cout << " END "<<endl;
}