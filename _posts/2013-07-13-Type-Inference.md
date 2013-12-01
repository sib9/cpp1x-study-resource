---
layout : post
title : "类型自动推导"
category : "Document"
---


在 C++03 中(包括C)，使用一个变量比如显式的指定它的类型。然而，随着模板类型和模板元编程技术的的引入，对象的类型，详细的定义一个函数的返回值，可能不易表达。因此，临时变量的存储变的很难，可能需要去了解具体模板元库的实现细节。

C++11用两种方式来解决这种问题。第一种是使用 auto 关键字来定义直接初始化的变量类型(也就是所谓的类型推导，根据初始化的值来推导类型）。

    auto some_strange_callable_type = std::bind(&some_function, _2, _1, some_object);
    auto other_variable = 5;

`some_strange_callable_type` 类型比较简单，不用管 `std::bind` 的实现细节(参数、返回值，是否重载),它的类型对于编译器来说很容易得到(编译器语义分析的一部分)，而用户判定它的类型不是那么容易。

`other_variable` 是一个 `int`, 和整型字面量类似。

此外，`decltype`可以在编译的时候判断出一个表达式的类型(第二种方式)，例如：

    int some_int;
    decltype(some_int) other_integer_variable = 5;

和 `auto` 配合使用非常牛逼，auto 变量的具体类型只有编译器知道，而 decltype 对于大量的运算符重载和类型特化的表示非常用用。

使用 auto 可以减少很多代码冗余，比如说，以前我们是这样写的：

    for (std::vector<int>::const_iterator itr = myvec.cbegin(); itr != myvec.cend(); ++itr)

现在可以这样写：

    for (auto itr = myvec.cbegin(); itr != myvec.cend(); ++itr)

代码更短了(而且假如类型很长的话，我们不用再费劲的去记忆类型的名字，我觉得这个用法太叼了)。尤其是在模板类型嵌套的时候，比如：

    std::map<std::string, std::list<std::string> >::const_iterator

当然，这种情况下使用 `typedef` 也是一种好方法。

`decltype`和`auto`可能推导出来的类型不同：

    #include <vector>
    int main() {
        const std::vector<int> v(1);
        auto a = v[0];        // a has type int
        decltype(v[1]) b = 1; // b has type const int&, the return type of
                              //   std::vector<int>::operator[](size_type) const
        auto c = 0;           // c has type int
        auto d = c;           // d has type int
        decltype(c) e;        // e has type int, the type of the entity named by c
        decltype((c)) f = c;  // f has type int&, because (c) is an lvalue
        decltype(0) g;        // g has type int, because 0 is an rvalue
    }

个人感觉，站在这个角度来说，decltype 比 auto 功能更强大一些; 反过来，auto 比 decltype 更精巧。

`decltype((variable))`的结果永远是引用，而`decltype(variable)`结果只有当 variable 本身就是一个引用时才是引用。

## 参考资料 ##

+ [Type inference](https://en.wikipedia.org/wiki/C%2B%2B11#Type_inference)
