LIBFLAG := -L. -lads1115_arm64
CFLAGS := -std=c++14 -pthread

all: $(patsubst %.cpp, %, $(wildcard *.cpp))

%: %.cpp Makefile
	g++ $< -o $@ $(CFLAGS) $(LIBFLAG)