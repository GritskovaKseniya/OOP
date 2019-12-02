#pragma once

#include <iostream>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    ///default constructor
    ///Fraction():Fraction(1, 1){};
    /// Integer number
    Fraction(int num):Fraction(num, 1){};

    Fraction(double number);

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
    bool operator !=(const Fraction &other);
    ///
    bool operator ==(const Fraction &other);
    /// ptint fraction
    void print(); 
    /// simplification fraction сокращение дроби
    Fraction Cancellation() const;

     friend ostream& operator<<(ostream& out, const Fraction& f);

private:
    /// fraction numerator
    int numerator;
    /// fraction denominator
    int denominator;
    /// check correct parametr
    bool check_parameter(int denominator);
   
};