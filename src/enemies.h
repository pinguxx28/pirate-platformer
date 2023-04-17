#pragma once

#include <stdbool.h>

typedef struct {
	int x, y;
	int hp;
	bool active;
} enemy;

#define ENEMIES_LEN 255
extern enemy enemies[ENEMIES_LEN];

void enemy_new(int x, int y);
void enemies_init();
void enemies_update();
void enemies_draw();
