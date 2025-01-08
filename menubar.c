#include "menubar.h"
#include <stdlib.h>

MenuBar* createMenuBar()
{
    MenuBar* menuBar = (MenuBar*)malloc(sizeof(MenuBar));
    menuBar->buttonCount = 3;
    menuBar->buttons = (Button**)malloc(menuBar->buttonCount * sizeof(Button*));
    menuBar->buttons[0] = createButton(0, 0, 100, 30, "File");
    menuBar->buttons[1] = createButton(100, 0, 100, 30, "Edit");
    menuBar->buttons[2] = createButton(200, 0, 100, 30, "Help");

    menuBar->subMenus = (SubMenu**)malloc(menuBar->buttonCount * sizeof(SubMenu*));
    menuBar->subMenus[0] = createSubMenu(0, 30, 2);
    menuBar->subMenus[1] = createSubMenu(100, 30, 2);
    menuBar->subMenus[2] = createSubMenu(200, 30, 2);

    addButtonToSubMenu(menuBar->subMenus[0], createButton(0, 0, 100, 30, "New"), 0);
    addButtonToSubMenu(menuBar->subMenus[0], createButton(0, 0, 100, 30, "Open"), 1);

    addButtonToSubMenu(menuBar->subMenus[1], createButton(0, 0, 100, 30, "Undo"), 0);
    addButtonToSubMenu(menuBar->subMenus[1], createButton(0, 0, 100, 30, "Redo"), 1);

    addButtonToSubMenu(menuBar->subMenus[2], createButton(0, 0, 100, 30, "About"), 0);
    addButtonToSubMenu(menuBar->subMenus[2], createButton(0, 0, 100, 30, "Help Topics"), 1);

    return menuBar;
}

void destroyMenuBar(MenuBar* menuBar)
{
    for (int i = 0; i < menuBar->buttonCount; ++i)
    {
        free(menuBar->buttons[i]);
        destroySubMenu(menuBar->subMenus[i]);
    }
    free(menuBar->buttons);
    free(menuBar->subMenus);
    free(menuBar);
}

void drawMenuBar(MenuBar* menuBar, SDL_Renderer* renderer)
{
    for (int i = 0; i < menuBar->buttonCount; ++i)
    {
        menuBar->buttons[i]->widget.draw(&menuBar->buttons[i]->widget, renderer);
        drawSubMenu(menuBar->subMenus[i], renderer);
    }
}

void updateMenuBar(MenuBar* menuBar)
{
    for (int i = 0; i < menuBar->buttonCount; ++i)
    {
        menuBar->buttons[i]->widget.update(&menuBar->buttons[i]->widget);
        updateSubMenu(menuBar->subMenus[i]);
    }
}

void handleMenuBarEvents(MenuBar* menuBar, SDL_Event* event)
{
    if (event->type == SDL_MOUSEBUTTONDOWN)
    {
        int x = event->button.x;
        int y = event->button.y;

        for (int i = 0; i < menuBar->buttonCount; ++i)
        {
            SDL_Rect buttonRect = { menuBar->buttons[i]->widget.x, menuBar->buttons[i]->widget.y, menuBar->buttons[i]->widget.width, menuBar->buttons[i]->widget.height };

            if (x >= buttonRect.x && x <= buttonRect.x + buttonRect.w && y >= buttonRect.y && y <= buttonRect.y + buttonRect.h)
            {
                toggleSubMenuVisibility(menuBar->subMenus[i]);
            }
            else
            {
                menuBar->subMenus[i]->visible = 0;
            }
        }
    }
}
