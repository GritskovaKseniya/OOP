#pragma once

#include <string>
#include <iostream>

using namespace std;

/// Результат разбора выражения - число либо текст ошибки
class ParseResult
{
public:
    /// Конструирует корректный результат (число)
    ParseResult(double result);
    
    /// Конструирует ошибочный результат
    ParseResult(string error);
    
    /// Возвращает значение, показывающее, есть ли ошибка
    bool is_error();
    
    /// Возвращает число
    double get_result();
    
    /// Возвращает текст ошибки
    string get_error();

private:
    double result;
    string error;
};

/// Типы токенов - перечисление, где каждому имени компилятором автоматически сопоставляется целое число.
enum TokenType
{
    EMPTY,
    NUMBER,
    OPER,
    UNKNOWN // Не пойми что - ошибка разбора
};

/// Токен (лексема, слово) - число, строка, пусто либо не пойми что.
class Token
{
    TokenType type;
public:
    /// Возвращает пустой токен. 
    Token();

    /// Возвращает токен-число.
    Token(double value);

    /// Возвращает токен-оператор.
    Token(char oper);

    /// Возвращает строку с символами, которые не удалось распознать.
    Token(string unknown);

    /// Возвращает информацию о токене.
    string debug();

    /// Проверяет не пустой ли токен.
    bool is_empty();

    /// Проверяет является ли токен числом.
    bool is_number();
    
    /// Возвращает числовое значение токена.
    double get_number();

    /// Проверяет является ли токен оператором.
    bool is_oper();

    /// Возвращает оператор.
    double get_oper();

private:
    /// Переменная, в которую кладем значение цифры/числа.
    double value; 
    /// Переменная, в которую кладем значение оператора.
    char oper; 
    /// Строка, в которорую кладем значение того, что не смогли распознать как число или оператор.
    string unknown; 
};


/// Разбивает строку на токены
class Tokenizer
{
public:
    /// Конструирует новый объект - при этом запоминается строка для разбора
    Tokenizer(string expr);
    
    /// Возвращает следующий токен из запомненной строки.
    /// Если строка кончилась, возвращает пустой токен token.is_empty()=true
    /// Если в строке ерунда - возвращает токен с type=UNKNOWN
    Token next_token();

private:
    /// Поле Expression.
    string expr; 
    /// Поле с номером позиции в строке. 
    int cur;  
    ///Функция, которая пропускает пробелы.
    void SkipSpaces();

};


/// Применяет оператор к аргументам num1 и num2 и записывает результат в result
/// Возвращает true, если оператор известен, иначе false
bool apply_op(char op, double num1, double num2, double* result);


/// Разбирает арифметическое выражение и считает результат
ParseResult eval(string expr);

ParseResult read_number();

