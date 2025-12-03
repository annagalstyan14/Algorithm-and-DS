#include "HanoiTower.h"
#include <iostream>

HanoiTower::HanoiTower(int disks) : numDisks(disks), moveCount(0) {
    for (int i = numDisks; i >= 1; i--) {
        pegs[0].push(i);
    }
}

void HanoiTower::moveDisk(int from, int to) {
    int disk = pegs[from].top();
    pegs[from].pop();
    pegs[to].push(disk);
    moveCount++;

    std::cout << "Move disk " << disk << " from " << char('A' + from) 
              << " to " << char('A' + to) << "\n";
}

void HanoiTower::solve(int n, int source, int destination, int temp) {
    if (n == 1) {
        moveDisk(source, destination);
        return;
    }
    if (n == 2) {
        moveDisk(source, temp);
        moveDisk(source, destination);
        moveDisk(temp, destination);
        return;
    }
    
    solve(n - 1, source, temp, destination);
    moveDisk(source, destination);
    solve(n - 1, temp, destination, source);
}

void HanoiTower::run() {
    std::cout << "Tower of Hanoi with " << numDisks << " disks\n";
    solve(numDisks, 0, 1, 2); 
    std::cout << "Completed in " << moveCount << " moves\n";
}

int HanoiTower::getMoveCount() const {
    return moveCount;
}