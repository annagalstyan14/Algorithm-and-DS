#pragma once
#include "Deque.h"
#include <cstddef>
#include <stdexcept>

template <typename T>
class ArrayDeque : public Deque<T> {
public:
    ArrayDeque() noexcept;
    ~ArrayDeque();
    ArrayDeque(const ArrayDeque&);
    ArrayDeque(ArrayDeque&&) noexcept;
    ArrayDeque& operator=(const ArrayDeque&);
    ArrayDeque& operator=(ArrayDeque&&) noexcept;

    void push_back(const T&) override;
    void push_back(T&&) override;
    void pop_back() override;
    void pop_front() override;
    void push_front(const T&) override;
    void push_front(T&&) override;
    bool empty()const noexcept override;
    std::size_t size() const noexcept override;
    const T& front() const override;
    const T& rear() const override;
    void clear() override;
    void swap(Deque<T>&) noexcept override;
    void swap(ArrayDeque<T>&) noexcept;
    void resize(std::size_t) override;

private:
    T* array_;
    std::size_t capacity_;
    std::size_t size_;
    std::size_t front_;
    std::size_t rear_;

    void resize_array(std::size_t new_capacity); 
};

#include "arrayDeque.cpp"