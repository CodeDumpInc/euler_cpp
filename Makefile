BINDIR = bin
ifeq ($(OS),Windows_NT)
	CC = "mingw32-g++-4.6.2.exe"
	EXT = .exe
	CHECKDIR = "-@ if not exist $(BINDIR) mkdir $(BINDIR)"
else
	CC = g++
	EXT = 
	CHECKDIR =
endif

SOURCES = $(wildcard Euler_*.cpp)
TARGETS = $(patsubst %.cpp, $(BINDIR)/%$(EXT), $(SOURCES) )

all: $(BINDIR) $(TARGETS)

$(BINDIR):
	mkdir $(BINDIR) -p
bin/%$(EXT): %.cpp  
	$(CC) $< -o $@ -Iinclude -O2 -Wall

clean: 
	rm ./$(BINDIR)/*
