/* SPDX-License-Identifier: MIT */
/* Copyright (c) Kirikiri SDL2 Developers */

#include "SDLApplication.h"
#include "SysInitImpl.h"
#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
	krkrsdl2_pre_init_platform();

// #if defined(_WIN32) && defined(_UNICODE)
// 	krkrsdl2_set_args(argc, argv);
// #else
	krkrsdl2_convert_set_args(argc, argv);
// #endif

	if (krkrsdl2_init_platform())
	{
		return SDL_APP_SUCCESS;
	}

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate)
{
	if (krkrsdl2_process_events())
		return SDL_APP_CONTINUE;
	return SDL_APP_SUCCESS;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
	sdl_process_events(*event);
	if (event->type == SDL_EVENT_QUIT) return SDL_APP_SUCCESS;
	return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
#ifndef __EMSCRIPTEN__
	krkrsdl2_cleanup();
#endif
}
