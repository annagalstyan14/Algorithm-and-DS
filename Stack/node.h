#ifndef NODE
#define NODE

template <typename T>
struct Node {
    Node(const T& val, Node* n = nullptr) : value(val), next(n) {}
    T value;
    Node* next;
};

#endif
