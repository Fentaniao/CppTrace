#include <iostream>
#include "string"
#include "PowerTrace.h"

using namespace std;

int main() {
    OutRedirect2File();
    cout << "Hello, World!" << endl;
    cout << "This is a program designed to preview the effect of our library" << endl;

    cout << ">> Trace among the file: " << endl;


    cout << ">> Trace simple variable: " << endl;

    int int_var = 3;
    double double_var = 3.14;
    char char_var = 'P';
    string string_var = "PI";

    trace(int_var);
    trace(double_var);
    trace(char_var);
    trace(string_var);


    cout << ">> Trace array variable: " << endl;
    int int_arr[60] = {2, 5, 4, 9};
    double double_arr[60] = {3.14, 6.28, 12.56};
    char char_arr[60] = {'P', 'I', 'p'};

    traceArr(int_arr);
    traceArr(double_arr);
    traceArr(char_arr);

    cout << ">> Trace in the cycle: " << endl;
    int i;
    int j;

    for (i = 0; i < 3; ++i)
        for (j = 0; j < 3; ++j) {
            trace(int_var, { i });
            traceArr(int_arr, { i, j });
        }

    cout << ">> Add description with variable: " << endl;
    trace(int_var, { i }, "Description");
    traceArr(int_arr, { i, j }, "Description");

    cout << ">> Print to the log file: " << endl;


    return 0;
}

