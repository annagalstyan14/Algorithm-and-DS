#include "arrayDeque.h"
#include <algorithm>
#include <stdexcept>
#include <utility>

template <typename T>
ArrayDeque<T>::ArrayDeque() noexcept
    : array_(new T[16]), capacity_(16), size_(0), front_(0), rear_(0) {}

template <typename T>
ArrayDeque<T>::~ArrayDeque() {
    clear();
    delete[] array_;
}

template <typename T>
ArrayDeque<T>::ArrayDeque(const ArrayDeque& other)
    : array_(new T[other.capacity_]), capacity_(other.capacity_), size_(other.size_),
      front_(other.front_), rear_(other.rear_) {
    for (std::size_t i = 0; i < size_; ++i) {
        array_[(front_ + i) % capacity_] = other.array_[(other.front_ + i) % other.capacity_];
    }
}

template <typename T>
ArrayDeque<T>::ArrayDeque(ArrayDeque&& other) noexcept
    : array_(other.array_), capacity_(other.capacity_), size_(other.size_),
      front_(other.front_), rear_(other.rear_) {
    other.array_ = nullptr;
    other.capacity_ = 0;
    other.size_ = 0;
    other.front_ = 0;
    other.rear_ = 0;
}

template <typename T>
ArrayDeque<T>& ArrayDeque<T>::operator=(const ArrayDeque& other) {
    ArrayDeque temp(other);
    swap(temp);
    return *this;
}

template <typename T>
ArrayDeque<T>& ArrayDeque<T>::operator=(ArrayDeque&& other) noexcept {
    if (this != &other) {
        delete[] array_;
        array_ = other.array_;
        capacity_ = other.capacity_;
        size_ = other.size_;
        front_ = other.front_;
        rear_ = other.rear_;
        other.array_ = nullptr;
        other.capacity_ = 0;
        other.size_ = 0;
        other.front_ = 0;
        other.rear_ = 0;
    }
    return *this;
}

template <typename T>
void ArrayDeque<T>::push_back(const T& value) {
    if (size_ == capacity_) {
        resize_array(capacity_ * 2);
    }
    array_[rear_] = value;
    rear_ = (rear_ + 1) % capacity_;
    ++size_;
}

template <typename T>
void ArrayDeque<T>::push_back(T&& value) {
    if (size_ == capacity_) {
        resize_array(capacity_ * 2);
    }
    array_[rear_] = std::move(value);
    rear_ = (rear_ + 1) % capacity_;
    ++size_;
}

template <typename T>
void ArrayDeque<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("Deque is empty");
    }
    rear_ = (rear_ - 1 + capacity_) % capacity_;
    --size_;
}

template <typename T>
void ArrayDeque<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("Deque is empty");
    }
    front_ = (front_ + 1) % capacity_;
    --size_;
}

template <typename T>
void ArrayDeque<T>::push_front(const T& value) {
    if (size_ == capacity_) {
        resize_array(capacity_ * 2);
    }
    front_ = (front_ - 1 + capacity_) % capacity_;
    array_[front_] = value;
    ++size_;
}

template <typename T>
void ArrayDeque<T>::push_front(T&& value) {
    if (size_ == capacity_) {
        resize_array(capacity_ * 2);
    }
    front_ = (front_ - 1 + capacity_) % capacity_;
    array_[front_] = std::move(value);
    ++size_;
}

template <typename T>
bool ArrayDeque<T>::empty()const noexcept {
    return size_ == 0;
}

template <typename T>
std::size_t ArrayDeque<T>::size() const noexcept {
    return size_;
}

template <typename T>
const T& ArrayDeque<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Deque is empty");
    }
    return array_[front_];
}

template <typename T>
const T& ArrayDeque<T>::rear() const {
    if (empty()) {
        throw std::out_of_range("Deque is empty");
    }
    return array_[(rear_ - 1 + capacity_) % capacity_];
}

template <typename T>
void ArrayDeque<T>::clear() {
    for (std::size_t i = 0; i < size_; ++i) {
        array_[(front_ + i) % capacity_].~T();
    }
    size_ = 0;
    front_ = 0;
    rear_ = 0;
}

template <typename T>
void ArrayDeque<T>::swap(Deque<T>& other) noexcept {
    if (auto* other_array = dynamic_cast<ArrayDeque<T>*>(&other)) {
        swap(*other_array);
    }
}

template <typename T>
void ArrayDeque<T>::swap(ArrayDeque<T>& other) noexcept {
    std::swap(array_, other.array_);
    std::swap(capacity_, other.capacity_);
    std::swap(size_, other.size_);
    std::swap(front_, other.front_);
    std::swap(rear_, other.rear_);
}

template <typename T>
void ArrayDeque<T>::resize(std::size_t new_size) {
    if (new_size == size_) {
        return;
    }
    if (new_size > capacity_) {
        resize_array(new_size);
    }
    while (size_ > new_size) {
        pop_back();
    }
    while (size_ < new_size) {
        push_back(T());
    }
}

template <typename T>
void ArrayDeque<T>::resize_array(std::size_t new_capacity) {
    if (new_capacity < size_) {
        new_capacity = size_;
    }
    T* new_array = new T[new_capacity];
    try {
        for (std::size_t i = 0; i < size_; ++i) {
            new_array[i] = std::move(array_[(front_ + i) % capacity_]);
        }
    } catch (...) {
        delete[] new_array;
        throw;
    }
    delete[] array_;
    array_ = new_array;
    capacity_ = new_capacity;
    front_ = 0;
    rear_ = size_;
}

template class ArrayDeque<int>;