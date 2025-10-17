#ifndef ARRAY_STACK_IPP
#define ARRAY_STACK_IPP

#include "ArrayStack.h"
#include <stdexcept>

template<typename T>
arrayStack<T>::arrayStack(const arrayStack& other) : elements(other.elements) {}

template<typename T>
arrayStack<T>::arrayStack(arrayStack&& other) noexcept : elements(std::move(other.elements)) {}

template<typename T>
arrayStack<T>& arrayStack<T>::operator=(const arrayStack& other) {
    if (this != &other) {
        elements = other.elements;
    }
    return *this;
}

template<typename T>
arrayStack<T>& arrayStack<T>::operator=(arrayStack&& other) noexcept {
    if (this != &other) {
        elements = std::move(other.elements);
    }
    return *this;
}

template<typename T>
void arrayStack<T>::push(const T& value) {
    elements.push_back(value);
}

template<typename T>
void arrayStack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Attempted to pop empty stack");
    }
    elements.pop_back();
}

template<typename T>
bool arrayStack<T>::empty() const {
    return elements.empty();
}

template<typename T>
void arrayStack<T>::clear() {
    elements.clear();
}

template<typename T>
const T& arrayStack<T>::top() const {
    if (empty()) {
        throw std::out_of_range("Attempted to access top of empty stack");
    }
    return elements.back();
}

template <typename T>
void swap(Stack<T>& first, Stack<T>& second) noexcept {
    using std::swap;
    swap(first.arr, second.arr);
    swap(first.capacity, second.capacity);
    swap(first.top, second.top);
    swap(first.count, second.count);
}

#endif
