CC			= g++
#CFLAGS		= -O4 -Wall -I/usr/local/include
CFLAGS		= -O4 -Wall -I/usr/include
DEST		= dst/
#LDFLAGS	= -L/usr/local/lib
LDFLAGS		= -L/usr/lib
LIBS		= #-lm -l
OBJS		= src/main.o
PROGRAM		= tetris.exe
#SRCDIR		= src/
WINOBJ		= 
DARWINOBJ	= Darwin/macsys.o

ifeq ($(os),Windows_NT)
# Windows stuff
#	PROGRAM = tetris.exe
#	OBJS = src/main.o
else
	ifeq ($(uname),Darwin)
		OBJS := DARWINOBJ
	else
	endif
endif

all:			$(PROGRAM)

$(PROGRAM):		$(OBJS)
#				@echo hello $(os)
				$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

clean:;			rm -f *.o *~ $(PROGRAM)

install:		$(PROGRAM)
				install -s $(PROGRAM) $(DEST)