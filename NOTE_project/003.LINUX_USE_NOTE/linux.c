/*================================================================
*   Copyright (C) 2018 All rights reserved.
*   
*   文件名称：linux.c
*   创 建 者：MoZhiYe
*   创建日期：2018年07月26日 22:10:25
*   描    述：
*
================================================================*/
1.ubuntu在运行命令无法apt-get获取锁问题, 解决办法:
sudo rm /var/cache/apt/archives/lock
sudo rm /var/lib/dpkg/lock


