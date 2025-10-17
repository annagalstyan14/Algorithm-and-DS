#include "queueList.h"
#include <iostream>

int main() {
    LinkedQueue<int> q;

    for (int i = 1; i <= 5; ++i) {
        q.enqueue(i);
        std::cout << "Enqueued: " << i << std::endl;
    }

    std::cout << "Front element: " << q.peek() << std::endl;

    while (!q.isEmpty()) {
        std::cout << "Dequeued: " << q.dequeue() << std::endl;
    }

    try {
        q.dequeue();
    } catch (const std::underflow_error& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
