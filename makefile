CC=gcc
IDIR=include
ODIR=obj
LDIR=lib
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=src/
OBJECTS=$(SOURCES: .c=.o)
EXECUTABLE=code_test



all:$(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):$(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm 
