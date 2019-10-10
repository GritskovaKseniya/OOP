#include "ExpressionAnalyzerSt.h"
#include <string>

bool apply_op(char op, double num1, double num2, double* result)
{
    if (op == '+')
    {
        *result = num1 + num2;
    }
    else if (op == '-')
    {
        *result = num1 - num2;
    }
    else
    {
        return false;
    }

    return true;
}

ParseResult ReadTerm(&tokenizer){
    Token t1 = tok.next_token();
    if (!t1.is_number())
    {
        return ParseResult("Expected number, but got" + t1.debug());
    }

    double result = t1.get_number();
    retutn 0;
}

ParseResult eval(string expr)
{
    /*
     * Грамматика
     *
     * Expression = Term [op Term]*
     * op = '+' | '-'
     * Term = Number [op2 Number]*
     * op2 = '*' | '/'
     * Number = Digit+[.Digit+]
     * Digit = '0' | '1' | ... | '8' | '9'
     *
     * (где [] - необязательная часть выражения
     * something* - выражение something может повторяться 0 и более раз
     * something+ - выражение something должно быть - по крайней мере 1 раз. Но можно и много раз подряд.
     * )
    */

    // Токенайзер считывает строку "по словам (лексемам)"
    Tokenizer tok = Tokenizer(expr);

    // Первый токен должен быть числом
    /*Token t1 = tok.next_token();
    if (!t1.is_number())
    {
        return ParseResult("Expected number, but got" + t1.debug());
    }

    double result = t1.get_number();
    */
    ParseResult number1 = ReadTerm(&tokenizer);
    if(number1.is_error())
    {
        return number1;
    }

    /// Написать логику функции ReadTerm(&tokenizer);
    /// Запомнить позицию предыдущего токена и сделать функцию backup, которая вернет значение предыдущей позиции, чтобы next_token не считал токен два раза
    ///
    double result = number1.get_result(); 


    // В цикле обрабатываем последующие сложения и вычитания
    while(true)
    {
        Token op_token = tok.next_token();
        if (op_token.is_empty())
        {
            // Если вместо оператора +,- получаем пустой токен, то это признак
            // конца обрабатываемой строки. Выходим из цикла и формируем результат.
            break;
        }
        if (!op_token.is_oper())
        {
            return ParseResult("Expected operator but got" + op_token.debug());
        }

        Token num_token = tok.next_token();
        if (!num_token.is_number())
        {
            return ParseResult("Expected number but got" + num_token.debug());
        }

        // Применяем оператор + или - к разобранным числам.
        char op = op_token.get_oper();
        if (!apply_op(op, result, num_token.get_number(), &result))
        {
            return ParseResult(string("Unknown operator ") + op);
        }
    }

    return ParseResult(result);
}

