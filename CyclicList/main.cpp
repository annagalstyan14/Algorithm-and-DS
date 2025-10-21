#include "CyclicList.h"
#include <iostream>

int main() {
    CyclicList<int> clist;

    clist.push_back(10);
    clist.push_back(20);
    clist.push_back(30);
    clist.insert(2, 25);

    std::cout << "Cyclic list contains: ";
    clist.display();
    std::cout << std::endl;

    clist.erase(0);
    std::cout << "List after deletion: ";
    clist.display();
    std::cout << std::endl;

    Node<int>* foundNode = clist.search(25);
    if (foundNode) {
        std::cout << "Node with value 25 found" << std::endl;
    } else {
        std::cout << "Node with value 25 not found" << std::endl;
    }

    clist.clear();
    std::cout << "After clearing list" << std::endl;
    clist.display();

    return 0;
}