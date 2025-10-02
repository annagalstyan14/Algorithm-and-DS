#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
class LinkedQueue {
private:
    struct Node{
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
        Node(T&& val) : data(std::move(val)), next(nullptr) {}
    }; 
    Node* front;
    Node* rear;
    size_t count;

public:
    LinkedQueue()
    : front(nullptr), rear(nullptr), count(0) {
    }
    ~LinkedQueue() {
        clear();
    }
    
    LinkedQueue(const LinkedQueue& other)
    : front(nullptr), rear(nullptr), count(0) {
        Node* current = other.front;
        while (current) {
            enqueue(current->data);
            current = current->next;
        }
    }

    LinkedQueue& operator=(LinkedQueue other){
        swap(*this, other);
        return *this;
    }

    LinkedQueue(LinkedQueue&& other) noexcept
    : front(other.front), rear(other.rear), count(other.count) {
        other.front = nullptr;
        other.rear = nullptr;
        other.count = 0;
    }

    LinkedQueue& operator=(LinkedQueue&& other) noexcept {
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

    friend void swap(LinkedQueue& first, LinkedQueue& second) noexcept {
        using std::swap;
        swap(first.front, second.front);
        swap(first.rear, second.rear);
        swap(first.count, second.count);    
    }   

    void enqueue(const T& item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        ++count;
    }

    void enqueue(T&& item) {
        Node* newNode = new Node(std::move(item));
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        ++count;
    }

    T dequeue() {
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

    T& peek() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return front->data;
    }

    const T& peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return front->data;
    }

    T& back() {
            if (isEmpty()) {
                throw std::underflow_error("Queue is empty");
            }
            return rear->data;
        }

    const T& back() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        return rear->data;
    }


    bool isEmpty() const {
        return count == 0;
    }

    size_t size() const {
        return count;
    }

    size_t getCount() const {
        return count;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
