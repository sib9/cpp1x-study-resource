---
layout : post
title : "[译]C++阅读列表"
category : "Book Recommend"
---

原文链接: [C++ Reading List](http://www.drdobbs.com/cpp/c-reading-list/240155654?pgno=1)

声明: 本文处于翻译中，尚未完成，请勿挑错。

## 1. [C++ Programming Language, 4th Edition](http://www.amazon.com/dp/0321563840) ##

![C++ Programming Language](http://image.cpp1x.org/CPP_Programming_Languages_01_full.jpg)

作者: [Bjarne Stroustrup](http://www.stroustrup.com/)

这本书毫无疑问的作为C++语言的“圣经”，权威的表达了语言本身以及它的特性，由C++之父Stroustrup完成。很多读者可能把 ANSI C++ 文档作为更权威的信息来源，但是它只是对于已经了解这门语言的人一个简洁的参考资源。这本书恰好相反，友好的(详尽的)解释了新特性，以及一些使用建议和应该避免的做法，让读者让容易理解一些特性。就此而言，这本书可以作为一本参考教程。

这本书没有使用等宽字体，垂直不对齐影响了美观。尽管如此，代码排版比以前的版本。第二个问题是这本书没有完全的涵盖C++语言。第4版有1328页,原版大约1000页。Stroustrup 多介绍了一些库，这些数字表明C++变得更加的复杂。 These concerns notwithstanding, I don't see how serious C++ programmers looking to use the new features of the language can proceed without this work.

极力推荐这本书！

## 2. [C++ Primer, 5th Edition](http://www.amazon.com/Primer-5th-Edition-Stanley-Lippman/product-reviews/0321714113) ##

![C++ Primer, 5th Edition](http://image.cpp1x.org/CPP_Primer_02_full.jpg)

作者: tanley Lippman, Josée Lajoie, Barbara Moo

多年以来，C++ Primer 都是作为 C++ 指定教程来对待的，第五版使用C++11全部重写，900页密集的页面描述了C++语言的方方面面。这还是保守说法，它的内容已经远远的超过 primer 这个词可以表达的范畴。没有一节告诉你可以“快速的学习这门语言”，而且坚持不懈的用文字覆盖了语言的每一个方面和C++程序员可能会遇到的问题。有没有怀疑过假如我们让析构函数作为C++11中提到的"deleted function"会怎么样呢? 我想过！这本书详细的回答了这个问题。

这本书只覆盖语言本身，通过讨论库和在附录中介绍了库中的头文件和算法的梗概(如果想详细的了解C++库的话，我建议看 the C++ Standard Library: A Tutorial and Reference，也就是我们下一个讨论的话题)。对比这两本书，公平的说，Stroustrup 的 C++ Programming Language, 4th Ed. 是这本书的竞争对手，Stroustrup的书主要是一个参考手册，反之，这本书更实用一些。讨论的如果你错误的使用特性会导致那些问题，包括了更多的代码，相比而言，比Stroustrup的书有更多的指导性。

我怀疑这本书早期是为了有语言基础的人写的。我不建议把这本书作为入门级书籍(学生或者第一次接触这门语言的人)。但是对于C++开发人员，想去使用C++11新特性的人来说的话，这本书是绝佳选择。

## 3. [The C++ Standard Library, 2nd Edition](http://www.amazon.com/dp/0321623215) ##

![The C++ Standard Library, 2nd Edition](http://image.cpp1x.org/CPP_StandardLibrary_03_full.jpg)

作者: Nicolai Josuttis

这是C++标准库经典的教程和参考手册第二版，专门为了C++11而作的。不像许多书籍一样覆盖所有的库和API，它不是以解释如何进行函数调用而出名的。确切的说是，它把标准库(大部分STL)划分成子块，然后解释基本组件的设计。只详细讲解了一部分API，最后对其他的API进行概述。章节中会解释设计思想、内部实现、应用以及对不同的选择进行对比。

那些讨论有说服力、清晰而且非常丰富。例如，在STL函数对象和lambda用12页仅仅解释函数对象是什么和为什么你要用它们。之后作者又解释了预定义函数对象(用另外的12页)。这些都为后面的讨论奠定了基础: lambda 之旅。因此，它的所有讲解超过了1000页。有些解释也非常的精简，完整的代码强调关键的部分，你可以看到精确的看到一个函数怎样使用或者如何实现的。

这本书的第一版被很多C++程序员当成经典，第二版毫无理由也会那么经典。作为第一版的升级版，高度推荐给你们。


## 4. [C++ Concurrency in Action](http://www.amazon.com/dp/1933988770) ##

![C++ Concurrency in Action](http://image.cpp1x.org/CPP_ConcurrencyInAction_04_full.jpg)

作者: Anthony Williams

这本书深入的探讨了基于C++11新特性下的并发。是由 Boost线程库 的初级开发和维护人员写的，负责语言的线程支持的基本原理。也就是说，这是由一个非常牛掰(highly qualified)的大神写的。

它从基础讲起，假定读者有一个很好的语言基础，但是刚开始写并行代码。它逐步解释了并发带来的问题，解决方案和解释互斥的局限性，然后说明了C++11是如何实现的。C++内存模型和原子操作。最后，它深入讲解了 lock-based 和 lock-free 数据结构。 It's the best treatment I've seen of these topics since Herb Sutter [discussed](http://www.drdobbs.com/cpp/lock-free-code-a-false-sense-of-security/210600279) them in our pages.

这本书涵盖了一些非常重要的但是被经常被忽视的主题: 即，多线程和多线程调试的设计代码。这些，在我看来都太短了。这本书的一大部分是参考资源(C++线程库大约有130页的讲解)。另一个附录是完整的 message-framework 实现和注释代码。毫无疑问作者在做家庭作业。

 I have a few small complaints, but they are truly small. The first is that you must have in-depth knowledge of C++, good-enough-to-skate-by won't be enough for this book. Second, the author consigns thread pools to the final chapters under the rubric of "Advanced Threading." In my opinion, pools mark the point at which concurrency gets really interesting; but here, it's where the author stops. Predictably, given this orientation, he does not ever address the Actor model, which gets a single passing mention in the index. It's as if this approach did not exist at all, even though it's integral to several languages — just not, in Williams' view, C++. (备注: 上面这段是与并发和线程池的讨论，译者不敢乱翻译，见谅!)
 
当然，这些抱怨是我个人的一些看法，而不是这本书的缺陷。Williams的工作是一个优秀的技巧，在这个领域可能需要一段时间才能到来。
 
如果你想近距离的看这本书的内容，我们最近发布了一篇摘录: [Waiting for One-Off Events with Futures](http://www.drdobbs.com/cpp/waiting-for-one-off-events-with-futures/232700082)
 
## 5.[Secure Coding in C and C++, 2nd Edition](http://www.amazon.com/Secure-Coding-2nd-Software-Engineering/dp/0321822137)## 

![Secure Coding in C and C++, 2nd Edition](http://image.cpp1x.org/Secure_Code_CPP_05_full.jpg)

作者:  Robert Seacord

This is the definitive work on writing secure code in C/C++. This new edition, which nearly doubles the size of the original 2005 work, illustrates how much we've learned in the interim about attacks on code. In fact, in reading through this book, one feels almost overwhelmed by the variety and imagination of attacks today. However, as the author capably explains, security is more than just the implementation of counter-techniques, but a mind-set that weaves security throughout the implementation. Only through such a consistent mindset, he argues, can the damage wrought by future attack methods be contained.

The book details numerous kinds of hacks and what can be done to prevent them or make them so difficult as to discourage the hacker. The explanations are remarkably well written and the code is clear. However, it requires a more-advanced formation than most books on programming: It needs the reader to have a fairly good idea of how C and C++ programs execute and what is happening at the machine level. Because the required information is not provided in the text, it's not possible to get the true value from the suggestions without having done this homework first.

For developers who can follow along and understand the inner workings of program execution, this book is not only an excellent guide, but a revelation. For example, Seacord's discussions of how attacks are enabled by doubly freeing an allocated chunk of memory highlights a feature of this simple coding error that might be completely overlooked if you were not a security expert. The explanation is illuminating.

The hands-on nature of this volume is exemplified by frequent recommendations of tools to use to verify code and lock down access mechanisms that crackers like to exploit. This is an excellent volume that will very definitely make you a more aware, and certainly better, programmer.

## 6. [Real-Time C++](http://www.amazon.com/dp/3642346871) ##

![Real-Time C++](http://image.cpp1x.org/Real_Time_CPP_06_full.jpg)

作者: Chris Kormanyos

This is a gentle introduction to using C++11 in real-time projects. The author presents several basic projects and shows how he used C++11 to code them. He starts with a product that targets an Atmel AVR microcontroller, which he programs using the GCC toolchain, explaining along the way: the design, implementation in hardware and code, and finally how to flash and execute the program. It turns on LEDs under various circumstances. He then moves on to more-ambitious projects, such as writing low-level hardware drivers in C++. In the final chapters, he examines extending the standard C++ library and the STL for embedded purposes.

The book is approachable and the code fairly clean. It shows that C++11 is a reasonable choice for embedded work. Overall, this is a good tutorial for C++ developers who want to get their feet wet in embedded programming, but due to the choice of sample projects, it probably won't appeal to programmers already active in that line of work.