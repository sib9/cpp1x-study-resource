---
layout : post
title : "Lambda 函数和表达式"
category : "Document"
---

C++11 支持匿名函数，文档中称为 `Lambda函数`，lambda 表达式格式如下：

    [capture](parameters)->return-type{body}

如果 `parameters`没有值的话，括号可以省略。如果 `body` 只有一个返回状态或者返回值为 void ，`return-type` 也经常被省略掉。如下：

    [capture](parameters){body}

一些 lambda 函数举例：

    [](int x, int y) { return x + y; } // implicit return type from 'return' statement
    [](int& x) { ++x; }   // no return statement -> lambda function's return type is 'void'
    []() { ++global_x; }  // no parameters, just accessing a global variable
    []{ ++global_x; }     // the same, so () can be omitted

`return-type` 不指定类型的时候，C++11 使用 decltype 来解析返回值类型(比如 `decltype(x+y)`)。

返回类型可以显式的用如下的方式指定：

    [](int x, int y) -> int { int z = x + y; return z; }

lambda 函数可以使用 lambda 函数外面的标志符。这些变量的集合通常被成为[闭包](https://en.wikipedia.org/wiki/Closure_(computer_science)#Function_objects_.28C.2B.2B.29)，闭包在 lambda 表达式的 `[]` 中定义，允许是值或者引用。如下所示：

    []        //no variables defined. Attempting to use any external variables in the lambda is an error.
    [x, &y]   //x is captured by value, y is captured by reference
    [&]       //any external variable is implicitly captured by reference if used
    [=]       //any external variable is implicitly captured by value if used
    [&, x]    //x is explicitly captured by value. Other variables will be captured by reference
    [=, &z]   //z is explicitly captured by reference. Other variables will be captured by value

下面的两个例子演示了 lambda 表达式的用法：

    std::vector<int> some_list{ 1, 2, 3, 4, 5 };
    int total = 0;
    std::for_each(begin(some_list), end(some_list), [&total](int x) {
      total += x;
    });

计算 `some_list` 的加和，存储到 `total` 中(引用传递)。

    std::vector<int> some_list{ 1, 2, 3, 4, 5 };
    int total = 0;
    int value = 5;
    std::for_each(begin(some_list), end(some_list), [&, value, this](int x) {
      total += x * value * this->some_func();
    });

除 value 和 this 外，引用传递。计算得到 total 的值。只能抓取闭包中的非静态函数，lambda 和创建它的时候具有相同的存取权限,不管是否 protected/private 成员。

一旦抓取到了，不管是隐式的还是显式(的调用)，闭包中类的成员范围是可测的(If this is captured, either explicitly or implicitly, then the scope of the enclosed class members is also tested.)。使用成员的时候不再需要显式的 `this->`语法。

如果闭包中引用的局部变量，它创建的更内层块引用之后调用，行为是未定义的。(If a closure object containing references to local variables is invoked after the innermost block scope of its creation, the behaviour is undefined.)

lambda 函数是实现依赖于类型的函数对象(function object)；类型的名字只有编译器可用。如果用户向把 lambda 函数作为参数来用的话，类型必须是一个模板类型，或者他们必须创建一个 `std::function` 或者一个相似的对象去抓取 lambda 值。 auto 关键可以用来存储 lambda 函数。

    auto my_lambda_func = [&](int x) { /*...*/ };
    auto my_onheap_lambda_func = new auto([=](int x) { /*...*/ });

下面的例子存储匿名函数在变量、vectors，和 arrays 中，然后把他们的名字当参数传递使用：

    #include<functional>
    #include<vector>
    #include<iostream>
    double eval(std::function<double(double)> f, double x = 2.0){return f(x);}
    int main(){
       std::function<double(double)> f0    = [](double x){return 1;};
       auto                          f1    = [](double x){return x;};
       decltype(f0)                  fa[3] = {f0,f1,[](double x){return x*x;}};
       std::vector<decltype(f0)>     fv    = {f0,f1};
       fv.push_back                  ([](double x){return x*x;});
       for(int i=0;i<fv.size();i++)  std::cout << fv[i](2.0) << "\n";
       for(int i=0;i<3;i++)          std::cout << fa[i](2.0) << "\n";
       for(auto &f : fv)             std::cout << f(2.0) << "\n";
       for(auto &f : fa)             std::cout << f(2.0) << "\n";
       std::cout << eval(f0) << "\n";
       std::cout << eval(f1) << "\n";
       std::cout << eval([](double x){return x*x;}) << "\n";
       return 0;
    }

lambda 如果 `[]` 为空的话，可以隐式转换成一个函数指针和对应的函数指针相同，所以下面是合法的：

    auto a_lambda_func = [](int x) { /*...*/ };
    void(*func_ptr)(int) = a_lambda_func;
    func_ptr(4); //calls the lambda.

## 参考资料 ##

+ [匿名对象 C++](https://en.wikipedia.org/wiki/Anonymous_function#C.2B.2B)
+ [Function objects (C++)](https://en.wikipedia.org/wiki/Closure_(computer_science#Function_objects_.28C.2B.2B.29)
