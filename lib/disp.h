#pragma once

#include <allegro5/allegro5.h>

#define BUFFER_W 160
#define BUFFER_H 120

#define DISP_SCALE 7
#define DISP_W (BUFFER_W * DISP_SCALE)
#define DISP_H (BUFFER_H * DISP_SCALE)

ALLEGRO_DISPLAY *get_disp();

void disp_init();
void disp_deinit();
void disp_pre_draw();
void disp_post_draw();
