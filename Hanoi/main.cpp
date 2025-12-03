#include "HanoiTower.h"

int main() {
    int disks = 4;
    
    HanoiTower tower(disks);
    tower.run();

    return 0;
}