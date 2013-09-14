# 静态断言 #

C++03 提供了方法去测试断言：使用宏和预处理指令 `#error` 。然而，这并不适合模板：宏测试断言是在运行时确定的，预处理指令是在是在预处理期，它们都发生在模板实例化之前。

新功能引入了一种新的测试断言方法，在编译期确定。使用新的关键字 `static_assert`。如下声明：

    static_assert (constant-expression, error-message);

eg:

    static_assert((PI > 3.14) && (PI < 3.15), "PI is inaccurate");

    template <class T>
    struct Check {
        static_assert(sizeof(int) <= sizeof(T), "T is too big enough!");
    };
    
    template <class Integral>
    Integral foo(Integral x, Integral y) {
        static_assert(std::is_integral<Integral>::value, "foo() parameter must be an integral type");
    }

当常量表达式为 `false` 时，编译器会生成一条错误信息。第一个例子有点像预处理宏`#error`，尽管与处理器只支持整数类型。对于而言，第二个例子在模板类 `Check` 实例化的时候进行检查。

静态断言在模版之外也同样很有用。比如特殊算法可能依赖于 `long long int`，要比 `int` 大很多。
