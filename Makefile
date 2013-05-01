ifeq ($(OS),Windows_NT)
	CC = "mingw32-g++-4.6.2.exe"
	EXT = .exe
else #has to be tested ;)
	CC = g++
	EXT = ""
endif

BINDIR = bin
SOURCES = $(wildcard Euler_*.cpp)
TARGETS = $(patsubst %.cpp, $(BINDIR)/%$(EXT), $(SOURCES) )

all: $(BINDIR) $(TARGETS)

$(BINDIR):
	-@ if not exist $(BINDIR) mkdir $(BINDIR)

bin/%.exe: %.cpp  
	$(CC) $< -o $@ -Iinclude -O2
