#include "ExpressionAnalyzerSt.h"
#include <string>
#include <cstdlib>

/// Конструктор.
Tokenizer::Tokenizer(string expr)
{
    this->expr = expr;
    cur = 0;
}

Token Tokenizer::next_token(){
    /// Возвращает следующий токен из запомненной строки.
    /// Если в строке ерунда - возвращает токен с type=UNKNOWN
    SkipSpaces();

    int start = cur; /// Заводим счетчик строки.

    /// Условие: Счётчик не вышел за пределы строки.
    while (cur < expr.length())
    {
        /// Проверяем значение символа на текущей позиции.
        if(expr.at(cur) == '+' | expr.at(cur) == '-')
        { 
            /// Создаем результирующий токен и кладем в него значение символа.
            Token result = Token(expr.at(cur)); 
            /// Увеличиваем счетчик на еденицу.
            cur++; 
            return result;
        }   

        /// Проверяем, является ли наш символ числом с помощью функции isdigit
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

            if(cur < expr.length() && (expr.at(cur) == '.' | expr.at(cur) == ','))
            {
                cur++;
                while(cur < expr.length() && isdigit(expr.at(cur)) )
                {
                    cur++;
                }
                /// Ошибка
            }
            /// Создаем подстроку с числом. 
            string number = expr.substr(start, cur - start);
            /// Преобразуем string to double и создаем новый токен с этим содержимым.
            Token result = Token(atof(number.c_str()));
            return result;
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
            return result;
        } 
    }
    /// Если мы тут, то строка закончилась. Возвращаем пустой токен.
    Token end = Token();
    return end;
     
}

void Tokenizer::SkipSpaces()
{
    /// Если мы не вышли за пределы строки и символ равен пробелу, то увеличиваем счетчик.
    while(cur < expr.length() && expr.at(cur) == ' '){
        cur++;
    }
}
