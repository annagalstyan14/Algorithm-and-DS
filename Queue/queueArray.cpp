#include "queueArray.h"

template <typename T>
void Queue<T>::resize() {
    size_t newCapacity = capacity * 2;
    T* newArr = new T[newCapacity];
    for (size_t i = 0; i < count; ++i) {
        newArr[i] = std::move(arr[(front + i) % capacity]);
    }
    delete[] arr;
    arr = newArr;
    front = 0;
    rear = count;
    capacity = newCapacity;
}

template <typename T>
Queue<T>::Queue(int size)
    : arr(new T[size]), capacity(size), front(0), rear(-1), count(0) {
    if (size <= 0) throw std::invalid_argument("Queue size must be positive");
}

template <typename T>
Queue<T>::~Queue() {
    delete[] arr;
}

template <typename T>
Queue<T>::Queue(const Queue& other)
    : arr(new T[other.capacity]), capacity(other.capacity), front(other.front), rear(other.rear), count(other.count) {
    for (size_t i = 0; i < other.count; ++i) {
        arr[(front + i) % capacity] = other.arr[(other.front + i) % other.capacity];
    }
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue other) {
    swap(*this, other);
    return *this;
}

template <typename T>
Queue<T>::Queue(Queue&& other) noexcept
    : arr(other.arr), capacity(other.capacity), front(other.front), rear(other.rear), count(other.count) {
    other.arr = nullptr;
    other.capacity = 0;
    other.front = 0;
    other.rear = -1;
    other.count = 0;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& other) noexcept {
    if (this != &other) {
        delete[] arr;
        arr = other.arr;
        capacity = other.capacity;
        front = other.front;
        rear = other.rear;
        count = other.count;

        other.arr = nullptr;
        other.capacity = 0;
        other.front = 0;
        other.rear = -1;
        other.count = 0;
    }
    return *this;
}

template <typename T>
void swap(Queue<T>& first, Queue<T>& second) noexcept {
    T* tempArr = first.arr;
    first.arr = second.arr;
    second.arr = tempArr;

    size_t tempCapacity = first.capacity;
    first.capacity = second.capacity;
    second.capacity = tempCapacity;

    size_t tempFront = first.front;
    first.front = second.front;
    second.front = tempFront;

    int tempRear = first.rear;
    first.rear = second.rear;
    second.rear = tempRear;

    size_t tempCount = first.count;
    first.count = second.count;
    second.count = tempCount;
}

template <typename T>
void Queue<T>::enqueue(const T& item) {
    if (count == capacity) {
        resize();
    }
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    ++count;
}

template <typename T>
void Queue<T>::enqueue(T&& item) {
    if (count == capacity) {
        resize();
    }
    rear = (rear + 1) % capacity;
    arr[rear] = std::move(item);
    ++count;
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    T item = std::move(arr[front]);
    front = (front + 1) % capacity;
    --count;
    return item;
}

template <typename T>
T& Queue<T>::peek() {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    return arr[front];
}

template <typename T>
const T& Queue<T>::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Queue is empty");
    }
    return arr[front];
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return count == 0;
}

template <typename T>
size_t Queue<T>::size() const {
    return count;
}

template <typename T>
size_t Queue<T>::getCapacity() const {
    return capacity;
}

template <typename T>
void Queue<T>::clear() {
    front = 0;
    rear = -1;
    count = 0;
}
