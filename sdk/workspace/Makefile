#
# Makefile for a workspace of RasPike-ART Platform(ASP3).
#

#
# Include configurations of RasPike-ART (ASP3) SDK
#

SDKDIR = ..
WSPDIR = $(basename $(PWD))
ASPMAKEFILE = Makefile.asp
include ../common/Makefile.workspace

ifeq ($(APPLDIR),)
APPLDIR = $(shell cat appdir)
include $(APPLDIR)/Makefile.inc
endif

DEVICE_CONFIG=../common/device_config.txt

ifneq ($(USE_RASPIKE_ART),)
include ../common/Makefile.raspike-art
DEVICE_CONFIG=../common/device_config_raspike-art.txt




endif

CLEAN_FILES+=../../libraspike-art/lib/*.a


start: appdir
	$(ADDITIONAL_PRE_APPL)
	#sudo env LD_PRELOAD=../common/setjmp/libssetjmp.so ./asp -d $(DEVICE_CONFIG)
	sudo env LD_PRELOAD=../common/setjmp/aarch64/libssetjmp.so ./asp -d $(DEVICE_CONFIG)

startsim: appdir
	$(ADDITIONAL_PRE_APPL)
	sudo env LD_PRELOAD=../common/setjmp/aarch64/libssetjmp.so ./asp -d $(DEVICE_CONFIG)

debug: appdir
	$(ADDITIONAL_PRE_APPL)
	gdb asp
appdir:
	@echo "make asp first!"

