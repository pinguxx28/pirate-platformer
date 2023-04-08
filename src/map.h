#pragma once

#include "../lib/disp.h"

#define TILE_SIZE 8
#define MAP_W (BUFFER_W / TILE_SIZE)
#define MAP_H (BUFFER_H / TILE_SIZE)

extern int background[MAP_H][MAP_W];
extern int foreground[MAP_H][MAP_W];
extern int decorations[MAP_H][MAP_W];

void background_draw();
void foreground_draw();
void decorations_draw();
