#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

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

    void resize();

public:
    Queue(int size = 8);
    ~Queue();
    Queue(const Queue& other);
    Queue& operator=(Queue other);
    Queue(Queue&& other) noexcept;
    Queue& operator=(Queue&& other) noexcept;

    friend void swap(Queue& first, Queue& second) noexcept;

    void enqueue(const T& item);
    void enqueue(T&& item);
    T dequeue();
    T& peek();
    const T& peek() const;
    bool isEmpty() const;
    size_t size() const;
    size_t getCapacity() const;
    void clear();
};

#endif // QUEUE_ARRAY_H
