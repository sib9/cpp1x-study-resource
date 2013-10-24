---
layout: post
title: "新的字符串常量"
category: "Document"
tags: []
---

译自： [New string literals](https://en.wikipedia.org/wiki/C%2B%2B11#New_string_literals)

C++03 提供了两种类型的字符串字面值。第一种，用两个双引号包含， 生成一个`const char`类型空终结符的(null-terminated)数组； 第二种，用 `L""` 定义的，生成`const wchar_t`的空终结符数组, `wchar_t`是一个为定义大小且语义上表示宽字符。字面量类型既不支持 UTF-8, UTF-16 也不支持 Unicode 编码。

字符类型的定义明确的表达成它至少需要存储 UTF-8 的 8-bit 编码，足够包含任何编译器基本运算的字符集。之前在 C++ 自身标准在中仅仅为字母使用，C 标准保证至少 8 位。

C++11 支持三种 Unicode 编码，即： UTF-8， UTF-16， UTF-32。除了之前的 `char` 类型外，C++11 添加了两种新的字符类型：`char_16_t`和`char32_t`，专门用来存储`UTF-16`和`UTF-32`。

先面展示了怎么为每一种编码创建字符串字面量：

    u8"I'am a UTF-8 string."
    u"This's a UTF-16 string."
    U"This's a UTF-32 string."

第一种类型是 `const char[]`, 第二种类型是 `char16_t[]`，第三种类型是`char32_t[]`。

当构造 Unicode 字符串字面量的时候，它经常直接向字符串中插入 Unicode 代码点。为了实现这一点，C++ 允许下面的代码语法：

    u8"This is Unicode Character: \u2018."
    u"This is a bigger Unicode Character: \u2018."
    U"This is Unicode Character: \U00002018."

`\u`后面是十六进制数字，不需要 `0x` 前缀。`\u` 代表 `16-bit` 代码点；可以用 `\U` 来表示 `32-bit` 代码点。必须要输入有效的 Unicode 代码点。例如，在 `U+D800~U+DFFF`中间的数字不能使用，它们是为`UTF-16`代理对预留的。

它也在避免使用转义字符串上是非常有用的，尤其是使用 XML 文件字面量，脚本语言，或者正则表达式，C++ 提供了一个原生的字符串字面量：

    R"(The String Data \ Stuff ")"
    R"delimiter(The String Data \ Stuff " )delimiter"

在第一种情况下，`"(` 和 `)"` 之间的部分是字符串。`"` 和 `\` 字符不再需要转义。在第二种情况下，以`delimiter(`开始，则只能以`)delimiter`结束。字符串 `delimiter` 可以把任何字符串在长度上改造成 16 个字符，允许用户在原生字符串字面量上使用 ")" 字符。例如，`R"delimiter((a-z))delimiter` 等价于 `(a-z)`.

原生字符串可以使用任何的宽字符常量做前缀：

    u8R"XXX(I'am a "raw UTF-8" string.)XXX"
    uR"*(This is a "raw UTF-16" string.)*"
    UR"(This is a "raw UTF-32" string.)"


## 扩展资料 ##

+ [New string literals](https://en.wikipedia.org/wiki/C%2B%2B11#New_string_literals)
