/* player.h */

#ifndef _PLAYER_H
#define _PLAYER_H

enum direction {UP, DOWN, LEFT, RIGHT};

/* prints player at specified coordinates */
void PrintPlayer(int x, int y);

/* moves player 1 space in any direction */
bool MovePlayer(int direction, Level *lvl);

#endif
