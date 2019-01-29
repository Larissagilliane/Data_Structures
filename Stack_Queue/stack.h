/*!
 * \brief Template class that implements the ADT Stack with dynamic array.
 *
 * \date October 13th, 2016.
 * \author selan
 */

#ifndef _STACK_H_
#define _STACK_H_

#include <iostream> // cout, endl
#include <iterator> // ostream_iterator
#include <cassert>  // assert().

template < typename T >
class Stack
{
    public:
        // Typical typedefs.
        using value_type = T;
        using size_type = size_t;
        using pointer = value_type*;
        using reference = value_type&;
        using const_reference = const value_type &;

        /*! 
         * \brief Creates a stack with the specified capacity.
         * \param cap The requested capacity.
         */
        Stack( size_type cap=0 );

        /*!
         * \brief Inserts an element on top of the stack.
         * \param value The element to be inserted.
         */
        void push( const_reference );

        /*!
         * \brief Checks whether a stack is empty.
         *
         * \return `true` if stack is empty, `false` otherwise.
         */
        bool empty( void ) const { return m_end == 0; }

        /*!
         * \brief Returns the element on the top of the stack.
         *
         * \throw `std::out_of_range` if the stack is empty,
         *
         * \return The valua at the top of the stack.
         */
        const_reference top( void ) const
        {
            if ( empty() ) throw std::out_of_range("Empty Stack!");

            return m_data[m_end-1];
        }

        /*!
         * \brief Removes the element on the top of the stack.
         */
        void pop(void)
        {
            if ( empty() ) throw std::out_of_range("Empty Stack!");

            m_end--;
        }


        /*!
         * \brief Debugging function design only to observe the internal values of the stack.
         * \param os stream to write to (usually `std::cout`)
         * \para p Stack we want to print the information from.
         * \return the stream we written to.
         */
        friend std::ostream & operator<<( std::ostream & os, const Stack & p )
        {
            os << "{ ";
            std::copy( &p.m_data[0], & p.m_data[p.m_end], 
                    std::ostream_iterator< value_type >( os, " ") );
            os << "| ";
            std::copy( &p.m_data[p.m_end], & p.m_data[p.m_capacity], 
                    std::ostream_iterator< value_type >( os, " ") );
            os << "}";

            return os;
        }


    private:
        /*!
         * \brief Increases the size of the stack.
         *
         * This method doubles the storage area when the stack is full
         * and an a call to `push()` is made.
         *
         * \param new_cap The new capacity.
         * \see push()
         */
        void reserve( size_type new_cap )
        {
            // 1) Alocar a nova memoria (maio).
            pointer temp = new value_type[ new_cap ];

            // 2) Copiar os elementos p/ nova memoria.
            std::copy( &m_data[0], &m_data[m_end], &temp[0] );
            std::fill( &temp[m_end], &temp[new_cap], 0 );

            // 3) Apagar a memoria antiga.
            delete [] m_data;

            // 4) Fazer o data apontar para nova memoria.
            m_data = temp;

            // 5) Atualizar a nova capacidade.
            m_capacity = new_cap;
        }

        size_type m_end;      //<! Stack's top or past-the-end pointer.
        size_type m_capacity; //<! Stack's capacity
        pointer m_data;       //<! data storage area.
};

#include "stack.inl"
#endif
