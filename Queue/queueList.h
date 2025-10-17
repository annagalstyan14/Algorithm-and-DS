#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
class LinkedQueue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val);
        Node(T&& val);
    }; 
    Node* front;
    Node* rear;
    size_t count;

public:
    LinkedQueue();
    ~LinkedQueue();
    LinkedQueue(const LinkedQueue& other);
    LinkedQueue& operator=(LinkedQueue other);
    LinkedQueue(LinkedQueue&& other) noexcept;
    LinkedQueue& operator=(LinkedQueue&& other) noexcept;

    friend void swap(LinkedQueue& first, LinkedQueue& second) noexcept;

    void enqueue(const T& item);
    void enqueue(T&& item);
    T dequeue();
    T& peek();
    const T& peek() const;
    T& back();
    const T& back() const;
    bool isEmpty() const;
    size_t size() const;
    size_t getCount() const;
    void clear();
};

#endif // QUEUE_LIST_H
