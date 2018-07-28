/*================================================================
*   Copyright (C) 2018 All rights reserved.
*   
*   文件名称：Note.c
*   创 建 者：MoZhiYe
*   创建日期：2018年07月27日 22:07:11
*   描    述：
*
================================================================*/

知识点1.构造linux内核源码树:
步骤一:查看linux系统运行内核的版本, 命令:
        name -r  //将显示版本
步骤二: 查看当前网上可供下载内核版本, 命令:
        sudo apt-cache search linux-source // 显示可供下载的版本
步骤三: 下载内核源码, 命令:
        sudo apt-get install linux-source(版本号)
步骤四: 下载完, 源码文件存放在/usr/src, 解压源码文件, 命令:
        sudo tar -jxvf linux-source(版本号)
步骤五: 进入解压文件夹, 配置内核, 命令:
        sudo make oldconfig
步骤六: 编译内核, 命令:
        sudo make //与sudo make bzImage相同, 一个小时
步骤七: 测试添加模块, 编写hello.c, Makefile, 文件见001.附件,
步骤八: 执行make编译, 
        加载模块, sudo insmod hello.ko
        查看所有驱动模块, lsmod
        移除模块, sudo rmmod hello
步骤九: 查看输出结果, vim /var/log/syslog
