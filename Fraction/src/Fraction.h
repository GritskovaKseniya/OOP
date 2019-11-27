#pragma once

#include <iostream>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    ///default constructor
    Fraction():Fraction(1, 1){};

    //Fraction(const Fraction* other); // конструктор копирования
    
    ~Fraction();
    ///function sweetens fractions
    void operator +(Fraction* other);
    ///
    void operator -(Fraction* other);
    ///
    void operator =(Fraction* other);
    ///
    void operator !=(Fraction* other);
    /// ptint fraction
    void print(); 
private:
    /// fraction numerator
    int numerator;
    /// fraction denominator
    int denominator;
    /// check correct parametr
    bool check_parameter(int numerator, int denominator);
    /// simplification fraction
    int simplification();
    /// find commo denominator in two fraction
    int find_common_denominator(int other_denominatorher);

    int Fraction::find_new_numerator(int other_numerator);

};