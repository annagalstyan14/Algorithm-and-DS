#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <map>
#include <string>

class Polynomial {
private:
    std::map<int, double, std::greater<int>> terms;

public:
    void addTerm(double coefficient, int power);
    void removeTerm(int power);
    std::string toString() const;
    void print() const;
};

#endif