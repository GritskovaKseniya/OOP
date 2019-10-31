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
    float perimether, area;

    triangle->setVisible();

    triangle->move(3,3);


    triangle->setSizes(7, 40);

    delete triangle;
    delete filledTriangle;
    return 0;
}