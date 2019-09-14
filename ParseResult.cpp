#include "ExpressionAnalyzerSt.h"
#include <string>

ParseResult::ParseResult(double result){
    this->result = result;
}

ParseResult::ParseResult(string error){
    this->error = error; 
}

bool ParseResult::is_error(){
    
    if(error != ""){
        return true;
    } else return false;
}

double ParseResult::get_result(){
    return result;
}

string ParseResult::get_error(){
    return error;
}

