#include <iostream>

struct SomeType {
    int member;
};


int main(int argc, char *argv[])
{
    std::cout << sizeof(SomeType::member) << std::endl;
    return 0;
}
