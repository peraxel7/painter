#pragma once

#include <SDL2/SDL.h>

// Funktionsdeklarationer
int engine_init();
void engine_quit();
SDL_Renderer* get_renderer();
void engine_clear(SDL_Color color);
