#https://cs.colby.edu/maxwell/courses/tutorials/maketutor/


# compiler with option -g for debug -Wall for all warning
#CC=g++-13 -g -Wall 
CC=clang++ -g -Wall -std=c++11


#include directory
IDIR =./inc
CFLAGS=-I$(IDIR) 
ODIR=obj

#LIBS=-lm
LIBS=

_DEPS = ds.hpp geom.hpp tests.hpp
	DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = ds.o geom.o main.o ds-impl.o tests.o
	OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#main.o:  main.cpp $(DEPS) $(ODIR)
#	$(CC) -c main.cpp $(CFLAGS) -o main.o

eureka: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ eureka
# DO NOT DELETE
