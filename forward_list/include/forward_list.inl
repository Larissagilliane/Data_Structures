// ARQUIVO .inl USADO DE ACORDO COM O ENSINADO EM SALA

#include "forward_list.h"

// Constructors
template <typename T>
Forward_list<T>::Forward_list() {
    m_start = new Node;
    m_end = new Node;
    m_size = 0;
    m_start->next = m_end;
}

template <typename T>
Forward_list<T>::Forward_list(const Forward_list<T> &l) {
    m_start = new Node;
    m_end = new Node;
    m_start->next = m_end;
    m_size = 0;
    for (auto it = l.cbegin(); it != l.cend(); it++)
        push_back(*it);
}

template <typename T>
Forward_list<T>::Forward_list(Forward_list<T> &&l) {
    // l data
    m_start = new Node;
    m_end = l.m_end;
    m_start->next = l.m_start->next;
    m_size = l.m_size;
    // Altera l
    l.m_end = new Node;
    l.m_start->next = l.m_end;
    l.m_size = 0;
}

// Destructor
template <typename T>
Forward_list<T>::~Forward_list() {
    clear();
    delete m_start;
    delete m_end;
}

// "Pega" o tamanho da lista
template <typename T>
int Forward_list<T>::size() const {
    return m_size;
}

// Verifica se a lista esta preenchida
template <typename T>
bool Forward_list<T>::empty() const {
    return m_size == 0;
}

// "Limpa" a lista
template <typename T>
void Forward_list<T>::clear() {
    Node *cp1 = m_start->next;
    while (cp1 != m_end) {
        Node *cp2 = cp1;
        cp1 = cp1->next;
        delete cp2;
    }
    m_size = 0;
    m_start->next = m_end;
}

// Pega o primeiro elemento
template <typename T>
T &Forward_list<T>::front() {
    return m_start->next->data;
}

// Pega o primeiro elemento( const )
template <typename T>
const T &Forward_list<T>::front() const {
    return m_start->next->data;
}

// Pega o ultimo elemento
template <typename T>
T &Forward_list<T>::back() {
    Node *temp = m_start;
    while (temp->next != m_end)
        temp = temp->next;
    return temp->data;
}

// Pega o ultimo elemento( const )
template <typename T>
const T &Forward_list<T>::back() const {
    Node *temp = m_start;
    while (temp->next != m_end)
        temp = temp->next;
    return temp->data;
}

// push_front
template <typename T>
void Forward_list<T>::push_front(const T &_x) {
    Node *_new = new Node(_x, m_start->next);
    m_start->next = _new;
    m_size++;
}

// push_back
template <typename T>
void Forward_list<T>::push_back(const T &_x) {
    // Search for the last element
    Node *temp = m_start;
    while (temp->next != m_end)
        temp = temp->next;
    // Creates a new element
    Node *_new = new Node(_x, temp->next);
    // Makes the last element point to _new
    temp->next = _new;
    // Increase List size
    m_size++;
}

// pop_front
template <typename T>
void Forward_list<T>::pop_front() {
    if (m_size > 0) {
        Node *temp = m_start->next;
        m_start->next = temp->next;
        m_size--;
        delete temp;
    }
}

// pop_back
template <typename T>
void Forward_list<T>::pop_back() {
    if (m_size > 0) {
        Node *aux1 = m_start;
        while (aux1->next->next != m_end)
            aux1 = aux1->next;
        Node *aux2 = aux1->next;  // Element to be dropped
        aux1->next = aux2->next;
        m_size--;
        delete aux2;
    }
}

// Atribui para todos os elementos da lista
template <typename T>
void Forward_list<T>::assign(const T &_val) {
    Node *temp = m_start;
    while (temp->next != m_end) {
        temp = temp->next;
        temp->data = _val;
    }
}

// Atribui para todos os elementos da lista
template <typename T>
void Forward_list<T>::assign(std::initializer_list<T> _il) {
    clear();
    for (auto i = _il.begin(); i != _il.end(); i++)
        push_back(*i);
}

// Retorna o primeiro elemento da lista
template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::begin() {
    return typename Forward_list<T>::iterator(m_start->next);
}

// Retorna um iterador para o começo da lista
template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::before_begin() {
    return typename Forward_list<T>::iterator(m_start);
}

// Retorna o final da lista
template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::end() {
    return typename Forward_list<T>::iterator(m_end);
}

// Returno um iterador para o primeiro elemento da lista
template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::cbegin() const {
    return typename Forward_list<T>::const_iterator(m_start->next);
}

// Retorna um iterador para o começo da lista
template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::cbefore_begin() const {
    return typename Forward_list<T>::const_iterator(m_start);
}

// Retorna um iterador para o final da lista
template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::cend() const {
    return typename Forward_list<T>::const_iterator(m_end);
}

// Insere um elemento
template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::insert_after(const_iterator _it, const T &_x) {
    Node *_new = new Node(_x, _it.m_node->next);
    _it.m_node->next = _new;
    m_size++;
    return Forward_list<T>::iterator(_it.m_node->next);
}

// Isere após o iterator
template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::insert_after(const_iterator _pos, std::initializer_list <T> _il) {
    for (auto it = _il.begin(); it != _il.end(); it++) {
        Node *_new = new Node(*it, _pos.m_node->next);
        _pos.m_node->next = _new;
        m_size++;
    }
    return Forward_list<T>::iterator(_pos.m_node->next);
}

// Remove todos os elementos depois do iterator
template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::erase_after(const_iterator _it) {
    if (_it.m_node != m_end && _it.m_node->next != m_end) {
        Node *cpy = _it.m_node->next;
        _it.m_node->next = cpy->next;
        m_size--;
        delete cpy;
        return Forward_list<T>::iterator(_it.m_node->next);
    }
    return Forward_list<T>::iterator(_it.m_node);
}

// Remove entre dois iterators
template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::erase_after(const_iterator _ini, const_iterator _end) {
    if (_ini.m_node != _end.m_node) {
        Node *cpy = _ini.m_node->next;
        _ini.m_node->next = _end.m_node;
        while (cpy != _end.m_node) {
            Node *aux = cpy;
            cpy = cpy->next;
            m_size--;
            delete aux;
        }
        return Forward_list<T>::iterator(_end.m_node);
    }
    return Forward_list<T>::iterator(_ini.m_node);
}

// Encontra o elemento da lista
template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::find(const T &_x) const {
    auto it = cbegin();
    while (it != cend()) {
        if (*it == _x)
            break;
        it++;
    }
    return it;
}
