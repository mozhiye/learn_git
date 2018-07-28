/*================================================================
*   Copyright (C) 2018 All rights reserved.
*   
*   文件名称：main.c
*   创 建 者：MoZhiYe
*   创建日期：2018年07月15日 14:48:54
*   描    述：
*
================================================================*/
#include "include.h"

int main(int argc, char *argv[])
{
    printf("This is main speaker, over, %d\n", SHARE_NUM);
    sub();
    add();

    return 0;
}


