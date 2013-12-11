R-value-Ref-And-Move-Construct|Language|2013-07-13

这篇文章是我从[Move semantics and rvalue references in C++11](http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html)翻译而来的。值得一提的是，不是全文/原文逐字逐句的翻译，加了一些我个人的理解，并进行了一定的精简。

----------------

## 问题 ##

    vector<int> double_values(const vector<int> & v)
    {
        vector<int> new_value;
        for (auto itr = v.begin(); itr != v.end(); ++itr)
        {
            new_value.push_back(2 * *itr);
        }
        
        return new_value;
    }

`double\_values` 中 new\_value 的构造是必须的，原则上来说，有两次拷贝：一次是返回 new\_value 时，会产生一个临时对象，另外一次是在调用 double\_value 时产生的，比如 `v = double_values(v);`，第一次拷贝由编译器进行一定的优化，而第二次调用 `vector` 的赋值运算符，需要复制所有的数据，也就是需要新的内存，既而迭代拷贝数据，之后临时对象进行析构。

## 解决方法 ##

接上面的例子。理论上来讲，临时对象，构造->赋值->析构，构造时，申请空间；析构时，释放空间(像是句废话，其实不然)。针对这个语句来说: `v = double_values(v)`，赋值过程中，释放内存->申请内存->赋值。那么有没有一种办法，可以让临时对象和v不要做重复的事情呢？我们假设是这样：把临时对象中的内存直接为v所用，这样就省了很多事情。

在 C++11 中，提供了 move constructor 和 move assignment 来解决这种问题。move语义可以减少很多不必须要的临时对象拷贝操作，并且保证从临时对象中拿到的资源是安全的。

move 语义的实现依赖于`(右值引用)rvalue-reference`。好吧，我们先来说说右值引用。

### 右值引用  ###

