#pragma once

#include "button.h"

typedef struct SubMenu
{
    Button** buttons;
    int buttonCount;
    int x, y;
    int visible;
} SubMenu;

SubMenu* createSubMenu(int x, int y, int buttonCount);
void destroySubMenu(SubMenu* menu);
void drawSubMenu(SubMenu* menu, SDL_Renderer* renderer);
void updateSubMenu(SubMenu* menu);
void addButtonToSubMenu(SubMenu* menu, Button* button, int index);
void toggleSubMenuVisibility(SubMenu* menu);
