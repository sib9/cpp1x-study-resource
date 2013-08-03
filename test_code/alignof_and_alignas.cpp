#include <iostream>
#include <vector>

struct test_align {
    int i;
    char c;
    float f;
    double d;
    long int li;
};

struct float_align {
    float f1;
    float f2;
};

struct char_align {
    char c1;
    char c2;
};

struct double_align {
    double d1;
    double d2;
};

struct short_int_align {
    short int si1;
    short int si2;
};

struct long_long_ing_align {
    long long int lli1;
    long long int lli2;
};

struct alignas(8) test_alignas {
    int i;
    char c;
    float f;
    double d;
    long int li;
};

int main(int argc, char *argv[])
{
    std::cout << sizeof(int) + sizeof(char) + sizeof(float)
        + sizeof(double) + sizeof(long int)  << std::endl;
    std::cout << sizeof(test_align) << std::endl;
    std::cout << alignof(test_align) << std::endl;

    std::cout << alignof(std::vector<int>) << std::endl;

    std::cout << alignof(float_align) << std::endl;

    std::cout << alignof(char_align) << std::endl;

    std::cout << alignof(double_align) << std::endl;

    std::cout << alignof(short_int_align) << std::endl;

    std::cout << alignof(long_long_ing_align) << std::endl;

    std::cout << sizeof(test_alignas) << std::endl;
    std::cout << alignof(test_alignas) << std::endl;

    return 0;
}
