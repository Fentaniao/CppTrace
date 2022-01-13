#ifndef POWERTRACE_H
#define POWERTRACE_H

/**
 * <h1>PowerTrace</h1>
 * <p>A C++ head file designs to trace variable
 * <hr />
 * <h2>Usage</h2>
 * <p>Copy this .h file to your project directory, and include <b><code>#include "PowerTrace.h"</code></b> in your target .cpp file.
 * <h2>Copyright</h2>
 * @author      Fentaniao
 * @version       2021/10/20
 */

// TODO 可以考虑使用修饰符进行控制，如"N2D描述S"表示输出traceNum为2，description为描述，S表示储存为日志

#include <iostream>

using namespace std;

/**
 * <h2>Customize</h2>
 * <p>trace customize variable
 */

//#define varName(x) #x


/**
 * <h2>trace</h2>
 * <p>trace simple variable
 */

//重载
#define TRACE_1(v) Trace(v, #v, __LINE__, __FUNCTION__)
#define TRACE_2(v, opt1) Trace(v, #v, __LINE__, __FUNCTION__, opt1)
#define TRACE_3(v, opt1, opt2) Trace(v, #v, __LINE__, __FUNCTION__, opt1, opt2)

//封装
#define TRACE_NARG(...) TRACE_ARG_N(__VA_ARGS__, 4, 3, 2, 1, 0)
#define TRACE_ARG_N(_1, _2, _3, _4, n, ...) n
#define TRACE_NC(f, ...) f(__VA_ARGS__)
#define TRACE_NB(nargs, ...) TRACE_NC(TRACE_ ## nargs, __VA_ARGS__)
#define TRACE_NA(nargs, ...) TRACE_NB(nargs, __VA_ARGS__)
#define trace(...) TRACE_NA(TRACE_NARG(__VA_ARGS__), __VA_ARGS__)

template<typename T>
void
Trace(const T var, const string &varName, const int lineNum, const string &function, const int traceNum = -1,
      const string &description = "") {
    //    变量名
    cout << "TRACE[Var=" << varName << "] ";

    //    变量属性：类型
    cout << "[Type=" << typeid(var).name() << "] ";

    //    值
    cout << "[Value=" << var << "] ";

    //    标志：函数名，行号，循环参数
    cout << "[Fun=" << function << ", ";
    cout << "Line=" << lineNum;
    if (traceNum != -1)
        cout << ", Cycle=" << traceNum;
    cout << "] ";

    //    描述
    if (!description.empty())
        cout << "[Desc: " << description << "] ";

    cout << endl;
}


/**
 * <h2>traceArr</h2>
 * <p>trace array variable
 */

//重载
#define TRACEARR_1(v) TraceArr(v, #v, extent<decltype(v)>::value, __LINE__, __FUNCTION__)
#define TRACEARR_2(v, opt1) TraceArr(v, #v, extent<decltype(v)>::value, __LINE__, __FUNCTION__, opt1)
#define TRACEARR_3(v, opt1, opt2) TraceArr(v, #v, extent<decltype(v)>::value, __LINE__, __FUNCTION__, opt1, opt2)

//封装
#define TRACEARR_NARG(...) TRACEARR_ARG_N(__VA_ARGS__, 4, 3, 2, 1, 0)
#define TRACEARR_ARG_N(_1, _2, _3, _4, n, ...) n
#define TRACEARR_NC(f, ...) f(__VA_ARGS__)
#define TRACEARR_NB(nargs, ...) TRACEARR_NC(TRACEARR_ ## nargs, __VA_ARGS__)
#define TRACEARR_NA(nargs, ...) TRACEARR_NB(nargs, __VA_ARGS__)
#define traceArr(...) TRACEARR_NA(TRACEARR_NARG(__VA_ARGS__), __VA_ARGS__)

template<typename T>
void
TraceArr(const T var, const string &varName, const int &maxLength, const int lineNum, const string &function,
         const int traceNum = -1,
         const string &description = "") {
    int i;
    //    参数计算
    int nonEmptyLength = 0;
    while (var[++nonEmptyLength] != '\0');

    //    变量名
    cout << "TRACE[Array=" << varName << "] ";

    //    变量属性：类型，长度
    cout << "[Type=" << typeid(var[0]).name() << ", "
         << "Len=" << nonEmptyLength << "/" << maxLength << "] ";

    //    值
    cout << "[Set={";
    for (i = 0; i < nonEmptyLength; i++)
        cout << var[i] << ", ";
    cout << "}] ";

    //    标志：函数名，行号，循环参数
    cout << "[Fun=" << function << ", ";
    cout << "Line=" << lineNum;
    if (traceNum != -1)
        cout << ", Cycle=" << traceNum;
    cout << "] ";

    //    描述
    if (!description.empty())
        cout << "[Desc: " << description << "] ";

    cout << endl;
}

#endif //POWERTRACE_H
