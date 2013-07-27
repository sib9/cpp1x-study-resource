#include <iostream>

void foo(char *) {
    std::cout << "call foo(char *)" << std::endl;
}

void foo(int) {
    std::cout << "call foo(int)" << std::endl;
}


int main(int argc, char *argv[])
{
    char *pc = nullptr; // ok
    char *pi = nullptr; // ok
    bool  b = nullptr; // ok, b is false
    // int i = nullptr; // error

    foo(nullptr);  // call foo(char *), not foo(int);
    
    return 0;
}
