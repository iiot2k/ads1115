UNAME_M := $(shell uname -m)
ifeq ($(UNAME_M),armv7l) 
	LIBFLAG := -L. -lads1115_arm32
endif
ifeq ($(UNAME_M),aarch64)
	LIBFLAG := -L. -lads1115_arm64
endif

CFLAGS := -std=c++14 -pthread

all: $(patsubst %.cpp, %, $(wildcard *.cpp))

%: %.cpp Makefile
	g++ $< -o $@ $(CFLAGS) $(LIBFLAG)