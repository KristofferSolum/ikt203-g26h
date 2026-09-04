#include <iostream>
#include "main.h"

// Step 2 a
// Create a global function called Add that takes two integers and returns the result.
int Add(int a, int b) {
    return a + b;
}

// Step 2 b
// Create a Greet function that takes a std::string name parameter and returns "Hello, " + name.
string Greet(const string &name) {
    return "Hello, " + name;
}

// Step 2c
//Create two callback predicate functions: IsEven and IsOdd.
bool IsEven(int value) {
    if (value % 2 == 0) {
        return true;
    }
    return false;
}
bool IsOdd(int value) {
    if (value % 2 != 0) {
        return true;
    }
    return false;
}

//Create a FilterAndPrint function that accepts an array of integers,
//the array's size (to prevent out-of-bounds loops), and a callback function as parameters.
void FilterAndPrint(int arr[], int size, PredicatePtr function) {
    for (int i = 0; i < size; i++) {
        if (function(arr[i])) {
            cout << arr[i] << " ";
        }
    }
}

// Step 2 d
// Create three functions: Play, Pause, and Quit. They should take no parameters and return nothing,
// only executing a std::cout with "Playing game...", "Game paused.", and "Quitting game." respectively.
void Play() {
    cout << "Playing game..." << endl;
}

void Pause() {
    cout << "Game paused." << endl;
}

void Quit() {
    cout << "Quitting game." << endl;
}

// Step 3 c
void DoubleInt(int &val) {
    val *= 2;
}

void CapitalizeChar(char &val) {
    val = toupper(val);
}




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
    TStaticArray<int, 3> numbers1;
    numbers1.Populate(0, 1);
    numbers1.Populate(1, 2);
    numbers1.Populate(2, 3);

    cout<<"------------- Step 1.2 b -------------"<<endl;
    numbers1.Print();

    // Step 1.2 c
    cout<<"------------- Step 1.2 c -------------"<<endl;
    PrintContainer(numbers1);

    // Step 2 a
    // Call the function twice using your pointer:
    // once using implicit dereference and once using explicit dereference.
    AddPtr FAdd = &Add;
    cout<<"------------- Step 2 a -------------"<<endl;
    cout << FAdd(2, 3) << endl;
    cout << (*FAdd)(2, 3) << endl;

    // Step 2 b
    // Create a type alias (using the modern using keyword or standard typedef)
    // named GreetPtr for a pointer to a function returning a std::string.
    GreetPtr FGreet = &Greet;
    cout<<"------------- Step 2 b -------------"<<endl;
    cout << (*FGreet)("Kristoffer") << endl;

    // Step 2 c
    //Create an array with 10 numbers and filter them by calling FilterAndPrint
    //twice—once with IsEven and once with IsOdd.
    int numbers2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout<<"------------- Step 2 c -------------"<<endl;
    FilterAndPrint(numbers2, 10, &IsEven);
    cout << endl;
    FilterAndPrint(numbers2, 10, &IsOdd);
    cout << endl;

    // Step 2 d
    // Create an array of function pointers containing these three functions.
    // Iterate over the array in a loop and execute all three functions dynamically.
    cout<<"------------- Step 2 d -------------"<<endl;

    GamePtr FPlay = &Play;
    GamePtr FPause = &Pause;
    GamePtr FQuit = &Quit;

    GamePtr gamingList[4] = {FPlay, FPause, FPlay, FQuit};

    for (const auto & i : gamingList) {
        i();
    }

    // Step 3 d
    cout<<"------------- Step 3 d -------------"<<endl;

    int nums[5] = {1, 2, 3, 4, 5};
    char chars[5] = {'a', 'b', 'c', 'd', 'e'};

    FActionFunc<int> FDoubleInt = &DoubleInt;
    FActionFunc<char> FCapitalizeChar = &CapitalizeChar;

    ProcessArray(nums, 5, FDoubleInt);
    ProcessArray(chars, 5, FCapitalizeChar);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    for (char c : chars) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
