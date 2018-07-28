#================================================================
#   Copyright (C) 2018  All rights reserved.
#   
#   文件名称：rule.mk
#   创 建 者：MoZhiYe
#   创建日期：2018年07月21日 16:19:55
#   描    述：
#
#================================================================
deps = $(objs:.o=.d)
deps += $(obj_ls:.o=.d)
deps += $(obj_bs:.o=.d)

.PHONY: out clean
 #先找object依赖,再走这里

sub_objs += $(OBJ_DIR)/*.o

out: object

ifeq ($(GEN_DIR),n)
	@for d in $$(ls); \
	do \
		if [ -d $$d ] && [ -s $$d/Makefile ]; then \
			$(MAKE) -C $$d; \
		fi \
	done
endif
ifeq ($(ROOT_DIR),y)
	$(CC) $(CFALG) $(includes) $(objs) $(obj_ls) $(obj_bs) $(sub_objs)
else
	cp $(objs) $(OBJ_DIR)/
endif

object:$(objs) $(obj_ls) $(obj_bs)

$(objs):%.o:%.c
	@$(CC) -MM $(includes) $< > $(@:.o=d.1) && \
	if [ -s "$(@:.o=d.1)" ]; then \
	echo -n $(dir $@ > $(@:.o=.d)); \
	cat $(@:.o=d.1) >> $(@:.o=.d); \
	echo >> $(@:.o=.d); \
	fi
	@rm $(@:.o=d.1)
	$(CC) $(includes) -c $< -o $@

$(obj_ls):%.o:%.s
	$(CC) $(includes) -c $< -o $@

$(obj_bs):%.o:%.S
	$(CC) $(includes) -c $< -o $@

clean:
	@-rm *.o *.d

ifeq ($(ROOT_DIR),y)
	@-rm *.bin
endif
ifeq ($(GEN_DIR),n)
	@for d in $$(ls); \
	do \
		if [ -d $$d ] && [ -s $$d/Makefile ]; then \
			$(MAKE) -C $$d clean; \
		fi \
	done
endif

-include $(deps)



