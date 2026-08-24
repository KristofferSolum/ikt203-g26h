//
// Created by krist on 24.08.2026.
//


#ifndef MAIN_H
#define MAIN_H
#include <iostream>
using namespace std;

//  Step 1a Create a generic template function that accepts any data type
//  and prints its size in bytes to the console (hint: use sizeof()).
template <typename T>
void PrintTypeSize(T v) {
    cout << sizeof(v) << endl;
}

// Step 1b Create a generic template function that returns the larger of two variables.
template <typename T>
T GetMax(T a, T b) {
    if (a > b) {
        return a;
    }
    return b;
}
#endif //MAIN_H
