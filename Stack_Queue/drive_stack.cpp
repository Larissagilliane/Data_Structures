#include <iostream> // cout, endl
#include <iterator> // ostream_iterator
#include <cassert>  // assert().

#include "stack.h"


int main()
{
    Stack< int > P(5);

    for ( auto i{0} ; i < 10 ; ++i )
    {
        P.push( i+1 );
        std::cout << ">> Stack: " << P << std::endl;
    }

    P.push(11);
    std::cout << ">> Stack: " << P << std::endl;

    {
        std::cout << ">>> Unit test#4: top()\n";
        // Testando top regular, com elementos.
        {
            Stack<int> P;
            P.push(1); P.push(2); P.push(3);

            assert( P.top() == 3 );
        }

        // Testando top() sobre uma pilha vazia.
        // E esperado o lançamento de uma exceção.
        {
            bool ok{false};

            try { 
                Stack<int> P;
                P.top();
            }
            catch ( const std::out_of_range & e ) {  ok = true; }
            assert( ok == true );
        }
        std::cout << ">>> Passed!\n";
    }

    return EXIT_SUCCESS;
}
