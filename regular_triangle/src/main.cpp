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
    Figure * figure;
    float perimether, area;

    triangle->setVisible();
    filledTriangle->setVisible();

    /*figure = triangle;
    cout << " NUMBER 1" << endl;
    figure->move(2,3);

    figure = filledTriangle;
    cout << " NUMBER 2" << endl;
    figure->move(3,4);
    triangle->setVisible();*/

    cout << " Change Border Color " << endl;
    filledTriangle->setBorderColor(c);
    int k = filledTriangle->getBorderColor();
    cout << k << endl;
    cout << " " << endl;

    filledTriangle->move(0,0);

    /*triangle->move(3,3);

    triangle->clacParms(perimether, area);
    cout << " P = " << perimether << endl;
    cout << " S = " << area << endl;
    cout << " " << endl;

    triangle->setSizes(7, 40);

    triangle->clacParms(perimether, area);
    cout << " P = " << perimether << endl;
    cout << " S = " << area << endl;
    cout << " " << endl;*/

    delete triangle;
    delete filledTriangle;
    return 0;
}