#include <iostream>
#include <iterator>
#include <vector>
#include <initializer_list>
#include <list>

struct object
{
    float first;
    int second;
};

template <typename T>
class my_list
{
public:
    my_list() {}

    my_list(const std::initializer_list<T> & x) {
        for (auto ite=x.begin(); ite!=x.end(); ++ite) {
            items_.push_back(*ite);
        }
    }
    void show_list() {
        copy(items_.begin(), items_.end(), std::ostream_iterator<T>(std::cout, " "));
        std::cout << std::endl;
    }
private:
    std::vector<T> items_;
};

void print_init_list(const std::initializer_list<int> x) {
    copy(x.begin(), x.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    {
        object scalar = {0.43f, 10};
        object an_array[3] = { {13.4f, 3}, {43.28f, 29}, {5.934f, 17} };

        std::cout << scalar.first << ", " << scalar.second << std::endl;
        for (int i = 0; i < 3; ++i)
        {
            std::cout << an_array[i].first << ", " << an_array[i].second << std::endl;
        }
    }

    {
        my_list<int> int_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        my_list<std::string> str_list = {"hello", "world", "C++", "11"};

        int_list.show_list();
        str_list.show_list();
    }

    {
        std::list<int> test_list = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        copy(test_list.begin(), test_list.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::vector<std::string> test_string = {"Make", "One", "Program", "Do", "One", "Thing", "Well"};
        copy(test_string.begin(), test_string.end(), std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << std::endl;
    }

    {
        print_init_list({5, 4, 3, 2, 1});
    }
    return 0;
}
