export sub_objs
GEN_DIR=n
all:
	@for d in $$(ls); \
	do \
		if [ -d $$d ] && [ -s $$d/Makefile ]; then \
			$(MAKE) -C $$d; \
		fi \
	done

clean:

ifeq ($(GEN_DIR),n)
	@for d in $$(ls); \
	do \
		if [ -d $$d ] && [ -s $$d/Makefile ]; then \
			$(MAKE) -C $$d clean; \
		fi \
	done
endif

