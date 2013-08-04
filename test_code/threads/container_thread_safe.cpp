
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <cstdarg>

template <typename T>
class container 
{
    // std::mutex _lock;
    std::recursive_mutex _lock;
    std::vector<T> _elements;
public:
    void add(T element) 
    {
        _lock.lock();
        _elements.push_back(element);
        _lock.unlock();
    }
 
    void addrange(int num, ...)
    {
        va_list arguments;
 
        va_start(arguments, num);
 
        for (int i = 0; i < num; i++)
        {
            _lock.lock();
            add(va_arg(arguments, T));
            _lock.unlock();
        }
 
        va_end(arguments); 
    }
 
    void dump()
    {
        _lock.lock();
        for(auto e : _elements)
            std::cout << e << std::endl;
        _lock.unlock();
    }
};
 
void func(container<int>& cont)
{
    cont.addrange(3, rand(), rand(), rand());
}
 
int main()
{
    srand((unsigned int)time(0));
    
    container<int> cont;
 
    std::thread t1(func, std::ref(cont));
    std::thread t2(func, std::ref(cont));
    std::thread t3(func, std::ref(cont));
 
    t1.join();
    t2.join();
    t3.join();
 
    cont.dump();
 
    return 0;
}
