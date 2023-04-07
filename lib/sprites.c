#include "lib/sprites.h"

#include "lib/helper.h"

ALLEGRO_BITMAP *sprite_sheet;

ALLEGRO_BITMAP *grab_sprite(int x, int y, int w, int h, const char *str)
{
	ALLEGRO_BITMAP *sprite = al_create_sub_bitmap(sprite_sheet, x, y, w, h);
	init_err(sprite, str);

	return sprite;
}

void load_sprite_sheet(const char *str)
{
	sprite_sheet = al_load_bitmap(str);
	init_err(sprite_sheet, "sprite sheet");
}
