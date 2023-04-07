#pragma once

#include <stdbool.h>

typedef struct {
	int x, y;
	int w, h;

	int dir, facing;

	bool idle;
	bool running;

	bool gun;
	int gun_timer;

	bool sword;
	int sword_timer;
	int sword_anim;
} player;

void player_init();
void player_update();
void player_draw();
