#include "roguelike.h"
#include "map.h"

bool LoadMap(FILE *fp, char path[], char buff[255][255]);
void PrintMap(char map[255][255]);

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
