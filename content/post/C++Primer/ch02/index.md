---
title: C++ Primer Ch02
description: Variables and basic types
date: 2023-11-06T22:34:55+08:00
image: assets/c++primer.jpg
math: true
toc: true
categories:
    - C++ Primer
tags:
    - CPP
    - C++ Primer
---

# 变量和基本类型

变量提供一个具名的、可供程序操作的存储空间。`C++`中每个变量都有其数据类型，数据类型决定着变量所占内存空间的大小和布局方式、该空间能存储的值的范围，以及变量能参与的运算。

## 变量的声明和定义

为了允许把程序拆分成多个逻辑部分来编写，`C++`语言支持**分离式编译（separate complication）** 机制，该机制允许将程序分割为若干个文件，每个文件可被独立编译。

为了支持分离式编译，`C++`语言将声明和定义区分开来。**声明（declaration）** 使得名字为程序所致，一个文件如果想使用别处定义的的名字则必须包含对那个名字的声明。而 **定义（definition）** 负责创建与名字关联的实体。

变量声明规定了变量的类型和名字，定义在此基础上，还申请存储空间，甚至可能会为变量赋一个初始值。

```cpp
extern int i;  // 声明
int i;  // 定义
int i = 3;  // 定义并赋值
extern int i = 3;  // 定义而非声明，extern失效
```

**注意：** 变量只能被定义一次，但可以被多次声明。因此在多个文件中使用同一个变量名时，需要多次声明，但只能有且仅在一个文件中定义。

### 标识符

`C++`的 **标识符（identifier）** 由字母、数字和下划线组成，其中必须以字母或下划线开头，没有长度限制，但对大小写敏感。

### 作用域

**作用域（scope）** 是程序的一部分，在其中名字有特定的含义，`C++`语言中大多数作用域都以花括号分隔。

作用域能彼此包含，被包含（嵌套）的作用域称为 **内层作用域（inner scope）**，包含着别的作用域的作用域称为 **外层作用域（outer scope）**。作用域中一旦声明了某个名字，它所嵌套着的所有作用域中都能访问该名字，同时允许在内层作用域中重新定义外层作用域已有的名字。

```cpp
#include "iostream"

int outer = 42;  // 全局作用域

int main() {
    int inner = 12;  // 内层作用域
    // 使用全局变量输出
    std::cout << outer << " " << inner << std::endl;
    
    int outer = 0;  // 局部重新定义，覆盖全局变量
    // 使用局部变量输出
    std::cout << outer << " " << inner << std::endl;

    // 显式访问全局变量
    std::cout << ::outer << " " << inner << std::endl;
    
    return 0;
}
```

## 复合类型

**复合类型（compound type）** 是指基于其他类型定义的类型，主要介绍引用和指针。

### 引用

**引用（reference）** 为对象起了另外一个名字，定义引用时，程序把引用和它的初始值 **绑定（bind）** 在一起，而不是将初始者拷贝给引用。

> 引用并非对象，相反的，它只是为一个已经存在的对象所起的另一个名字。

```cpp
#include "iostream"

int main() {
    int x = 3;  // 定义
    int &y = x;  // 引用
    int z = x;  // 定义

    y = 3;  // 修改 y 的值，实际是修改 x 的值
    std::cout << x << " " << y << std::endl;

    return 0;
}
```

### 指针

**指针（pointer）** 是“指向（point to）”另外一种类型的复合类型。与引用类似，指针也实现了对其他对象的间接访问，但指针还有很多不同点：

- 指针本身就是一个对象，允许对指针赋值和拷贝，而且在指针的生命周期内它可以先后指向几个不同的对象。
- 指针无须在定义时赋初值，和其他内置类型一样，没有赋初值时将拥有一个不确定值。

```cpp
int *ip1, *ip2;  // ip1 和 ip2 都是指向 int 类型对象的指针
double dp, *dp2;  // dp2 是指向 double 类型对象的指针，dp 是 double 类型对象
```

指针存放某个对象的地址，想获取该地址，需要使用 **取地址符（`&`）**：

```cpp
int val = 42;
int *p = &val;  // p 存放变量 val 的地址，或者说 p 是指向变量 val 的指针
```

> 因为引用不是对象，没有实际地址，因此不能定义指向引用的指针。

指针的值（即地址）应属于下列 4 种状态之一：

- 指向一个对象。
- 指向紧邻对象所占空间的下一个位置。
- 空指针，意味着指针没有指向任何对象。
- 无效指针，也就是上述情况之外的其他值。

如果指针指向了一个对象，则允许使用 **解引用符（`*`）** 来访问该对象：

```cpp
int val = 42;
int *p = &val;

std::cout << *p << std::endl;  // 由符号 * 得到指针 p 所指的对象，输出 42
```

