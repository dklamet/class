
CC=g++

#Optimized
#CPPFLAGS= -O3 -Wno-pmf-conversions

#Debugging with profiling info
#CPPFLAGS= -g -pg -MMD $(INCPATH) -Wno-pmf-conversions

#Debugging, no profiling
CPPFLAGS= -g  -MMD $(INCPATH) -Wno-pmf-conversions

PROGRAM = main
PROGRAM1= main1

SOURCES = main.cpp
SOURCES1 = main1.cpp

OBJECTS=$(patsubst %.cpp,%.o, $(SOURCES))
OBJECTS1=$(patsubst %.cpp,%.o, $(SOURCES1))

DEPS=$(SOURCES:.cpp=.d)
DEPS1=$(SOURCES1:.cpp=.d)

%.o:%.cpp
	g++ $(CPPFLAGS) -c $(INCLUDEDIRS) -o $@  $<


all:$(PROGRAM) $(PROGRAM1)

$(PROGRAM):$(OBJECTS) 
	g++ $(CPPFLAGS) -o $(PROGRAM)  $(OBJECTS)  $(LIBS) 

$(PROGRAM1):$(OBJECTS1) 
	g++ $(CPPFLAGS) -o $(PROGRAM1)  $(OBJECTS1)  $(LIBS) 

$(OBJECTS) $(OBJECTS1): Makefile

remake: clean $(PROGRAM)

clean:
	rm $(OBJECTS) $(PROGRAM) $(DEPS)
	rm $(OBJECTS1) $(PROGRAM1) $(DEPS1)

-include $(SOURCES:.cpp=.d)
-include $(SOURCES1:.cpp=.d)

