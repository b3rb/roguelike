# Usage: make [-f path/Makefile] [WIN=Y]

CC = gcc
CFLAGS = -O3 -g -Werror -Wall
LDFLAGS = -L/usr/lib

SRCDIR = src
INCLUDE = -Iinclude
TARGET = roguelike
SRC = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRC:.c=.o)

ifeq ($(WIN), Y)
	CC = x86_64-w64-mingw32-gcc
	LDFLAGS += -lpdcurses
else
	LDFLAGS += -lm -lncurses
endif

bin/$(TARGET) :
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

# copies assets to build folder
	@cp -r assets/ bin/

# compiling
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS) $(INCLUDE)
	@echo "Done!"


.PHONY: clean
clean :
	rm -rf $(OBJS)
	rm -rf bin/*.exe
	rm -rf bin/roguelike
	rm -rf bin/assets
