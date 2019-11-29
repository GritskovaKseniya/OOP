#include "Fraction.h"
#include <string>
#include <sstream>
#include <iostream>

Fraction::Fraction(int numerator, int denominator){
    this->numerator = numerator;
    this->denominator = denominator;
}

Fraction::Fraction(const Fraction &other){
    this->numerator = other.numerator;
    this->denominator = other.denominator;
}


Fraction::~Fraction(){
}

Fraction Fraction::operator+(const Fraction &other){
    int new_numerator = numerator*other.denominator + other.numerator*denominator;
    int new_denominator = denominator*other.denominator;
    Fraction result(new_numerator,new_denominator);
    result.Cancellation();
    return result;
}
    
Fraction Fraction::operator -(const Fraction &other){
    int new_numerator = numerator*other.denominator - other.numerator*denominator;
    int new_denominator = denominator*other.denominator;
    Fraction result(new_numerator,new_denominator);
    result.Cancellation();
    return result;  
}

Fraction Fraction::operator *(const Fraction &other){
    int new_numerator = numerator*other.numerator;
    int new_denominator = denominator*other.denominator;
    Fraction result(new_numerator,new_denominator);
    result.Cancellation();
    return result;  
}

Fraction Fraction::operator /(const Fraction &other){
    int new_numerator = numerator*other.denominator;
    int new_denominator = denominator*other.numerator;
    Fraction result(new_numerator,new_denominator);
    result.Cancellation();
    return result;  
}
Fraction Fraction::operator =(const Fraction &other){
    this->numerator = other.numerator;
    this->denominator = other.denominator;
    return *this;
}

bool Fraction::operator !=(const Fraction &other){
    return !(*this == other);
}

bool Fraction::operator ==(const Fraction &other){
    return this->numerator == other.numerator
        && this->denominator == other.denominator;
}

void Fraction::print(){
    bool check = check_parameter(denominator);
    if(check == true){
        if(numerator == denominator){
            cout << 1 << endl;
        }
        cout << numerator << "/" << denominator << endl;
    }else if(numerator == 0){
        cout << 0 << endl;
    }else if(denominator == 0){
        cout << 0 << endl;
    }
}

bool Fraction::check_parameter(int denominator){
    if(denominator > 0 && numerator > 0){
        return true;
    }
}

// module
int abs (int value) {
	return (value < 0) ? -value : value;
}
// Euclid's algorithm НОД
int gcd (int a, int b) {
	while (b)
		b ^= a ^= b ^= a %= b;
	return abs(a);
}
// smallest common multiple НОК
int scm(int a, int b) 
{ 
  return a*b / gcd(a, b); 
}

Fraction Fraction::Cancellation(){
    int GCD = gcd(numerator, denominator);
    int new_numerator = numerator/GCD;
    int new_denominator = denominator/GCD;
    Fraction reduced_fraction(new_numerator,new_denominator);
    return reduced_fraction;
}

Fraction Fraction::doubleToFraction(double number){
    double fraction_part = number - ((long)number);
    std::stringstream ss;
    ss << fraction_part;
    string s = ss.str();
    int degree = s.length() - 2;
    int den = 1;
    for(int i = 0; i < degree;i++){
        den = den*10;
    }
    int num = number*den;
    Fraction fraction(num, den);
    return fraction;
}
