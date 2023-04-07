#include "src/player.h"

#include "lib/disp.h"
#include "lib/draw.h"
#include "lib/key.h"
#include "src/bitmap.h"
#include "src/bullets.h"

#define K_RIGHT ALLEGRO_KEY_RIGHT
#define K_LEFT  ALLEGRO_KEY_LEFT
#define P_MOV_SPD 1

#define K_GUN   ALLEGRO_KEY_X
#define P_GUN_CLDWN 60

#define K_SWORD ALLEGRO_KEY_Z
#define P_SWORD_CLDWN 60 // includes animation too
#define P_SWORD_ANIM  40

// facing directions
#define LEFT -1
#define RIGHT 1 

player p;

void player_init() {
	p.w = 8;
	p.h = 8;
	p.x = (BUFFER_W - p.w) / 2;
	p.y = (BUFFER_H - p.h);

	p.dir = 0;
	p.facing = 1;

	p.idle = true;
	p.running = false;

	p.gun = false;
	p.gun_timer = 0;

	p.sword = false;
	p.sword_timer = 0;
	p.sword_anim = 0;
}

static void player_handle_movement() {
	p.dir = key[K_RIGHT] - key[K_LEFT];

	p.idle = true;
	p.running = false;

	if (p.dir && !p.gun && !p.sword) {
		p.x += p.dir * P_MOV_SPD;
		p.idle = false;
		p.running = true;
	}

	if (p.dir != 0) {
		p.facing = p.dir;
	}
}

static void player_handle_gun() {
	if (p.gun_timer > 0) {
		p.gun_timer--;

		if (p.gun_timer == 0) {
			p.gun = false;

			if (p.facing == LEFT) {
				p.x += 4;
			}
		}
	}
	if (key[K_GUN] && p.gun_timer == 0) {
		p.gun = true;
		p.gun_timer = P_GUN_CLDWN;
		bullet_new(p.x + (p.w / 2), p.y + 4, p.facing * 3);

		if (p.facing == LEFT) {
			p.x -= 4;
		}
	}
}

static void player_handle_sword() {
	if (p.sword_timer > 0) {
		p.sword_timer--;
	}

	if (key[K_SWORD] && p.sword_timer == 0) {
		p.sword = true;
		p.sword_anim = P_SWORD_ANIM;
		p.sword_timer = P_SWORD_CLDWN;

		if (p.facing == LEFT) {
			p.x -= 2;
		}
	}

	if (p.sword_anim > 0) {
		p.sword_anim--;

		if (p.facing == LEFT && p.sword_anim + 1 == P_SWORD_ANIM / 2) {
			p.x -= 3;
		}
		if (p.sword_anim == 0) {
			p.sword = false;

			if (p.facing == LEFT) {
				p.x += 5;
			}
		}
	}
}

void player_update() {
	player_handle_movement();
	player_handle_gun();
	player_handle_sword();
}

void player_draw() {
	static int frames = 0;
	frames = (++frames % 40);

	int curr_anim = frames / 20;
	bool flip_hori = p.facing == LEFT;
	int sx, sy;
	int sw = 8, sh = 8;

	if (p.idle)	{
		sx = curr_anim * 16 + 3;
		sy = 4;
	}
	if (p.running) {
		sx = (curr_anim + 2) * 16 + 3;
		sy = 4;
		if (curr_anim == 0) sw = 9;
	}
	if (p.gun) {
		sx = (curr_anim + 4) * 16 + 3;
		sy = 4;
		sw = 12;
	}
	if (p.sword) {
		int sword_anim = 1 - p.sword_anim / 20;

		sx = (sword_anim + 6) * 16 + 3;
		sy = 4;
		if (sword_anim == 0) sw = 10;
		if (sword_anim == 1) sw = 13;
	}
	al_draw_bitmap_region(characters, sx, sy, sw, sh, p.x, p.y, flip_hori);
}
