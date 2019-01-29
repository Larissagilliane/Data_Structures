#include "stack.h"

template < class T >
Stack<T>::Stack( size_type cap )
    : m_end{0}
    , m_capacity{cap}
    , m_data{ new value_type[m_capacity] }
{
    // Preencher todo o vetor com zeros.
    std::fill( &m_data[0], &m_data[m_capacity], 0 );
}

template < class T >
void Stack<T>::push( const_reference value )
{
    // Verificar se tem espaco para inserir
    if ( m_end == m_capacity ) // full

    // Dobrar a capacidade & copiar valores.
    reserve( 2 * m_capacity );

    // Inserir non final (push_back).
    m_data[m_end++] = value;
}
