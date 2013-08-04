#include <iostream>
#include <thread>

void func(int& a)
{
    a++;
}

int main()
{
    int a = 42;
    std::thread t(func, std::ref(a));
    t.join();

    std::cout << a << std::endl;
    
    return 0;
}
