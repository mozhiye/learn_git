/*================================================================
*   Copyright (C) 2018 All rights reserved.
*   
*   文件名称：NOTE.cpp
*   创 建 者：MoZhiYe
*   创建日期：2018年07月22日 14:27:30
*   描    述：
*
================================================================*/
//2018年7月22日14:27:43
//知识点1: 运算符重载, 使用相同的符号进行多种操作叫做运算符重载
//知识点2: 强制类型转换格式:
(long) thorn;  //或者
long (thorn);  //thorn是变量, 像是函数调用, 或者
static_cast <long> (thorn); //更为严格
//知识点3: auto关键字
auto n = 100; //自动根据数字类型确定变量的类型
//知识4: 从键盘读取一行;
cin.getline(name, 20);
//知识点5: 字符串类型
string str1; //可以进行相加,string是一种类, 则str便是声明的对象, 可调用对象的方法(即函数)
int len1 = st1.size(); //返回该字符串的长度, 读取string类的方法:
getline(cin, str) //将cin作为参数, 指出到哪里去查找输入

//知识点6: 结构体变量声明
struct inflatable goose;
inflatable goose; //c++可以省略struct, 初始化使用逗号分隔值列表,并可以不用等号
inflatable duck {"abc", 0.12, 9.98};
//结构体成员位字段
struct torgle {
    unsigned int SN : 4; //4bit
    unsigned int unuse : 4; //4bit
    bool gooIn : 1; //1bit
};

//知识点7: 为一个数据类型分配内存, c++方法
int *pn = new int; //让pn指向一块int内存, 并用delete删除, 属于动态数组
delete pn;
/*注意分配数组格式*/
int *psome = new int[10]; //申请
delete [] psome; //释放

//知识点8: 指针和数组名的区别;
sizeof(数组名) = 长度;
sizeof(指针) = 仅仅是指针的长度
数组名的值是固定的,无法改变
&数组名; //整个数组的地址, (&数组名) + 1 = 整个数组字节数跨度
数组名是首元素地址, 数组名 + 1 = 单元素字节数
