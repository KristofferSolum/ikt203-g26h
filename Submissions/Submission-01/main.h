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

// Step 2 a
// Create a global function called Add that takes two integers and returns the result.
// Declare and initialize a function pointer to this function.

int Add(int a, int b);
using AddPtr = int(*)(int, int);

// Step 2 b
// Create a Greet function that takes a std::string name parameter and returns "Hello, " + name.
// Create a type alias (using the modern using keyword or standard typedef)
// named GreetPtr for a pointer to a function returning a std::string.
string Greet(const string &name);
using GreetPtr = string(*)(const string&);

// Step 2 c
//Create two callback predicate functions: IsEven and IsOdd.
//They should each take an integer parameter and return a bool (true if the condition is met).
//Create a FilterAndPrint function that accepts an array of integers,
//the array's size (to prevent out-of-bounds loops), and a callback function as parameters.

bool IsEven(int value);
bool IsOdd(int value);

using PredicatePtr = bool(*)(int);

void FilterAndPrint(int [], int size, PredicatePtr function);

// Step 2 d
// Create three functions: Play, Pause, and Quit. They should take no parameters and return nothing
void Play();
void Pause();
void Quit();

using GamePtr = void(*)();

#endif //MAIN_H
