---
layout : post
title : "显式使用或禁用特定的成员函数"
category : "Language"
---

译自：[Explicitly defaulted and deleted special member functions](https://en.wikipedia.org/wiki/C%2B%2B11#Explicitly_defaulted_and_deleted_special_member_functions)

在 C++03 中，编译器为类提供了默认的构造函数，拷贝构造函数，赋值运算符(operator=)，析构函数。程序员通过自己定义这些函数来重载他们，C++ 也定义了几个全局运算符(operator=,operator new)可供类来使用，程序员也可以重载它们。

然而，这种可控性太弱了。让一个类天生就不可复制，我们可以声明一个 `private` 的拷贝构造函数和赋值运算符，但是不实现它们。使用它们的时候，会产生一个链接错误。

在这种情况下，如果类中定义了任何一种构造函数，编译器不再生成默认的构造函数。很多情况下，这样做是很有用的。但是，如果一个类既在指定了构造函数的同时，编译器又可以生成一个默认的构造函数就更好了。
C++ 允许显式的使用或者删除指定的成员函数。例如，下面声明了使用中的默认构造函数：

    struct SomeType {
        SomeType() = default;
        SomeType(OtherType value);
    };

下面的类是不可复制的：

    struct NonCopyable {
        NonCopyable() = default;
        NonCopyable(const NonCopyable&) = delete;
        NonCopyable & operator=(const NonCopyable&) = delete;
    };

`= delete` 表示这个函数的不可调用的，也可以用这种方法来禁止函数传入特定的参数：

    struct NoInt {
        void f(double i);
        void f(int) = delete;
    };

编译器不允许 `NoInt::f` 传入一个 `int` 类型的参数，而不是悄悄的把 `int` 转成 `double`。下面这种方法可以禁掉除 `double` 之外的所有参数：

    struct OnlyDouble {
        void f(double d);
        template<class T> void f(T) = delete;
    };

## 扩展资料 ##

+ [Explicitly defaulted and deleted special member functions](https://en.wikipedia.org/wiki/C%2B%2B11#Explicitly_defaulted_and_deleted_special_member_functions)
