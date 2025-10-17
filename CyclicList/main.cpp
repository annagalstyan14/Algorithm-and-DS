#include "CyclicList.h"
#include <iostream>

int main() {
    CyclicList<int> clist;

    clist.insertAtHead(10);
    clist.insertAtTail(20);
    clist.insertAtTail(30);
    clist.instertAfter(20, 25);

    std::cout << "Cyclic List after insertions: ";
    clist.display();

    clist.deleteNode();
    std::cout << "Cyclic List after deleting head: ";
    clist.display();

    Node* foundNode = clist.search(25);
    if (foundNode) {
        std::cout << "Node with value 25 found." << std::endl;
    } else {
        std::cout << "Node with value 25 not found." << std::endl;
    }

    clist.clear();
    std::cout << "Cyclic List after clearing: ";
    clist.display();

    return 0;
}