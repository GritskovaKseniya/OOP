#include "ExpressionAnalyzerSt.h"
#include <sstream>

using namespace std;

Token::Token(){
    type = EMPTY;
}

Token::Token(double value){
    type = NUMBER;
    this->value = value;
}

Token::Token(char oper){
    type = OPER;
    this->oper = oper;
}

Token::Token(string unknown){
    type = UNKNOWN;
    this->unknown = unknown;
}
    
string Token::debug(){
    ostringstream strs;
    
    switch (type){
        case EMPTY:
            strs << "EMPTY";
            break;

        case NUMBER:
            strs << "NUMBER" << " " << value;
            break;
    
        case OPER:
            strs << "OPER" << " " << oper;
            break;
    
        case UNKNOWN:
            strs << "UNKNOWN" << " " << unknown;
            break;
    
        default:
            break;
    }

    return strs.str();
}

bool Token::is_empty(){
    return type == EMPTY;
}

bool Token::is_number(){
    return type == NUMBER;
}

double Token::get_number(){
    return  value;
}

bool Token::is_oper(){
    return type == OPER;
}
double Token::get_oper(){
    return oper;
}