#include <new>
#include <iostream>

struct Point {
    Point() {}
    Point(int x, int y) : x_(x), y_(y) {}
    int x_, y_;
};

union U {
    int z;
    double w;
    Point p;  // Illegal in C++03; legal in C++11
    U() {
        new (&p) Point(); // Due to the Point member, a constructor definition is now required.
    }
};

int main(int argc, char *argv[])
{
    U u;
    u.p = Point(1, 2);

    std::cout << u.z << std::endl;
    std::cout << u.w << std::endl;

    std::cout << u.p.x_ << std::endl;
    std::cout << u.p.y_ << std::endl;
    return 0;
}
