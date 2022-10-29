CC = g++
TARGET = movielibrary
CFLAGS = -g -Wall -Wextra
# Complies showing all errors and warnings

all: movielibrary

# List the object files needed to create the executable file.

$(TARGET):	 main.o Movie_library.o
	$(CC) $(CFlags) -o $(TARGET) main.o Movie_library.o

# Creates the rules need to link everything to main

main.o: main.cpp Movie_library.h
	$(CC) $(CFLAGS) -c main.cpp

# Creates the rules for Movie_library.o

Movie_library.o:	Movie_library.cpp Movie_library.h
	$(CC) $(CFLAGS) -c Movie_library.cpp

# Creates a blank slate (done by 'make clean')

clean:
	$(RM) movielibrary *.o *~
