#pragma once

#include <SDL2/SDL.h>

typedef struct Widget
{
    int x, y, width, height;
    void (*draw)(struct Widget* widget, SDL_Renderer* renderer);
    void (*update)(struct Widget* widget);
} Widget;

void initWidget(Widget* widget, int x, int y, int width, int height, void (*draw)(Widget*, SDL_Renderer*), void (*update)(Widget*));
