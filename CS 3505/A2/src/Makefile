CC = g++
CFLAGS = -Wall
LIBHARU = ../../libharu
INCLUDE = ../include

spiralPDF: spiralPDF.cpp HaruPDF.o Spiral.o
	$(CC) $(CFLAGS) -o spiralPDF spiralPDF.cpp HaruPDF.o Spiral.o -I$(INCLUDE)  -I$(LIBHARU)/include -L$(LIBHARU)/src -lhpdfs

HaruPDF.o: HaruPDF.cpp $(INCLUDE)/HaruPDF.h
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -I$(INCLUDE) -c HaruPDF.cpp

Spiral.o: Spiral.cpp $(INCLUDE)/Spiral.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c Spiral.cpp

clean:
	rm -f *.o *.a test

test: spiralPDF
	./spiralPDF "hello I hope this makes a spiral, I am going to add some text to see how this really looks when I make it big! It does not look bad, how about we make it go off the page a little bit?"
