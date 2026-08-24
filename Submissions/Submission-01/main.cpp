#include <iostream>
#include "main.h"

int main() {

    //  Step 1a Test it with an int, a double, and a custom struct.
    constexpr int test1 = 5;
    constexpr double test2 = 1.5;
    struct struct1 {
        int a;
        string b;

    };
    const struct1 test3{5, "Hello world!"};
    std::cout << "------------- Step 1a -------------" << std::endl;
    PrintTypeSize(test1);
    PrintTypeSize(test2);
    PrintTypeSize(test3);

    //  Step 1 Test it with two int
    std::cout << "------------- Step 1b -------------" << std::endl;
    int a=5, b=4;
    cout << GetMax(a, b) << endl;

    return 0;
}