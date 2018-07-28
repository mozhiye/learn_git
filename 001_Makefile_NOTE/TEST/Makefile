#================================================================
#   Copyright (C) 2018  All rights reserved.
#   
#   文件名称：Makefile
#   创 建 者：MoZhiYe
#   创建日期：2018年07月15日 20:41:18
#   描    述：
#
#================================================================

SOURCE := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o, $(SOURCE))
TARS := $(foreach file, $(SOURCE), $(patsubst %.c, %.o, $(file)))

all:
	echo "$(SOURCE)"
	echo "$(OBJS)"
	echo "$(TARS)"
