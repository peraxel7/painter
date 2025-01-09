#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct FontEngine
{
    TTF_Font *font;
    SDL_Texture *glyphTextures[256];
    int glyphWidths[256];
    int glyphHeights[256];
    SDL_Renderer *renderer;
} FontEngine;

FontEngine *createFontEngine();
void initFontEngine(FontEngine *fontEngine, SDL_Renderer *renderer, const char *fontPath, int fontSize);
void renderText(FontEngine *fontEngine, const char *text, int x, int y);
void destroyFontEngine(FontEngine *fontEngine);
