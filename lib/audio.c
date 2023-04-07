#include "lib/audio.h"

#include <stdio.h>
#include <allegro5/allegro_acodec.h>
#include "lib/helper.h"

#define AUDIO_LEN 255
Audio audio[AUDIO_LEN];

void audio_init()
{
	init_err(al_install_audio(), "audio");
	init_err(al_init_acodec_addon(), "audio codecs");
	init_err(al_reserve_samples(128), "reserve samples");

	for (int i = 0; i < AUDIO_LEN; ++i)
	{
		audio[i].set = false;
	}
}

int load_sample(const char *str)
{
	for (int i = 0; i < AUDIO_LEN; ++i)
	{
		if (audio[i].set) continue;

		audio[i].sample = al_load_sample(str);
		init_err(audio[i].sample, "audio sample");

		audio[i].set = true;
		return i;
	}

	printf("couldn't load sample %s\n", str);
	printf("aborting program\n");
	exit(1);
}

void play_sample(int s, float volume)
{
	al_play_sample(audio[s].sample, volume, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}
