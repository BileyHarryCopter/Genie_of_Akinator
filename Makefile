# MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS
# MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS
# MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS
CC= gcc
CFLAGS= -c
LEXERSRC=  sources/lexer
PARCERSRC= sources/parcer
DUMPSRC= sources/dump

all: start clean

start: main.o lexer.o parcer.o dump.o
	$(CC) main.o lexer.o parcer.o dump.o -o start

main.o:
	$(CC) $(CFLAGS) main.c

lexer.o:
	$(CC) $(CFLAGS) $(LEXERSRC)/lexer.c

parcer.o:
	$(CC) $(CFLAGS) $(PARCERSRC)/parcer.c

dump.o:
	$(CC) $(CFLAGS) $(DUMPSRC)/dump.c

run:
	./start

leaks:
	leaks -atExit -- ./start

clean:
	rm -rf *.o
# MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS
# MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS
# MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS # MY PRETTY CFLAGFS
