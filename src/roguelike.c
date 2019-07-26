#include "roguelike.h"
#include "map.h"
#include "player.h"

int main(int argc, char *argv[]) {

	/* initializes ncurses */
	initscr();
	noecho();

  /* creates map */
  Level *map = CreateMap(9, 5);
	
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
  DestroyMap(map);
  free(map);

	return 0;
}
