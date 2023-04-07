#include "lib/font.h"

#include "lib/helper.h"

ALLEGRO_FONT *font;

ALLEGRO_FONT *get_font()
{
	return font;
}

void font_init()
{
	font = al_create_builtin_font();
	init_err(font, "allegro font");
}
