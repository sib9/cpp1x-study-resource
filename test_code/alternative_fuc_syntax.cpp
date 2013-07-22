#include <iostream>

template <typename LHS, typename RHS>
auto adding_fuc(const LHS & lhs, const RHS & rhs) -> decltype(lhs+rhs) {
    return lhs + rhs;
}

auto get_name() -> std::string {
    return "jerryzhang";
}
int main(int argc, char *argv[])
{
    int l = 1;
    float r = 1.5;
    auto result = adding_fuc(l, r);
    std::cout << result << std::endl;

    std::cout << get_name() << std::endl;
    
    return 0;
}
