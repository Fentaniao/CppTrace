#include <iostream>
#include "string"
#include "CppTrace.h"

using namespace std;

int main() {
    cout << "This is a program designed to preview the effect of our library" << endl;

    cout << ">> Trace simple variable among the file: " << endl;
    int int_var = 3;
    double double_var = 3.14;
    char char_var = 'P';
    string string_var = "PI";

    trace(int_var);
    trace(double_var);
    trace(char_var);
    trace(string_var);


    cout << ">> Trace array variable among the file: " << endl;
    int int_arr[60] = {2, 5, 4, 9};
    double double_arr[60] = {3.14, 6.28, 12.56};
    char char_arr[60] = {'P', 'I', 'p'};

    traceArr(int_arr);
    traceArr(double_arr);
    traceArr(char_arr);


    cout << ">> Trace in the cycle: " << endl;
    int i, j;

    for (i = 0; i < 2; ++i)
        for (j = 0; j < 2; ++j) {
            trace(int_var, { i });
            traceArr(int_arr, { i, j });
        }


    cout << ">> Add description when tracing variable: " << endl;
    trace(int_var, { i }, "This is the description");
    traceArr(int_arr, { i, j }, "This is the description");


    //cout << ">> Print to the log file: " << endl;
    //OutRedirect2File("Time");
    //cout << "Hello, World!" << endl;
    //OutRedirect2File();
    //cout << "Hello, World!" << endl;


    return 0;
}