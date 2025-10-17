#pragma once
#include "Node.h"
#include <stdexcept>
#include <cstddef>

template<typename T>
class CyclicList {
    private:
        Node* head;
    public:
    CyclicList() : head(nullptr) {}

    bool isEmpty() const;
    void insertAtHead(int value);
    void insertAtTail(int value);
    void instertAfter(int key, int value);
    void deleteNode();
    void display() const;
    Node* search(int key) const;
    void clear();
    ~CyclicList();

};

#include "CyclicList.cpp"
