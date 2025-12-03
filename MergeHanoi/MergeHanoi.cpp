#include "MergeHanoi.h"
#include <iostream>

void MergeHanoi::initStackA(std::initializer_list<int> disks) {
    for (int disk : disks) {
        stackA.push(disk);
    }
}

void MergeHanoi::initStackB(std::initializer_list<int> disks) {
    for (int disk : disks) {
        stackB.push(disk);
    }
}

void MergeHanoi::merge() {
    while (!stackA.empty() && !stackB.empty()) {
        if (stackA.top() < stackB.top()) {
            std::cout << "Move " << stackA.top() << " from A to Result\n";
            result.push_back(stackA.top());
            stackA.pop();
        } else {
            std::cout << "Move " << stackB.top() << " from B to Result\n";
            result.push_back(stackB.top());
            stackB.pop();
        }
    }

    while (!stackA.empty()) {
        std::cout << "Move " << stackA.top() << " from A to Result\n";
        result.push_back(stackA.top());
        stackA.pop();
    }

    while (!stackB.empty()) {
        std::cout << "Move " << stackB.top() << " from B to Result\n";
        result.push_back(stackB.top());
        stackB.pop();
    }
}

void MergeHanoi::printResult() const {
    std::cout << "\nResult (front=top): ";
    for (int disk : result) {
        std::cout << disk << " ";
    }
    std::cout << "\n";
}