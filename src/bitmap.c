#include "../src/bitmap.h"

#include <stdio.h>

ALLEGRO_BITMAP *characters;
ALLEGRO_BITMAP *tileset;
ALLEGRO_BITMAP *decotileset;

void bitmaps_load() {
	characters = al_load_bitmap("assets/characters.png");
	if (!characters) { printf("couldn't load characters\n"); exit(1); }

	tileset = al_load_bitmap("assets/tileset.png");
	if (!tileset) { printf("couldn't load tileset\n"); exit(1); }

	decotileset = al_load_bitmap("assets/decorations.png");
	if (!decotileset) { printf("couldn't load tilset\n"); exit(1); }
}
