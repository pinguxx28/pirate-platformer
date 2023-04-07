#include "src/bitmap.h"

ALLEGRO_BITMAP *characters;

void bitmaps_load() {
	characters = al_load_bitmap("assets/characters.png");
}
