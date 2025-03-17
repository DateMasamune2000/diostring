test: libdiostring.a diostring.h test.c
	gcc -o test test.c -L. -ldiostring

libdiostring.a: diostring.o
	ar rcs libdiostring.a diostring.o

diostring.o: diostring.c diostring.h
	gcc -c diostring.c -o diostring.o

