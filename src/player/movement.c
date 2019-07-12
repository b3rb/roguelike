/* player movement functions */

void PrintPlayer(int x, int y);
bool MovePlayer(int direction, char map[255][255]);

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


