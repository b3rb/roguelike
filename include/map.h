/* map.h */

#ifndef _MAP_H
#define _MAP_H

typedef struct Level {
  int w, h;
  char **map;
} Level;

/* creates procedurally generated map */
Level *CreateMap(int width, int height);

/* prints map buffer and returns cursor to player */
void PrintMap(Level *lvl);

/* frees resources from map array */
void DestroyMap(Level *lvl);

#endif
