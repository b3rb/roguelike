#include "roguelike.h"

#define FLOOR '.'
#define HALL '#'

enum direction {UP, DOWN, LEFT, RIGHT};

bool LoadMap(FILE *fp, char path[], char buff[255][255]);
void PrintMap(char buff[255][255]);
void PrintPlayer(int x, int y);
void RefreshMap(char map[255][255]);
bool MovePlayer(int direction, char map[255][255]);

int WinMain(int argc, char *argv[]) {

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

	/* user input and WinMain gameloop */
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

bool LoadMap(FILE *fp, char path[], char buff[255][255]) {

	/* opens file for reading and checks for errors */
	bool success = true;
	fp = fopen(path, "r");
	if (fp == NULL) {
		perror("Failed to load map");
		success = false;
	}
	else {
		/* saves map to buffer */
		int lines = 0;
		while(fgets(buff[lines], 255, fp) != NULL) ++lines;

		/* closes file */
		fclose(fp);
	}

	return success;
}

void PrintMap(char buff[255][255]) {

	int x, y; /* player coords */
	getyx(stdscr, y, x);

	move(0, 0);
	for (int i = 0; *buff[i] != '\0'; ++i) {
		printw("%s", buff[i]);
	}

	/* restores cursor position */
	move(y, x);
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

