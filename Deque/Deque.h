#pragma once
#include <cstddef>

template <typename T>
class Deque 
{
public:
	virtual void push_back(const T&) = 0;
	virtual void push_back(T&&) = 0;
	virtual void pop_back() = 0;
	virtual void pop_front() = 0;
	virtual void push_front(const T&) = 0;
	virtual void push_front(T&&) = 0;
	virtual bool empty() const noexcept = 0;
	virtual std::size_t size() const noexcept = 0;
	virtual const T& front() const = 0;
	virtual const T& rear() const = 0;
	virtual void clear() = 0;
    virtual void swap(Deque<T>&) noexcept = 0;
    virtual ~Deque() = default;
    virtual void resize(std::size_t) = 0;
};