#include "submenu.h"
#include <stdlib.h>

SubMenu* createSubMenu(int x, int y, int buttonCount)
{
    SubMenu* menu = (SubMenu*)malloc(sizeof(SubMenu));
    menu->buttons = (Button**)malloc(buttonCount * sizeof(Button*));
    menu->buttonCount = buttonCount;
    menu->x = x;
    menu->y = y;
    menu->visible = 0; // Initialt inte synlig
    return menu;
}

void destroySubMenu(SubMenu* menu)
{
    for (int i = 0; i < menu->buttonCount; ++i)
    {
        free(menu->buttons[i]);
    }
    free(menu->buttons);
    free(menu);
}

void drawSubMenu(SubMenu* menu, SDL_Renderer* renderer)
{
    if (!menu->visible) return;

    for (int i = 0; i < menu->buttonCount; ++i)
    {
        menu->buttons[i]->widget.draw(&menu->buttons[i]->widget, renderer);
    }
}

void updateSubMenu(SubMenu* menu)
{
    if (!menu->visible) return;

    for (int i = 0; i < menu->buttonCount; ++i)
    {
        menu->buttons[i]->widget.update(&menu->buttons[i]->widget);
    }
}

void addButtonToSubMenu(SubMenu* menu, Button* button, int index)
{
    if (index >= 0 && index < menu->buttonCount)
    {
        button->widget.x = menu->x;
        button->widget.y = menu->y + index * button->widget.height;
        menu->buttons[index] = button;
    }
}

void toggleSubMenuVisibility(SubMenu* menu)
{
    menu->visible = !menu->visible;
}
