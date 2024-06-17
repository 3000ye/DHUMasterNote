---
title: Linked List
description: "Data Structure: Linked List (CPP and Python)"
date: 2024-02-21T19:14:32+08:00
image: assets/dataStructures.jpg
math: true
toc: true
categories:
    - Data Structure
tags:
    - CPP
    - Data Structure
---

# 数据结构：链表

## 线性表

线性表是具有**相同**数据类型的 $n(n \ge 0)$ 个**数据元素**的**有限序列**，其中 $n$ 为**表长**，当 $n = 0$ 时线性表是一个**空表**。若用 $L$ 命名线性表，则其一般表示为：

$$
L = (a_1, a_2, \cdots, a_i, a_{i + 1}, \cdots, a_n)
$$

几个概念：

- $a_i$ 是线性表中的“第 $i$ 个”元素线性表中的**位序**，位序从 $1$ 开始，数组下标从 $0$ 开始。
- $a_1$ 是**表头元素**，$a_n$ 是**表尾元素**。

除第一个元素外，每个元素有且仅有一个**直接前驱**；除最后一个元素外，每个元素有且仅有一个**直接后继**。

线性表有两种存储方式，一种是顺序存储结构，另一种是链式存储结构。我们常用的数组就是一种典型的顺序存储结构。

## 链表

链式存储结构就是两个相邻的元素在内存中可能不是相邻的，每一个元素都有一个指针域，指针域一般是存储着到下一个元素的指针。

这种存储方式的优点是定点插入和定点删除的时间复杂度为 $O(1)$，缺点是访问的时间复杂度最坏为 $O(n)$。

链表就是链式存储的线性表。根据指针域的不同，链表分为单向链表、双向链表、循环链表等等。

### 单向链表

单向链表中包含数据域和指针域，其中数据域用于存放数据，指针域用来连接当前结点和下一节点。

<div style='display: flex; justify-content: center;'>
<img src='https://oi-wiki.org/ds/images/list.svg' alt='img' style='zoom:100%;' />
</div>
