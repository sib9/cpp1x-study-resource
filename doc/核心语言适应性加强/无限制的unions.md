译自：[Unrestricted unions](https://en.wikipedia.org/wiki/C%2B%2B11#Right_angle_bracket)

在 C++03 中 union 的成员不能是一个对象类型。例如， unions 不能包含任何定义了一个 non-trivial 的构造函数。C++11 解除了一些限制：

+ Unions 可以包含有 non-trivial 对象的成员；
+ 如果这样的话，编译器不再提供隐式的构造函数，需要自己去定义.

下面是一个简单的 C++11 unions 定义：



### 扩展资料 ###

+ [Unrestricted unions](https://en.wikipedia.org/wiki/C%2B%2B11#Right_angle_bracket)
+ [What is a non-trivial constructor in C++?](http://stackoverflow.com/questions/3899223/what-is-a-non-trivial-constructor-in-c)

