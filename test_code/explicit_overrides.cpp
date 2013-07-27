#include <iostream>

struct Base {
    virtual void some_func(float a)
        {
            std::cout << "Base: " << a << std::endl;
        }
};

struct Derived : Base {
    virtual void some_func(int a)
        {
            std::cout << "Derived : "  << a << std::endl;
        }
};

// compiler: error: 'virtual void NewDerived::some_func(int)' marked override, but does not override. 
// struct NewBase {
//     virtual void some_func(float a)
//         {
//             std::cout << "NewBase: " << a << std::endl;
//         }
// };

// struct NewDerived : NewBase {
//     virtual void some_func(int a) override  // ill-formed - doesn't override a base class method
//         {
//             std::cout << "NewDerived: " << a << std::endl;
//         }
// };


// struct Base1 final{};

// struct Derived : Base final {};  // ill-formed because the class Base1 has been marked final

// struct Base2 {
//     virtual void f() final;
// };

// struct Derived2 : Base2 {
//     virtual void f(); // ill-formed because the class Base1 has been marked final
// };

int main(int argc, char *argv[])
{
    {
        Base* p = new Derived();
        p->some_func(0.0);
        Derived d;
        d.some_func(0);
    }

    // {
    //     NewBase * p = new NewDerived();
    //     p->some_func(1.0);
    // }
    return 0;
}
