rm=/bin/rm -f
CC=cc
DEFS=
INCLUDES=-I.
LIBS=

DEFINES= $(INCLUDES) $(DEFS)
CFLAGS= -std=c99 $(DEFINES) -g -O2 -fomit-frame-pointer -funroll-loops

all: aes128e_driver

aes128e_driver: aes128e_driver.o aes128e.o
	$(CC) $(CFLAGS) -o aes128e_driver aes128e_driver.c aes128e.o $(LIBS)

aes128e.o: aes128e.c
	$(CC) $(CFLAGS) -c aes128e.c $(LIBS)

clean:
	$(rm) aes128e.o aes128e_driver *.o core *~

