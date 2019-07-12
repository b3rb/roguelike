/* map.h */

#ifndef _MAP_H
#define _MAP_H

/* loads map from .lvl file */
bool LoadMap(FILE *fp, char path[], char buff[255][255]);

/* prints map buffer and returns cursor to player */
void PrintMap(char map[255][255]);

#endif
