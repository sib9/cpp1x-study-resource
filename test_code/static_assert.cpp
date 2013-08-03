#include <iostream>

template <class T>
struct Check {
    static_assert(sizeof(int) <= sizeof(T), "T is too big enough!");
};

template <class Integral>
Integral foo(Integral x, Integral y) {
    static_assert(std::is_integral<Integral>::value,
                  "foo() parameter must be an integral type");
}


int main(int argc, char *argv[])
{

    const float PI = 6;
    static_assert((PI > 3.14) && (PI < 3.15), "PI is inaccurate");

    Check<char> c;
    
    return 0;
}
