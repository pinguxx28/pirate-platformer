#include "game.h"

#include "bitmap.h"
#include "bullets.h"
#include "player.h"
#include "map/background.h"
#include "map/foreground.h"
#include "map/decorations.h"

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
	background_draw();
	foreground_draw();
	decorations_draw();
	bullets_draw();
	player_draw();
}
