/*!
 *  @authors LARISSA GILLIANE MELO DE MOURA - 20160000820
 */

#include <iostream>
#include <cassert>
#include "forward_list.h"

int main(int argc, char const *argv[]) 
{
    int i;

    Forward_list<int> ex1;
    Forward_list<int> ex2(ex1);
    Forward_list<int>::iterator it;
    Forward_list<int>::const_iterator c_it;

   
    // Unity #1: size()
    // Testa o tamanho
    assert(ex1.size() == 0);
    assert(ex2.size() == 0);


    // Unity #2: empty()
    // Testa se estao vazias
    assert(ex1.empty() == true);
    assert(ex2.empty() == true);


    // Unity #3: push_front()
    // Insere o elemento 3
    ex1.push_front(3);
    ex2.push_front(3);

    //Confere se a lista esta preenchida
    assert(ex1.empty() == false);  // empty() 
    assert(ex2.empty() == false);  // empty() 

    //Confere o elemento da frente
    assert(ex1.front() == 3);      // front() 
    assert(ex2.front() == 3);      // front() 

    //Confere o elemento do final
    assert(ex1.back() == 3);       // back()
    assert(ex2.back() == 3);       // back() 


    // Unity #4: push_back()
    // Insere o elemento 10 no final
    ex1.push_back(10);
    ex2.push_back(10);

    //Confere se a lista esta preenchida 
    assert(ex1.empty() == false);  // empty()
    assert(ex2.empty() == false);  // empty()

    //Confere o elemento da frente
    assert(ex1.front() == 3);      // front() 
    assert(ex2.front() == 3);      // front()
    
    //Confere o elemento do final
    assert(ex1.back() == 10);      // back() 
    assert(ex2.back() == 10);      // back()
    

    // Unity #5: pop_front()
    // Retira o elemento da frente 
    ex1.pop_front();
    ex2.pop_front();
    

    //Confere se um elemento foi removido 
    assert(ex1.size() == 1);       // size() 
    assert(ex2.size() == 1);       // size()
    
    //Confere se a lista esta preenchida 
    assert(ex1.empty() == false);  // empty()
    assert(ex2.empty() == false);  // empty() 
   
    //Confere o elemento da frente
    assert(ex1.front() == 10);     // front()
    assert(ex2.front() == 10);     // front() 
    
    //Confere o elemento do final
    assert(ex1.back() == 10);      // back() 
    assert(ex2.back() == 10);      // back() 
    

    ex1.push_front(3);
    ex2.push_front(3);

    // Unity #6: pop_back()
    ex1.pop_back();
    ex2.pop_back();
    
    assert(ex1.size() == 1);       // size()
    assert(ex2.size() == 1);       // size()

    assert(ex1.empty() == false);  // empty() 
    assert(ex2.empty() == false);  // empty()

    assert(ex1.front() == 3);      // front()
    assert(ex2.front() == 3);      // front() 

    assert(ex1.back() == 3);       // back()
    assert(ex2.back() == 3);       // back()


    // Unity#7: clear()
    ex1.clear();
    ex2.clear();
    
    assert(ex1.size() == 0);      // size()
    assert(ex2.size() == 0);      // size() 

    assert(ex1.empty() == true);  // empty()
    assert(ex2.empty() == true);  // empty()


    // Unity #8: push_back() and back()
    for (i = 0; i < 10; i++) 
    {
        ex1.push_back(i);
        ex2.push_back(i);
        
        assert(ex1.back() == i);
        assert(ex2.back() == i);
        
    }

    // Unity #9: assign(), front() and pop_front();
    ex1.assign(100);
    ex2.assign(100);
    
    for (i = 0; i < 10; i++) {
        assert(ex1.front() == 100);
        assert(ex2.front() == 100);
        
        ex1.pop_front();
        ex2.pop_front();
        
    }

    // Unity #10: size() and empty()
    assert(ex1.size() == 0);
    assert(ex2.size() == 0);
    
    assert(ex1.empty() == true);
    assert(ex2.empty() == true);
    

    // Unity #11: assign()
    ex1.assign({0, 1, 2, 3});
    ex2.assign({0, 1, 2, 3});
    
    for (i = 0; i < 4; i++) 
    {
        assert(ex1.front() == i);
        assert(ex2.front() == i);
        
        ex1.pop_front();
        ex2.pop_front();
       
    }

    // Unity  #12: size() and empty()
    assert(ex1.size() == 0);
    assert(ex2.size() == 0);
    
    assert(ex1.empty() == true);
    assert(ex2.empty() == true);
    

    // Unity #13: 
    ex1.assign({ 1, 2, 3, 4, 5, 6});
    ex2.assign({ 1, 2, 3, 4, 5, 6});
    

    // To ex1
    it = ex1.insert_after(ex1.before_begin(), 0);
    for (it = ex1.begin(), i = 0; it != ex1.end(); ++it, i++) 
    {
        assert(ex1.front() == i);
        ex1.pop_front();
    }
    assert(i == 7);

    // To ex2
    it = ex2.insert_after(ex2.before_begin(), 0);
    for (it = ex2.begin(), i = 0; it != ex2.end(); ++it, i++) 
    {
        assert(ex2.front() == i);
        ex2.pop_front();
    }
    assert(i == 7);

    // Unity #14: assign() 
    ex1.assign({ 1, 2, 3, 4, 5, 6});
    ex2.assign({ 1, 2, 3, 4, 5, 6});

    // To ex1
    it = ex1.insert_after(ex1.before_begin(), 0);
    for (c_it = ex1.cbegin(), i = 0; c_it != ex1.cend(); c_it++, i++) 
    {
        assert(ex1.front() == i);
        ex1.pop_front();
    }
    assert(i == 7);

    // To ex2
    it = ex2.insert_after(ex2.before_begin(), 0);
    for (c_it = ex2.cbegin(), i = 0; c_it != ex2.cend(); c_it++, i++) 
    {
        assert(ex2.front() == i);
        ex2.pop_front();
    }
    assert(i == 7);
    

    // Unit #15: erase_after()
    // Preenche a lista
    for (i = 0; i < 10; i++) 
    {
        ex1.push_back(i);
        ex2.push_back(i);
        
    }
    it = ex1.erase_after(ex1.cbefore_begin());
    it = ex2.erase_after(ex2.cbefore_begin());
    

    assert(ex1.size() == 9);        
    assert(ex2.size() == 9);       
    
    assert(ex1.front() == 1);      
    assert(ex2.front() == 1);      
    
    assert(ex1.back() == 9);       
    assert(ex2.back() == 9);       
    

    // Clear List content
    ex1.clear();
    ex2.clear();
    

    // Unit #16: erase_after()
    // Preenche a lista
    for (i = 0; i < 10; i++) 
    {
        ex1.push_back(i);
        ex2.push_back(i);
        
    }
    it = ex1.erase_after(ex1.cbegin(), ex1.cend());
    it = ex2.erase_after(ex2.cbegin(), ex2.cend());

    assert(ex1.size() == 1);       // Test for ex1
    assert(ex2.size() == 1);       // Test for ex2
 
    assert(ex1.empty() == false);  // Test for ex1
    assert(ex2.empty() == false);  // Test for ex2
  
    assert(ex1.front() == 0);      // Test for ex1
    assert(ex2.front() == 0);      // Test for ex2

    assert(ex1.back() == 0);       // Test for ex1
    assert(ex2.back() == 0);       // Test for ex2


    // Clear List
    ex1.clear();
    ex2.clear();

    // Unit #17: find()
    // Preenche a lista
    for (i = 0; i < 10; i++) 
    {
        ex1.push_back(i);
        ex2.push_back(i);
    }
    for (i = 0; i < 10; i++) 
    {
        assert(*ex1.find(i) == i);
        assert(*ex2.find(i) == i);
    }

    // Limpa a lista
    ex1.clear();
    ex2.clear();

    for (i = 0; i < 10; i++) 
    {
        ex1.push_back(i);
        ex2.push_back(i);
    }

    std::cout << "\nNormal exiting...\n\n";

    return EXIT_SUCCESS;
}
