/*!
 *  @authors LARISSA GILLIANE MELO DE MOURA
 */

 #include <exception>    // std::out_of_range
 #include <iostream>     // std::cout, std::endl
 #include <memory>       // std::unique_ptr
 #include <iterator>     // std::advance, std::begin(), std::end(), std::ostream_iterator
 #include <algorithm>    // std::copy
 #include <initializer_list> // std::initializer_list
 #include <cassert>      // assert()
 #include <limits>       // std::numeric_limits<T>
#include "vector.h"

int main(int argc, char const *argv[])
{
    
    int i;
    Vector<int> ex1;
    Vector<int> ex2(15);

    // Unity #1: capacity()
    assert(ex1.capacity() == 1);
    assert(ex2.capacity() == 15);

    // Unity #2: size()
    assert(ex1.size() == 0);
    assert(ex2.size() == 0);

    for (i = 0; i < 10; i++) 
    {
        ex1.push_back(i);
        ex2.push_back(i);
    }

    // Unity #3: data()
    int *m_ptr1 = ex1.data();
    int *m_ptr2 = ex2.data();

    for (i = 0; i < 10; i++) 
    {
        assert(*(m_ptr1+i) == i);
        assert(*(m_ptr2+i) == i);
    }

    // Unity  #4: 
    i = 0;
    for (auto it = ex1.cbegin(); it != ex1.cend(); it++, i++)
        assert(*it == i);
    assert(i == 10);

    // Unity  #5: 
    i = 0;
    for (auto it = ex1.cbegin(); it != ex1.cend(); ++it, i++)
        assert(*it == i);
    assert(i == 10);

    // Unity  #6:
    i = 0;
    for (auto it = ex1.begin(); it != ex1.end(); it++, i++)
        assert(*it == i);
    assert(i == 10);

    // Unity  #7: 
    i = 0;
    for (auto it = ex1.begin(); it != ex1.end(); ++it, i++)
        assert(*it == i);
    assert(i == 10);


    // Unity  #8: back()
    assert(ex1.back() == 9);
    assert(ex2.back() == 9);

    // Unity  #9: front()
    assert(ex1.front() == 0);
    assert(ex2.front() == 0);

    // Unity  #10: size() 
    assert(ex1.size() == 10);
    assert(ex2.size() == 10);

    ex1.pop_back();
    ex2.pop_back();

    // Unity  #11: size() 
    assert(ex1.size() == 9);
    assert(ex2.size() == 9);

    ex1.assign(10);
    ex2.assign(11);

    // Unity  #12: assign(), at() 
    for (i = 0; i < 9; i++) 
    {
        assert(ex1.at(i) == 10);
        assert(ex1[i] == 10);
        assert(ex2.at(i) == 11);
        assert(ex2[i] == 11);
    }

    // Limpa vector
    ex1.clear();
    ex2.clear();

    // Unity  #13: size() 
    assert(ex1.size() == 0);
    assert(ex2.size() == 0);

    std::cout << "\nNormal exiting...\n\n";

    return EXIT_SUCCESS;
}
