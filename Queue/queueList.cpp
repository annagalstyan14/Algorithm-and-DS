\#include "queueList.h"

template <typename T>
LinkedQueue<T>::Node::Node(const T& val) : data(val), next(nullptr) {}

template <typename T>
LinkedQueue<T>::Node::Node(T&& val) : data(std::move(val)), next(nullptr) {}

template <typename T>
LinkedQueue<T>::LinkedQueue()
    : front(nullptr), rear(nullptr), count(0) {}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue& other)
    : front(nullptr), rear(nullptr), count(0) {
    Node* current = other.front;
    while (current) {
        enqueue(current->data);
        current = current->next;
    }
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(LinkedQueue other) {
    swap(*this, other);
    return *this;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(LinkedQueue&& other) noexcept
    : front(other.front), rear(other.rear), count(other.count) {
    other.front = nullptr;
    other.rear = nullptr;
    other.count = 0;
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(LinkedQueue&& other) noexcept {
    if (this != &other) {
        clear();
        front = other.front;
        rear = other.rear;
        count = other.count;

        other.front = nullptr;
        other.rear = nullptr;
        other.count = 0;
    }
    return *this;
}

template <typename T>
void swap(LinkedQueue<T>& first, LinkedQueue<T>& second) noexcept {
    using std::swap;
    swap(first.front, second.front);
    swap(first.rear, second.rear);
    swap(first.count, second.count);    
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& item) {
    Node* newNode = new Node(item);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    ++count;
}

template <typename T>
void LinkedQueue<T>::enqueue(T&& item) {
    Node* newNode = new Node(std::move(item));
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    ++count;
}

template <typename T>
T LinkedQueue<T>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    Node* temp = front;
    T item = std::move(front->data);
    front = front->next;
    delete temp;
    --count;
    if (isEmpty()) {
        rear = nullptr;
    }
    return item;
}

template <typename T>
T& LinkedQueue<T>::peek() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    return front->data;
}

template <typename T>
const T& LinkedQueue<T>::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    return front->data;
}

template <typename T>
T& LinkedQueue<T>::back() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    return rear->data;
}

template <typename T>
const T& LinkedQueue<T>::back() const {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    return rear->data;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return count == 0;
}

template <typename T>
size_t LinkedQueue<T>::size() const {
    return count;
}

template <typename T>
size_t LinkedQueue<T>::getCount() const {
    return count;
}

template <typename T>
void LinkedQueue<T>::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Explicit template instantiation for common types to avoid linker issues
template class LinkedQueue<int>;
template class LinkedQueue<std::vector<int>>;
