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
