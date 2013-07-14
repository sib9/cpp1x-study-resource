#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using std::vector;


/* 旧式的 swap 函数
 * 如果 a 和 b 是一个很大的数据结构，3 次拷贝操作非常低效。
 */
template <typename T>
void old_swap(T& a, T& b)
{
    T tmp(a);
    a = b;
    b = tmp;
}

/* 新的 swap 函数
 * 使用 move 而不是 copy，大大的提升了 swap 的性能。
 */
template <typename T>
void new_swap(T& a, T& b)
{
    T tmp = move(a);
    a = move(b);
    b = move(tmp);
}

/*
 * 临时对象产生的拷贝是非常昂贵的
 */
vector<int> double_values(const vector<int> & v)
{
    vector<int> new_value;
    for (auto itr = v.begin(); itr != v.end(); ++itr)
    {
        new_value.push_back(2 * *itr);
    }
    
    return new_value;
}

void print_ref(const std::string & str) 
{
    std::cout << str << std::endl;
}

void print_ref(std::string && str)
{
    std::cout << str << std::endl;
}

std::string get_name()
{
    return "jerryzhang_by_get_name";
}


int main(int argc, char *argv[])
{
    {
        std::string left = "left";
        std::string right = "right";

        old_swap(left, right);
        std::cout << left << ", " << right << std::endl;
    }

    {
        std::string left = "left";
        std::string right = "right";
        
        new_swap(left, right);
        std::cout << left << ", " << right << std::endl;
    }

    {
        vector<int> v;
        for (int i = 0; i < 100; ++i)
        {
            v.push_back(i);
        }
        v = double_values(v);
        
        std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

    {
        std::string name("jerryzhang");
        print_ref(name);
        print_ref(get_name());
    }
    
    return 0;
}
