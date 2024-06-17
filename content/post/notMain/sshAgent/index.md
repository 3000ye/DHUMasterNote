---
title: SSH Key Agent
description: Generate multiple ssh keys on one device for different git platforms
date: 2023-12-26T16:23:26+08:00
image: assets/gitssh.png
math: true
toc: true
tags:
    - Git
    - SSH
---

# 为不同的 Git 服务生成不同的 SSH Key

在一台设备上使用 Git 托管代码时，我们可能会遇到以下需求：

- 我有多个 Git 平台（Github, Gitlab, ...）的账号，每个平台的账号都需要一个 SSH Key。
- 在同一个 Git 平台，我有多个账号，每个账号都需要一个 SSH Key。
- 不同平台的账号，可能使用相同邮箱进行注册。

这时，如何生成和管理 SSH Key 成为一个问题。

## 设置局部 Git 信息

在不同文件夹下，都可以设置不同的局部 Git 信息：

```shell
git config user.name "name"
git config user.email "email"
```

## 开启 SSH Agent

开启 SSH Agent 对 SSH 执行代理，用于缓存私钥：

```shell
eval "$(ssh-agent -s)"
```

## 生成不同的 SSH Key

指定文件名，生成不同的 SSH Key，即使相同邮箱也可以进行区分：

```shell
ssh-keygen -t rsa -b 4096 -f ~/.ssh/id_rsa_name -C "your_email@example.com"
```

将生成的私钥添加进代理：

```shell
ssh-add ~/.ssh/id_rsa_name

# MacOS
ssh-add --apple-use-keychain ~/.ssh/id_rsa_name
```

## 将公钥添加到 Git 平台

首先复制 SSH 公钥：

```shell
cat ~/.ssh/id_rsa_name.pub
```

然后到 Git 平台中，添加该公钥。
