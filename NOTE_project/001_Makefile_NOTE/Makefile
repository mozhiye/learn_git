#================================================================
#   Copyright (C) 2018  All rights reserved.
#   
#   文件名称：Makefile
#   创 建 者：MoZhiYe
#   创建日期：2018年07月15日 10:16:04
#   描    述：
#
#================================================================

#1.设置文件搜索路径: 使用VPATH变量
VPATH = add : sub #设置路径为add和sub文件夹

#2.语法1:
add_init.o : %.o : %.c #把以.o结尾的改为.c结尾

#3.自动推导规则:
$(TARGET) : xxx.o xxx.o #默认是有.o : .c 的规则
	$(CC) -o $@ $^

#4.假想目标
.PHONY : clean
clean:
	rm xxx.o

#5.递归make
ROOT_DIR
|
|-tmp
|-Makefile
|-include
|    |-public.h
|
|-src
|  |-moda
   |  |-Makefile
   |  |-moda.c
   |  |-moda.h
   |
   |-modb
       |-Makefile
	   |-modb.c
	   |-modb.h
#在总控Makefile中,进入子目录并执行Makefile的命令有两种写法
#第一种:
add:
	cd add && $(MAKE)  #进入add目录并执行make命令
#第二种:
add:
	$(MAKE) -C add #进入add子目录并执行make命令
#在总控Makefile中传递变量到下级Makefile,使用声明
export 变量

#总控Makefile写法示例:

CC = gcc

ROOT := $(shell pwd)
INCLUDE := $(ROOT)/include
SRC := $(ROOT)/src

USR_SUB_DIR := $(SRC)/moda $(SRC)/modb

default : usr

usr : 
	@for n in $(USR_SUB_DIR);
	do $(MAKE) -C $$n;  #n是一个文件a夹名称,cd命令是shell命令,把n放到shell中解析
	done

clean:
	@for n in $(USR_SUB_DIR); #加@不回显命令信息, 分行写要加"\"
	do $(MAKE) -c $$n clean;
	done
#知识点:for循环
#1. for循环是shell中的循环, 属于shell命令,
#2. $变量:是引用的是Makefile中定义的变量, 解析时展开
#3. $$变量:是引用在Makefile中定义的shell变量
#4. -rm dir 加“-”遇到文件不存在时会忽略错误
#5. make -n 或者 --just-print只显示命令，但不会执行,用于调试Makefile

#moda目录下Makefile
CC = gcc
ROOT := $(shell pwd)/../..
INCLUDE := $(ROOT)/include
CFAGS += -I$(INCLUDE)

target : moda

moda : moda.o
	$(CC) -o moda moda.o
moda.o : moda.c
	$(CC) $(CFAGS) -c moda.c

clean:
	-rm *.o moda

#知识点:
#1. 赋值符号
#":=", 在定义中立马生效,ROOT := xxx, ROOT就等于xxx,之前定义过会覆盖原来的值, 前面的变量不可以引用后面的变量
# “=” ROOT = xxx,直到用到时才生效($(ROOT)),期间xxx的值改变,ROOT的值随着改变
#“?=”如果没有被赋值过就赋值

#字符操作函数
#1.获取匹配模式的文件名wildcard, 用于目录寻找所有的c文件
#格式 $(wildcard PATTERN)
SOURCE = $(wildcard *.c)  #返回当前目录下所有扩展名为*.c的文件列表

#2. 模式替换函数patsubst, 用于将.c结尾变成.o结尾
#格式: $(patsubst pattern, replacement, text)
OBJS = $(patsubst %.c, %.o, $(SOURCE))  #将.c原文件替换为.o文件

#循环函数foreach
#格式: $(foreach VAR, LIST, TEXT) #先把LIST中单词逐个给VAR, 然后执行TEXT命令操作
OBJS = $(foreach file, $(SOURCE), $(patsubst %.c, %.o, $(file))) #把.c变成.o的另一种方法

