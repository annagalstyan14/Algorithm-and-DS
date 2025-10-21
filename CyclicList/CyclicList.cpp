#include "CyclicList.h"
#include <utility>
#include <iostream>
#include <stdexcept>

template<typename T>
std::size_t CyclicList<T>::size() const noexcept {
    if (!head) {
        return 0;
    }
    std::size_t count = 1;
    Node<T>* current = head->next;
    while (current != head) {
        ++count;    
        current = current->next;
    }
    return count;
}

template<typename T>
bool CyclicList<T>::empty() const noexcept {
    return head == nullptr;
}   

template<typename T>
const T& CyclicList<T>::front() const {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    return head->data;
}

template<typename T>
const T& CyclicList<T>::back() const {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    return head->data;
}

template<typename T>
Node<T>* CyclicList<T>::search(const T& key) const {
    if (empty()) {
        return nullptr;
    }
    Node<T>* current = head;
    do {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    } while (current != head);
    return nullptr;
}   

template<typename T>
void CyclicList<T>::clear() {
    if (empty()) {      
        return;
    }
    Node<T>* current = head->next;
    while (current != head) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    delete head;    
    head = nullptr;
}   

template<typename T>
void CyclicList<T>::swap(List<T>& other) noexcept {
    CyclicList<T>* otherCyclic = dynamic_cast<CyclicList<T>*>(&other);
    if (otherCyclic) {
        std::swap(head, otherCyclic->head);
    }
}   

template<typename T>
void CyclicList<T>::push_back(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (empty()) {
        head = newNode;
        head->next = head;
    } else {
        Node<T>* tail = head;
        while (tail->next != head)
            tail = tail->next;
        tail->next = newNode;
        newNode->next = head;
    }
}

template<typename T>
void CyclicList<T>::push_back(T&& value) {
    Node<T>* newNode = new Node<T>(std::move(value));
    if (empty()) {
        head = newNode;
        head->next = head;
    } else {
        Node<T>* tail = head;
        while (tail->next != head)
            tail = tail->next;
        tail->next = newNode;
        newNode->next = head;
    }
}   

template<typename T>
void CyclicList<T>::push_front(const T& value) {
    push_back(value);
    head = head->next;
}

template<typename T>
void CyclicList<T>::push_front(T&& value) {
    push_back(std::move(value));
    head = head->next;
}

template<typename T>
void CyclicList<T>::pop_back() {
    if (empty()) throw std::out_of_range("List is empty");

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node<T>* prev = head;
    while (prev->next->next != head)
        prev = prev->next;

    Node<T>* last = prev->next;
    prev->next = head;
    delete last;
}


template<typename T>
void CyclicList<T>::pop_front() {
    if (empty()) throw std::out_of_range("List is empty");

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }

    Node<T>* tail = head;
    while (tail->next != head)
        tail = tail->next;

    Node<T>* newHead = head->next;
    tail->next = newHead;
    delete head;
    head = newHead;
}

template<typename T>
void CyclicList<T>::insert(std::size_t index, const T& value) {
    if (index == 0) {
        push_front(value);
        return;
    }

    std::size_t currentIndex = 0;
    Node<T>* current = head;
    do {
        if (currentIndex + 1 == index) {
            Node<T>* newNode = new Node<T>(value);
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
        ++currentIndex;
    } while (current != head);

    throw std::out_of_range("Index out of range");
}

template<typename T>
void CyclicList<T>::insert(std::size_t index, T&& value) {
    if (index == 0) {
        push_front(std::move(value));
        return;
    }

    std::size_t currentIndex = 0;
    Node<T>* current = head;
    do {
        if (currentIndex + 1 == index) {
            Node<T>* newNode = new Node<T>(std::move(value));
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
        ++currentIndex;
    } while (current != head);

    throw std::out_of_range("Index out of range");
}

template<typename T>
void CyclicList<T>::erase(std::size_t index) {
    if (empty()) throw std::out_of_range("List is empty");

    if (index == 0) {
        pop_front();
        return;
    }

    std::size_t currentIndex = 0;
    Node<T>* current = head;
    do {
        if (currentIndex + 1 == index) {
            Node<T>* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            delete nodeToDelete;
            return;
        }
        current = current->next;
        ++currentIndex;
    } while (current != head);

    throw std::out_of_range("Index out of range");
}

template<typename T>
void CyclicList<T>::display() const {
    if (empty()) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node<T>* current = head;
do {
    std::cout << current->data << " ";
    current = current->next;
} while (current != head);
}
