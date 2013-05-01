ifeq ($(OS),Windows_NT)
	CC = "mingw32-g++-4.6.2.exe"
	EXT = .exe
else #has to be tested ;)
	CC = g++
	EXT = ""
endif

all: $(patsubst %.cpp, bin/*$(EXT), $(wildcard Euler_*.cpp))

bin/%.exe: %.cpp Makefile
	$(CC) $< -o $@ -Iinclude -O2