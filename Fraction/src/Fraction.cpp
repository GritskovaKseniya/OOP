#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator){
        this->numerator = numerator;
        this->denominator = denominator;
}

Fraction::~Fraction(){
}

Fraction Fraction::operator+(const Fraction &other){
    int new_numerator = numerator*other.denominator + other.numerator*denominator;
    int new_denominator = denominator*other.denominator;
    Fraction result(new_numerator,new_denominator);
    return result;
}
    
Fraction Fraction::operator -(const Fraction &other){
    int new_numerator = numerator*other.denominator - other.numerator*denominator;
    int new_denominator = denominator*other.denominator;
    Fraction result(new_numerator,new_denominator);
    return result;  
}

Fraction Fraction::operator *(const Fraction &other){
    int new_numerator = numerator*other.numerator;
    int new_denominator = denominator*other.denominator;
    Fraction result(new_numerator,new_denominator);
    return result;  
}

Fraction Fraction::operator /(const Fraction &other){
    int new_numerator = numerator*other.denominator;
    int new_denominator = denominator*other.numerator;
    Fraction result(new_numerator,new_denominator);
    return result;  
}
Fraction Fraction::operator =(const Fraction &other){
    /*this->numerator = other.numerator;
    this->denominator = other.denominator;
    return *this;*/
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
        cout << numerator << "/" << denominator << endl;
    }else
    {
        cout << " Denominator is not correct" << endl;
    }
}

bool Fraction::check_parameter(int denominator){
    if(denominator > 0){
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

void Fraction::Cancellation(){

}
