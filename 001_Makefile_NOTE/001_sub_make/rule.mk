#================================================================
#   Copyright (C) 2018  All rights reserved.
#   
#   文件名称：rule.mk
#   创 建 者：MoZhiYe
#   创建日期：2018年07月21日 16:19:55
#   描    述：
#
#================================================================

.PHONY: out clean
 #先找object依赖,再走这里

sub_objs += $(OBJ_DIR)/*.o

out: object
	@echo "execute"

ifeq ($(GEN_DIR),n)
	@echo "for circle"
	@for d in $$(ls); \
	do \
		if [ -d $$d ] && [ -s $$d/Makefile ]; then \
			$(MAKE) -C $$d; \
		fi \
	done
endif
ifeq ($(ROOT_DIR),y)
	echo "$(sub_objs)"
	$(CC) $(CFALG) $(includes) $(objs) $(obj_ls) $(obj_bs) $(sub_objs)
else
	cp $(objs) $(OBJ_DIR)/
endif

object:$(objs) $(obj_ls) $(obj_bs)

$(objs):%.o:%.c
	$(CC) $(includes) -c $< -o $@

$(obj_ls):%.o:%.s
	$(CC) $(includes) -c $< -o $@

$(obj_bs):%.o:%.S
	$(CC) $(includes) -c $< -o $@

clean:
	@-rm *.o $(wildcard $(OBJ_DIR)/*.o)

ifeq ($(GEN_DIR),n)
	@for d in $$(ls); \
	do \
		if [ -d $$d ] && [ -s $$d/Makefile ]; then \
			$(MAKE) -C $$d clean; \
		fi \
	done
endif

