#ifndef LINKED_STACK_IPP
#define LINKED_STACK_IPP
#include "linkedStack.h"
#include <cassert>

template <typename T>
linkedStack<T>::linkedStack(const linkedStack& other) : m_top(nullptr) {
    if (other.m_top == nullptr) return;
    Node<T>* other_current = other.m_top;
    linkedStack<T> temp;
    while (other_current) {
        temp.push(other_current->value);
        other_current = other_current->next;
    }
    while (!temp.empty()) {
        push(temp.top());
        temp.pop();
    }
}

template <typename T>
linkedStack<T>::linkedStack(linkedStack&& other) noexcept : m_top(other.m_top) {
    other.m_top = nullptr; 
}

template <typename T>
linkedStack<T>& linkedStack<T>::operator=(const linkedStack& other) {
    if (this != &other) {
        clear();
        linkedStack<T> temp(other);
        std::swap(m_top, temp.m_top);
    }
    return *this;
}

template <typename T>
linkedStack<T>& linkedStack<T>::operator=(linkedStack&& other) noexcept {
    if (this != &other) {
        clear();
        m_top = other.m_top;
        other.m_top = nullptr;
    }
    return *this;
}

template <typename T>
linkedStack<T>::~linkedStack() {
    clear();
}

template <typename T>
void linkedStack<T>::push(const T& value) {
    m_top = new Node<T>(value, m_top);
}

template <typename T>
void linkedStack<T>::pop() {
    if (empty()) return;
    Node<T>* temp = m_top;
    m_top = temp->next;
    delete temp;
}

template <typename T>
bool linkedStack<T>::empty() const {
    return m_top == nullptr;
}

template <typename T>
void linkedStack<T>::clear() {
    while (!empty())
        pop();
}

template <typename T>
const T& linkedStack<T>::top() const {
    assert(m_top != nullptr);
    return m_top->value;
}

#endif