#include "font.h"
#include <stdlib.h>

FontEngine *createFontEngine()
{
    FontEngine *fontEngine = (FontEngine *)malloc(sizeof(FontEngine));
    if (fontEngine != NULL)
    {
        fontEngine->font = NULL;
        fontEngine->renderer = NULL;

        for (int i = 0; i < 256; i++)
        {
            fontEngine->glyphTextures[i] = NULL;
            fontEngine->glyphWidths[i] = 0;
            fontEngine->glyphHeights[i] = 0;
        }
    }
    return fontEngine;
}

void initFontEngine(FontEngine *fontEngine, SDL_Renderer *renderer, const char *fontPath, int fontSize)
{
    fontEngine->renderer = renderer;
    fontEngine->font = TTF_OpenFont(fontPath, fontSize);

    for (int i = 0; i < 256; i++)
    {
        SDL_Surface *surface = TTF_RenderGlyph_Blended(fontEngine->font, (char)i, (SDL_Color){255, 255, 255, 255});
        if (surface != NULL)
        {
            fontEngine->glyphTextures[i] = SDL_CreateTextureFromSurface(renderer, surface);
            fontEngine->glyphWidths[i] = surface->w;
            fontEngine->glyphHeights[i] = surface->h;
            SDL_FreeSurface(surface);
        }
        else
        {
            fontEngine->glyphTextures[i] = NULL;
            fontEngine->glyphWidths[i] = 0;
            fontEngine->glyphHeights[i] = 0;
        }
    }
}

void renderText(FontEngine *fontEngine, const char *text, int x, int y)
{
    int offsetX = x;

    for (const char *c = text; *c != '\0'; c++)
    {
        SDL_Texture *glyphTexture = fontEngine->glyphTextures[(unsigned char)*c];
        if (glyphTexture != NULL)
        {
            int glyphWidth = fontEngine->glyphWidths[(unsigned char)*c];
            int glyphHeight = fontEngine->glyphHeights[(unsigned char)*c];
            SDL_Rect dstRect = {offsetX, y, glyphWidth, glyphHeight};
            SDL_RenderCopy(fontEngine->renderer, glyphTexture, NULL, &dstRect);
            offsetX += glyphWidth;
        }
    }
}

void destroyFontEngine(FontEngine *fontEngine)
{
    if (fontEngine->font)
    {
        TTF_CloseFont(fontEngine->font);
    }

    for (int i = 0; i < 256; i++)
    {
        if (fontEngine->glyphTextures[i] != NULL)
        {
            SDL_DestroyTexture(fontEngine->glyphTextures[i]);
        }
    }

    free(fontEngine);
}
