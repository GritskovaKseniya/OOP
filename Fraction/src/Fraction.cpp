#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator){
    this->numerator = numerator;
    this->denominator = denominator;
}

Fraction::~Fraction(){
}

void Fraction::operator +(Fraction* other){
    int other_denominator = other->denominator;
    int new_denominator = find_common_denominator(other_denominator);
    Fraction result(1,new_denominator);
}
    
void Fraction::operator -(Fraction* other){

}

void Fraction::operator =(Fraction* other){

}

void Fraction::operator !=(Fraction* other){

}

void Fraction::print(){
    bool check = check_parameter(numerator,denominator);
    if(check == true){
        cout << numerator << "/" << denominator << endl;
    }else
    {
        cout << " Denominator is not correct" << endl;
    }
}

bool Fraction::check_parameter(int numerator, int denominator){
    if(denominator > 0){
        return true;
    }
}

// module
int abs (int value) {
	return (value < 0) ? -value : value;
}
// Euclid's algorithm 
int gcd (int a, int b) {
	while (b)
		b ^= a ^= b ^= a %= b;
	return abs(a);
}
// smallest common multiple
int scm(int a, int b) 
{ 
  return a*b / gcd(a, b); 
}

int Fraction::simplification(){

}

int Fraction::find_common_denominator(int other_denominator){
    int this_denominator = this->denominator; // узнаем делитель первого числа
    return scm(this_denominator, other_denominator); // находим нод
}

int Fraction::find_new_numerator(int other_numerator){
    
}