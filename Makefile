# MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS
# MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS
# MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS
CC= gcc
CFLAGS= -c
LEXERSRC=  sources/lexer

all: start clean

start: main.o lexer.o
	gcc main.o lexer.o -o start

main.o:
	$(CC) $(CFLAGS) main.c

lexer.o:
	$(CC) $(CFLAGS) $(LEXERSRC)/lexer.c

run:
	./start

leaks:
	leaks -atExit -- ./start

clean:
	rm -rf *.o
# MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS
# MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS
# MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS 