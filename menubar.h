#pragma once

#include "button.h"
#include "submenu.h"

typedef struct MenuBar
{
    Button** buttons;
    SubMenu** subMenus;
    int buttonCount;
} MenuBar;

MenuBar* createMenuBar();
void destroyMenuBar(MenuBar* menuBar);
void drawMenuBar(MenuBar* menuBar, SDL_Renderer* renderer);
void updateMenuBar(MenuBar* menuBar);
void handleMenuBarEvents(MenuBar* menuBar, SDL_Event* event);
