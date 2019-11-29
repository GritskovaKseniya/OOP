#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Fraction.h"

using namespace std;


int main() {
    int a = 5, b = 8, c = 3, d = 4;
    Fraction first = Fraction(a,b);
    cout << "first: ";  first.print(); cout << " " << endl;
    Fraction second = Fraction(c,d);
    cout << "second: "; second.print(); cout << " " << endl;

    Fraction sum = first + second;
    sum.print();

    Fraction dif = first - second;
    dif.print();

    Fraction mult = first * second;
    mult.print();

    Fraction div = first / second;
    div.print();

    first = second;
    first.print();
}