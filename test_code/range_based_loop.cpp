#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    for (int i : v) {
        std::cout << i << " " ;
    }
    std::cout << std::endl;

    for (auto ite : v) {
        std::cout << ite << " ";
    }
    std::cout << std::endl;

    
    for (int& i : v) {
        ++i;
    }


    for (auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
