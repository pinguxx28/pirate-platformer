#include "src/game.h"

#include "src/bitmap.h"
#include "src/bullets.h"
#include "src/player.h"

void init() {
	bitmaps_load();
	bullets_init();
	player_init();
}

void update() {
	bullets_update();
	player_update();
}

void draw() {
	bullets_draw();
	player_draw();
}
