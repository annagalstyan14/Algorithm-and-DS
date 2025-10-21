#include "arrayDeque.h"
#include <utility>
#include <stdexcept>

template <typename T>
ArrayDeque<T>::ArrayDeque()
    : data(16), capacity(16), size_(0), front_(0), rear_(0) {}

template <typename T>
ArrayDeque<T>::~ArrayDeque() = default;

template <typename T>
ArrayDeque<T>::ArrayDeque(const ArrayDeque& other)
    : data(other.capacity), capacity(other.capacity),
      size_(other.size()), front_(0), rear_(other.size()) {
    for (std::size_t i = 0; i < size_; ++i) {
        data[i] = other.data[(other.front_ + i) % other.capacity];
    }
}

template <typename T>
ArrayDeque<T>::ArrayDeque(ArrayDeque&& other) noexcept
    : data(std::move(other.data)), capacity(other.capacity),
      size_(other.size()), front_(other.front_), rear_(other.rear_) {
    other.capacity = 0;
    other.size_ = 0;
    other.front_ = 0;
    other.rear_ = 0;
}

template <typename T>
ArrayDeque<T>& ArrayDeque<T>::operator=(const ArrayDeque& other) {
    if (this != &other) {
        ArrayDeque temp(other);
        swap(temp);
    }
    return *this;
}

template <typename T>
ArrayDeque<T>& ArrayDeque<T>::operator=(ArrayDeque&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
        capacity = other.capacity;
        size_ = other.size();
        front_ = other.front_;
        rear_ = other.rear_;

        other.capacity = 0;
        other.size_ = 0;
        other.front_ = 0;
        other.rear_ = 0;
    }
    return *this;
}

template <typename T>
void ArrayDeque<T>::push_back(const T& value) {
    if (size_ == capacity) resize_array(capacity * 2);
    data[rear_] = value;
    rear_ = (rear_ + 1) % capacity;
    ++size_;
}

template <typename T>
void ArrayDeque<T>::push_back(T&& value) {
    if (size_ == capacity) resize_array(capacity * 2);
    data[rear_] = std::move(value);
    rear_ = (rear_ + 1) % capacity;
    ++size_;
}

template <typename T>
void ArrayDeque<T>::push_front(const T& value) {
    if (size_ == capacity) resize_array(capacity * 2);
    front_ = (front_ - 1 + capacity) % capacity;
    data[front_] = value;
    ++size_;
}

template <typename T>
void ArrayDeque<T>::push_front(T&& value) {
    if (size_ == capacity) resize_array(capacity * 2);
    front_ = (front_ - 1 + capacity) % capacity;
    data[front_] = std::move(value);
    ++size_;
}

template <typename T>
void ArrayDeque<T>::pop_back() {
    if (empty()) throw std::out_of_range("Deque is empty");
    rear_ = (rear_ - 1 + capacity) % capacity;
    --size_;
}

template <typename T>
void ArrayDeque<T>::pop_front() {
    if (empty()) throw std::out_of_range("Deque is empty");
    front_ = (front_ + 1) % capacity;
    --size_;
}

template <typename T>
const T& ArrayDeque<T>::front() const {
    if (empty()) throw std::out_of_range("Deque is empty");
    return data[front_];
}

template <typename T>
const T& ArrayDeque<T>::rear() const {
    if (empty()) throw std::out_of_range("Deque is empty");
    return data[(rear_ - 1 + capacity) % capacity];
}

template <typename T>
bool ArrayDeque<T>::empty() const noexcept {
    return size_ == 0;
}

template <typename T>
std::size_t ArrayDeque<T>::size() const noexcept {
    return size_;
}

template <typename T>
void ArrayDeque<T>::clear() {
    size_ = 0;
    front_ = 0;
    rear_ = 0;
}

template <typename T>
void ArrayDeque<T>::swap(Deque<T>& other) noexcept {
    if (auto* o = dynamic_cast<ArrayDeque<T>*>(&other)) {
        swap(*o);
    }
}

template <typename T>
void ArrayDeque<T>::swap(ArrayDeque<T>& other) noexcept {
    data.swap(other.data);
    std::swap(capacity, other.capacity);
    std::swap(size_, other.size_);
    std::swap(front_, other.front_);
    std::swap(rear_, other.rear_);
}

template <typename T>
void ArrayDeque<T>::resize(std::size_t new_size) {
    if (new_size == size_) return;
    if (new_size > capacity) resize_array(new_size);
    while (size_ > new_size) pop_back();
    while (size_ < new_size) push_back(T());
}

template <typename T>
void ArrayDeque<T>::resize_array(std::size_t new_capacity) {
    if (new_capacity < size_) new_capacity = size_;
    std::vector<T> new_data(new_capacity);
    for (std::size_t i = 0; i < size_; ++i) {
        new_data[i] = std::move(data[(front_ + i) % capacity]);
    }
    data = std::move(new_data);
    capacity = new_capacity;
    front_ = 0;
    rear_ = size_;
}