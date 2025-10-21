#pragma once
#include "Node.h"
#include <cstddef>

 template<typename T>
    class List
    {
    public:
        virtual void push_back(const T&) = 0;
        virtual void push_back(T&&) = 0;
        virtual void pop_back() = 0;
        virtual void pop_front() = 0;   
        virtual void push_front(const T&) = 0;
        virtual void push_front(T&&) = 0;
        virtual void insert( std::size_t, const T&) = 0;
        virtual void insert( std::size_t, T&&) = 0;
        virtual void erase( std::size_t) = 0;
        virtual bool empty() const noexcept = 0;
        virtual std::size_t size() const noexcept = 0;
        virtual const T& front() const = 0;
        virtual const T& back() const = 0;
        virtual void clear() = 0;
        virtual void swap(List<T>&) noexcept = 0;
        virtual ~List() = default;
        virtual Node<T>* search(const T& key) const = 0;
    };

