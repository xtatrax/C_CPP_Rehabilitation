CC			= g++
#CFLAGS		= -O4 -Wall -I/usr/local/include
CFLAGS		= -O4 -Wall -I/usr/include
DEST		= dst/
#LDFLAGS	= -L/usr/local/lib
LDFLAGS		= -L/usr/lib
LIBS		= #-lm -l
OBJS		= src/main.o commox/sys.o
PROGRAM		= tetris.exe
#SRCDIR		= src/
MINGWOBJ	= 
DARWINOBJ	= 

ifeq ($(OS),Windows_NT)
# Windows + MinGW ということにする
	OBJS += $(MINGWOBJ)
#	LDFLAGS += -static -lstdc++ -lgcc -lwinpthread
#	PROGRAM = tetris.exe
#	OBJS = src/main.o
else
	ifeq ($(uname),Darwin)
		OBJS += $(DARWINOBJ)
	else
	endif
endif

all:			$(PROGRAM)

$(PROGRAM):		$(OBJS)
#				@echo hello $(os)
				$(CC) $(OBJS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

clean:;			find . -name "*.o" -o -name "*~" -o -name "$(PROGRAM)" | xargs rm

install:		$(PROGRAM)
				install -s $(PROGRAM) $(DEST)