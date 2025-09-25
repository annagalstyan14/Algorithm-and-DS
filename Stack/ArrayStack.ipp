#ifndef ARRAY_STACK_IPP
#define ARRAY_STACK_IPP
#include "ArrayStack.h"
#include <stdexcept>

template <typename T>
arrayStack<T>::arrayStack(const arrayStack& other) : elements(other.elements) {}

template <typename T>
arrayStack<T>::arrayStack(arrayStack&& other) noexcept : elements(std::move(other.elements)) {}

template <typename T>
arrayStack<T>& arrayStack<T>::operator=(const arrayStack& other) {
    if (this != &other) {
        elements = other.elements;
    }
    return *this;
}

template <typename T>
arrayStack<T>& arrayStack<T>::operator=(arrayStack&& other) noexcept {
    if (this != &other) {
        elements = std::move(other.elements);
    }
    return *this;
}

template <typename T>
void arrayStack<T>::push(const T& value) {
    try {
        elements.push_back(value);
    } catch (const std::bad_alloc&) {
        throw std::runtime_error("Memory allocation failed in push");
    }
}

template <typename T>
void arrayStack<T>::pop() {
    if (empty()) return;
    elements.pop_back();
}

template <typename T>
bool arrayStack<T>::empty() const {
    return elements.empty();
}

template <typename T>
void arrayStack<T>::clear() {
    elements.clear();
}

template <typename T>
const T& arrayStack<T>::top() const {
    if (empty()) {
        throw std::runtime_error("Attempted to access top of empty stack");
    }
    return elements.back();
}

#endif