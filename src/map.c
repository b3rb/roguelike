#include "roguelike.h"
#include "map.h"

void CreateMap(Level *lvl);
void PrintMap(Level *lvl);

void CreateMap(Level *lvl) {

  /* procedurally generates map */
  for (int y = 0; y < lvl->h; y++) {
    for (int x = 0; x < lvl->w; x++) {
      lvl->map[y][x] = '.';
    }
  }
}

void PrintMap(Level *lvl) {

	int x, y; /* player coords */
	getyx(stdscr, y, x);

	move(0, 0);
	for (int y = 0; y < lvl->h; ++y) {
    for (int x = 0; x < lvl->w; ++x) {
      printw("%c", lvl->map[y][x]);
    }
    printw("\n");
	}

	/* restores cursor position */
	move(y, x);
}
