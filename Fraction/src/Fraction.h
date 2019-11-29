#pragma once

#include <iostream>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    ///default constructor
    Fraction():Fraction(1, 1){};
    /// Integer number
    Fraction(int number):Fraction(number, 1){};

    Fraction(const Fraction &other); // конструктор копирования
    
    ~Fraction();

    int sign() const; // fraction sign
    ///function sweetens fractions
    Fraction operator +(const Fraction &other);
    ///
    Fraction operator -(const Fraction &other);

    Fraction operator *(const Fraction &other);

    Fraction operator /(const Fraction &other);
    ///
    Fraction operator =(const Fraction &other);
    ///
    Fraction operator !=(const Fraction &other);
    /// ptint fraction
    void print(); 
private:
    /// fraction numerator
    int numerator;
    /// fraction denominator
    int denominator;
    /// Integer number
    int number;
    /// fraction integer part
    int intPart;
 
    /// check correct parametr
    bool check_parameter(int denominator);
   
   
    /// simplification fraction сокращение дроби
    void Cancellation();
    /// преобразование в смешанный вид
    void GetMixedView();
    /// выделение целой части
    void GetIntPart(); 
    /// find commo denominator in two fraction
    int find_common_denominator(int other_denominatorher);

    int find_new_numerator(int other_numerator);

    int getNumerator() const;
    int getDenominator() const;


};