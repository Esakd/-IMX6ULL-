KERNELDIR := /home/alientek/Desktop/Linux_ZDYZ
CURRENT_PATH := $(shell pwd)

obj-m := fasyncKey.o

build: kernel_modules

kernel_modules:
	$(MAKE) -C $(KERNELDIR) M=$(CURRENT_PATH) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(CURRENT_PATH) clean
