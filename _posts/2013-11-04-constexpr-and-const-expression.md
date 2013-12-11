---
layout : post
title : "constexpr和常量表达式"
category : "Language"
---

常量表达式(const expression) 是指值不会改变并且在编译过程就能得到计算结果的表达式。

## constexpr 变量 ##

C++11 新标准规定，允许将变量声明为constexpr类型以便由编译器来验证变量是否是一个常量表达式。声明为constexpr 的变量一定是一个常量，而且必须用常量表达式初始化。

    constexpr int mf = 20; // 20 是常量表达式
    constexpr int limit = mf + 1; // mf + 1 是常量表达式
    constexpr sz = size();  // 只有当size是一个constexpr函数时
                            // 才是一条正确的语句

## 指针和 constexpr ##

在 constexpr 声明中如果定义了一个指针，constexpr 仅对指针有效，与指针所指的对象无关。

    const int *p = nullptr;    // p 是一个指向整行常量的指针
    constexpr int *q = nullptr; // q 是一个指向整数的常量指针

p 是可变的，p指向的对象是不可变的。q是不可变的，q指向的对象是可变的。

## 参考资料 ##

+ C++ Primer(第5版)中文版 P59
