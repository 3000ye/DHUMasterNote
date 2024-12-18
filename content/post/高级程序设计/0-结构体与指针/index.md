---
title: "Ch0: 结构体与指针"
description: "Ch0: 结构体与指针"
date: 2024-06-17T13:52:36+08:00
image: 
math: true
toc: true
categories:
    - 高级程序设计
tag:
    - CPP
---

# 结构体、指针
## 结构体

### 类型声明

结构体的声明和类的声明类似，区别如下：

1. 使用关键字 `struct`。
2. 通常只声明成员变量，不包含成员函数。
3. 结构体的成员默认是 `public` 的。

```cpp
结构体模板：
struct 结构体名称 {
    成员列表
};

结构体示例：
struct ListNode {
    int val;
    ListNode *next;
};
```

### 别名

```cpp
typedef struct ListNode {
    ...
} LN;
```

### 构造函数

可以使用构造函数来初始化结构体：

```cpp
struct Employee {
    string name;    // 员工姓名
    int vacationDays,    // 允许的年假
    daysUsed;    //已使用的年假天数
    Employee (string n = "", int d = 0) {    // 构造函数
        name = n;
        vacationDays = 10;
        daysUsed = d;
    }
};

// 初始化
Employee castor("Castor", 3);
```

## 指针与引用

1. 变量的指针是变量的地址。
2. 存放另一个变量的地址的变量，成为指针变量，它的值为指针。
3. 指针变量只能指向同一个类型的变量。

```cpp
int i = 1, j = 2;   // 变量
int *p1 = &i, *p2 = &j;    // 指针变量
```

### 指针与引用做函数参数

在函数参数传递时，实参传递给形参的时候是按 **值** 传递的，形参实际是实参的拷贝，即函数的运行不会影响实参本身。

传递变量的指针或引用，可以在函数运行时可以修改实参本身，其中引用更加便于理解。

```cpp
// 直接传递变量
void notChange(int x) { x ++; }
// 传递变量的指针
void change(int *x) { x ++; }
// 传递变量的引用
void change2(int &x) { x ++; }

int main() {
    int a = 1, b = 1, c = 1;

    notChange(a);
    change(&b);
    change2(c);
}
```
