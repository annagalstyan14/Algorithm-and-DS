#include "Polynomial.h"
#include <iostream>

int main() {
    Polynomial p;
    
    p.addTerm(3, 2);
    p.addTerm(2, 1);
    p.addTerm(-5, 0);
    
    std::cout << "p(x) = ";
    p.print();
    
    p.addTerm(4, 3);
    std::cout << "After adding 4x^3: ";
    p.print();
    
    p.removeTerm(1);
    std::cout << "After removing x term: ";
    p.print();
    
    return 0;
}