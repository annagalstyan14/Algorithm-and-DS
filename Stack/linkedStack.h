#ifndef LINKED_STACK
#define LINKED_STACK
#include "node.h"
#include "stack.h"

template<typename T>
class linkedStack : public Stack<T> {
public:
    linkedStack() : m_top(nullptr) {}
    linkedStack(const linkedStack& other);
    linkedStack(linkedStack&& other) noexcept;
    linkedStack& operator=(const linkedStack& other);
    linkedStack& operator=(linkedStack&& other) noexcept;
    ~linkedStack();
    void push(const T&);
    void pop();
    bool empty() const;
    void clear();
    const T& top() const;
private:
    Node<T>* m_top;
};

#include "linkedStack.ipp"
#endif