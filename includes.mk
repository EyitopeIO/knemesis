
# Options: DEBUG | BETA | STABLE
BUILD_MODE := DEBUG


COMMON_FLAGS += -fpic -I$(INCLUDIR)


UOBJSDIR := usrc
EOBJSDIR := plugs common
INCLUDIR := include


USRCF := $(shell find $(UOBJSDIR) -type f \( -iname "*.cpp" -o  -iname "*.c" \))
ESRCF := $(shell find $(EOBJSDIR) -type f \( -iname "*.cpp" -o  -iname "*.c" \))


UOBJS :=$(USRCF:%=%.o)
EOBJS :=$(ESRCF:%=%.o)


ifeq ($(strip $(BUILD_MODE)),DEBUG)
COMMON_FLAGS += -g
endif


CXXFLAGS += $(COMMON_FLAGS)
CFLAGS += $(COMMON_FLAGS)


