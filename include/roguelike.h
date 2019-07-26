/* roguelike.h */

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define FLOOR '.'

#ifndef _ROGUELIKE_H
#define _ROGUELIKE_H

typedef struct Level {
  int w, h;
  char **map;
} Level;

Level *CreateLevel(int width, int height);

#endif
