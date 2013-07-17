In C++03, a class or struct must follow a number of rules in order for it to be considered a plain old data (POD) type. Types that fit this definition produce object layouts that are compatible with C, and they could also be initialized statically. The C++03 standard has restrictions on what types are compatible with C or can be statically initialized despite no technical reason a compiler couldn't accept the program; if someone were to create a C++03 POD type and add a non-virtual member function, this type would no longer be a POD type, could not be statically initialized, and would be incompatible with C despite no change to the memory layout.

C++11 relaxed several of the POD rules, by dividing the POD concept into two separate concepts: trivial and standard-layout.
A type that is trivial can be statically initialized. It also means that it is legal to copy data around via memcpy, rather than having to use a copy constructor. The lifetime of a trivial type begins when its storage is defined, not when a constructor completes.
A trivial class or struct is defined as one that:

1. Has a trivial default constructor. This may use the default constructor syntax (SomeConstructor() = default;).
2. Has trivial copy and move constructors, which may use the default syntax.
3. Has trivial copy and move assignment operators, which may use the default syntax.
4. Has a trivial destructor, which must not be virtual.

Constructors are trivial only if there are no virtual member functions of the class and no virtual base classes. Copy/move operations also require that all of the non-static data members be trivial.

A type that is standard-layout means that it orders and packs its members in a way that is compatible with C. A class or struct is standard-layout, by definition, provided:

1. It has no virtual functions
2. It has no virtual base classes
3. All its non-static data members have the same access control (public, private, protected)
4. All its non-static data members, including any in its base classes, are in the same one class in the hierarchy
5. The above rules also apply to all the base classes and to all non-static data members in the class hierarchy
6. It has no base classes of the same type as the first defined non-static data member

A class/struct/union is considered POD if it is trivial, standard-layout, and all of its non-static data members and base classes are PODs.

By separating these concepts, it becomes possible to give up one without losing the other. A class with complex move and copy constructors may not be trivial, but it could be standard-layout and thus interop with C. Similarly, a class with public and private non-static data members would not be standard-layout, but it could be trivial and thus memcpy-able.

以上摘自: wikipedia.org，也就是扩展资料中的第一条。本想翻译一把的，看了一遍感觉理解上无压力。如果我都无压力，大家的英语水平就更没有压力了。真心不推荐看中文版的wiki，感觉翻译的也太业余了，特别生硬。

测试代码在 `test_code/POD.cpp`

#### 扩展资料 ####
+ [Modification to the definition of plain old data](https://en.wikipedia.org/wiki/C%2B%2B11#Modification_to_the_definition_of_plain_old_data)
+ [翻译：怎样理解C++中的Aggregate和POD类型---An answer from stackoverflow](http://www.cnblogs.com/tingshuo/archive/2013/03/25/2981197.html)
