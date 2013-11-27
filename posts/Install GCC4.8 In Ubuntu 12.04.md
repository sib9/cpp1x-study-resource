Install-GCC4.8-Ubuntu|Compiler|2013-07-13

## 安装 ##

    sudo add-apt-repository ppa:ubuntu-toolchain-r/test
    sudo apt-get update
    sudo apt-get install gcc-4.8
    sudo apt-get install g++-4.8

## 测试 ##

方法一:

    gcc-4.8 -v
    g++-4.8 -v

如果安装成功应输出为：gcc version 4.8.1 (Ubuntu 4.8.1-2ubuntu1~12.04) 

方法二：

    ls /usr/bin/gcc* -l
    ls /usr/bin/g++* -l

我的输出结果为：

    -rwxr-xr-x 1 root root 306200  4月 15 08:27 /usr/bin/gcc-4.6
    -rwxr-xr-x 1 root root 527596  4月 22 04:47 /usr/bin/gcc-4.7
    -rwxr-xr-x 1 root root 716296  6月  5 22:00 /usr/bin/gcc-4.8
    -rwxr-xr-x 1 root root  21988  4月 22 04:47 /usr/bin/gcc-ar-4.7
    -rwxr-xr-x 1 root root  22000  6月  5 22:00 /usr/bin/gcc-ar-4.8
    -rwxr-xr-x 1 root root  21988  4月 22 04:47 /usr/bin/gcc-nm-4.7
    -rwxr-xr-x 1 root root  22000  6月  5 22:00 /usr/bin/gcc-nm-4.8
    -rwxr-xr-x 1 root root  21988  4月 22 04:47 /usr/bin/gcc-ranlib-4.7
    -rwxr-xr-x 1 root root  22000  6月  5 22:00 /usr/bin/gcc-ranlib-4.8

Ubuntu 默认 GCC 版本是4.6，我之前曾经装过 4.7，现在装了 4.8，所以你可以看到三个版本。

## 将 4.8 设为默认 GCC 版本 ##

为了修改默认 GCC 版本，我们需要修改软链接。当然，你也可以不修改，只不过每次使用的时候都需要 gcc-4.8/g++-4.8 带上版本，不方便。

    sudo rm /usr/bin/gcc
    sudo ln -s /usr/bin/gcc-4.8 /usr/bin/gcc
    sudo rm /usr/bin/g++
    sudo ln -s /usr/bin/g++-4.8 /usr/bin/g++

然后， gcc -v 提示的 GCC 版本就是 4.8.1，非常 Happy。

## 测试 Demo ##

安装了可能感觉不够爽，是时候用 gcc4.8 编一把 C++11 了，才不枉废了半天劲。我找了一个简单的 demo :

    // Ubuntu 12.04 GCC4.8
    
    #include <iostream>
    #include <algorithm>
    
    int main()
    {
        char s[] = "Hello CPP11 World!";
        int Uppercase = 0;
    
        std::for_each(s, s+sizeof(s), [&Uppercase] (char c)
                 {
                     if (isupper(c))
                         Uppercase++;
                 });
    
        std::cout << Uppercase << " uppercase letters in: " << s << std::endl;
    
        return 0;
    }

注意：编译的时候加上`-std=c++11`(不加编译器也会很友善的提醒你，^_^)；

## 参考资料 ##

+ [Ubuntu12.04安装GCC4.7并设置C++11](http://maykiller.com/2012/ubuntu-install-gcc-4-7-with-set-default/1/)，非常感谢这位博主，在我多方尝试后这是一个有效且简单的做法。
+ 测试Demo来自:[C++11 中值得关注的极大变化(详解)](http://coolshell.cn/articles/5265.html)
