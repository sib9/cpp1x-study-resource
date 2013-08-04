C++03 中 `sizeof` 可以用与获取类型和对象的大小。但是不可以这么用：

    struct SomeType {
        OtherType member;
    };
    
    sizeof(SomeType::member); // // Does not work with C++03. Okay with C++11

这样可以得到 OtherType 的大小，C++03 不能这么做，会产生一个编译错误。C++11 可以这么用，也允许和 C++11 新添加的 alighof 操作符一起用。
