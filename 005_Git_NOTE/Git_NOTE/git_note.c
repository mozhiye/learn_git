/*================================================================
*   Copyright (C) 2018 All rights reserved.
*   
*   文件名称：git_note.c
*   创 建 者：MoZhiYe
*   创建日期：2018年07月27日 22:55:14
*   描    述：
*
================================================================*/
问题1: 怎么创建一个新的仓库, 注意仓库必须依赖github服务器, 新建仓库, 创建仓库都是在github上的, 
       而linux是从上面上传, 克隆, 同步仓库内容.
    步骤一: 在github上新建一个空的仓库, github上会有提示命令行, 内容如下:在linux上同步仓库, 
            方法一: 还没有仓库
            …or create a new repository on the command line //在linux上新建一个空的仓库, 然后上传, 同步.
            echo "# learn_git" >> README.md
            git init
            git add README.md
            git commit -m "first commit"
            git remote add origin https://github.com/mozhiye/learn_git.git
            git push -u origin master
            方法二: 上传一个已有的仓库:
            …or push an existing repository from the command line
            git remote add origin https://github.com/mozhiye/learn_git.git
            git push -u origin master
    注意点1: github地址有两种, 都可以:
            地址1(https地址): https://github.com/mozhiye/learn_git.git
            地址2(SSH地址): git@github.com:mozhiye/learn_git.git
    注意点2: 新建仓库, github建议每个仓库都包含README, LICENCE, 和.gitignore文件
            (原文)We recommend every repository include a README, LICENSE, and .gitignore.
知识点1: git remote 讲解, git remote 意为远程/远程的意思,
         用法一: git remote add +远程库名 +远程库地址
                 例子: git remote add origin https://github.com/mozhiye/learn_git.git  //在linux文件夹中添加一个远程库, 并命名为origin
    注意点3: 名字是可以任意取的, 远程分支一般默认命名为origin
知识点2: git push 讲解, push是推送的意思, 该命令用于将本地分支的更新, 推送到远程主机上
        用法一: git push <远程主机名> <本地分支名>:<远程分支名>
                例子: git push -u origin master  //将本地的master分支推送到origin主机的master分支。如果master不存在，则会被新建
                    参数1: -u: set up-stream //如果当前分支与多个主机存在追踪关系，则可以使用-u选项指定一个默认主机，这样后面就可以不加任何参数使用git push, 上面命令将本地的master分支推送到origin主机，同时指定origin为默认主机，后面就可以不加任何参数使用git push了.

总结学习路线: 
    1.现在github上新建一个空仓库
    2.然后在linux下新建文件夹, 初始化仓库, 添加远程仓库(与远程仓库建立起连接)
    3.在linux下新建文件内容, 添加到暂存区, 提交更改
    4.把当前分支(master)推送到远程仓库, 在当前分支再添加其他文件, 作为主分支再推送到远端, 
      往后在这个分支上新建多个分支, 添加内容, 上传, 形成工程项目

问题2: 已有项目仓库, 怎么把他拉下来, 拥有多个分支怎么办, 内容会是一样的吗?
使用命令历史:
git push origin master:master //提交到远程仓库
git branch -vv -a //查看所有分支
git remote //查看远程仓库信息
git diff //有待查看
git commit -m "添加004_linux驱动学习笔记" //提交更改
git add NOTE_project/004_Linux_Module_Develop_NOTE/ //添加到暂存区
git pull origin master //有待查看
git branch -d linux_note //删除本地分支
git merge origin/master //合并远程分支到当前分支
git log -p master.. origin/master //有待查看
git fetch origin //有待查看
git log --graph --pretty=oneline --abbrev-commit //以图形化显示git分支图
git push uniqune --delete git_note //删除远程分支
git remote show origin //查看远程分支信息, 在删除分支后立马能看不到这一分支信息
git remote prune origin //prune意为修剪, 解决在另一个用户删除远程分支后还能看到不存在分支的情况

怎么更新分支信息


