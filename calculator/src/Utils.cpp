#include "ExpressionAnalyzerSt.h"
#include <string>

bool apply_op(char op, double num1, double num2, double* result)
{
    switch (op)
    {
    case '+':
        *result = num1 + num2;
        break;
    case '-':
        *result = num1 - num2;
        break;
    case '*':
        *result = num1 * num2;
        break;
    case '/':
        *result = num1 / num2;
        break;
    default:
        return false;
        break;
    }
    
    return true;
}

ParseResult ReadTerm(&tokenizer){

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

    /*if(tok.get_operation() == '-'){
        Token t2 = tok.next_token();
        if(t2.is_number()){
            return (t2.get_number() )*(-1);
        }
    }*/

    ParseResult t1 = get_number(&tokenizer);
    if(t1.is_error())
    {
        return t1;
    }

    /// Написать логику функции ReadTerm(&tokenizer);
    /// Запомнить позицию предыдущего токена и сделать функцию backup, которая вернет значение предыдущей позиции, чтобы next_token не считал токен два раза

    double result = t1.get_result(); 

    // В цикле обрабатываем последующие сложения и вычитания
    while(true)
    {
        Token op_token = tokenizer->next_token();
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

        ParseResult term = next_token(tokenizer);

        if (term.is_error())
        {
            return term;
        }

        // Применяем оператор + или - к разобранным числам.
        char op = op_token.get_oper();
        if (!apply_op(op, result, num_token.get_result(), &result))
        {
            return ParseResult(string("Unknown operator ") + op);
        }
    }

    return ParseResult(result);
}
