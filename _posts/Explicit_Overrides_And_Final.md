# 显式重载和 Final 操作符#

译自: [Explicit overrides and final](https://en.wikipedia.org/wiki/C%2B%2B11#Explicit_overrides_and_final)

在 C++03 中，重载基类的虚函数，不能达到重载的效果。比如：

    struct Base {
        virtual void some_func(float a)
            {
                std::cout << "Base: " << a << std::endl;
            }
    };
    
    struct Derived : Base {
        virtual void some_func(int a)
            {
                std::cout << "Derived: "  << a << std::endl;
            }
    };

当用基类指针指向派生类对象时，调用`some_func`并不调用派生类的 `some_func`(也就是上面说的不能达到重载的效果，但是编译器并没有报错)。这是因为它们有不同的函数签名(signature)，它们是两个不同的虚函数。常常会因为修改了基类的函数参数，却没有同步派生类的函数参数，引发很多问题(多态)。

C++11 提供显式重载语法来解决这个问题：

    struct NewBase {
        virtual void some_func(float a)
            {
                std::cout << "NewBase: " << a << std::endl;
            }
    };
    
    struct NewDerived : NewBase {
        virtual void some_func(int a) override  // ill-formed - doesn't override a base class method
            {
                std::cout << "NewDerived: " << a << std::endl;
            }
    };

显示的使用`override`告诉编译器检查基类(们)去检查是否有虚函数有确定的签名，如果没有的话，编译器会报错。(译者住：这样的话，相当与把问题放大了，让用户明确自己的使用)。

C++11 也提供了阻止派生类重载基类函数的方法，是用`final`来实现的：

    struct Base1 final{};
    
    struct Derived : Base final {};  // ill-formed because the class Base1 has been marked final
    
    struct Base2 {
        virtual void f() final;
    };
    
    struct Derived2 : Base2 {
        virtual void f(); // ill-formed because the class Base1 has been marked final
    };

`Base1`是`final`类，`virtual void f() final`是`final`函数，显示告诉编译器该类/虚函数是不能用来派生/重载的，

注意，不管是`override`还是`final`都不是语言的关键字，它们是技术上的标志符(`technically identifiers`)；只有在指定的上下文中才有特定的含义。在其他情况下，它们都是无意义的标志符。

## 扩展资料 ##

+ [Explicit overrides and final](https://en.wikipedia.org/wiki/C%2B%2B11#Explicit_overrides_and_final)
