# 对象构造能力的提升 #

译自： [Object construction improvement](https://en.wikipedia.org/wiki/C%2B%2B11#Object_construction_improvement)

在 C++03 中，构造一个类不允许用调用这个类的其他构造函数；这样会导致每个构造函数都要构造所有的类成员，或者调用一个公共的成员函数，如下：

     class SomeType {
        int number;
    public:
        SomeType(int new_number) : number(new_number) {}
        SomeType() : number(42) {}
    };
    
    class SomeType {
        int number;
    private:
        void Construct(int new_number) {
            number = new_number;
        }
    public:
        SomeType(int new_number) {
            Construct(new_number);
        }
        SomeType() {
            Construct(42);
        }
    };

基类的构造函数不能直接暴露给派生类；每个派生类必须实现构造函数，即便是基类构造函数已经很完善了。类的非常量数据成员不能在声明的地方初始化，且只能在构造函数中初始化。

C++11 提供了所有这些问题的解决方案。

C++11 允许构造函数调用其他的同等构造函数(peer constructors)(也就是"委托")。添加少量的代码就可以实现构造函数去调用其他构造函数。Java, C#, D 等语言都有委托。

语法如下：

    class SomeType {
        int number;
    public:
        SomeType(int new_number) : number(new_number) {}
        SomeType() : SomeType(42) {}
    };

注意，这种情况下，`new_number`成为了默认参数。新的语法允许默认值(42)表现到实现上，而不是一个接口——受益的是库代码的维护者，直接把默认值'烤'到调用站，而构造委托允许修改值但不需要重新编译代码库。

需要注意的是：C++03 认为对象构造是在构造函数执行完毕进行构造的，但是 C++11 认为对象构造是在任何一个构造函数执行完毕。多个构造函数都允许执行，意味着每个委托构造函数可以构造一个自己拥有类型的对象。派生类构造函数在它们基类的所有委托构造函数执行完毕(基类全部构造结束)再执行的。

对于基类构造函数，C++11允许类去指定基类的那个构造函数去继承。这意味着：C++11 编译器会生成代码去执行继承操作，把派生类转发给基类。注意，这是一个有或者无的(all-or-nothing)特性；或者所有的基类的构造函数转发或者一个都没有转发。对于多重继承的限制，例如，类的构造函数不能继承有多个签名的两个类。并且不能构造在派生类中已经存在的基类签名。

语法如下

    class BaseClass {
    pubic:
        BaseClass(int value);
    };
    
    class DerivedClass : public BaseClass {
    public:
        using BaseClass::BaseClass;
    };

对于成员初始化，C++11 允许下面的语法：

    class SomeClass {
    public:
        SomeClass() {}
        explicit SomeClass(int new_value) : value(new_value) {}
    private:
        int value = 5;
    };

如果构造函数没有重写它的话，所有类的构造函数都会把值初始化为 5。上面空的构造函数会初始化为5，但是有参的那个构造函数根据参数进行赋值。

它也能用构造函数或者统一的初始化方法，取代上面的赋值操作。


## 扩展资料 ##

+ [Object construction improvement](https://en.wikipedia.org/wiki/C%2B%2B11#Object_construction_improvement)
