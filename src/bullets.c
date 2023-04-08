#include "../src/bullets.h"

#include "../lib/draw.h"

bullet bullets[BULLETS_LEN];

void bullet_new(int x, int y, int xvel) {
	for (int i = 0; i < BULLETS_LEN; i++) {
		if (bullets[i].active) continue;

		bullets[i].x = x;
		bullets[i].y = y;
		bullets[i].xvel = xvel;
		bullets[i].active = true;
		break;
	}
}

void bullets_init() {
	for (int i = 0; i < BULLETS_LEN; i++) {
		bullets[i].active = false;
	}
}

void bullets_update() {
	for (int i = 0; i < BULLETS_LEN; i++) {
		if (!bullets[i].active) continue;

		bullets[i].x += bullets[i].xvel;
	}
}

void bullets_draw() {
	for (int i = 0; i < BULLETS_LEN; i++) {
		if (!bullets[i].active) continue;

		al_draw_pixel(bullets[i].x, bullets[i].y, WHITE);
	}
}
