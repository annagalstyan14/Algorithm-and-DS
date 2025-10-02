#ifndef ARRAY_STACK
#define ARRAY_STACK
#include "stack.h"
#include <vector>
#include <cstddef>

template<typename T>
class arrayStack : public Stack<T> {
public:
    arrayStack() = default; 
    arrayStack(const arrayStack& other);
    arrayStack(arrayStack&& other) noexcept;
    arrayStack& operator=(const arrayStack& other);
    arrayStack& operator=(arrayStack&& other) noexcept;
    ~arrayStack() = default;

    void push(const T&) override;
    void pop() override;
    bool empty() const override;
    void clear() override;
    const T& top() const override;

private:
    std::vector<T> elements;
}; 

#include "ArrayStack.ipp"
#endif
