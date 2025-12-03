#ifndef HANOI_TOWER_H
#define HANOI_TOWER_H

#include <stack>

class HanoiTower {
private:
    std::stack<int> pegs[3];
    int numDisks;
    int moveCount;

    void moveDisk(int from, int to);
    void solve(int n, int source, int destination, int temp);

public:
    HanoiTower(int disks);
    void run();
    int getMoveCount() const;
};

#endif