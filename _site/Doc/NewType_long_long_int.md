# long long int 类型 #

在 C++03 中提供的最大整型类型是 `long int`，它保证大小至少要等于 `int` 的位数。这样导致了 `long int` 一些编译器上大小为 64-bit， 一些为 32-bit。C++11添加一个新的类型 `long long int`，它保证最小要和`long int`一样大，且不能小于 64-bit 。这个类型一开始在 C99 和标准 C 中被引入，很多 C++ 编译器之前已经作为一种扩展来支持它。

## 参考资料 ##

+ [Type long long int](https://en.wikipedia.org/wiki/C%2B%2B11#Type_long_long_int)


