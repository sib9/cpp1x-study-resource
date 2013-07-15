
本文翻译自：[http://en.cppreference.com/w/cpp/language/constexpr](http://en.cppreference.com/w/cpp/language/constexpr)。对应测试代码在：`test_code/constexpr.cpp`

---

constexpr - 指定变量或者函数可以在编译器进行计算。

constexpr 指示符(specifier)表示变量或者函数的值可能在编译期间进行计算。但是这些变量和函数必须是在编译期是个常量表达式，constexpr 指示符暗示着一个对象是个 const 对象.

`constexpr 变量`必须满足以下要求：

+ it must be immediately construted or assigned a value.
+ the constructor parameters or the value to be assigned must contain only literal values, constexpr variables and functions. 
+ the constructor used to construct the object (either implicit or explicit) must satisfy the requirements of constexpr constructor. In the case of explicit constructor, it must have constexpr specified.

`constexpr 函数`必须满足以下要求：

+ it must not be virtual
+ ts return type must be LiteralType
+ each of its parameters must be literal type
+ the function body must be either deleted or defaulted or contain only the following:
    + null statement
    + static_assert declarations
    + typedef declarations and alias declarations that do not define classes or enumerations
    + using declarations
    + using directives
    + exactly one return statement that contains only literal values, constexpr variables and functions.

`constexpr 构造函数` 必须满足以下要求：

+ each of its parameters must be literal type
+ the class must have no virtual base classes
+ the constructor body must be either deleted or defaulted or contain only the following:
  + null statements
  + static_assert declarations
  + typedef declarations and alias declarations that do not define classes or enumerations
  + using declarations
  + using directives
+ the constructor must not have a function-try block
+ every base class and every non-static member must be initialized, either in the constructors initialization list or by a member brace-or-equal initializer. In addition, every constructor involved must be a constexpr constructor and every clause of every brace-or-equal initializer must be a constant expression
+ every implicit conversion involved must be a constant expression

ps: 对于 constexpr 我的理解是用编译时间换运行时间的一种做法。没怎么了解过模板元编程，翻译上很多地方拿捏不准，因此就直接把英文拷贝过来的。
