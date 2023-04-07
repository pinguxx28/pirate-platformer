#include "lib/helper.h"

#include <stdio.h>
#include <stdlib.h>

void init_err(bool test, const char *desc)
{
	if (test != EXIT_SUCCESS) return;

	printf("couldn't init %s\n", desc);
	printf("aborting program\n");
	exit(1);
}

int random_i(int low, int high)
{
	return low + (rand() % (high - low));
}

float random_f(float low, float high)
{
	return low + ((float)rand() / (float)RAND_MAX) * (high - low);
}