> 解引用操作仅适用于有效指针，无效指针无法解引用。

**空指针（null pointer）** 不指向任何对象，在试图使用一个指针之前代码可以先检查其是否为空。

生成空指针：

```cpp
int *p1 = nullptr;  // 等价于 int *p1 = 0
int *p2 = 0;
```

指针和引用都能提供对其他对象的间接访问，然而在具体实现细节上二者有很大不同，其中引用本身并非是一个对象。定义引用之后，就无法令其再绑定到另外的对象，之后每次使用这个引用都是访问它最初绑定的那个对象。

指针没有这种限制，给指针赋值就是令它存放一个新的地址，从而指向一个新的对象。

```cpp
int i = 42;
int *pi = 0;  // pi 为空指针
int *pi2 = &i;  // pi2 存放 i 的地址
int *pi3;  // pi3 的值无法确定

pi3 = pi2;  // pi3 和 pi2 指向同一个对象 i
pi2 = 0;  // pi2 变为空指针
```

## const 限定符

有时我们想定义这样一种变量，它的值不能被改变，这在程序运行过程中对于某些特定值非常有用。为了满足这一要求，可以使用关键字`const`对变量的类型加以限定：

```cpp
const int bufferSize = 512;  // 限定缓冲区大小为 512
```

默认情况下，`const`对象被设定为仅在单个文件内有效。当多个文件中出现了同名的`const`变量时，其等同于在多个文件中分别定义了独立的变量。但当我们需要其在多个文件中保持一致时，需要在定义和声明前面都加上`extern`：

```cpp
// 定义文件 xxx.cpp
extern const int bufferSize = 512;

// 声明文件 xxx.hpp
extern const int bufferSize;
```

### 指针和 const

与引用一样，也可以令指针指向常量与非常量。**指向常量的指针（pointer to const）** 不能用于改变其所指对象的值。要想存放常量对象的地址，必须使用指向常量的指针：

```cpp
const int val = 42;  // val 为常量对像，其值不能改变

int *pi = &val;  // 报错，pi 为普通指针，不能存放常量对象地址
const int *pi2 = &val;  // 使用指向常量的指针存放常量对象地址
*pi2 = 20;  // 报错，不能给指向常量的指针赋值
```

## 处理类型

随着程序越来越复杂，其中使用的变量类型也越复杂，如何处理这些类型成为一个问题。

### 类型别名

**类型别名（type alias）** 是一个名字，它是某种类型的同义词。

使用关键字`typedef`定义类型别名：

```cpp
typedef long long ll;  // ll 是 long long 的同义词
```

使用 **别名声明（alias declaration）** 定义类型别名：

```cpp
using ll = long long;  // ll 是 long long 的同义词
```

### auto 类型说明符

编程时常常需要将表达式的结果赋给变量，这就要求需要事先知道结果的类型。但是要做到这一点有时并不容易，因此`C++11`引入了`auto`类型说明符，它能自动分析表达式结果的类型。

```cpp
auto item = val1 + val2;  // item 初始化为 val1 和 val2 相加的结果
```

使用`auto`定义或声明多个变量时，所有变量的类型必须一致：

```cpp
auto x = 3, y = 5;
auto x = 3, y = 4.2;  // 报错，同一行的变量类型必须一致
```

### decltype 类型指示符

有时会遇到这种情况：希望从表达式中推断出要定义的变量的类型，但是不想用该表达式的值初始化变量——即只使用表达式的数据类型，不使用表达式的结果。

因此`C++11`引入了`decltype`类型指示符，它的作用是返回操作数的数据类型：

```cpp
int x = 5, y = 7;
decltype(x + y) z = 6;  // z 为 int 类型
```

## 自定义数据结构

内置的数据类型并不能满足所有的需求，因此`c++`提供了自定义数据类型的方式：

```cpp
struct student {
    std::string name;
    std::string sex;
    int gender;
};

// 定义
student jack{"jack", "m", 18};
// 先声明后赋值
student castor;
castor.name = "castor", castor.sex = "m", castor.gender = 18;
```

### 自定义数据结构使用别名

和内置数据类型一样，自定义数据结构也能使用别名：

```cpp
using stu = studeng;

// 或直接在定义时使用别名
using stu = struct student {
    std::string name;
    std::string sex;
    int gender;
};
```

### 编写自己的头文件

当我们在编写头文件时，会引入其他头文件，而在生产文件中，又会再次引入这些头文件。这样就导致一个问题，某些头文件被重复引入了。因此，在编写头文件时需要做一定的保护措施：

```cpp
// studeng.h
#ifndef STUDENT_H
#define STUDENT_H

#include "string"

struct student {
    std::string name;
    std::string sex;
    int gender;
};

#endif
```
