
CC=g++

CPPFLAGS=-g 
LIB=libdraw

SOURCES=draw.cc 

OBJECTS=$(patsubst %.cc,%.o, $(SOURCES))

drawlib.a:$(OBJECTS)
	ar r $(LIB).a $^
clean:
	rm $(OBJECTS) $(LIB).a
