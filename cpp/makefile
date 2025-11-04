# makefile for general C++ experiments done by me, all filenames start
# with irb-

# to check for memory errors (in, for example hello42), do this:
# $ valgrind --tool=memcheck ./hello42

CXXFLAGS = -g -Wall -Wshadow -Wconversion -std=c++20

executables = irb-hello-world
# create a linker map file for extra info on the executable
LDFLAGS += -Wl,-Map=$@.map


all : $(executables)


.PHONY: clean
clean:
	rm -fv $(executables) *.map
