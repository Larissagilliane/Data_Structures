#include "list.h"

// Construtores
template <typename T>
List<T>::List() 
{
    m_start = new Node;
    m_end = new Node;
    m_size = 0;
    m_start->next = m_end;
    m_end->prev = m_start;
}

template <typename T>
List<T>::List(const List<T> &l) 
{
    m_start = new Node;
    m_end = new Node;
    m_start->next = m_end;
    m_end->prev = m_start;
    m_size = 0;
    for (auto it = l.cbegin(); it != l.cend(); it++)
        push_back(*it);
}

template <typename T>
List<T>::List(List<T> &&l) 
{
    // l data
    m_start = new Node;
    m_end = l.m_end;
    m_start->next = l.m_start->next;
    m_size = l.m_size;
    // l alterado
    l.m_end = new Node;
    l.m_start->next = l.m_end;
    l.m_end->prev = l.m_start;
    l.m_size = 0;
}

// Destructor
template <typename T>
List<T>::~List() 
{
    clear();
    delete m_start;
    delete m_end;
}

// "Pega" o tamanho da lista
template <typename T>
int List<T>::size() const {
    return m_size;
}

// Verifica se está vazia
template <typename T>
bool List<T>::empty() const {
    return m_size == 0;
}

// Limpa a lista
template <typename T>
void List<T>::clear() {
    Node *cp1 = m_start->next;
    while (cp1 != m_end) {
        Node *cp2 = cp1;
        cp1 = cp1->next;
        delete cp2;
    }
    m_size = 0;
    m_start->next = m_end;
    m_end->prev = m_start;
}

// "Pega" o primeiro elemento da lista
template <typename T>
T &List<T>::front() {
    return m_start->next->data;
}

// "Pega" o primeiro elemento da lista (const )
template <typename T>
const T &List<T>::front() const {
    return m_start->next->data;
}

// Pega o ultimo elemento
template <typename T>
T &List<T>::back() {
    return m_end->prev->data;
}

// Pega o ultimo elemento( const )
template <typename T>
const T &List<T>::back() const {
    return m_end->prev->data;
}

// push_front
template <typename T>
void List<T>::push_front(const T &_x) {
    Node *_new = new Node(_x, m_start->next, m_start);
    m_start->next->prev = _new;
    m_start->next = _new;
    m_size++;
}

// push_back
template <typename T>
void List<T>::push_back(const T &_x) {
    Node *_new = new Node(_x, m_end, m_end->prev);
    m_end->prev->next = _new;
    m_end->prev = _new;
    m_size++;
}

// pop_front
template <typename T>
void List<T>::pop_front() {
    if (m_size > 0) {
        Node *temp = m_start->next;
        temp->next->prev = m_start;
        m_start->next = temp->next;
        m_size--;
        delete temp;
    }
}

// pop_back
template <typename T>
void List<T>::pop_back() {
    if (m_size > 0) {
        Node *temp = m_end->prev;
        temp->prev->next = m_end;
        m_end->prev = temp->prev;
        m_size--;
        delete temp;
    }
}

// Atribui para todos os elementos da lista
template <typename T>
void List<T>::assign(const T &_val) {
    Node *temp = m_start;
    while (temp->next != m_end) {
        temp = temp->next;
        temp->data = _val;
    }
}

// Atribui para todos os elementos da lista
template <typename T>
void List<T>::assign(std::initializer_list<T> _il) {
    clear();
    for (auto it = _il.begin(); it != _il.end(); it++)
        push_back(*it);
}

// Retorna o primeiro elemento da lista
template <typename T>
typename List<T>::iterator List<T>::begin() {
    return typename List<T>::iterator(m_start->next);
}

// Retorna um iterador para o começo da lista
template <typename T>
typename List<T>::iterator List<T>::before_begin() {
    return typename List<T>::iterator(m_start);
}

// Retorna o final da lista
template <typename T>
typename List<T>::iterator List<T>::end() {
    return typename List<T>::iterator(m_end);
}

// Returno um iterador para o primeiro elemento da lista
template <typename T>
typename List<T>::const_iterator List<T>::cbegin() const {
    return typename List<T>::const_iterator(m_start->next);
}

// Retorna um iterador para o começo da lista
template <typename T>
typename List<T>::const_iterator List<T>::cbefore_begin() const {
    return typename List<T>::const_iterator(m_start);
}

// Retorna um iterador para o final da lista
template <typename T>
typename List<T>::const_iterator List<T>::cend() const {
    return typename List<T>::const_iterator(m_end);
}

// Insere um elemento
template <typename T>
typename List<T>::iterator List<T>::insert_after(const_iterator _it, const T &_x) {
    Node *_new = new Node(_x, _it.m_node->next);
    _it.m_node->next->prev = _new;
    _it.m_node->next = _new;
    m_size++;
    return List<T>::iterator(_it.m_node->next);
}

// Isere após o iterator
template <typename T>
typename List<T>::iterator List<T>::insert_after(const_iterator _pos, std::initializer_list <T> _il) {
    for (auto it = _il.begin(); it != _il.end(); it++) {
        Node *_new = new Node(*it, _pos.m_node->next);
        _pos.m_node->next->prev = _new;
        _pos.m_node->next = _new;
        m_size++;
    }
    return List<T>::iterator(_pos.m_node->next);
}

// Remove todos os elementos depois do iterator
template <typename T>
typename List<T>::iterator List<T>::erase_after(const_iterator _it) {
    if (_it.m_node != m_end && _it.m_node->next != m_end) {
        Node *cpy = _it.m_node->next;
        cpy->next->prev = _it.m_node;  // ATTENTION HERE
        _it.m_node->next = cpy->next;
        m_size--;
        delete cpy;
        return List<T>::iterator(_it.m_node->next);
    }
    return List<T>::iterator(_it.m_node);
}

// Remove entre dois iterators
template <typename T>
typename List<T>::iterator List<T>::erase_after(const_iterator _ini, const_iterator _end) {
    if (_ini.m_node != _end.m_node) {
        Node *cpy = _ini.m_node->next;
        _ini.m_node->next = _end.m_node;
        _end.m_node->prev = _ini.m_node;
        while (cpy != _end.m_node) {
            Node *aux = cpy;
            cpy = cpy->next;
            m_size--;
            delete aux;
        }
        return List<T>::iterator(_end.m_node);
    }
    return List<T>::iterator(_ini.m_node);
}

// Encontra o elemento da lista
template <typename T>
typename List<T>::const_iterator List<T>::find(const T &_x) const {
    auto it = cbegin();
    while (it != cend()) {
        if (*it == _x) break;
        it++;
    }
    return it;
}
