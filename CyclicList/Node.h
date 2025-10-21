#pragma once
#include <utility>

template <typename T>
struct Node {
    T data;
    Node* next;

    Node() : data(), next(nullptr) {}
    Node(const T& value) : data(value), next(nullptr) {}
    Node(T&& value) : data(std::move(value)), next(nullptr) {}
};
