#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator){
    bool valid = check_parameter(denominator);
    if(valid == true){
        this->numerator = numerator;
        this->denominator = denominator;
    }else if(numerator == 0){
        this->numerator = 0;
        this->denominator = 0;
    }else {
        this->numerator = 0;
        this->denominator = 0;
    }
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

Fraction Fraction::operator !=(const Fraction &other){

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

int Fraction::find_common_denominator(int other_denominator){
    int this_denominator = this->denominator; // узнаем делитель первого числа
    return scm(this_denominator, other_denominator); // находим нод
}

int Fraction::find_new_numerator(int other_numerator){
    
}