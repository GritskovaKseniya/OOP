#include "ExpressionAnalyzerSt.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

/// Конструктор.
Tokenizer::Tokenizer(string expr)
{
    this->expr = expr;
    cur = 0;
    this->has_push_back = false;
}

/// Добавить распознавание отрицательных чисел

/// Добавить операции умножения и деления

/// Возвращает следующий токен из запомненной строки.
/// Если в строке ерунда - возвращает токен с type=UNKNOWN
Token Tokenizer::next_token(){
    
    if (has_push_back) {
        has_push_back = false;
        return last_token;
    }

    SkipSpaces();

    int start = cur; /// Заводим счетчик строки.
    int ex = cur;

    /// Условие: Счётчик не вышел за пределы строки.
    while (cur < expr.length())
    {
        /// Проверяем, является ли наш символ оператором.
        if(
            expr.at(cur) == '*' 
            || expr.at(cur) == '/' 
            || expr.at(cur) == '+' 
            || expr.at(cur) == '-'
            || expr.at(cur) == '('
            || expr.at(cur) == ')'
          )
        { 
            /// Создаем результирующий токен и кладем в него значение символа.
            Token result = Token(expr.at(cur)); 
            /// Увеличиваем счетчик на еденицу.
            cur++; 
            
            last_token = result;
            return last_token;
        }
        
        /// Проверяем, является ли наш символ числом с помощью функции isdigit (возвращает true, если число)
        if( cur < expr.length() && isdigit(expr.at(cur)) )
        {
            /// Запоминаем значение указателя и увеличиваем счетчик.
            start = cur;
            cur++;

            /// Опять проверяем является ли символ числом. 
            while(cur < expr.length() && isdigit(expr.at(cur)) )
            {
                cur++;
            }

            if(cur < expr.length() && expr.at(cur) == '.' )
            {
                cur++;
                /// Если после точки число.
                while(cur < expr.length() && isdigit(expr.at(cur)) )
                {
                    cur++;
                }

                /// Если после точки не число мы должны вернуть unknown строку и заветшить предоставление токенов.
             /*   if(cur < expr.length() && ( 
                    !isdigit(expr.at(cur))
                        )
                    ){
                    ex = cur-2;

                }*/
            }/*
            string unknown = expr.substr(ex); //кладем всё, от начала указатела до конца строки
            cout << unknown << endl;
            Token result1 = Token(unknown);*/
            /// Создаем подстроку с числом. 
            string number = expr.substr(start, cur - start);
            /// Преобразуем string to double и создаем новый токен с этим содержимым.
            Token result = Token(atof(number.c_str()));
            
            last_token = result;
            return last_token;

        } else 
        {
            start = cur;
            cur++;
            while(cur < expr.length() )
            {
                cur++;
            }
            /// Создаем подстроку, в которую кладем невалидные данные. 
            string unknown = expr.substr(start); //кладем всё, от начала указатела до конца строки
            Token result = Token(unknown);
            
            last_token = result;
            return last_token;
        } 
    }
    /// Если мы тут, то строка закончилась. Возвращаем пустой токен.
    Token end = Token();
    last_token = end;

    return last_token;
     
}

void Tokenizer::SkipSpaces()
{
    /// Если мы не вышли за пределы строки и символ равен пробелу, то увеличиваем счетчик.
    while(cur < expr.length() && expr.at(cur) == ' '){
        cur++;
    }
}

bool Tokenizer::push_back() {
    if (this->has_push_back) {
        return false;
    }

    this->has_push_back = true;
    return true;
}
