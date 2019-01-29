#ifndef vECTOR_H_
#define vECTOR_H_

 #include <exception>    // std::out_of_range
 #include <iostream>     // std::cout, std::endl
 #include <memory>       // std::unique_ptr
 #include <iterator>     // std::advance, std::begin(), std::end(), std::ostream_iterator
 #include <algorithm>    // std::copy
 #include <initializer_list> // std::initializer_list
 #include <cassert>      // assert()
 #include <limits>       // std::numeric_limits<T>

typedef size_t size_type;

template <typename T>
class Vector 
{
 public:
    /**
     * @brief Constutor Default
     * @param _sz Tamanho do vetor igual a 1
     */
    explicit Vector(size_type _sz = 1);

    /** 
     * @param v Outro vetor a ser copiado
     */
    Vector(const Vector &v);

    /**
     * @param v Outro vetor a ser movio
     */
    Vector(Vector &&v);

    /**
     * @brief  Destrutor
     */
    ~Vector() {}


    /**
     * @return Tamanho
     */
    size_type size() const;

    /**
     * @brief Limpa o vetor
     */
    void clear();

    /**
     * @brief Verifica se esta preenchido
     * @return True se estiver vazio, False caso constrário
     */
    bool empty() const;

    /**
     * @brief Insere elemento no final
     * @param _x Elemento a ser inserido
     */
    void push_back(const T &_x);

    /**
     * @brief Remove o último elemendo 
     */
    void pop_back();

    /**
     * @return O último elemento do vetor
     */
    const T &back() const;

    /**
     * @return O primeiro elemeto do vetor
     */
    const T &front() const;

    /**
     * @brief Atribui um valor 
     * @param _x Valor a ser usado 
     */
    void assign(const T &_x);

    /**
     * @return Capacidade 
     */
    size_type capacity() const;

    /**
     * @brief Informa uma nova capacidade 
     * @param _new_capacity A nova capacidade
     */
    void reserve(size_type _new_capacity);

    /**
     * @param _idx posição
     * @return O elemento da posição
     */
    T &at(size_type _idx);

    /**
     * @param idx A posição a ser acessada
     * @return O elemento da posição
     */
    T &operator[](size_type idx) const 
    {
        return m_data[idx];
    }

     /**
     * @param v Elemento a ser copiado
     * @return Novo elemento
     */
    Vector &operator=(const Vector &v) 
    {
        clear();

        for (auto i(0u); i < v.m_end; i++)
            push_back(v[i]);

        return (*this);
    }

     /**
     * @param v Elemento a ser movido
     * @return Novo elemento
     */
    Vector &operator=(Vector &&v) 
    {
        clear();

        m_data = std::move(v.m_data);
        m_capacity = v.m_capacity;
        m_end = v.m_end;
        v.m_end = 0;
        v.m_capacity = 0;

        return (*this);
    }

    /**
     * @return Ponteiro para o começo do array
     */
    T* data();


    class const_iterator;

    
    class iterator;

    /**
     * @return iterator para o inicio da lista
     */
    iterator begin();

    /**
     * @return iterator para o final da lista
     */
    iterator end();

    /**
     * @return const_iterator para o primeiro elemento da lista
     */
    const_iterator cbegin() const;

    /**
     * @return const_iterator para o final da lista
     */
    const_iterator cend() const;

 private:
    size_type m_end = 0;         
    size_type m_capacity = 1;     
    std::unique_ptr<T[]> m_data;
};

template <typename T>
class Vector<T>::const_iterator 
{
 public:
    /**
     * @brief Construtor
     */
    const_iterator() {}

    /**
     * @return O valor do elemento
     */
    const T &operator*() const {
        return *m_ptr;
    }

    /**
     * @return const_iterator
     */
    const_iterator &operator++() 
    {
        m_ptr++;
        return (*this);
    }

    /**
     * @return const_iterator
     */
    const_iterator operator++(int) 
    {
        const_iterator copy(m_ptr);
        m_ptr++;
        return copy;
    }

    /**
     * @return const_iterator
     */
    const_iterator &operator--() 
    {
        m_ptr--;
        return (*this);
    }

    /**
     * @return const_iterator
     */
    const_iterator operator--(int) 
    {
        const_iterator copy(m_ptr);
        m_ptr--;
        return copy;
    }

    /**
     * @param _other Elemento da direita
     * @return True se forem iguais
     */
    bool operator==(const const_iterator &_other) const 
    {
        return (m_ptr == _other.m_ptr);
    }

    /**
     * @param _other Elemento da direita
     * @return True se foram diferentes ou falso caso sejam iguais
     */
    bool operator!=(const const_iterator &_other) const {
        return !(*this == _other);
    }

 protected:
    
    const_iterator(T *_p) : m_ptr(_p) {}
    T *m_ptr;                
    friend class Vector<T>;  
};

template <typename T>
class Vector<T>::iterator : public Vector<T>::const_iterator 
{
 public:
    /**
     * @brief Construtor
     */
    iterator() : const_iterator() {}

    /**
     * @return valor do elemento (const)
     */
    const T &operator*() const {
        return *(const_iterator::m_ptr);
    }

    /**
     * @return O valor do elemento
     */
    T &operator*() {
        return *(const_iterator::m_ptr);
    }

    /**
     * @return iterador
     */
    iterator &operator++() {
        const_iterator::m_ptr++;
        return (*this);
    }

    /**
     * @return iterador
     */
    iterator operator++(int) {
        iterator copy(const_iterator::m_ptr);
        const_iterator::m_ptr++;
        return copy;
    }

    /**
     * @return iterador
     */
    iterator &operator--() {
        const_iterator::m_ptr--;
        return (*this);
    }

    /**
     * @return iterador
     */
    iterator operator--(int) {
        const_iterator copy(const_iterator::m_ptr);
        const_iterator::m_ptr--;
        return copy;
    }

 protected:
    iterator(T *_p) : const_iterator(_p) {}
    friend class Vector<T>;  
};

#include "vector.inl"
#endif