#知识点:
objects = foo.o bar.o
$(objects) : %.o : %.c  #静态模式规则, 把objects中.o结尾改成.c结尾
	$(CC) -c $< -o $@

#展开后等价于, 效率高
foo.o : foo.c
	$(CC) -c foo.c -o foo.o

bar.o : bar.c
	$(CC) -c bar.c -o bar.o

#头文件自动生成依赖方法
#利用C编译器的 "-M" / "-MM" 选项
$(CC) -MM main.c #输出是
main.o : main.c defs.h
#我们把编译器为每一个源文件自动生成的依赖关系放到一个文件中,并以.d为后缀, .d文件存放对应.c文件的依赖关系
#.d文件也是一个Makefile文件, 自动生成.d文件方法:
%.d : %.c
	@set -e; rm -f $@; \   #先删除所有的.d文件
	$(CC) -M $(CPPFLAGS) $< > $@.$$$$; \ #相当于$(CC) -M main.c,生成.c的依赖文件 $@即目标, main.d, $$$$表示一个随机编号,最后生成的文件名可能是main.d.12345
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \ #sed是字符替换字符串, 格式sed 's/原字符串/替换字符串/'
	rm -f $@.$$$$  #删除临时文件

#这四步将实现:
main.o : main.c defs.h #转成
main.o main.d : main.c defs.h #.d文件也会自动更新

#生成.d文件之后, 在主Makefile文件中用include包含进来
sources = foo.c bar.c
include $(sources:.c=.d)  #.c=.d意思是做一个替换,把变量$(sources)所有.c字符串都替换成.d

#知识点: 隐藏原命令语句用@
@echo xxx

#知识点: cd 命令在下一命令生效需要写在同一行上
exec:
	cd /home/chen; pwd

#而分两行写, 则无效
	cd /home/chen
	pwd

#知识点: 改变文件后缀, 可利用变量值替换方法:
foo := a.o b.o c.o
bar := $(foo:.o=.c)  #把变量foo中.o结尾替换为.c结尾
#也可以利用静态模式:
foo := a.o b.o c.o
bar := $(foo:%.o=%.c)

#知识点:define 定义变量用法,相当于 " = "
define two-lines
	echo foo
	echo $(bar)
endef
#知识点:目标变量，为某个目标设置局部变量:
prog : CFLAGS = -g  #这个变量会作用到由这个目标所引发的所有规则中去
prog : prog.ofoo.o bar.o
	$(CC) $(CFLAGS) prog.o foo.o bar.o
prog.o : prog.c
	$(CC) $(CFLAGS) prog.c
#知识点: 模式变量
$.o : CFLAGS = -O #给所有%.o结尾的目标定义目标变量

#知识点:条件判断, 关键字ifeq, else endif
ifeq ($(CC), gcc)
	libs = $(libs_for_gcc)
else
	libs = $(normal_libs)
endif

#另外两个条件关键字:ifneq; ifdef; ifndef,所有行不能以[Tab]键开始,只有需要执行的命令才需要[Tab]开始
bar = 
foo = $(bar)
ifdef foo
	frobozz = yes  #仅仅测试变量是否有值, 这时为真
else
	frobozz = no
endif
#####################################################
foo = 
ifdef foo
	frobozz = yes  #仅仅测试变量是否有值
else
	frobozz = no   #这时为假
endif

