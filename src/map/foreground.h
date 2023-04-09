#pragma once

#include "map.h"

#define LADDER 1
#define BLOCK  2 // first block with collision

extern int foreground[MAP_H][MAP_W];
void foreground_draw();
