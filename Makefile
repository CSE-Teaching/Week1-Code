# This is a sample Makefile 
# Definition of source files
SIMPLE = first.c  second.c printArgs.c  scope.c  
STRUCTURE = structure.c structure2.c structure3.c structure4.c structure5.c structure6.c 
REVERSE = linkedList.c reverseArray.c reverseList.c 

SOURCES = $(SIMPLE) $(STRUCTURE) $(REVERSE)

EXECUTABLES = $(patsubst %.c,%,$(SOURCES))
OBJECTS = $(patsubst %.c,%.o,$(SOURCES))

reverseArray: linkedList.o reverseArray.o 
	cc -o $@ $@.o $<
reverseList: linkedList.o reverseList.o 
	cc -o $@ $@.o $<

structure% : structure.h structure%.o
	cc -o $@ structure$*.o 

% : %.o
	cc -o $@  $<

%.o : %.c
	cc -c  $<

all: $(EXECUTABLES)

clean:
	- /bin/rm *o 
	- /bin/rm $(EXECUTABLES)
