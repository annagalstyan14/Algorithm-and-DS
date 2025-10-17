#include "CyclicList.h"
#include <iostream>

template<typename T>
bool CyclicList<T>::isEmpty() const {
    return head == nullptr;
}

template<typename T>
void CyclicList<T>::insertAtHead(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

template<typename T>
void CyclicList<T>::insertAtTail(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = head;
    }
}   

template<typename T>
void CyclicList<T>::instertAfter(int key, int value) {
    Node* targetNode = search(key);
    if (!targetNode) {
        throw std::invalid_argument("Key not found");
    }
    Node* newNode = new Node(value);
    newNode->next = targetNode->next;
    targetNode->next = newNode;
}   

template<typename T>
void CyclicList<T>::deleteNode() {
    if (isEmpty()) {
        throw std::underflow_error("List is empty");
    }
    if (head->next == head) {
        delete head;
        head = nullptr;
    } else {
        Node* tail = head;
        while (tail->next != head) {    
            tail = tail->next;
        }
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }
}

template<typename T>
void CyclicList<T>::display() const {
    if (isEmpty()) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node* current = head;
    do {
        std::cout << current->value << " ";
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
}

template<typename T>
Node* CyclicList<T>::search(int key) const {
    if (isEmpty()) {
        return nullptr;
    }
    Node* current = head;
    do {
        if (current->value == key) {
            return current;
        }
        current = current->next;
    } while (current != head);
    return nullptr;
}   

template<typename T>
void CyclicList<T>::clear() {
    while (!isEmpty()) {
        deleteNode();       
    }
}   

template<typename T>
CyclicList<T>::~CyclicList() {
    clear();
}
