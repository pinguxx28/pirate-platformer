#include "decorations.h"

#include "../bitmap.h"

int decorations[MAP_H][MAP_W] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,2,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0 },
	{ 0,2,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0 },
	{ 0,2,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0 },
	{ 0,2,0,0,0,0,0,0,0,0,0,0,0,3,1,0,0,0,0,1 },
	{ 0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0 },
	{ 0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0 },
	{ 1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0 },
	{ 0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,2,0,0 },
	{ 0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,2,1,0 },
	{ 0,0,0,0,0,0,0,3,0,0,0,0,0,0,4,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,3,1,1,0,1,4,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
};

void decorations_draw() {
	int sx, sy;
	int dx, dy;
	const int sw = 8;
	const int sh = 8;
	int flip;

	for (int y = 0; y < MAP_H; y++) {
		for (int x = 0; x < MAP_W; x++) {
			if (!decorations[y][x]) continue;

			dx = x * TILE_SIZE;
			dy = y * TILE_SIZE;
			flip = 0;
			switch(decorations[y][x]) {
				case 1:
					sx = 24;
					sy = 48;
					break;
				case 2:
					sx = rand() % 3 * 8;
					sy = 104;
					break;
				case 3:
					flip = ALLEGRO_FLIP_HORIZONTAL;
				case 4:
					sx = 24;
					sy = 8;
					break;

			}

			al_draw_bitmap_region(decotileset, sx, sy, sw, sh, dx, dy, flip);
		}
	}
}
