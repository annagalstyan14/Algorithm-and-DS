#include "queueArray.h"
#include <iostream>

int main() {
    Queue<int> q;

    for (int i = 1; i <= 10; ++i) {
        q.enqueue(i);
        std::cout << "Enqueued: " << i << std::endl;
    }

    while (!q.isEmpty()) {
        std::cout << "Front: " << q.peek() << std::endl;
        std::cout << "Dequeued: " << q.dequeue() << std::endl;
    }

    try {
        q.dequeue();
    } catch (const std::underflow_error& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}