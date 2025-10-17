#include "arrayDeque.h"
#include <iostream>
#include <stdexcept>

int main() {
    ArrayDeque<int> deque;
    deque.push_back(1);
    deque.push_back(2);
    deque.push_front(0);

    std::cout << "Size: " << deque.size() << "\n";
    std::cout << "Front: " << deque.front() << "\n";
    std::cout << "Rear: " << deque.rear() << "\n";

    deque.pop_front();
    std::cout << "After pop_front, Front: " << deque.front() << "\n";

    deque.pop_back();
    std::cout << "After pop_back, Rear: " << deque.rear() << "\n";

    deque.resize(5);
    std::cout << "After resize to 5, Size: " << deque.size() << "\n";

    try {
        ArrayDeque<int> empty_deque;
        empty_deque.front();
    } catch (const std::out_of_range& e) {
        std::cout << "Caught expected exception: " << e.what() << "\n";
    }

    ArrayDeque<int> copy_deque(deque);
    std::cout << "Copy deque size: " << copy_deque.size() << "\n";

    ArrayDeque<int> other_deque;
    other_deque.push_back(10);
    deque.swap(other_deque);
    std::cout << "After swap, deque size: " << deque.size() << "\n";
    std::cout << "After swap, other_deque size: " << other_deque.size() << "\n";

    return 0;
}

