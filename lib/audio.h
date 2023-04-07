#pragma once

#include <allegro5/allegro_audio.h>

typedef struct
{
	ALLEGRO_SAMPLE *sample;
	bool set;
} Audio;

void audio_init();
int  load_sample(const char *str);
void play_sample(int s, float volume);
