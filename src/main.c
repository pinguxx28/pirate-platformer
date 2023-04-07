#include "lib/helper.h"
#include "lib/disp.h"
#include "lib/key.h"
#include "lib/draw.h"
#include "lib/audio.h"
#include "lib/font.h"
#include "src/game.h"

#include <allegro5/allegro_image.h>
int main()
{
	init_err(al_init(), "allegro");
	init_err(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    init_err(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    init_err(queue, "queue");

	font_init();
	disp_init();
	audio_init();
	keyboard_init();

	init_err(al_init_primitives_addon(), "primitives addon");
	init_err(al_init_image_addon(), "image addon");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(get_disp()));
    al_register_event_source(queue, al_get_timer_event_source(timer));

	bool done = false;
	bool redraw = true;

    ALLEGRO_EVENT event;

	init();

    al_start_timer(timer);

    while(1)
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
				update();

                if(key[ALLEGRO_KEY_ESCAPE])
                    done = true;

                redraw = true;
                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;

        keyboard_update(&event);

        if(redraw && al_is_event_queue_empty(queue))
        {
            disp_pre_draw();
            al_clear_to_color(al_map_rgb(50,50,50));

			draw();

            disp_post_draw();
            redraw = false;
        }
    }

    disp_deinit();
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
}