#知识点:函数调用, 函数调用以"$"开头, 函数与参数用空格分隔，参数间以逗号分隔
#注意: 列表内单词都是以空格, Tab, 回车, 换行分隔
#函数1: subst, 字符串处理函数
$(subst #被替换, #替换, #列表)
$(subst ee, EE, feet on the street)

#函数2: 模式字符串替换函数
$(patsubst #匹配模式, #替换模式, #列表)
$(patsubst %.c, %.o, xc.c bar.c)

#函数3: strip, 去掉<string>字符串中开头和结尾的空字符
$(strip a b c ) #去掉开头和结尾的空格

#函数4: findstring, 查找字符串函数
$(findstring #查找的字符串, #列表) #返回字符串
$(findstring a,a b c)

#函数5:filter, 过滤函数
sources := foo.c bar.c baz.s ugh.h
$(filter %.c $.s, $(sources)) #保留.c .s的字符串

#函数6: filter-out
$(filter %.c $.s, $(sources)) #保留除了.c .s以外的字符串

#函数7: sort, 排序函数
$(sort foo bar lose) #按首字母排序,返回bar foo lose

#函数8: word, 取单词函数
$(word #序号, #列表)
$(word 2, foo bar baz) #取出列表中第二个单词

#函数9: wordlist, 取出列表中从 xx 到 xx 之间的单词
$(wordlist 2, 3, foo bar baz)

#函数10: words, 单词个数统计
$(words $(sources)) #返回sources中有多少个单词, 结合word, 可取出最后一个单词

#函数11: firstword, 首单词函数
$(firstword foo bar) #取出第一个单词

#字符串操作函数结束

#知识点: 指定编译器对文件的搜索路径
CFLAGS += $(patsubst %,-I%, $(subst :, , $(CPATH)))

#知识点: 文件名操作函数
#函数1: dir, 取文件的目录函数

$(dir src/foo.c hacks) #返回"src/ ./"

#函数2: nodir, 取文件名函数
$(nodir src/foo.c hacks) #返回"foo.c hacks"

#函数3: suffix, 取后缀函数
$(suffix src/foo.c hacks) #返回".c"

#函数4:basename, 取文件名前缀部分
$(basename src/foo.c hacks) #返回"foo hacks"

#函数5: addsuffix, 加后缀函数
$(addsuffix .c, foo bar) #把后缀.c加在每个单词的后面

#函数6: addprefix, 加前缀函数, 一般为路径
$(addprefix src/,foo bar) #为每个文件加上路径

#函数7: join, 连接函数
$(join aaa bbb ccc,111 222 333) #返回"aaa111 bbb222 ccc333"

#知识点: foreach, 循环函数
names := a b c d
files := $(foreach n,$(names),$(n).o) #返回每次循环的结果列表啊, 注意n只是一个临时变量,foreach执行完后将不起作用

#知识点: if函数, 注意if是一个函数, 而ifeq是一个关键字,与define, include同类
$(if <条件判断>,<执行语句>) #或者
$(if <条件判断>,<执行语句>,<条件不成立的执行语句>)

#知识点: call函数, 创建新的参数化函数
reverse = $(1) $(2) #1 2是参数顺序
foo = $(call reverse,a,b)  #返回foo = a b

#知识点: origin函数, 查询变量来自哪里, 环境变量, 在Makefile中定义, 自动变量等
$(origin 变量名) #返回预定义的一些值

#知识点: shell函数, shell里面的命令
contents := $(shell cat foo)
files := $(shell echo *.c)

#知识点: 控制make的函数
$(error <text ...>) #执行error调用, make停止
$(warning <text ...>)

#知识点: 检查规则, 调试Makefile
make -n #不执行命令, 只过一遍依赖

make -B #重编译所有目标

make -C <dir> #指定读取某一目录下的Makefile文件

make -I<dir> #指定一个makefile搜索的目标

make -j [<jobsnum>] #同时运行命令个数

make -k #出错也不停止运行

make -qp #只输出信息而不想执行Makefile

make -p -f /dev/null #输出信息包含Makefile文件名和行号

#知识点: 隐含规则
#1.自动推导.o文件的目标依赖
foo : foo.o bar.o
	$(CC) xxxx
#不再需要写.o的依赖规则, Makefile自动推导生成.o的命令, 默认执行的命令是
	$(CC) -c $(CPPFLAGS) $(CFLAGS)
#针对C++, 会自动推导找文件.cc, 默认执行命令是:
	$(CXX) -c $(CPPFLAGS) $(CFLAGS)

#知识点: 函数库文件模式
archive(member) : xxx.c #目标是archive, 第一次找archive, 没有找到, 第二次找把member当作目标a

foolib(hack.o) : hack.o
	ar cr foolib hack.o


