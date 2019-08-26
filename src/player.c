/* player.c */

#include "roguelike.h"
#include "player.h"

void PrintPlayer(int x, int y);
bool MovePlayer(int direction, Level *lvl);

void PrintPlayer(int x, int y) {

	/* moves cursor to spawn position and places player */
	mvprintw(y, x, "@");
	move(y, x);
}

bool MovePlayer(int direction, Level *lvl) {

  bool success = true;
  int x, y;
  getyx(stdscr, y, x); /* gets player coords */

	/* detects if movement is possible */
	switch(direction) {
		case UP:
      if (y - 1 >= 0) {
			  if (lvl->map[y - 1][x] == FLOOR) --y;
      }
			break;

		case DOWN:
      if (y + 1 < lvl->h) {
			  if (lvl->map[y + 1][x] == FLOOR) ++y;
      }
			break;

		case LEFT:
      if (x - 1 >= 0) {
			  if (lvl->map[y][x - 1] == FLOOR) --x;
      }
			break;

		case RIGHT:
      if (x + 1 < lvl->w) {
			  if (lvl->map[y][x + 1] == FLOOR) ++x;
      }
			break;

		default:
			break;
	}
	PrintPlayer(x, y);

return success;
}


