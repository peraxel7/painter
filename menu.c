#include "menu.h"
#include <stdlib.h>

Menu* createMenu(int buttonCount)
{
    Menu* menu = (Menu*)malloc(sizeof(Menu));
    menu->buttons = (Button**)malloc(buttonCount * sizeof(Button*));
    menu->buttonCount = buttonCount;
    return menu;
}

void destroyMenu(Menu* menu)
{
    for (int i = 0; i < menu->buttonCount; ++i)
    {
        free(menu->buttons[i]);
    }
    free(menu->buttons);
    free(menu);
}

void drawMenu(Menu* menu, SDL_Renderer* renderer)
{
    for (int i = 0; i < menu->buttonCount; ++i)
    {
        menu->buttons[i]->widget.draw(&menu->buttons[i]->widget, renderer);
    }
}

void updateMenu(Menu* menu)
{
    for (int i = 0; i < menu->buttonCount; ++i)
    {
        menu->buttons[i]->widget.update(&menu->buttons[i]->widget);
    }
}

void addButtonToMenu(Menu* menu, Button* button, int index)
{
    if (index >= 0 && index < menu->buttonCount)
    {
        menu->buttons[index] = button;
    }
}
