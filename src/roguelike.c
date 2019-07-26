#include "roguelike.h"
#include "map.h"
#include "player.h"

Level *CreateLevel(int width, int height);
static void DestroyLevel(Level *lvl);

int main(int argc, char *argv[]) {

	/* initializes ncurses */
	initscr();
	noecho();

  /* creates map */
  Level *map = CreateLevel(9, 5);
  CreateMap(map);
	
	/* prints map and player */
	PrintMap(map);
	PrintPlayer(0, 0);
	refresh();

	/* user input and main gameloop */
	bool quit = false;
	while(!quit) {
		char input = getch();

		switch(input) {
			case 'w':
				PrintMap(map);
				MovePlayer(UP, map);
				break;

			case 's':
				PrintMap(map);
				MovePlayer(DOWN, map);
				break;

			case 'a':
				PrintMap(map);
				MovePlayer(LEFT, map);
				break;

			case 'd':
				PrintMap(map);
				MovePlayer(RIGHT, map);
				break;

			case 'q':
				quit = true;
				break;

			default:
				break;
		}
	}

	/* ends ncurses session */
	endwin();

  /* frees resources */
  DestroyLevel(map);

	return 0;
}

Level *CreateLevel(const int width, const int height) {

  /* allocates memory for level */
  Level *lvl = malloc(sizeof(Level));

  /* allocates memory for map */
  lvl->map = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    lvl->map[i] = malloc(sizeof(char) * width);
  }

  /* assigns width and height variables */
  lvl->w = width;
  lvl->h = height;

  return lvl;
}

static void DestroyLevel(Level *lvl) {

  /* frees resources for map */
  for (int i = 0; i < lvl->h; i++) {
    free(lvl->map[i]);
  }
  free(lvl->map);

  /* frees resources for level */
  free(lvl);
}
