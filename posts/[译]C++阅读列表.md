cpp-reading-list|Book Recommend|2013-12-15

原文链接: [C++ Reading List](http://www.drdobbs.com/cpp/c-reading-list/240155654?pgno=1)


## 1. [C++ Programming Language, 4th Edition](http://www.amazon.com/dp/0321563840) ##

![C++ Programming Language](http://image.cpp1x.org/CPP_Programming_Languages_01_full.jpg)

作者: [Bjarne Stroustrup](http://www.stroustrup.com/)

这本书堪称C++语言的“圣经”，表达了语言本身以及它的特性，由 C++ 之父 Stroustrup 完成。很多读者可能把 ANSI C++ 文档作为更权威的信息来源，但是它只是对于已经了解这门语言的人一个简洁的参考资源。这本书恰好相反，友好的(详尽的)解释了新特性，以及一些使用建议和应该避免的做法，让读者让容易理解一些特性。就此而言，这本书可以作为一本参考教程。

这本书没有使用等宽字体，垂直不对齐影响了美观。尽管如此，代码排版比以前的版本好多了。第二个问题是这本书没有完全的涵盖 C++ 语言，第 4 版有 1328 页,原版大约 1000 页。Stroustrup 多介绍了一些库，这些数字表明 C++ 变得更加的复杂。These concerns notwithstanding, I don't see how serious C++ programmers looking to use the new features of the language can proceed without this work.

极力推荐这本书！

## 2. [C++ Primer, 5th Edition](http://www.amazon.com/Primer-5th-Edition-Stanley-Lippman/product-reviews/0321714113) ##

![C++ Primer, 5th Edition](http://image.cpp1x.org/CPP_Primer_02_full.jpg)

作者: tanley Lippman, Josée Lajoie, Barbara Moo

多年以来，C++ Primer 都被作为 C++ 指定教程来，第五版使用 C++11 全部重写，900 页密集的页面描述了 C++ 语言的方方面面。这还是保守说法，它的内容已经远远的超过 primer 这个词可以表达的范畴。没有一节告诉你可以“快速的学习这门语言”，而且坚持不懈的用文字覆盖了语言的每一个方面和 C++ 程序员可能会遇到的问题。有没有怀疑过假如我们让析构函数作为 C++11 中提到的"deleted function"会怎么样呢? 我想过！这本书详细的回答了这个问题。

这本书只覆盖语言本身，通过讨论库和在附录中介绍了库中的头文件和算法的梗概(如果想详细的了解C++库的话，我建议看 the C++ Standard Library: A Tutorial and Reference，也就是我们下一个讨论的话题)。对比这两本书，Stroustrup 的 C++ Programming Language, 4th Ed. 是这本书的竞争对手，Stroustrup 的书主要是一个参考手册，反之，这本书更偏向应用。讨论内容形如如果你错误的使用特性会导致那些问题，包括了更多的代码，相比而言，比 Stroustrup 的书有更多的指导性。

我怀疑这本书早期是为了有语言基础的人写的。我不建议把这本书作为入门级书籍(学生或者第一次接触这门语言的人)。但是对于 C++ 开发人员，想去使用 C++11 新特性的人来说的话，这本书是绝佳选择。

## 3. [The C++ Standard Library, 2nd Edition](http://www.amazon.com/dp/0321623215) ##

![The C++ Standard Library, 2nd Edition](http://image.cpp1x.org/CPP_StandardLibrary_03_full.jpg)

作者: Nicolai Josuttis

这是 C++ 标准库经典的教程和参考手册第二版，专门为了C++11而作。不像许多书籍一样覆盖所有的库和API，它不是以解释如何进行函数调用而出名的。它把标准库(大部分STL)划分成子块，然后解释基本组件的设计。只详细讲解了一部分API，最后对其他的API进行概述。章节中会解释设计思想、内部实现、应用以及对不同的选择进行对比。

那些讨论有说服力、清晰而且非常丰富。例如，在 STL 函数对象和 lambda 用 12 页仅仅解释函数对象是什么和为什么你要用它们。之后作者又解释了预定义函数对象(用另外的12页)。这些都为后面的讨论奠定了基础: lambda 之旅。因此，它的所有讲解超过了1000页。有些解释也非常的精简，完整的代码强调关键的部分，你可以看到精确的看到一个函数怎样使用或者如何实现的。

这本书的第一版被很多C++程序员当成经典，第二版作为第一版的升级版，必定延续经典，推荐给你们。


## 4. [C++ Concurrency in Action](http://www.amazon.com/dp/1933988770) ##

![C++ Concurrency in Action](http://image.cpp1x.org/CPP_ConcurrencyInAction_04_full.jpg)

作者: Anthony Williams

This book is a deep dive into concurrency using C++11 features. It's written by the primary developer and maintainer of the Boost Thread library, which is the basis for much of the language's new threading support. In sum, it's written by a highly qualified author.

It starts off with the basics, assuming the reader has good (even very good) command of the language, but is new to writing parallel code. It steps through the problems posed by concurrency, the solutions and limitations of mutual exclusion, and how they're implemented in C++11. It then moves through the C++ memory model and atomic types. Finally, it digs into the design of lock-based and lock-free data structures. It's the best treatment I've seen of these topics since Herb Sutter discussed them in our pages.

The book thoughtfully covers topics of real importance that are frequently overlooked in other treatments; namely, designing code for multithreading and debugging threaded applications. Of these, both treatments are too short in my view. A large part of the book is reference material (almost 130 pages on the C++ threading library alone). And another appendix is a full message-framework all laid out in code with explanations throughout. There's no doubt the author has done his homework.

 I have a few small complaints, but they are truly small. The first is that you must have in-depth knowledge of C++, good-enough-to-skate-by won't be enough for this book. Second, the author consigns thread pools to the final chapters under the rubric of "Advanced Threading." In my opinion, pools mark the point at which concurrency gets really interesting; but here, it's where the author stops. Predictably, given this orientation, he does not ever address the Actor model, which gets a single passing mention in the index. It's as if this approach did not exist at all, even though it's integral to several languages — just not, in Williams' view, C++.

Overall, these complaints reflect my preferences, rather than any flaws that invalidate the book. Williams' work is an excellent treatment and likely to be the defining title in this area for a long time to come.  

If you want a closer look at content from this book, we recently published an excerpt from it, in a popular article: "Waiting for One-Off Events with Futures."

## 5.[Secure Coding in C and C++, 2nd Edition](http://www.amazon.com/Secure-Coding-2nd-Software-Engineering/dp/0321822137)##

![Secure Coding in C and C++, 2nd Edition](http://image.cpp1x.org/Secure_Code_CPP_05_full.jpg)

作者:  Robert Seacord

This is the definitive work on writing secure code in C/C++. This new edition, which nearly doubles the size of the original 2005 work, illustrates how much we've learned in the interim about attacks on code. In fact, in reading through this book, one feels almost overwhelmed by the variety and imagination of attacks today. However, as the author capably explains, security is more than just the implementation of counter-techniques, but  weaves security throughout the implementation. Only through such a consistent mindset, he argues, can the damage wrought by future attack methods be contained.

The book details numerous kinds of hacks and what can be done to prevent them or make them so difficult as to discourage the hacker. The explanations are remarkably well written and the code is clear. However, it requires a more-advanced formation than most books on programming: It needs the reader to have a fairly good idea of how C and C++ programs execute and what is happening at the machine level. Because the required information is not provided in the text, it's not possible to get the true value from the suggestions without having done this homework first.


For developers who can follow along and understand the inner workings of program execution, this book is not only an excellent guide, but a revelation. For example, Seacord's discussions of how attacks are enabled by doubly freeing an allocated chunk of memory highlights a feature of this simple coding error that might be completely overlooked if you were not a security expert. The explanation is illuminating.

The hands-on nature of this volume is exemplified by frequent recommendations of tools to use to verify code and lock down access mechanisms that crackers like to exploit. This is an excellent volume that will very definitely make you a more aware, and certainly better, programmer.

## 6. [Real-Time C++](http://www.amazon.com/dp/3642346871) ##

![Real-Time C++](http://image.cpp1x.org/Real_Time_CPP_06_full.jpg)

作者: Chris Kormanyos

This is a gentle introduction to using C++11 in real-time projects. The author presents several basic projects and shows how he used C++11 to code them. He starts with a product that targets an Atmel AVR microcontroller, which he programs using the GCC toolchain, explaining along the way: the design, implementation in hardware and code, and finally how to flash and execute the program. It turns on LEDs under various circumstances. He then moves on to more-ambitious projects, such as writing low-level hardware drivers in C++. In the final chapters, he examines extending the standard C++ library and the STL for embedded purposes.

The book is approachable and the code fairly clean. It shows that C++11 is a reasonable choice for embedded work. Overall, this is a good tutorial for C++ developers who want to get their feet wet in embedded programming, but due to the choice of sample projects, it probably won't appeal to programmers already active in that line of work.

笔者注:

只翻译了前三本书的简介，后面的没有翻译。笔者对并发、安全、Real-Time了解不多，不敢随便翻译(了解相关技术的同学，可以帮忙翻译)。说一下自己的看法：

> C++ Programming Language 和 C++ Primer 这两本书选一本看就行了，对于入门，我推荐前者。有C++基础，我推荐后者。我和这篇文章作者的观点相同，C++ Primer 真的不适合作为入门书籍，门槛高，让人望而却步。
> 
> The C++ Standard Library 这本书看过人的都知道，是非常好的一本工具书籍，目前第二版没有中文版。
> 后面这三本书不适合初学者，看了简介以后，个人最想看 C++ Concurrency in Action。
> 
> C++11 增加了很多新的特性和标准库，但是不用看太多的书籍。仅 C++ Primer, 5th Edition 和 The C++ Standard Library, 2nd Edition 这两本书足够。
> 
> C++ 的最大问题在于它的繁杂，给程序员很多奇淫的机会，其实这本身对学 C++ 的人没有太多的好处。语言毕竟最终都是要面向应用的，执迷于技巧容易本末倒置，忽略了真正关注的东西。把 C++ 当成工具对待(从这个角度看C++11，它的确比以前强大了太多)。

_这篇文章原本是答应 [博乐在线](http://blog.jobbole.com/) 要翻译的，结果因为当时没时间就没有翻译。昨天翻译才发现自己确实没有能力全部翻译，就成了现在的半成品，也就不再投稿给 博乐在线 了，抱歉。_