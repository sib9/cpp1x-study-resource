#include <iostream>
#include <stdexcept>

constexpr int multiply(int x, int y)
{
    return x * y;
}

constexpr int get_default_array_size(int multiplier)
{
    return 10 * multiplier;
}

class circle
{
public:
    constexpr circle(int x, int y, int radius)
        : _x(x), _y(y), _radius(radius) 
        {}
    constexpr double get_area() const
        {
            return _radius * _radius * 3.1415926;
        }
    
private:
    int _x;
    int _y;
    int _radius;
};

constexpr int factorial(int n)
{
    return n <= 1 ? 1 : (n * factorial(n-1));
}

// literal class
class conststr
{
public:
    template<std::size_t N>
    constexpr conststr(const char(&a)[N]) 
        : p(a), sz(N-1)
        {}
    // constexpr functions signal errors by throwing exceptions from operator ?:
    constexpr char operator[](std::size_t n) const 
        {
            return n < sz ? p[n] : throw std::out_of_range("");
        }
    constexpr std::size_t size() const 
        {
            return sz;
        }
    
private:
    const char * p;
    std::size_t sz;
};

constexpr std::size_t countlower(conststr s , std::size_t n = 0,
                                 std::size_t c = 0)
{
    return n == s.size() ? c : (s[n] >= 'a' && s[n] <= 'z' ? countlower(s, n+1, c+1):countlower(s, n+1, c));
}

// output function that requires a compile-time constant, for testing
template<int n>
struct constN
{
    constN() 
        {
            std::cout << n << '\n';
        }
    
};

int main(int argc, char *argv[])
{
    const int val = multiply(10, 10);
    std::cout << val << std::endl;

    int my_array[get_default_array_size(3)];

    std::cout << "4! = ";
    constN<factorial(4)> out1;

    volatile int k = 8;
    std::cout << k << " != " << factorial(k) << '\n';

    std::cout << "Number of lowercase letters in \"hello, world!\" is ";
    constN<countlower("Hello, world!")> out2;
    
    return 0;
}
