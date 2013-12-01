---
layout : post
title : "初始化列表"
category : "Document"
---

译自：[https://en.wikipedia.org/wiki/C%2B%2B11#Initializer_lists](https://en.wikipedia.org/wiki/C%2B%2B11#Initializer_lists)，非全部翻译，进行了一定调整和扩充。


C++03 的初始化列表特性是从 C 语言继承过来的，结构体或者数组可以用大括号包含的参数列表来初始化(按照定义的顺序依次初始化)。这种初始化方式递归的，因此结构体数组或者结构体包含其他结构体也可以这么用。

    struct object
    {
        float first;
        int second;
    };
    object scalar = {0.43f, 10};
    object an_array[3] = { {13.4f, 3}, {43.28f, 29}, {5.934f, 17} };

C++03 的初始化列表特性，只能用于结构体或者符合POD的类。C++11 对这个特性进行了扩展，可以用户有所的类包括标准库容器，比如 `std::vector`。

C++11 使用模板`std::initializer_list`来实现使用列表初始化这一技术，构造函数或者其他函数都可以把它作为参数。比如：

    template <typename T>
    class my_list
    {
    public:
        my_list() {}
    
        my_list(const std::initializer_list<T> & x) {
            for (auto ite=x.begin(); ite!=x.end(); ++ite) {
                items_.push_back(*ite);
            }
        }
        void show_list() {
            copy(items_.begin(), items_.end(), std::ostream_iterator<T>(std::cout, " "));
            std::cout << std::endl;
        }
    private:
        std::vector<T> items_;
    };

对于一个函数：

    void print_init_list(const std::initializer_list<int> x) {
        copy(x.begin(), x.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }

值得注意的是，需要使用`{}`来初始化一个 `std::initializer_list` 对象，比如上面的函数调用方式为 `print_init_list({5, 4, 3, 2, 1})`。列表只能被构造和复制一次，初始化列表是常量，不要妄图去修改它的值。

C++11 标准容器也可以用以下的方式去初始化：

        std::list<int> test_list = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::vector<std::string> test_string = {"Make", "One", "Program", "Do", "One", "Thing", "Well"};


## 扩展资料 ##

+ [Initializer lists](https://en.wikipedia.org/wiki/C%2B%2B11#Initializer_lists)
+ [C++11: Initializer lists](http://oopscenities.net/2011/05/09/c0x-initializer-lists/)
