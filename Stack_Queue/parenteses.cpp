/*!
 *  Este programa utiliza uma ED do tipo pilha para verificar se uma
 *  espressão está totalmente "parentisada" corretamente, ou seja,
 *  se os parênteses de abertura e fechamento casam corretamente e não
 *  há sobras.
 *
 *  Por exemplo:
 *
 *  ```
 *  "(()()())()((()))" está correta.
 *  ")(" não está correta.
 *  "(()" não está correta.
 *  "())" não está correta.
 *  ```
 *
 *  O programa pode ser adaptado para tratar também qualquer tipo de símbolo
 *  de aninhamento, como colchetes, chaves, etc.
 */

#include <iostream>
#include <vector>
#include <cassert>

#include "stack.h"

bool validate_expression( const std::string & s )
{
    Stack<char> P;

    for ( auto i(0u) ; i < s.size() ; ++i )
    {
        if ( s[i] == '(' )
        {
            P.push(s[i]);
        }
        else if ( s[i] == ')' )
        {
            if ( not P.empty() )  P.pop();
            else                  return false; // Extra ')' found.
        }
        else
        {
            // Do nothing. Just ignore this character.
            // It is neither '(' nor ')'.
        }
    }

    // At the end, the stack must be empty.
    // Otherwise it means one or more '(' were left without a match. 
    return P.empty();
}

int main()
{
    std::vector<std::string> entradaOK =
    {
        "()(())((()))(()()())",
        "((()))",
        "()",
        "(a+b*(c-d))"
    };

    std::vector<std::string> entradaNOK =
    {
        ")",
        "(",
        "(()",
        ")(",
        "()))"
    };

    // Procura avaliar as expressões corretas. Se alguma expressão não for avaliada como
    // correta, o assert() interrompe a execução do programa.
    for ( auto it = entradaOK.begin() ; it != entradaOK.end() ; ++it )
        assert( validate_expression( *it ) == true );

    // Procura avaliar as expressões INcorretas. Se alguma expressão não for identificada como
    // problemática,  o assert() interrompe a execução do programa.
    for ( auto it = entradaNOK.begin() ; it != entradaNOK.end() ; ++it )
        assert( validate_expression( *it ) == false );

    std::cout << ">>> As expressões foram avaliadas corretamente!\n\n";

    std::cout << ">>> Normal exiting.\n";

    return 0;
}
