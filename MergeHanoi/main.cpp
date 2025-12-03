#include "MergeHanoi.h"

int main() {
    MergeHanoi mh;

    mh.initStackA({5, 3, 1});
    mh.initStackB({6, 4, 2});

    mh.merge();
    mh.printResult();

    return 0;
}
