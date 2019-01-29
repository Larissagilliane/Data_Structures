#ifndef _QUEUE_
#define _QUEUE_

#include <vector>

template < class T >
class Queue
{
    private:
        std::vector<T> m_data;

    public:
        using size_type = size_t;
        using const_reference = const T &;

        Queue( size_type cap_ )
        {
            m_data.resize( cap_ );
        }

        void enqueue( const_reference value_ )
        {
            m_data.push_back( value_);
        }

        void dequeue( void )
        {
            m_data.erase( m_data.begin() );
        }

        T front( void ) const
        {
            return m_data.front();
        }

        bool empty( void ) const
        {
            return m_data.empty();
        }
};

#endif
