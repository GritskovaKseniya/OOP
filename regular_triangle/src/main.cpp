#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Figure.h"
#include "Triangle.h"
#include "FilledTriangle.h"

using namespace std;

int main() {
    int c, x, y, length, alfa, f;
    //Figure* figure;
    c = 455;
    x = 2;
    y = 1;
    length = 4;
    alfa = 47;
    f = 17; 
    Triangle* triangle = new Triangle(c, x, y, length, alfa);
    FilledTriangle* filledTriangle = new FilledTriangle(c, x, y, length, alfa, f);
    Figure* figure;
    float perimether, area;

    triangle->setVisible();
    filledTriangle->setVisible();


    cout << " Moving triangle......  " << endl;
    triangle->move(3,3);
    cout << " Changing triangle parameters......  " << endl;
    triangle->setSizes(7,30);
    cout << " Getting angle......  " << endl;
    int k = triangle->getAlfa();
    cout << " Angle is  " << k << endl;
    cout << " " << endl;
    cout << " Getting length of a side......  " << endl;
    int m = triangle->getLength();
    cout << " The length of a side  " << m << endl;
    cout << " " << endl;


    cout << " Moving filled triangle......  " << endl;
    filledTriangle->move(4,4);
    cout << " Changing filled triangle parameters......  " << endl;
    filledTriangle->setSizes(17,45);
    cout << " Getting angle......  " << endl;
    int o = filledTriangle->getAlfa();
    cout << " Angle is  " << o << endl;
    cout << " " << endl;
    cout << " Getting length of a side......  " << endl;
    int w = filledTriangle->getLength();
    cout << " The length of a side  " << w << endl;
    cout << " " << endl;
    cout << " Change Border Color (filled triangle) " << endl;
    filledTriangle->setBorderColor(c);
    int l = filledTriangle->getBorderColor();
    int p = filledTriangle->getFillColor();
    cout << " Border Color " << l << endl;
    cout << " " << endl;
    cout << " Moving filled triangle... " << endl;
    filledTriangle->move(0,0);


    figure = triangle;
    cout << " Moving figure (triangle)..." << endl;
    figure->move(2,3);
    figure->calcParms(perimether, area);
    cout << " P = " << perimether << endl;
    cout << " S = " << area << endl;
    cout << " " << endl;



    figure = filledTriangle;
    cout << " Moving figure (filledtriangle)... " << endl;
    figure->move(3,4);
    figure->calcParms(perimether, area);
    cout << " P = " << perimether << endl;
    cout << " S = " << area << endl;
    cout << " " << endl;


    delete triangle;
    delete filledTriangle;
    return 0;
}