#pragma once

#include "widget.h"
#include <SDL2/SDL_ttf.h>

typedef struct Button
{
    Widget widget;
    const char* label;
    TTF_Font* font; // Lägg till denna rad för fonten
} Button;

Button* createButton(int x, int y, int width, int height, const char* label);
void drawButton(Widget* widget, SDL_Renderer* renderer);
void updateButton(Widget* widget);
