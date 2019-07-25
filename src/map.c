#include "roguelike.h"
#include "map.h"

Level *CreateMap(int width, int height);
void PrintMap(Level *lvl);

Level *CreateMap(int width, int height) {

  /* allocates memory */
  Level *lvl = malloc(sizeof(Level));
  lvl->map = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; ++i) {
    lvl->map[i] = malloc(sizeof(char));
  }

  /* assigns width and height variables */
  lvl->w = width;
  lvl->h = height;

  /* procedurally generates map */
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      lvl->map[y][x] = '.';
    }
  }

  return lvl;
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
