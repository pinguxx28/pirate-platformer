#pragma once

#include <stdbool.h>

typedef struct {
	int x, y;
	int xvel;
	bool active;
} bullet;

#define BULLETS_LEN 255
extern bullet bullets[BULLETS_LEN];

void bullet_new(int x, int y, int xvel);
void bullets_init();
void bullets_update();
void bullets_draw();
