# Usage: make [-f path/Makefile] [WIN=Y]

CC = gcc
CFLAGS = -O3 -g -Werror -Wall
LDFLAGS = -L/usr/lib -Iinclude

SRCDIR = src
INCDIR = include
INCLUDE = $(wildcard $(INCDIR)/*.h)
TARGET = roguelike
SRC = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRC:.c=.o)

ifeq ($(WIN), Y)
	CC = x86_64-w64-mingw32-gcc
	LDFLAGS += -lpdcurses
else
	LDFLAGS += -lm -lncurses
endif

bin/$(TARGET): $(SRC) $(INCLUDE)
# options
ifeq ($(WIN), Y)
	@echo -e "\n=========================="
	@echo -e "Building Windows binary..."
	@echo -e "==========================\n"
	@sed -i 's/ncurses.h/pdcurses.h/g' include/$(TARGET).h
else
	@echo -e "\n========================"
	@echo -e "Building Linux binary..."
	@echo -e "========================\n"
	@sed -i 's/pdcurses.h/ncurses.h/g' include/$(TARGET).h
endif
	@echo -e "Build options:"
	@echo -e "CC = $(CC)"
	@echo -e "CFLAGS = $(CFLAGS)"
	@echo -e "LDFLAGS = $(LDFLAGS)\n"

# compiling
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS)
	@echo "Done!"


.PHONY: clean
clean :
	rm -rf $(OBJS)
	rm -rf bin/*.exe
	rm -rf bin/roguelike
	rm -rf bin/assets
