#include "Polynomial.h"
#include <iostream>
#include <sstream>

void Polynomial::addTerm(double coefficient, int power) {
    if (coefficient == 0) return;
    
    terms[power] += coefficient;
    
    if (terms[power] == 0) {
        terms.erase(power);
    }
}

void Polynomial::removeTerm(int power) {
    terms.erase(power);
}

std::string Polynomial::toString() const {
    if (terms.empty()) return "0";
    
    std::stringstream ss;
    bool first = true;
    
    for (const auto& term : terms) {
        int power = term.first;
        double coef = term.second;
        
        if (!first) {
            if (coef > 0) ss << " + ";
            else {
                ss << " - ";
                coef = -coef;
            }
        } else if (coef < 0) {
            ss << "-";
            coef = -coef;
        }
        
        if (power == 0) {
            ss << coef;
        } else if (power == 1) {
            if (coef != 1) ss << coef;
            ss << "x";
        } else {
            if (coef != 1) ss << coef;
            ss << "x^" << power;
        }
        
        first = false;
    }
    
    return ss.str();
}

void Polynomial::print() const {
    std::cout << toString() << "\n";
}