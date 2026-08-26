#include <iostream>
#include "main.h"

int main() {

    //  Step 1.1 a
    //  Test it with an int, a double, and a custom struct.
    constexpr int test1 = 5;
    constexpr double test2 = 1.5;
    struct Tstruct1 {
        int a;
        string b;

    };
    const Tstruct1 test3{5, "Hello world!"};
    std::cout << "------------- Step 1.1 a -------------" << std::endl;
    PrintTypeSize(test1);
    PrintTypeSize(test2);
    PrintTypeSize(test3);

    //  Step 1.1 b
    //  Test it with two int
    std::cout << "------------- Step 1.1 b -------------" << std::endl;
    int a=5, b=4;
    cout << GetMax(a, b) << endl;

    //  Step 1.1 c
    //  You must successfully pass a custom struct into GetMax
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

    TStudent bestStudent = GetMax(student1, student2);

    std::cout << "------------- Step 1.1 c -------------" << std::endl;
    cout << bestStudent.name << ": " << bestStudent.grade << endl;

    // Step 1.2 a
    TDataPack<int, double, std::string> dataPack = {5, 2.3, "hello"};
    cout<<"------------- Step 1.2 a -------------"<<endl;
    cout << dataPack.value << endl;
    cout << dataPack.rest.value << endl;
    cout << dataPack.rest.rest.value << endl;

    // Step 1.2 b
    TStaticArray<int, 3> numbers;
    numbers.Populate(0, 1);
    numbers.Populate(1, 2);
    numbers.Populate(2, 3);

    cout<<"------------- Step 1.2 b -------------"<<endl;
    numbers.Print();

    // Step 1.2 c
    cout<<"------------- Step 1.2 c -------------"<<endl;
    PrintContainer(numbers);

    return 0;
}