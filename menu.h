#pragma once

#include "button.h"

typedef struct Menu
{
    Button** buttons;
    int buttonCount;
} Menu;

Menu* createMenu(int buttonCount);
void destroyMenu(Menu* menu);
void drawMenu(Menu* menu, SDL_Renderer* renderer);
void updateMenu(Menu* menu);
void addButtonToMenu(Menu* menu, Button* button, int index);
