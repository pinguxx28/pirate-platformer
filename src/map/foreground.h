#pragma once

#include "map.h"

#define LADDER 1
#define STAIR_LEFT 2
#define STAIR_RIGHT 3
#define BLOCK  4 // first block with collision

//#define FG_DEBUG

extern int foreground[MAP_H][MAP_W];
void foreground_draw();
