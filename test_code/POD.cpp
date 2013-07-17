#include <iostream>

struct X
{
    int i1;
    int i2;
};

struct Y
{
    char c;
    X x;
    int i[2];
    float f;
    
protected:
    static double d;
    
private:
    void g() 
        {}
};

struct POD
{
    int x;
    int y;
    void f() 
        {}
    static std::vector<char> v; // static members do not matter
};

struct AggrateButNotPOD1
{
    int x;
    ~AggregateButNotPOD1() // user-defined destrcutor
        {}
};

struct AggrateButNotPOD2
{
    AggrateButNotPOD1 arrOfNonPod[3]; // array of non-POD class
};



int main(int argc, char *argv[])
{
    Y y = {'a', {10, 20}, {20, 30} };

    std::cout << y.c << ", "
              << y.x.i1 << ", "
              << y.x.i2 << ", "
              << y.i[0] << ", "
              << y.i[1] << ", "
              << y.f << std::endl;
    
    
    return 0;
}
