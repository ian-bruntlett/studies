# makefile for trying examples in C++ Lambda Story, Chapter 2.

# to check for memory errors (in, for example hello42), do this:
# $ valgrind --tool=memcheck ./hello42

CXXFLAGS = -g -Wall -Wshadow -Wconversion -std=c++2a

executables = lambda_and_function_obj diff_types \
              std_function_and_auto

# create a linker map file for extra info on the executable
# (not needed at the moment)
# LDFLAGS += -Wl,-Map=$@.map


all : $(executables)


.PHONY: clean
clean:
	rm -fv $(executables) *.map
