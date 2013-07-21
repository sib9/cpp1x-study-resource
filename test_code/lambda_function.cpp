#include <iostream>
#include <vector>
#include <algorithm>

double eval(std::function<double(double)> f, double x = 2.0) {
    return f(x);
}

int main(int argc, char *argv[])
{
    {
        std::vector<int> some_list{1, 2, 3, 4, 5};
        int total = 0;
        std::for_each(begin(some_list), end(some_list), [&total](int x) {
                total += x;
            });
        std::cout << total << std::endl;
    }

    {
        std::vector<int> some_list{1, 2, 3, 4, 5};
        int total = 0;
        int value = 4;
        std::for_each(begin(some_list), end(some_list), [&total, value](int x) {
                total += (x + value);
                //value += 1; // compile error: assignment of read-only varriable ...
            });
        std::cout << total << std::endl;
        std::cout << value << std::endl;
    }

    {
        std::vector<int> some_list{1, 2, 3, 4, 5};
        int total = 0;
        int value = 4;
        std::for_each(begin(some_list), end(some_list), [&](int x) {
                total += (x + value);
                value += 1; // compile error: assignment of read-only varriable ...
            });
        std::cout << total << std::endl;
        std::cout << value << std::endl;
    }

    {
        std::function<double(double)> f0 = [](double x) { return 1;};
        auto                          f1 = [](double x) { return x; };
        decltype(f0)                  fa[3] = {f0,f1,[](double x){return x*x;}};

        std::vector<decltype(f0)>     fv    = {f0,f1};
        fv.push_back                  ([](double x){return x*x;});

        for(int i=0;i<fv.size();i++)
            std::cout << fv[i](2.0) << "\n";
        for(int i=0;i<3;i++)
            std::cout << fa[i](2.0) << "\n";
        for(auto &f : fv)
            std::cout << f(2.0) << "\n";
        for(auto &f : fa)
            std::cout << f(2.0) << "\n";

        
        std::cout << eval(f0) << "\n";
        std::cout << eval(f1) << "\n";
        std::cout << eval([](double x){return x*x;}) << "\n";
    }
    return 0;
}
