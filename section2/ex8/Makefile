
CC=g++

#Optimized
#CPPFLAGS= -O3 -Wno-pmf-conversions

#Debugging with profiling info
#CPPFLAGS= -g -pg -MMD $(INCPATH) -Wno-pmf-conversions

#Debugging, no profiling
CPPFLAGS= -g  -MMD $(INCPATH) -Wno-pmf-conversions

INCLUDEDIRS=-I../../libdraw -I../thread
LIBDIR=../../libdraw


LIBS=-lX11 -l draw -L /usr/X11R6/lib -L $(LIBDIR) 



PROGRAM = main

SOURCES = main.cpp

OBJECTS=$(patsubst %.cpp,%.o, $(SOURCES))
DEPS=$(SOURCES:.cpp=.d)

%.o:%.cpp
	g++ $(CPPFLAGS) -c $(INCLUDEDIRS) -o $@  $<


$(PROGRAM):$(OBJECTS) 
	g++ $(CPPFLAGS) -o $(PROGRAM)  $(OBJECTS)  $(LIBS) 

$(OBJECTS): Makefile

remake: clean $(PROGRAM)

clean:
	rm $(OBJECTS) $(PROGRAM) $(DEPS)

-include $(SOURCES:.cpp=.d)

