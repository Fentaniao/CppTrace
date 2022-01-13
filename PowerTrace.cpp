
#include <iostream>
#include "PowerTrace.h"

using namespace std;

int main() {
    int i;
    int j;

    int indexV1 = 3;
    int weight[58] = {2, 5, 4, 9};


    for (i = 0; i < 3; ++i) {
        trace(indexV1);
        trace(indexV1, i);
        trace(indexV1, i, "23");
        traceArr(weight);
        traceArr(weight, i);
        traceArr(weight, i, "555");
    }


    return 0;
}