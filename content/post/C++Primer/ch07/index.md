---
title: C++ Primer Ch07
description: Class
date: 2023-12-10T14:35:42+08:00
image: assets/c++primer.jpg
math: true
toc: true
categories:
    - C++ Primer
tags:
    - CPP
    - C++ Primer
---

# 类

类的基本思想是 **数据抽象（data abstraction）** 和 **封装（encapsulation）**。数据抽象是一种依赖于 **接口（interface）** 和 **实现（implementation）** 分离的编程（及设计）技术。类的接口包括用户所能执行的操作，类的实现则包括类的数据成员、负责接口实现的函数体以及定义类所需的各种私有函数。

封装实现了类的接口和实现的分离，封装后的类隐藏了它的实现细节，即类的用户只能使用接口而无法访问实现部分。

类要想实现数据抽象和封装，首先需要定义一个 **抽象数据类型（abstract data type）**。

## 定义抽象数据类型

## 访问控制与封装

我们为类定义了接口之后，没有任何机制强制用户使用这些接口，我们的类还没有进行封装。在 `C++` 中使用 **访问说明符（access specifiers）** 加强类的封装：

- 定义在 `public` 说明符之后的成员，在整个程序内都可被访问。
- 定义在 `private` 说明符之后的成员，只能被类的成员访问，即隐藏了这些成员的实现。

定义新的 `Sales_data` 类：

```cpp
class Sales_data {
  private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    double avg_price() const { return units_sold ? revenue / units_sold : 0; }

  public:
    Sales_data() = default;
    Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(const std::string &s): bookNo(s) {}
    Sales_data(std::istream&);
    std::string isbn() const { return bookNo; };
    Sales_data &combine(const Sales_data&);
};
```