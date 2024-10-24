---
title: "Ch6: 线性回归"
description: 
date: 2024-10-24T13:10:44+08:00
image: assets/ML.jpg
math: true
toc: true
categories:
    - 机器学习
tag:
    - Machine Learning
    - Python
---

# 线性回归
## 线性回归的形式化定义

线性回归模型假设输出 $y$ 与输入特征 $\mathbf{x}$（通常表示为一个向量）之间的关系可以表示为一个线性方程：
$$
y = \mathbf{w}^T \mathbf{x} + b
$$
其中，$y$ 是目标变量（输出）；$\mathbf{x}$ 是输入变量，包含多个特征 $(x_1, x_2, \cdots, x_n)$；$\mathbf{W}$ 是权重向量，代表每个特征的权重；$b$ 是偏置项（intercept），用来调整输出。

