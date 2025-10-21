#pragma once
#include "List.h"
#include "Node.h"
#include <stdexcept>
#include <cstddef>

template<typename T>
class CyclicList : public List<T> {
private:
    Node<T>* head;
    Node<T>* tail;
    std::size_t count;

public:
    CyclicList() : head(nullptr) {}
    void push_back(const T&) override;
    void push_back(T&&) override;
    void pop_back() override;
    void pop_front() override;   
    void push_front(const T&) override;
    void push_front(T&&) override;
    void insert( std::size_t, const T&) override;
    void insert( std::size_t, T&&) override;
    void erase( std::size_t) override;
    bool empty() const noexcept override;
    std::size_t size() const noexcept override;
    const T& front() const override;
    const T& back() const override;
    void clear() override;
    void swap(List<T>&) noexcept override;
    ~CyclicList() override = default;
    Node<T>* search(const T& key) const override; 
    void display() const;
};

#include "CyclicList.cpp"