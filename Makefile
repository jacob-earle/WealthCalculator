CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g 
LDFLAGS=-g 

SRCS=calc.cc
OBJS=$(subst .cc,.o,$(SRCS))

all: WealthCalculator

WealthCalculator: calc.o
	$(CXX) $(LDFLAGS) -o WealthCalculator $(OBJS) $(LDLIBS)

calc.o: calc.cc
