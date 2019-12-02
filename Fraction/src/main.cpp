#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Fraction.h"

using namespace std;

int main() {
    int a = 5, b = 8, c = -3, d = 4;

    Fraction first = Fraction(0.05);
    cout << "First fraction: "<< first << " " << endl;
    Fraction second = Fraction(2.04);
    cout << "Second fraction: " << second << " " << endl;
    Fraction third = Fraction(2,4);
    cout << "Third fraction: " << third << " " << endl;
    Fraction fourth = Fraction(1,2);
    cout << "Fourth fraction: " << fourth << " " << endl;

    /*if(third == fourth){
        cout << "Third fraction equal fourth fraction = "<< third << " " << endl;
    } else if(third != fourth){
        cout << "Third fraction no equal fourth fraction "<< third << " " << fourth << " " << endl;
    }*/

    Fraction sum = first + second;
    cout << "First fraction + Second fraction: "; first.print(); cout << " + "; second.print(); cout << " = "; sum.print(); cout << " " << endl;

    first = second;
    cout << "first = second. " << endl; cout << "First fraction: "; first.print(); cout << " " << endl;
    cout << "Second fraction: "; second.print(); cout << " " << endl;

    Fraction sum2 = first + second;
    cout << "First fraction + Second fraction: "; first.print(); cout << " + "; second.print(); cout << " = "; sum2.print(); cout << " " << endl;

    Fraction dif = third - fourth;
    third.print(); cout << " - "; fourth.print(); cout << " = "; dif.print(); cout << " " << endl;

    Fraction mult = fourth * third;
    third.print(); cout << " * "; fourth.print(); cout << " = "; mult.print(); cout << " " << endl;

    Fraction div = first / second;
    first.print(); cout << " / "; second.print(); cout << " = "; div.print(); cout << " " << endl;


    /*if(first == second){
        cout << "First fraction equal second fraction = ";  first.print(); cout << " " << endl;
    } else if(first != second){
        cout << "First fraction no equal second fraction ";  first.print(); cout << " "; second.print(); cout << " " << endl;
    }*/
}