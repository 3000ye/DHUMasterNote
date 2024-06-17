#!/bin/bash

# 检查是否提供了提交备注作为参数
if [ $# -eq 0 ]; then
  echo "请提供提交备注作为参数。"
  exit 1
fi

# 生成网页
hugo
# 进入仓库目录
cd public
# 提取提交备注
commit_message="$1"
# 添加所有更改
git add .
# 提交更改并附带提交备注
git commit -m "$commit_message"

# 推送更改到远程仓库（假设你已经设置了远程仓库）
git push origin main

echo "Pages clinet completed!"


###### 仓库 pull 和 push 冲突解决
# git pull --rebase prigin main
# git push origin main
