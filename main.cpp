#include <iostream>
#include "PowerTrace.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    cout << "This is a program designed to preview the effect of our library" << endl;

    cout<<">> Trace simple variable: "<< endl;

    cout<<">> Trace array variable: "<< endl;

    cout<<">> Trace in the cycle: "<<endl;

    cout<<">> Trace among the file: "<<endl;

    cout<<">> Print to the log file: "<<endl;

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
