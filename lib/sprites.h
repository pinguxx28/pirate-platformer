#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

ALLEGRO_BITMAP *grab_sprite(int x, int y, int w, int h, const char *str);
void load_sprite_sheet(const char *str);
