# makefile to use when working on examples for Bjarne Stroustrup's
# book, "Programming Principles and Practice Using C++" (3rd Edition),
# working on examples using Ubuntu 24.04.4 LTS x86_64.
#
# Ian Bruntlett, January 2026 - 26th February 2026 9:50ish 
# with help on the accu-general mailing list from Jonathan Wakely
# and on the accu-members for people to test these example programmes.

# Tell the C++ compiler to include debugging information (-g), have
# some useful warnings, that modules are in use (-fmodules), and
# that we are using a bleeding edge version of the C++ language.

# tell make where to find the C++ compiler
CXX = /opt/gcc-latest/bin/g++

# flags for the C++ compiler
CXXFLAGS = -g -Wall -Wshadow -Wconversion -fmodules -std=c++23

# the names of the programmes built using this makefile
executables = hello-std hello-ppp3 greetings

# website address for gcc-latest,
# so we can check its version - $ make look-for-compiler
# or download it - make get-the-compiler
compiler_link = https://kayari.org/gcc-latest/gcc-latest.deb

module_std=$(shell find /opt/gcc-latest/ -iname std.cc)

# linker flags, to locate library files without having to:
# set export LD_LIBRARY_PATH=/opt/gcc-latest/lib64
LDFLAGS += -Wl,-rpath,/opt/gcc-latest/lib64

# if you want to create a linker map file for extra info on your
# executables then uncomment this line below:
# LDFLAGS += -Wl,-Map=$@.map 

all : $(executables)

# Note that commands are preceded by a TAB character
# and not a sequence of space characters.

# Build a module for using the Standard C++ Library
# gcm.cache/std.gcm - the 'compiled module interface'
# std.o - contains the modules definitions.
std.o: $(module_std)
	$(CXX) $(CXXFLAGS) -c $(module_std)

# Build a module for using the examples from the book PPP
# gcm.cache/ppp.gcm - the 'compiled module interface' for PPP extensions
# PPP.o - contains the PPP extensions definitions.
PPP.o: PPP.ixx
	$(CXX) $(CXXFLAGS) -c PPP.ixx

# build an executable file that uses the Standard Library module
hello-std: std.o hello-std.cpp

# build an executable file that greets the user using modern C++ facilities
greetings : std.o greetings.cpp

# build an executable file that uses the PPP module from the book PPP3
hello-ppp3: std.o PPP.o hello-ppp3.cpp

.PHONY: clean
clean:
	rm -rfv gcm.cache/
	rm -fv $(executables) *.o *.map

# check to see the version information of the current compiler
.PHONY: look-for-compiler
look-for-compiler:
	@echo Checking the current version of the compiler
	@echo ============================================
	wget --spider --content-disposition $(compiler_link) 2>&1 | grep Location

# download the current compiler
.PHONY: get-the-compiler
get-the-compiler:
	@echo Only downloading the compiler if we don\'t already have it.
	@echo ==========================================================
	wget --no-clobber  --content-disposition $(compiler_link)

# display help message
.PHONY: help
help:
	@echo makefile to build executables and also a bit of housework.
	@echo "make hello-std  - make Hello World programme that does an import std;"
	@echo "make greetings  - a more modern Hello World programme."
	@echo "make hello-ppp3 - make Hello World programme that uses the PPP module."
	@echo "make all        - make module files and the example programmes."
	@echo "make std.o      - make the standard library module files."
	@echo "make PPP.o      - make utility module for the book PPP3 \(Stroustrup\)."
	@echo "make              from the book PPP3."
	@echo "make clean      - delete the executable files and object files"
	@echo "                  typically done after updating the compiler."
	@echo "make look-for-compiler - see what the current compiler version is"
	@echo "make get-the-compiler  - download the most recent compiler"
	@echo module_std = $(module_std)
	@$(CXX) --version | head -1

# PPP files from https://stroustrup.com/programming.html
# a few programmes by me, a makefile, a supporting shell script,
# and my draft article
module-article.tar.gz : PPP.ixx PPP.h PPP_support.h PPPheaders.h\
	hello-std.cpp hello-ppp3.cpp greetings.cpp \
	makefile prepare-for-gcc-latest \
	irb-cpp-stdlib-a-matter-of-import.odt \
	irb-delete-elves
	tar -czf $@ $^
