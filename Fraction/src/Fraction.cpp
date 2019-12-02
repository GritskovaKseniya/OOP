#include "Fraction.h"
#include <string>
#include <sstream>
#include <iostream>

Fraction::Fraction(int numerator, int denominator){
    if(
        ((numerator == 0) && (denominator == 0)) ||
        ( (numerator == 0) || (denominator == 0) )
    ){
        this->numerator = 0;
        this->denominator = 0;
    }else if(denominator < 0){
        this->numerator = numerator*(-1);
        this->denominator = denominator*(-1);
        //Cancellation();
    }else {
        this->numerator = numerator;
        this->denominator = denominator;
        //Cancellation();
    }
}

Fraction::Fraction(const Fraction &other){
    this->numerator = other.numerator;
    this->denominator = other.denominator;
}


Fraction::~Fraction(){
}

Fraction Fraction::operator+(const Fraction &other){
    int new_numerator; 
    int new_denominator;
    if(denominator == other.denominator){
        new_denominator = denominator;
        new_numerator = numerator+ other.numerator;
    }else {
        new_denominator = denominator*other.denominator;
        new_numerator = numerator*other.denominator + other.numerator*denominator;
    }
    Fraction result(new_numerator,new_denominator);
    Cancellation();
    return result;
}
    
Fraction Fraction::operator -(const Fraction &other){
    int new_numerator;
    int new_denominator; 
    if(denominator == other.denominator){
        new_numerator = numerator - other.numerator;
        new_denominator = denominator;
    }else{
        new_numerator = numerator*other.denominator - other.numerator*denominator;
        new_denominator = denominator*other.denominator;
    }
    Fraction result(new_numerator,new_denominator);
    Cancellation();
    return result;  
}

Fraction Fraction::operator *(const Fraction &other){
    int new_numerator = numerator*other.numerator;
    int new_denominator = denominator*other.denominator;
    Fraction result(new_numerator,new_denominator);
    Cancellation();
    return result;  
}

Fraction Fraction::operator /(const Fraction &other){
    int new_numerator = numerator*other.denominator;
    int new_denominator = denominator*other.numerator;
    Fraction result(new_numerator,new_denominator);
    Cancellation();
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
  /*  Fraction b = other.Cancellation();
    Fraction a = this->Cancellation();*/
    return this->numerator == other.numerator
        && this->denominator == other.denominator;
}

void Fraction::print(){
    bool check = check_parameter(denominator);
    if(check == true){
        if(numerator == denominator){
            cout << 1;
        } else {
            Cancellation();
            cout << numerator << "/" << denominator;
        }
    }else if(numerator == 0){
        cout << 0;
    }else if(denominator == 0){
        cout << 0;
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
        /// 
	return abs(a);
}
// smallest common multiple НОК
int scm(int a, int b) 
{ 
  return a*b / gcd(a, b); 
}

Fraction Fraction::Cancellation() const{
    int GCD = gcd(numerator, denominator);
    int new_numerator = numerator/GCD;
    int new_denominator = denominator/GCD;
    Fraction reduced_fraction(new_numerator,new_denominator);
    return reduced_fraction;
}

Fraction::Fraction(double number){
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
    Fraction f(num, den);
    numerator = f.numerator;
    denominator = f.denominator;
}

ostream& operator<<(ostream& out, const Fraction& f)
{
    out << f.numerator << "/" << f.denominator;
}