简单来讲，左值：`An lvalue is an expression whose address can be taken, a locator value--essentially, an lvalue provides a (semi)permanent piece of memory. You can make assignments to lvalues`，右值: `An expression is an rvalue if it results in a temporary object`。我看过一些资料，大体上可以去这么去理解。细节部分还是挺多的，如果关心的话可以去看`资料`中的[http://www.caole.net/diary/lvalue.html](http://www.caole.net/diary/lvalue.html)，讲的挺不错的。

右值引用会和一个临时对象绑定。比如，在 C++11 之前，如果你有一个临时对象，你可以用`regular`或者`lvalue reference` 去绑定它，但是仅仅是在`const`的情况下：

    const string & name = get_name(); // ok
    string& name = get_name(); // NOT ok

这是因为临时对象生存周期所限，引用它的地址，一直它本身就消失了，这是很危险的。注意，常量引用一个临时对象，这个对象不会立即析构，但是他仍旧是一个临时对象，所以你不能修改它。

在 C++11 中，右值引用允许你为右值绑定一个可变引用，但是不能是一个左值。换句话说，右值引用可以检测到一个对象是不是临时对象。右值引用使用`&&`语法来声明而不是`&`，可以是常量，也可以是非常量。和左值引用一样，尽管你很少见到一个常量右值引用。

    const string && name = get_name(); // ok
    string && name = get_name();  // alse ok - praise be!

使用左值和右值引用重载函数，调用情况是什么样呢？

    void print_ref(const std::string & str) 
    {
        std::cout << str << std::endl;
    }
    
    void print_ref(std::string && str)
    {
        std::cout << str << std::endl;
    }

    std::string name("jerryzhang");
    print_ref(name); // calls the first print_ref function, taking an lvalue reference
    print_ref(get_name()); // calls the second print_ref function, taking a mutable rvalue reference

现在，我们有了自己的方式去判定一个引用变量指向的是临时对象还是非临时变量(permanent object)。右值引用版本的方法，像是一个俱乐部的秘密后门入口，只有你可以进入，如果你是一个临时对象的话。

了解了右值引用，是时候看看它的具体用途了。


### move constructr 和 move assignment operator ###

右值引用的最常用用途是创建move构造函数和move赋值运算符（具有相同的规则）。move构造可以避免重新申请内存，因为我们知道它已经提供了一个临时对象，我们不需要从它来复制字段，而是直接从它们上move过来。

如果字段是一个内置类型(primitive type), 比如`int`，我们就直接复制。其实我们关心的是，字段的类型是`指针`：这种情况下，不是申请内存/初始化内存，我们可以直接`偷取`指针，然后把临时对象的指针指空。我们知道临时对象已经不再用，因此可以使用它指针所指向的内存。

假如我们有下面这样一个简单的`ArrayWrapper`类：

    class ArrayWrapper
    {
    public:
        ArrayWrapper(int n)
            : _p_vals(new int[n])
            , _size(n)
            {}
        // copy constructor
        ArrayWrapper(const ArrayWrapper & other)
            : _p_vals(new int[other._size))
            , _size(other._size)
            {
                for (int i = 0; i <_size; ++i)
                {
                    _p_vals[i] = other._p_vals[i];
                    
                }
            }
        ~ArrayWrapper()
            {
                delete [] _p_vals;
                
            }
    private:
        int * _p_vals;
        int _size;
    };

注意，拷贝构造函数既申请了内存又对每个值进行了赋值，这个拷贝操作很耗费时间。下面是使用 move 构造，对效率进行了提升：

    class ArrayWrapper
    {
    public:
        // default constructor produces a moderately size array
        ArrayWrapper()
            : _p_vals(new int[64])
            , _size(64)
            {}
    
        ArrayWrapper(int n)
            : _p_vals(new int[n])
            , _size(n)
            {}
    
        // move constructor
        ArrayWrapper(ArrayWrapper && other)
            : _p_vals(other._p_vals)
            , size(other._size)
            {
                other._p_vals = NULL;
            }
    
        // copy constructor
        ArrayWrapper(const ArrayWrapper& other)
            : _p_vals(new int[other._p_vals])
            , _size(other._size)
            {
                for (int i = 0; i < _size ; ++i)
                {
                    _p_vals[i] = other._p_vals[i];
                }
            }
        ~ArrayWrapper()
            {
                delete [] _p_vals;   
            }
    private:
        int *_p_vals;
        int _size;
    };

`move constructor` 要比 `copy constructor` 简单且高效的多！ 有两点需要注意：

1. 参数是`非常量`右值引用
2. `other._p_vals` 要置为 `NULL`

第二点是站在第一点的基础上的，如果传入的是一个`常量`的右值引用，`_p_vals`也不可能置为`NULL`。如果没有进行指针的置空的话，临时对象析构时会把指针所指向的内存进行释放，也就是我们的`move`没有真正的`move`——当我们使用已经释放了的内存，会引发崩溃。

再重复一下，只有确定参数是一个临时对象的时候才会去调用 `move constructor`——并且只有临时对象才可以被修改。反过来，如果你有一个函数返回的是临时对象，它会去调用 `copy constructor`而不是`move constructor`，因此你不能这样写代码：

    const ArrayWrapper getArrayWrapper(); // make the move constructor useless, the temporary is const!

仍旧有一种情况我们没有考虑到：我们需要赋值的字段是一个对象，例如，想象一下，我们有个媒体数据字段：

    class MetaData
    {
    public:
        MetaData(int size, const std::string & name)
            : _name(name)
            , _size(size)
            {}
    
        // copy constructor
        MetaData(const MetaData & other)
            : _name(other._name)
            , _size(other._size)
            {}
    
        // move constructor
        MetaData(MetaData&& other)
            : _name(other.name)
            , _size(other._size)
            {}
    
        std::string getName() const 
            {
                return _name;
            }
    
        int getSize() const
            {
                return _size;
            }
    private:
        std::string _name;
        int _size;
    };

现在我们的数据有一个`name`字段和`size`字段，我们不得不去修改 `ArrayWrapper`的定义：

    class ArrayWrapper
    {
    public:
        // default constructor produces a moderately sized array
        ArrayWrapper()
            : _p_vals(new int[64])
            , _metadata(64, "ArrayWrapper")
            {}
        ArrayWrapper(int n)
            : _p_vals(new int[n])
            , _metadata(n, "ArrayWrapper")
            {}
    
        // move constructor
        ArrayWrapper(ArrayWrapper && other)
            : _p_vals(other._p_vals)
            , _metadata(n, "ArrayWrapper")
            {}
    
        // copy constructor
        ArrayWrapper(const ArrayWrapper & other)
            : _p_vals(new int[other._metadata.getSize()])
            , _metadata(other._metadata)
            {
                other._p_vals = NULL;
            }
    
        // copy constructor
        ArrayWrapper(const ArrayWrapper & other)
            : _p_vals(new int[other._metadata.getSize()])
            , _metadata(other._metadata)
            {
                for (int i = 0; i < _metadata.getSize(); ++i)
                {
                    _p_vals[i] = other._p_vals[i];
                }
            }
    
        ~ArrayWrapper()
            {
                delete [] _p_vals;
            }
    
    private:
        int *_p_vals;
        MetaData _metadata;
    };

这样可以工作吗？看起来就应该这样实现，不是吗？在 `ArrayWrapper` 的 `move constructor` 中调用 `MetaData` 的 `move constructor`，问题是不能这样执行。原因很简单，在`move constructor`中的`other`值，是一个右值引用？对于`MetaData`，它是一个左值，因此调用`copy constructor`而不是`move constructor`。可以这样去理解，右值是一个即将消失的对象，存活时间有限。我们向`move constructor`中传入一个临时对象，它就有个一个新的作用域，在上下文中右值表达式会被评估，临时对象干完它所做的事情，之后就不存在了。但是在我们的构造中，对象有了一个名字，它可以存活到我们整个函数的作用域，换句话说，我们在函数中使用了临时变量不止一次，这种情况下，临时对象会被定义在本地函数中。实际上，它已经上是本地函数中的一个左值，我们可以使用它的本地地址，和正常的变量一样使用。其实，我们在另外一个函数中使用到了它。如果`MetaData`中我们调用了`move constructor`而不是`copy constructor`，我们直接`move`对象，这样就危险了。

    // move constructor
    ArrayWrapper(ArrayWrapper && other)
    :_p_vals(other._p_vals)
        , _metadata(other._metadata)
    {
        // if _metadata(other._metadata) calls the move constructor, using
        // other._meta here would be extremely dangerous!
        other._p_vals = NULL;
    }

总结：左值和右值引用是左值表达式。不同之处在于左值引用一个左值的常量引用，而右值只是一个右值的引用。有点像指针和它所指对象的区别。指向的是右值，但是，我们用右值自身的时候，它就是一个左值。

ps: 这段的翻译实在是有些揪心，我自己都看不下去了。针对这个问题，我的理解是：“右值生命周期很短，并且对于一个右值我们只能使用一次，如果使用了多次，会拷贝生成一个本地对象，也就是我们实际用的不再是临时对象了。这个时候我们使用的是本地对象，和临时对象扯不上什么关系了，所以调用的是 copy constructor 而不是 move constructor”。可能作者理解的更深一些吧，把我看的都有些凌乱了。

#### std::move ####

解决上面问题的办法就是使用 `std::move`，在 `<utility>` 中，`std::move` 是这样解释的：`ok, honest to God I know I have an lvalue, but I want it to be an rvalue.`，`std::move` 本身没有做任何移动的操作；它只是把一个左值转换成右值，因此，你可以在我们的 `move constructor` 中调用它来实现转换。我们代码可能会这样去实现：

    #include <utility> // for std::move |  ps: 实际上，我没有添加这个头文件上也可以使用 std::move
    
    ArrayWrapper(ArrayWrapper&& other)
        :_p_vals(other._p_vals)
        , _metadata(std::move(other._metadata))
    {
        other._p_vals = NULL;
    }

当然，我们也应该回到 `MetaData` 把它补充完整：

    MetaData(MetaData&& other)
        :_name(std::move(other._name)) // oh, blissful efficiency
         : _size(other._size)
    {}

#### Move 赋值运算符 ####

我们也应该在 `move assignment operator` 中使用相同的方法来实现 `move construcotr`。

#### Move构造函数和隐式生成的构造函数 ####

我们知道，在C++中，我们声明任何一种构造函数的时候，编译器就不再给你声明默认的构造函数了。这这儿也是这样的，添加一个 `move constructor` 之后，需要你自己声明和定义自己的默认构造函数。

#### std::move 的工作机制 ####

你可能想过，怎么样去写一个像 `std::move` 这样的函数呢？你怎么才能实现把左值引用转换成右值引用呢？可能你已经想到了，是[类型转换](http://www.cprogramming.com/tutorial/lesson11.html)。`std::move`做了很多的调用操作，但是它的核心操作仅仅是使用 static\_cast 转换成右值引用。也就是说，实际上你不需要使用 `move` —— 你还是要用的，尽管这里面的操作很清晰。事实是这个转换是必要的，这是一个好的习惯！意味着你的转换不会出问题，如果用 static\_cast 替代 move 是非常危险的。你应该尽可能的使用 std::move 去把一个左值转换成右值，确保右值永远不会绑定到自己的左值上。

### 显式的返回一个右值引用 ###

任何时候你都应该写返回显式右值引用的函数吗？任何时候返回一个右值引用是什么意思？函数返回的对象不已经是右值了吗？

先回答第二个问题：返回一个显式的右值引用不同于返回一个对象的值。看下面的例子：

    int x;
    
    int getInt()
    {
        return x;
    }
    
    int && getRvalueInt()
    {
        // notice that it's fine to move a primitive type--remember, std::move is just a cast
        return std::move(x);
    }

第一种情况很清晰，`getInt()` 是一个右值， 是 x 的副本。通过写一些帮助函数，让我们看清这一点:

    void printAddress(const int & v)
    {
        cout << reinterpret_cast<const void*>(&v) << endl;
    }
    
v    printAddress(getInt());
    printAddress(x);

当你运行这段代码的时候，你会发现打印了两个不同的值。

换个方式：

    printAddress(getRValueInt());
    printAddress(x);

打印出相同的值，因为我们返回的是一个显示的右值。

因此返回一个右值引用和不返回右值引用是不同的，这个不同在你返回一个已经存在对象，而不是临时对象的时候表现的非常明显。

现在回到是否必要去做的问题上。答案是，很多情况下不用(probably not)。大多数情况下，它有点像悬挂引用(引用存在，但是临时对象要被析构)。返回左值引用非常危险，可能对象出了作用域就不再存在了。右值引用不能保持一个对象一直存活着。` Returning an rvalue reference would primarily make sense in very rare cases where you have a member function and need to return the result of calling std::move on a field of the class from that function--and how often are you going to do that?`

### Move语义和标准库 ###

回到最原始的例子上——我们使用`vector`，我们没有控制 `vector` 类是否有 `move constructor` 或者 `move assignment operator`。幸运的是，标准委员会很明智，move 语义已经被添加到标准库中。也就意味着你现在可以高效的返回 `vectors`, `maps`, `strings`和其他标准库中的对象，好好享受 move 语义吧。

### STL容器移动 ###

实际上，标准库跟近了一步，如果在你自己实现的类中实现 move 语义，当你使用这些类对象的STL容器的时候，STL会自动使用 `std::move`，自动选择最有利的 `move-enable` 类和高效的复制操作。

## 扩展资料 ##

+ [C/C++中的左值](http://www.caole.net/diary/lvalue.html)
+ [L-Value and R-Value Expressions](http://msdn.microsoft.com/en-us/library/bkbs2cds.aspx)
+ [C++11 FAQ中文版：右值引用](http://www.chenlq.net/books/cpp11-faq/c-0-x-faq-chinese-version-an-an-rvalue-references.html)
+ [Move semantics and rvalue references in C++11](http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html)
+ [typecasting](http://www.cprogramming.com/tutorial/lesson11.html)
+ [static_cast](http://www.cprogramming.com/reference/typecasting/staticcast.html)
