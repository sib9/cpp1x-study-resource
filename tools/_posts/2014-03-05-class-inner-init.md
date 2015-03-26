---
layout : post
title : "类内部初始化"
category : "Language"
---

## 类内部初始化 ##
  c++11中能像c#/java一样在成员变量声明的同时初始化，可通过赋值初始化，也可通过列表初始化，见如下代码：
  
    #include <iostream>
    using namespace std;

    struct foo_data
    {
    public:
	    foo_data() : val('b'){}

	    char val = 'a';
	    char val2{'x'};
    };

    int main(int argc,char* argv[])
    {
	    foo_data data;
	    cout<<data.val<<endl;
	    return 0;
    }
