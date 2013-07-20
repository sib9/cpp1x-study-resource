#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<std::string> str_array;
    str_array.push_back("Make");
    str_array.push_back("one");
    str_array.push_back("program");
    str_array.push_back("do");
    str_array.push_back("one");
    str_array.push_back("thing");
    str_array.push_back("well");

    // C++03
    for (std::vector<std::string>::const_iterator ite = str_array.begin();
             ite != str_array.end(); ++ite) {
        std::cout << *ite << " " ;
    }
    std::cout<< std::endl;
    
    // C++11
    for (auto ite = str_array.begin(); ite != str_array.end(); ++ite) {
        std::cout << *ite << " ";
    }
    std::cout << std::endl;


    const std::vector<int> v(1);
    auto a = v[0];        // a has type int
    decltype(v[1]) b = 1; // b has type const int&, the return type of
                          //   std::vector<int>::operator[](size_type) const
    auto c = 0;           // c has type int
    auto d = c;           // d has type int
    decltype(c) e;        // e has type int, the type of the entity named by c
    decltype((c)) f = c;  // f has type int&, because (c) is an lvalue
    decltype(0) g;        // g has type int, because 0 is an rvalue

    return 0;
}
