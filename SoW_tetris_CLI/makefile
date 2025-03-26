CC            = gcc
CFLAGS        = -O4 -Wall -I/usr/local/include
DEST          = dst/
LDFLAGS       = -L/usr/local/lib
LIBS          = #-lhoge -lm
OBJS          = src/main.o Darwin/macsys.o
PROGRAM       = tetris
#SRCDIR        = src/



all:            $(PROGRAM)

$(PROGRAM):     $(OBJS)
				$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

clean:;         rm -f *.o *~ $(PROGRAM)

install:        $(PROGRAM)
				install -s $(PROGRAM) $(DEST)