#include "foreground.h"

#include "../../lib/draw.h"
#include "../bitmap.h"
#include <stdlib.h> // rand

int foreground[MAP_H][MAP_W] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 4,1,4,4,4,4,4,4,4,4,2,0,0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0,0,4,4,2,0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0,0,0,4,4,2,0,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0,0,0,0,4,4,2,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,1,4,4 },
	{ 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0 },
	{ 0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0 },
	{ 4,4,4,4,4,2,0,0,0,0,0,0,0,0,0,0,0,1,0,0 },
	{ 4,4,4,4,4,4,2,0,0,0,0,0,0,0,0,0,0,1,0,0 },
	{ 4,4,4,4,4,4,4,2,0,0,0,0,0,0,3,4,4,4,4,4 },
	{ 4,4,4,4,4,4,4,4,2,0,0,0,0,3,4,4,4,4,4,4 },
	{ 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
};

void foreground_draw() {
	srand(0);
	int sx, sy;
	int dx, dy;
	const int sw = 8;
	const int sh = 8;

	for (int y = 0; y < MAP_H; y++) {
		for (int x = 0; x < MAP_W; x++) {
			if (!foreground[y][x]) continue;

			dx = x * TILE_SIZE;
			dy = y * TILE_SIZE;

			int block = foreground[y][x];
			if (block < BLOCK) continue;

#ifdef FG_DEBUG
			// indicates ladder but ladders are drawn in decorations
			if (block == LADDER) {
				al_draw_rectangle(dx, dy, dx + TILE_SIZE, dy + TILE_SIZE, RED, 1);
				continue;
			} else if (block == STAIR_LEFT) {
				al_draw_rectangle(dx, dy, dx + TILE_SIZE, dy + TILE_SIZE, GREEN, 1);
				continue;
			} else if (block == STAIR_RIGHT) {
				al_draw_rectangle(dx, dy, dx + TILE_SIZE, dy + TILE_SIZE, BLUE, 1);
				continue;
			}
#endif

			switch(block) {
				case BLOCK:
					sx = rand() % 8;
					sy = 0;
					break;
			}

			al_draw_bitmap_region(tileset, sx, sy, sw, sh, dx, dy, 0);
		}
	}
}
