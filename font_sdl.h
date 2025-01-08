#pragma once

#include <SDL2/SDL_ttf.h>

// Funktionsdeklarationer
int font_init();
void font_quit();
TTF_Font* load_font(const char* path, int size);
void close_font(TTF_Font* font);
