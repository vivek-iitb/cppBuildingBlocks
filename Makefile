#https://cs.colby.edu/maxwell/courses/tutorials/maketutor/


# compiler with option -g for debug -Wall for all warning
#CC=g++-13 -g -Wall 
CC=clang++ -g -Wall -std=c++11

# https://stackoverflow.com/questions/30573481/how-to-write-a-makefile-with-separate-source-and-header-directories 
#include directory
IDIR =./inc
SDIR =./src
CPPFLAGS=-I$(IDIR) 
ODIR=obj

#LIBS=-lm
LIBS=

_DEPS = ds.hpp geom.hpp tests.hpp
	DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = ds.o geom.o main.o tests.o
	OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)

eureka: $(OBJ) 
	$(CC) -o $@ $^ $(CPPFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ eureka
# DO NOT DELETE
