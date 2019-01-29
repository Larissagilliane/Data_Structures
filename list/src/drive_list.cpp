/*!
 *  @authors LARISSA GILLIANE MELO DE MOURA
 */

#include <iostream>
#include <cassert>
#include "list.h"

int main(int argc, char const *argv[]) {
    int i;
    List<int> ex1;
    List<int> ex2(ex1);
    List<int>::iterator it;
    List<int>::const_iterator c_it;

    // Unity #1: size()
    assert(ex1.size() == 0);
    assert(ex2.size() == 0);

    // Unity #2: empty()
    assert(ex1.empty() == true);
    assert(ex2.empty() == true);

    // Unity #3: push_front() 
    ex1.push_front(3);
    ex2.push_front(3);
   
    assert(ex1.empty() == false);  
    assert(ex2.empty() == false);  

    assert(ex1.front() == 3);      
    assert(ex2.front() == 3);    
  
    assert(ex1.back() == 3); 
    assert(ex2.back() == 3);      


    // Unity#4: push_back() 
    ex1.push_back(10);
    ex2.push_back(10);

    assert(ex1.empty() == false); 
    assert(ex2.empty() == false);  

    assert(ex1.front() == 3);    
    assert(ex2.front() == 3);     

    assert(ex1.back() == 10); 
    assert(ex2.back() == 10);     


    // Unity #5: pop_front()
    ex1.pop_front();
    ex2.pop_front();

    assert(ex1.empty() == false); 
    assert(ex2.empty() == false);  
  
    assert(ex1.front() == 10);    
    assert(ex2.front() == 10);    

    assert(ex1.back() == 10);     
    assert(ex2.back() == 10);   
  

    ex1.push_front(3);
    ex2.push_front(3);


    // Unity#6: pop_back()
    ex1.pop_back();
    ex2.pop_back();
       

    assert(ex1.empty() == false);  
    assert(ex2.empty() == false); 
 
    assert(ex1.front() == 3);     
    assert(ex2.front() == 3);    

    assert(ex1.back() == 3);     
    assert(ex2.back() == 3);     

    // Unity #7: clear() 
    ex1.clear();
    ex2.clear();
   
    assert(ex1.size() == 0);     
    assert(ex2.size() == 0);     

    assert(ex1.empty() == true);  
    assert(ex2.empty() == true);  
   

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
  
    for (i = 0; i < 10; i++) 
    {
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
    ex1.assign({1, 2, 3, 4});
    ex2.assign({1, 2, 3, 4});
  
    for (i = 1; i < 5; i++) 
    {
        assert(ex1.front() == i);
        assert(ex2.front() == i);
        
        ex1.pop_front();
        ex2.pop_front();
    
    }

    // Unity#12: size() and empty() 
    assert(ex1.size() == 0);
    assert(ex2.size() == 0);
   
    assert(ex1.empty() == true);
    assert(ex2.empty() == true);
  

    // Unity test #13:
    ex1.assign({1, 2, 3, 4, 5, 6});
    ex2.assign({1, 2, 3, 4, 5, 6});
    
    // Para ex2
    it = ex1.insert_after(ex1.before_begin(), 0);
    for (it = ex1.begin(), i = 0; it != ex1.end(); ++it, i++) 
    {
        assert(ex1.front() == i);
        ex1.pop_front();
    }
    assert(i == 7);
    // Para ex2
    it = ex2.insert_after(ex2.before_begin(), 0);
    for (it = ex2.begin(), i = 0; it != ex2.end(); ++it, i++) 
    {
        assert(ex2.front() == i);
        ex2.pop_front();
    }
    assert(i == 7);
    


    ex1.assign({1, 2, 3, 4, 5, 6});
    ex2.assign({1, 2, 3, 4, 5, 6});
  
    // Para ex2
    it = ex1.insert_after(ex1.before_begin(), 0);
    for (c_it = ex1.cbegin(), i = 0; c_it != ex1.cend(); c_it++, i++) 
    {
        assert(ex1.front() == i);
        ex1.pop_front();
    }
    assert(i == 7);

    // Para ex2
    it = ex2.insert_after(ex2.before_begin(), 0);
    for (c_it = ex2.cbegin(), i = 0; c_it != ex2.cend(); c_it++, i++) 
    {
        assert(ex2.front() == i);
        ex2.pop_front();
    }
    assert(i == 7);
    

    // Unit #15: erase_after() 
    for (i = 0; i < 10; i++)
    {
        ex1.push_back(i);
        ex2.push_back(i);
        

    }
    it = ex1.erase_after(ex1.cbefore_begin());
    it = ex2.erase_after(ex2.cbefore_begin());
    
    assert(ex1.empty() == false); 
    assert(ex2.empty() == false); 
  
    assert(ex1.front() == 1);      
    assert(ex2.front() == 1);      
    
    assert(ex1.back() == 9);       
    assert(ex2.back() == 9);    
 

    // Limpa a lista
    ex1.clear();
    ex2.clear();
    

    // Unit #16: erase_after() 
    for (i = 0; i < 10; i++) 
    {
        ex1.push_back(i);
        ex2.push_back(i);
        
    }
    it = ex1.erase_after(ex1.cbegin(), ex1.cend());
    it = ex2.erase_after(ex2.cbegin(), ex2.cend());
    
    assert(ex1.empty() == false);  
    assert(ex2.empty() == false);  
    
    assert(ex1.front() == 0);   
    assert(ex2.front() == 0);   

    assert(ex1.back() == 0);    
    assert(ex2.back() == 0);     
    

    // Limpa lista
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
