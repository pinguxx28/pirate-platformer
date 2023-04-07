#!/bin/bash

CC=cc
FILES="src/*.c lib/*.c"
CFLAGS="$(pkg-config allegro-5 allegro_font-5 allegro_primitives-5 allegro_audio-5 allegro_acodec-5 allegro_image-5 --libs --cflags) -I./"
OUTPUT="-o game.out"

set -e
$CC $FILES $CFLAGS $OUTPUT
