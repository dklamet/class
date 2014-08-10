
CC=g++


#CPPFLAGS= -O3 -Wno-pmf-conversions
CPPFLAGS= -g -pg -MMD $(INCPATH) -Wno-pmf-conversions
#CPPFLAGS= -g -MMD $(INCPATH) -Wno-pmf-conversions

PROGRAM = main

SOURCES = main.cpp

OBJECTS=$(patsubst %.cc,%.o, $(SOURCES))
DEPS=$(SOURCES:.cc=.d)

%.o:%.cpp
	g++ $(CPPFLAGS) -c $(INCLUDEDIRS) -o $@  $<


$(PROGRAM):$(OBJECTS) 
	g++ $(CPPFLAGS) -o $(PROGRAM)  $(OBJECTS)  $(LIBS) 

$(OBJECTS): Makefile

remake: clean $(PROGRAM)

clean:
	rm $(OBJECTS) $(PROGRAM) $(DEPS)

-include $(SOURCES:.cpp=.d)

