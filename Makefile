# Usage: make [-f path/Makefile] [WIN=Y]

CC = gcc
CFLAGS = -O3 -g -Werror -Wall
LDFLAGS = -L/usr/lib

SRCDIR = src
TARGET = roguelike
SRC = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRC:.c=.o)

ifeq ($(WIN), Y)
	CC = x86_64-w64-mingw32-gcc
	LDFLAGS += -lpdcurses
else
	LDFLAGS += -lm -lncurses
endif

build/$(TARGET) :
# options
ifeq ($(WIN), Y)
	@echo -e "\n=========================="
	@echo -e "Building Windows binary..."
	@echo -e "==========================\n"
	@sed -i 's/ncurses.h/pdcurses.h/g' $(SRCDIR)/$(TARGET).h
	@sed -i 's/main/WinMain/g' $(SRCDIR)/$(TARGET).c
else
	@echo -e "\n========================"
	@echo -e "Building Linux binary..."
	@echo -e "========================\n"
	@sed -i 's/pdcurses.h/ncurses.h/g' $(SRCDIR)/$(TARGET).h
	@sed -i 's/WinMain/main/g' $(SRCDIR)/$(TARGET).c
endif
	@echo -e "Build options:"
	@echo -e "CC = $(CC)"
	@echo -e "CFLAGS = $(CFLAGS)"
	@echo -e "LDFLAGS = $(LDFLAGS)\n"

	@cp -r assets/ build/

	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS)
	@echo "Done!"


.PHONY: clean
clean :
	rm -rf $(OBJS)
	rm -rf build/*.exe
	rm -rf build/roguelike
	rm -rf build/assets
