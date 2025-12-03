#ifndef MERGE_HANOI_H
#define MERGE_HANOI_H

#include <stack>
#include <deque>

class MergeHanoi {
private:
    std::stack<int> stackA;
    std::stack<int> stackB;
    std::deque<int> result;

public:
    void initStackA(std::initializer_list<int> disks);
    void initStackB(std::initializer_list<int> disks);
    void merge();
    void printResult() const;
};

#endif