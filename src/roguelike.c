#include "roguelike.h"
#include "map.h"

enum direction {UP, DOWN, LEFT, RIGHT};

void PrintPlayer(int x, int y);
bool MovePlayer(int direction, char map[255][255]);

int main(int argc, char *argv[]) {

	FILE *fp = NULL;
	char map[255][255]; /* file buffer */

	/* loads files and assigns to buffer */
	if (!LoadMap(fp, "assets/lvls/map.txt", map)) {
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

void PrintPlayer(int x, int y) {

	/* moves cursor to spawn position and places player */
	mvprintw(y, x, "@");
	move(y, x);
}

bool MovePlayer(int direction, char map[255][255]) {

	bool success = true;;
	int x, y;
	getyx(stdscr, y, x); /* gets player coords */
	
	/* detects if movement is possible */
	switch(direction) {
		case UP:
			if (map[y - 1][x] == FLOOR || map[y - 1][x] == HALL) --y;
			break;

		case DOWN:
			if (map[y + 1][x] == FLOOR || map[y + 1][x] == HALL) ++y;
			break;

		case LEFT:
			if (map[y][x - 1] == FLOOR || map[y][x - 1] == HALL) --x;
			break;

		case RIGHT:
			if (map[y][x + 1] == FLOOR || map[y][x + 1] == HALL) ++x;
			break;

		default:
			break;
	}
	PrintPlayer(x, y);

	return success;
}

