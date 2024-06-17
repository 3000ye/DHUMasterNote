---
title: Docker
description: 
date: 2024-02-29T17:40:52+08:00
image: 
math: 
license: 
hidden: true
comments: true
draft: true
---


```sh
# 服务器操作
docker run -p 20000:22 --name my_docker_server -itd docker_images:1.0  # 创建并运行docker_lesson:1.0镜像

docker attach my_docker_server  # 进入创建的docker容器
passwd  # 设置root密码


# 本地操作
ssh root@xxx.xxx.xxx.xxx -p 20000
```