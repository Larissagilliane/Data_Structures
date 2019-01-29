 #include <exception>    // std::out_of_range
 #include <iostream>     // std::cout, std::endl
 #include <memory>       // std::unique_ptr
 #include <iterator>     // std::advance, std::begin(), std::end(), std::ostream_iterator
 #include <algorithm>    // std::copy
 #include <initializer_list> // std::initializer_list
 #include <cassert>      // assert()
 #include <limits>       // std::numeric_limits<T>
#include "vector.h"

// Construtor
template <typename T>
Vector<T>::Vector(size_type _sz) : m_capacity(_sz), m_data(new T[_sz]) {}

// Copy construtor
template <typename T>
Vector<T>::Vector(const Vector &v) : m_capacity(v.m_capacity), m_data(new T[v.m_capacity]) 
{
    for (auto i(0u); i < v.m_end; i++)
        push_back(v[i]);
}

// Move construtor
template <typename T>
Vector<T>::Vector(Vector &&v) : m_capacity(v.m_capacity), m_data(std::move(v.m_data)) 
{
    m_end = v.m_end;
    v.m_end = 0;
    v.m_capacity = 0;
}

// Tamanho do vector
template <typename T>
size_type Vector<T>::size() const 
{
    return m_end;
}

// Limpa vector
template <typename T>
void Vector<T>::clear() 
{
     m_end = 0;
}

// Verifica se está preenchido
template <typename T>
bool Vector<T>::empty() const 
{
    return m_end == 0;
}

// Push Back
template <typename T>
void Vector<T>::push_back(const T &_x) {
    if (m_end >= m_capacity)
        reserve( 2*(m_capacity-1) + 1);

    m_data[m_end++] = _x;
}

// Pop Back
template <typename T>
void Vector<T>::pop_back() 
{
    (&m_data[--m_end])->~T();
}

// "Pega" o ultimo elemento
template <typename T>
const T &Vector<T>::back() const 
{
    if ( empty() )
    {
         throw std::out_of_range("[Vector::back()] Vector is empty!");
    }
    return m_data[m_end - 1];
}

// "Pega" o elemento da frente
template <typename T>
const T &Vector<T>::front() const 
{
    if ( empty() )
    {
         throw std::out_of_range("[Vector::front()] Vector is empty!");
    }
    return m_data[0];
}

// Atribui 
template <typename T>
void Vector<T>::assign(const T &_x) 
{
    for (auto i(0u); i < m_end; i++)
        m_data[i] = _x;
}

// "Pega" a capacidade
template <typename T>
size_type Vector<T>::capacity() const 
{
    return m_capacity;
}

template <typename T>
void Vector<T>::reserve(size_type _new_capacity) 
{
    if (_new_capacity > m_capacity) 
    {
        
        std::unique_ptr<T[]> c_list(new T[_new_capacity]);
        
        for (auto i(0u); i < m_end; i++) 
        {
            c_list[i] = m_data[i];
            (&m_data[i])->~T();
        }
        // Move c_list para m_data
        m_data = std::move(c_list);
        
        m_capacity = _new_capacity;
    }
}


template <typename T>
T &Vector<T>::at(size_type _idx) 
{
    if (_idx >= m_end || _idx < 0)
        throw std::out_of_range("Index out of range!");
    return m_data[_idx];
}

template <typename T>
T* Vector<T>::data() 
{
    return m_data.get();
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin() 
{
    return iterator( &m_data[0] );
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end() 
{
    return iterator( &m_data[m_end] );
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const 
{
    return typename Vector<T>::const_iterator(m_data.get());
}

template <typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const 
{
    return typename Vector<T>::const_iterator(m_data.get() + m_end);

}
