#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Fraction.h"

using namespace std;


int main() {
    int a = 16;
    int b = 4;
    Fraction* fraction = new Fraction(a,b);
    fraction->print();
}