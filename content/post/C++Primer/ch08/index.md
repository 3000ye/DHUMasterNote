---
title: C++ Primer Ch08
description: IO library
date: 2023-12-10T15:24:27+08:00
image: assets/c++primer.jpg
math: true
toc: true
categories:
    - C++ Primer
tags:
    - CPP
    - C++ Primer
---

# IO 库

我们的程序已经使用了很多 IO 库设施：

- `istream` （输入流）类型，提供输入操作。
- `ostream` （输出流）类型，提供输出操作。
- `cin`，一个 `istream` 对象，从标准输入读取数据。
- `cout`，一个 `ostream` 对象，想标准输出写入数据。
- `cerr`，一个 `ostream` 对象，通常用于输出程序错误信息，写入到标准错误。
- `>>` 运算符，用来从一个 `istream` 对象中读取输入数据。
- `<<` 运算符，用来向一个 `ostream` 对象中写入输出数据。
- `getline` 函数，从一个给定的 `istream` 对象中读取一行数据，存入到一个给定的 `string` 对象中。

## IO 库

IO 类型和对象一般都是操纵 `char` 数据的，但有些使用需要对文件、`string` 进行操作，因此分别定义了三个头文件：

- `iostream` 头文件：从标准流中读写数据，`istream`、`ostream` 等。
- `fstream` 头文件：从文件中读写数据，`ifstream`、`ofstream` 等。
- `sstream` 头文件：从字符串中读写数据，`istringstream`、`ostringstream` 等。

