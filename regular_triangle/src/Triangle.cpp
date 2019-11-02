#include "Triangle.h"
#include <math.h>

Triangle::Triangle(int c, int x, int y, int length, int alfa):Figure(c, x, y){
    this->length = length;
    this->alfa = alfa;
    bool CorP = correctParametr(length, alfa);
    if( CorP == true){
        this->length = length;
        this->alfa = alfa;
    } else {
        this->length = 2;
        this->alfa = 0;
        cerr << "Not correct parametrs. The default settings are set.\n";
    }
}

Triangle::~Triangle(){

}

void Triangle::calcParms(float& perimeter, float& area) const{
    perimeter = 3*length;
    area = (length*length*sqrt(3))/4;
}

void Triangle::setSizes(int length, int alfa){
    bool CorP = correctParametr(length, alfa);
    if( CorP == true){
        this->length = length;
        this->alfa = alfa;
        draw();
    } else cerr << "That parametrs don't right\n";
    
}

bool Triangle::correctParametr(int length, int alfa){
    if(length > 0){
        return true;
    }
}

int Triangle::getAlfa() const{
    return alfa;
}

int Triangle::getLength() const{
    return length;
}

void Triangle::draw() const {
    cout << " The TRIAHGLE draw " << endl;
    cout << " Center (x;y): (" << x << ";" << y << ") " << endl;
    cout << " The length of a side: " << length << endl;
    cout << " Angle of rotation: " << alfa << endl;
    cout << " Visible: " << isVisible() << endl;
    cout << " Border color: " << getBorderColor() << endl;
    cout << " END "<<endl;
    cout << " " << endl;
}