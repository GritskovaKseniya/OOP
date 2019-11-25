#pragma once

#include <iostream>

using namespace std;

class Fraction {
public:
    Fraction(double c);
    Fraction(const double* c);
    ~Fraction();
    void operator +(double c);
    void operator -(double c);
    void operator =(double c);
    void operator !=(double c);
    double print(); 
private:
    double* c;
};