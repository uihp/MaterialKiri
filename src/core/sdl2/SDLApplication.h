/* SPDX-License-Identifier: MIT */
/* Copyright (c) Kirikiri SDL2 Developers */

#pragma once
#include "tjsCommHead.h"
#include <SDL3/SDL.h>

extern void krkrsdl2_pre_init_platform(void);
extern void krkrsdl2_set_args(int argc, tjs_char **argv);
extern void krkrsdl2_convert_set_args(int argc, char **argv);
extern bool krkrsdl2_init_platform(void);
extern bool krkrsdl2_process_events(void);
extern void sdl_process_events(SDL_Event event);
extern void krkrsdl2_cleanup(void);
