#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
class Queue {
private:
    T* arr;
    size_t capacity;
    size_t front;
    size_t rear;
    size_t count;

    void resize() {
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

public:
    Queue(int size = 8)
    : arr(new T[size]), capacity(size), front(0), rear(-1), count(0) {
    if (size <= 0) throw std::invalid_argument("Queue size must be positive");
    }
    ~Queue() {
        delete[] arr;
    }

    Queue(const Queue& other)
    : arr(new T[other.capacity]), capacity(other.capacity), front(other.front), rear(other.rear), count(other.count) {
        for (size_t i = 0; i < other.count; ++i) {
            arr[(front + i) % capacity] = other.arr[(other.front + i) % other.capacity];
        }
    }

    Queue& operator=(Queue other){
        swap(*this, other);
        return *this;
    }

    Queue(Queue&& other) noexcept
    : arr(other.arr), capacity(other.capacity), front(other.front), rear(other.rear), count(other.count) {
        other.arr = nullptr;
        other.capacity = 0;
        other.front = 0;
        other.rear = -1;
        other.count = 0;
    }   

    Queue& operator=(Queue&& other) noexcept {
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

    friend void swap(Queue& first, Queue& second) noexcept {
        using std::swap;
        swap(first.arr, second.arr);
        swap(first.capacity, second.capacity);
        swap(first.front, second.front);
        swap(first.rear, second.rear);
        swap(first.count, second.count);
    }   

    void enqueue(const T& item) {
        if (count == capacity) {
            resize();
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        ++count;
    }

    void enqueue(T&& item) {
        if (count == capacity) {
            resize();
        }
        rear = (rear + 1) % capacity;
        arr[rear] = std::move(item);
        ++count;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        T item = std::move(arr[front]);
        front = (front + 1) % capacity;
        --count;
        return item;
    }

    T& peek() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return arr[front];
    }

    const T& peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return arr[front];
    }

    bool isEmpty() const {
        return count == 0;
    }

    size_t size() const {
        return count;
    }

    size_t getCapacity() const {
        return capacity;
    }

    void clear() {
        front = 0;
        rear = -1;
        count = 0;
    }
};
