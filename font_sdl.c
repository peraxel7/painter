#include "font_sdl.h"
#include <stdio.h>

int font_init()
{
    // Initiera SDL_ttf
    if (TTF_Init() == -1)
    {
        printf("SDL_ttf kunde inte initieras! SDL_ttf Fel: %s\n", TTF_GetError());
        return 0;
    }

    return 1;
}

void font_quit()
{
    // Stäng SDL_ttf
    TTF_Quit();
}

TTF_Font* load_font(const char* path, int size)
{
    // Ladda font
    TTF_Font* font = TTF_OpenFont(path, size);
    if (font == NULL)
    {
        printf("Font kunde inte laddas! SDL_ttf Fel: %s\n", TTF_GetError());
        return NULL;
    }
    return font;
}

void close_font(TTF_Font* font)
{
    // Stäng font
    TTF_CloseFont(font);
}
