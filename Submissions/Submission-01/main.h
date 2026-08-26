//
// Created by krist on 24.08.2026.
//


#ifndef MAIN_H
#define MAIN_H
#include <iostream>
using namespace std;

//  Step 1.1 a
//  Create a generic template function that accepts any data type
//  and prints its size in bytes to the console (hint: use sizeof()).
template <typename T>
void PrintTypeSize(T v) {
    cout << sizeof(v) << endl;
}

// Step 1.1 b
// Create a generic template function that returns the larger of two variables.
template <typename T>
T GetMax(T a, T b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Step 1.2 a
// Variadic Template Struct:
// Create a struct called TDataPack that can hold an arbitrary number of different data types
// (e.g., template <typename... Args>). This acts like a custom Tuple.
template <typename... Args>
struct TDataPack;

template <>
struct TDataPack<>{
};

template <typename First, typename ...Rest>
struct TDataPack<First, Rest...> {
    First value;
    TDataPack<Rest...> rest;
};

// Step 1.2 b
// Create a TStaticArray class where both the data type and the array size are known at compile time.
// This requires a non-type template parameter (e.g., template <typename T, int Size>).
// Implement a method to populate it and a method to print its contents.
template <typename T, int Size>
class TStaticArray {
private:
    T data[Size]{};
public:
    void Populate(int index, T value) {
        data[index] = value;
    }
    void Print() {
        for (int i = 0; i < Size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

// Step 1.2 c
//  Create a function that accepts another template as its parameter.
//  For example, create a PrintContainer function that specifically accepts yourTStaticArray blueprint.
//  (Hint: the syntax looks like template <template <typename, int> class Container, typename T, int N>).

template <
    template <typename, int> class Container,
    typename T,
    int N
>
void PrintContainer(Container<T, N>& container) {
    container.Print();
}

#endif //MAIN_H
