#include "widget.h"

void initWidget(Widget* widget, int x, int y, int width, int height, void (*draw)(Widget*, SDL_Renderer*), void (*update)(Widget*))
{
    widget->x = x;
    widget->y = y;
    widget->width = width;
    widget->height = height;
    widget->draw = draw;
    widget->update = update;
}
