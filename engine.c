#include "engine.h"
#include <stdio.h>
#include <stdlib.h>

FontEngine* createFontEngine()
{
    FontEngine *fontEngine = malloc(sizeof(FontEngine));
    fontEngine->font = NULL;
    for (int i = 0; i < 256; i++)
    {
        fontEngine->glyphTextures[i] = NULL;
        fontEngine->glyphWidths[i] = 0;
        fontEngine->glyphHeights[i] = 0;
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
            fontEngine->glyphTextures[i] = SDL_CreateTextureFromSurface(fontEngine->renderer, surface);
            fontEngine->glyphWidths[i] = surface->w;
            fontEngine->glyphHeights[i] = surface->h;
            SDL_FreeSurface(surface);
        }
    }
}

void destroyFontEngine(FontEngine *fontEngine)
{
    for (int i = 0; i < 256; i++)
    {
        if (fontEngine->glyphTextures[i] != NULL)
        {
            SDL_DestroyTexture(fontEngine->glyphTextures[i]);
        }
    }

    TTF_CloseFont(fontEngine->font);
    free(fontEngine);
}

void renderTextFromFontEngine(FontEngine *fontEngine, const char *text, int x, int y)
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
            SDL_RenderCopy(fontEngine->renderer, glyphTexture, NULL, &dstRect); // Använd den sparade renderer
            offsetX += glyphWidth;
        }
    }
}



Engine* createEngine()
{
    Engine* engine = (Engine*)malloc(sizeof(Engine));
    engine->running = 0;
    engine->window = NULL;
    engine->renderer = NULL;
    return engine;
}

void destroyEngine(Engine* engine)
{
    free(engine);
}

int initEngine(Engine* engine, const char* title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL kunde inte initialiseras: %s\n", SDL_GetError());
        return 0;
    }

    if (TTF_Init() == -1)
    {
        printf("SDL_ttf kunde inte initialiseras: %s\n", TTF_GetError());
        return 0;
    }

    engine->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!engine->window)
    {
        printf("Fönstret kunde inte skapas: %s\n", SDL_GetError());
        return 0;
    }

    engine->renderer = SDL_CreateRenderer(engine->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!engine->renderer)
    {
        printf("Renderaren kunde inte skapas: %s\n", SDL_GetError());
        return 0;
    }

    engine->globalFont = TTF_OpenFont("Arial.ttf", 24); // Anpassa sökvägen och storleken
    if (!engine->globalFont)
    {
        SDL_Log("Failed to load font: %s", TTF_GetError());
        destroyEngine(engine);
        return 0;
    }

    engine->running = 1;
    return 1;
}

void handleEvents(Engine* engine)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            engine->running = 0;
        }
    }
}

void updateEngine(Engine* engine)
{
    // Uppdatera spelets tillstånd här
}

void renderEngine(Engine* engine)
{
    SDL_SetRenderDrawColor(engine->renderer, 0, 0, 0, 255);
    SDL_RenderClear(engine->renderer);
    // Rendera spelobjekt här
    SDL_RenderPresent(engine->renderer);
}

void cleanEngine(Engine* engine)
{
    if (engine->globalFont)
    {
        TTF_CloseFont(engine->globalFont);
    }
    if (engine->renderer)
    {
        SDL_DestroyRenderer(engine->renderer);
        engine->renderer = NULL;
    }
    if (engine->window)
    {
        SDL_DestroyWindow(engine->window);
        engine->window = NULL;
    }
    TTF_Quit();
    SDL_Quit();
}
