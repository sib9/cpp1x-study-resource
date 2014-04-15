## 增强的sizeof ##

  在c++98/03中无法对类内部成员变量使用sizeof运算符，及时能用，也是通过比较hack的方式进行。而在C++11中，你可以对类内部的成员变量进行sizeof操作，见如下代码：
  
    #include <iostream>
    #include <algorithm>
    using namespace std;

    struct foo_data
    {
    public:
	    foo_data(const char _val) : val(_val){}
    public:
	    char val = 'a';
    };

    int main(int argc,char* argv[])
    {
	    cout<<"sizeof foo_data::val is "<<sizeof(foo_data::val)<<endl;
	    return 0;
    }
