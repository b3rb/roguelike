#include "roguelike.h"
#include "map.h"
#include "player.h"

int main(int argc, char *argv[]) {

	FILE *fp = NULL;
	char map[255][255]; /* file buffer */

	/* loads files and assigns to buffer */
	if (!LoadMap(fp, "assets/lvls/map.lvl", map)) {
		exit(1);
	}

	/* initialized ncurses */
	initscr();
	noecho();
	
	/* prints map and player */
	PrintMap(map);
	PrintPlayer(3, 4);
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

	return 0;
}
