#ifndef STACK
#define STACK

template<typename T>
class Stack{
    virtual void push(const T&) =0;
    virtual void pop() =0;
    virtual bool empty() const = 0;
    virtual void clear() =0;
    virtual const T& top() const = 0;
};

#endif