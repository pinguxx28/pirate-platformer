#include "enemies.h"

enemy enemies[ENEMIES_LEN];

void enemy_new(int x, int y) {
	for (int i = 0; i < ENEMIES_LEN; i++) {
		if (enemies[i].active) continue;

		enemies[i].x = x;
		enemies[i].y = y;
		break;
	}
}

void enemies_init() {
	for (int i = 0; i < ENEMIES_LEN; i++) {
		enemies[i].hp = 10;
		enemies[i].active = false;
	}
}

void enemies_update() {
	for (int i = 0; i < ENEMIES_LEN; i++) {
		if (!enemies[i].active) continue;
	}
}

void enemies_draw() {
	for (int i = 0; i < ENEMIES_LEN; i++) {
		if (!enemies[i].active) continue;

		// TODO add enemies drawing
	}
}
