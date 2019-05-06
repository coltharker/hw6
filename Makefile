# Filename	Makefile
# Date		May 05, 2019
# Author	Joseph Harker
# Email		jch170430@utdallas.edu
# Course	CS3377.501
# Version	1.0
# Copyright 2019, All Rights Reserved

CXX = g++
CXXFLAGS =
CPPFLAGS = -Wall -g -I/scratch/perkins/include
LDFLAGS = -L/scratch/perkins/lib
LDLIBS = -lcdk -lcurses

EXECFILE = prog6

OBJS = main.o

all: $(EXECFILE)

clean:
	rm -f $(OBJS) $(EXECFILE) *.P *~ \#*

$(EXECFILE): $(OBJS)
	$(CXX) -o $@  $(OBJS) $(LDFLAGS) $(LDLIBS)
