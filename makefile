#
#   This file is part of the String Manipulation program, 
#   its a make file for compiling the string manipulation program
#
#   File name: makefile
#

OBJECTS = main.o string_utility.o utility.o 
CC = gcc
CFLAGS = -w

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ 

main.o: main.c
	$(CC) -c main.c

string_utility.o: string_utility.c string_utility.h
	$(CC) -c string_utility.c

utility.o: utility.c utility.h
	$(CC) -c utility.c

#client.o: client.c client.h
#	$(CC) -c client.c
#remove the object files
clean:
	-rm *.o