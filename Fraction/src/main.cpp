#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Fraction.h"

using namespace std;


int main() {
    int a = 5, b = 8, c = 3, d = 4;
    Fraction first = Fraction(d, b);
    cout << "first: ";  first.print(); cout << " " << endl;
    Fraction second = Fraction(a,b);
    cout << "second: "; second.print(); cout << " " << endl;
    Fraction se = Fraction(3.15);
    se.print();
/*
    first = second;
    cout << "first: ";  first.print(); cout << " " << endl;
    cout << "second: "; second.print(); cout << " " << endl;
    cout << "Cancellation: "; first.Cancellation(); cout << " " << endl;

    Fraction sum = first + second;
    cout << "sum: "; sum.print(); cout << " " << endl;

    Fraction dif = first - second;
    cout << "dif: "; dif.print(); cout << " " << endl;

    Fraction mult = first * second;
    cout << "mult: "; mult.print(); cout << " " << endl;

    Fraction div = first / second;
    cout << "div: "; div.print(); cout << " " << endl;

    if(first == second){
        cout << "Fraction equal: ";  first.print(); cout << " " << endl;
    } else cout << "no equal " << endl;

    if(first != second){
        cout << "Fraction no equal: ";  first.print(); cout << " "; second.print(); cout << " " << endl;
    } else cout << " equal " << endl;

    */
    
}