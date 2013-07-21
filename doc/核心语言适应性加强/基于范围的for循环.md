1. 译自 [Range-based for loop](https://en.wikipedia.org/wiki/C%2B%2B11#Range-based_for_loop)
2. 测试代码在 `test_code/range_based_loop.cpp`

C++11 扩展一种新的遍历列表的 for 循环语法(range-base for，基于范围的 for 循环)，使得遍历列表非常简单了。可以遍历 C 式的数组、初始化列表(initializer lists)，和定义了 begin()/end() 函数(返回迭代器)的类型。所有的标准库容器都可以使用 range-base for 来遍历：

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    for (int i : v) {
        std::cout << i << " " ;
    }
    std::cout << std::endl;

    for (auto ite : v) {
        std::cout << ite << " ";
    }
    std::cout << std::endl;

    
    for (int& i : v) {
        ++i;
    }


    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;


### 扩展资料 ###
+ [C++11 range-based for loops](http://www.cprogramming.com/c++11/c++11-ranged-for-loop.html) 推荐阅读
+ [Range-based for loop](https://en.wikipedia.org/wiki/C%2B%2B11#Range-based_for_loop)

