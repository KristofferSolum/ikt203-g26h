#include <iostream>
#include "main.h"

int main() {

    //  Step 1a Test it with an int, a double, and a custom struct.
    constexpr int test1 = 5;
    constexpr double test2 = 1.5;
    struct Tstruct1 {
        int a;
        string b;

    };
    const Tstruct1 test3{5, "Hello world!"};
    std::cout << "------------- Step 1a -------------" << std::endl;
    PrintTypeSize(test1);
    PrintTypeSize(test2);
    PrintTypeSize(test3);

    //  Step 1b Test it with two int
    std::cout << "------------- Step 1b -------------" << std::endl;
    int a=5, b=4;
    cout << GetMax(a, b) << endl;

    //  Step 1c You must successfully pass a custom struct into GetMax
    //  (e.g., a TStudent struct with a grade integer).
    //  For the template to compile, you will need to
    //  overload the > operator inside your custom struct!
    struct TStudent {
        std::string name;
        int grade;
        bool operator>(const TStudent &other) const {
            return grade > other.grade;
        }
    };

    TStudent student1 = {"Kristoffer", 4};
    TStudent student2 = {"Henrik", 5};

    TStudent max = GetMax(student1, student2);

    std::cout << "------------- Step 1b -------------" << std::endl;
    cout << max.name << ": " << max.grade << endl;
    return 0;
}