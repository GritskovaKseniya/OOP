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

    /// Написать логику функции ReadTerm(&tokenizer);
    /// Запомнить позицию предыдущего токена и сделать функцию backup, которая вернет значение предыдущей позиции, чтобы next_token не считал токен два раза
ParseResult ReadTerm(Tokenizer* tokenizer){
    ParseResult num = read_number(tokenizer);

    if (num.is_error()) {
        return num;
    }

    double result = num.get_result();

    Token operation_token = tokenizer -> next_token();
    
    if (!operation_token.is_oper()) {
        return ParseResult("Expected opeation");
    }

    char oper = operation_token.get_oper();

    while (oper == '*' || oper == '/')
    {
        num = read_number(tokenizer);
        
        if (num.is_error()) {
            return num;
        }

        apply_op(oper, result, num.get_result(), &result);

        operation_token = tokenizer -> next_token();

        if (
            operation_token.is_empty()
        ) {
            return ParseResult(result);
        }        

        if (!operation_token.is_oper()) {
            return ParseResult("Expected operation");
        }

        oper = operation_token.get_oper();
    }

    return ParseResult(result);
}

ParseResult read_number(Tokenizer* tokenizer) {
    Token token = tokenizer->next_token();
    int multiplier = 1;

    if (token.is_oper()) {
        char oper = token.get_oper();

        if (oper != '+' && oper != '-') {
            return ParseResult("Expected '+' or '-'");
        }

        multiplier = oper == '+' ? 1 : -1;

        token = tokenizer -> next_token();
    }

    if (token.is_number()) {
        return ParseResult(multiplier * token.get_number());
    }
        
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
    Tokenizer tokenizer = Tokenizer(expr);

    ParseResult t1 = read_number(&tokenizer);
    if(t1.is_error())
    {
        return t1;
    }

    double result = t1.get_result(); 

    // В цикле обрабатываем последующие сложения и вычитания
    while(true)
    {
        Token op_token = tokenizer.next_token();
        if (op_token.is_empty())
        {
            // Если вместо оператора +,- получаем пустой токен, то это признак
            // конца обрабатываемой строки. Выходим из цикла и формируем результат.
            break;
        }

        // Если не получили оператор - выводим ошибку
        if (!op_token.is_oper())
        {
            return ParseResult("Expected operator but got" + op_token.debug());
        }

        ParseResult term = read_number(&tokenizer);

        if (term.is_error())
        {
            return term;
        }

        // Применяем оператор + или - к разобранным числам.
        char op = op_token.get_oper();
        if (!apply_op(op, result, term.get_result(), &result))
        {
            return ParseResult(string("Unknown operator ") + op);
        }
    }

    return ParseResult(result);
}

