#ifndef _FOWARD_LIST_H_
#define _FOWARD_LIST_H_

typedef size_t size_type;

template <typename T>
class Forward_list {
 public:
    /**
     * @brief Construtor
     */
    Forward_list();

    /**
     * @param l lista copiada
     */
    explicit Forward_list(const Forward_list &l);

    /**
     * @param l A lista a ser movida
     */
    explicit Forward_list(Forward_list &&l);

    /**
     * @brief Destrutor
     */
    ~Forward_list();

    /**
     * @brief Pega o tamanho
     * @return The Forward List size
     */
    int size() const;

    /**
     * @brief Verifica se esta preenchida
     * @return True se estiver vazia, e false caso contrário
     */
    bool empty() const;

    /**
     * @brief Remove todos os elementos da lista
     */
    void clear();

    /**
     * @brief "Pega" o primeiro elemento
     * @return A referencia para o primeiro elemento
     */
    T &front();

    /**
     * @brief "Pega" o primeiro elemento
     * @return A referencia para o primeiro elemento
     */
    const T &front() const;

    /**
     * @brief "Pega" o ultimo elemento
     * @return A referencia para o ultimo elemento
     */
    T &back();

    /**
     * @brief "Pega" o ultimo elemento
     * @return A referencia para o ultimo elemento
     */
    const T &back() const;

    /**
     * @brief Insere o elemento no inicio da lista
     * @param _x O elemento a ser inserido
     */
    void push_front(const T &_x);

    /**
     * @brief Insere o elemento no final da lista
     * @param _x O elemento a ser inserido
     */
    void push_back(const T &_x);

    /**
     * @brief Remove o primeiro elemento
     */
    void pop_front();

    /**
     * @brief Remove o ultimo elemento
     */
    void pop_back();

    /**
     * @brief Atribui o valor para todos os elementos da lista
     * @param  Valor a ser atribuido
     */
    void assign(const T &_val);

    /**
     * @param _il Lista inicializada com o valor
     */
    void assign(std::initializer_list<T> _il);

    class const_iterator;

    class iterator;

    /**
     * @return Itarator para o primeiro elemento da lista
     */
    iterator begin();

    /**
     * @return iterator para o inicio da lista
     */
    iterator before_begin();

    /**
     * @return iterator para o final da lista
     */
    iterator end();

    /**
     * @return const_iterator para o primeiro elemento da lista
     */
    const_iterator cbegin() const;

    /**
     * @brief const_iterator para o começo da lista
     * @return const_iterator para o começo da lista
     */
    const_iterator cbefore_begin() const;

    /**
     * @return A const_iterator para o final da lista
     */
    const_iterator cend() const;

    /**
     * @param _it iterador para a posição ser inserida
     * @param _x Elemento a ser inserido
     * @return Um iterador para o elemento inserido
     */
    iterator insert_after(const_iterator _it, const T &_x);

    /**
     * @param _pos Iterador para a posição
     * @param _il Lista a ser inserido
     * @return Iterador para o ultimo elemento
     */
    iterator insert_after(const_iterator _pos, std::initializer_list <T> _il);

    /**
     * @param _it Iterador para a posição
     * @return A posição do elemento removido
     */
    iterator erase_after(const_iterator _it);

    /**
     * @brief Remove elementos entre os iteradores
     * @param _ini Iterador para a posição inicial
     * @param _end Iterador para a posição final
     */
    iterator erase_after(const_iterator _ini, const_iterator _end);

    /**
     * @param _ini Iterador para a posição inicial
     * @param _end Iterador para a posição final
     */
    template <class IT>
    void assign(IT _ini, IT _end);

    /**
     * @brief Encontra um elemento da lista
     * @param _x  elemento a se encontrador
     * @return Um iterator
     */
    const_iterator find(const T &_x) const;

    /**
     * @param l Elemento a ser copiado
     * @return Novo elemento
     */
    Forward_list &operator=(const Forward_list &l) {
        delete m_start;
        delete m_end;

        m_start = new Node;
        m_end = new Node;
        m_start->next = m_end;
        m_size = 0;
        for (auto it = l.cbegin(); it != l.cend(); it++)
            push_back(*it);

        return (*this);
    }

    /**
     * @param l Elemento a ser movido
     * @return Novo elemento
     */
    Forward_list &operator=(Forward_list &&l) {
        delete m_start;
        delete m_end;

        m_start = new Node;
        m_end = l.m_end;
        m_start->next = l.m_start->next;
        m_size = l.m_size;

        l.m_end = new Node;
        l.m_start->next = l.m_end;
        l.m_size = 0;

        return (*this);
    }

 private:
    struct Node {
        T data;      //!< Data field
        Node *next;  //!< Pointer to the next node in the list.
        Node(const T &_d = T(), Node *_nxt = nullptr) : data(_d), next(_nxt) {}
    };
    Node *m_start;      
    Node *m_end;      
    size_type m_size;  
};

template <typename T>
class Forward_list<T>::const_iterator {
 public:
    /**
     * @brief Construtor
     */
    const_iterator() {}

    /**
     * @return O valor do elemento
     */
    const T &operator*() const {
        return m_node->data;
    }

    /**
     * @return const_iterator
     */
    const_iterator &operator++() {
        m_node = m_node->next;
        return (*this);
    }

    /**
     * @return const_iterator
     */
    const_iterator operator++(int) {
        const_iterator cpy(m_node);
        m_node = m_node->next;
        return cpy;
    }

    /**
     * @param _rhs Elemento da direita
     * @return True se forem iguais
     */
    bool operator==(const const_iterator &_rhs) const {
        return (m_node == _rhs.m_node);
    }

    /**
     * @param _rhs Elemento da direita
     * @return True se foram diferentes ou falso caso sejam iguais
     */
    bool operator!=(const const_iterator &_rhs) const {
        return !(*this == _rhs);
    }

 protected:
    const_iterator(Node *_p) : m_node(_p) {}
    Node *m_node;                 
    friend class Forward_list<T>; 
};

template <typename T>
class Forward_list<T>::iterator : public Forward_list<T>::const_iterator {
 public:
    /**
     * @brief Construtor
     */
    iterator() : const_iterator() {}

    /**
     * @return valor do elemento (const)
     */
    const T &operator*() const {
        return const_iterator::m_node->data;
    }

     /**
     * @return valor do elemento
     */
    T &operator*() {
        return const_iterator::m_node->data;
    }

    /**
     * @return iterador
     */
    iterator &operator++() {
        const_iterator::m_node = const_iterator::m_node->next;
        return (*this);
    }

    /**
     * @return iterador
     */
    iterator operator++(int) {
        iterator cpy(const_iterator::m_node);
        const_iterator::m_node = const_iterator::m_node->next;
        return cpy;
    }

 protected:
    iterator(Node *_p) : const_iterator(_p) {}
    friend class Forward_list<T>; 
};

#include "forward_list.inl"
#endif
