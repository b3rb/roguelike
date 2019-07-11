# Usage: make [-f path/Makefile] [WIN=Y]

CC = gcc
LINK = gcc
CFLAGS = -O3 -g -Werror -Wall
LDFLAGS = -L/usr/lib -lm

SRCDIR = src

ifeq ($(WIN),Y)
	# mingw32 gcc compiler
	CC = x86_64-w64-mingw32-gcc
	LINK = x86_64-w64-mingw32-gcc
	# uses pdcurses instead of ncurses
	LDFLAGS += -lpdcurses
  @sed -n 's/ncurses.h/pdcurses.h/g' $(SRCDIR)/roguelike.h
else
	LDFLAGS += -lncurses
  @sed -n 's/pdcurses.h/ncurses.h/g' $(SRCDIR)/roguelike.h
endif

roguelike : $(OBJ)

.PHONY : clean
clean :
	rm -rf build/*.o
	rm -rf build/*.exe
	rm -rf build/roguelike
	rm -rf build/assets
