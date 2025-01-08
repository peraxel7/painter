#include "engine_sdl.h"
#include <stdio.h>

// Globala variabler för SDL
static SDL_Window* gWindow = NULL;
static SDL_Renderer* gRenderer = NULL;

int engine_init()
{
    // Initiera SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL kunde inte initieras! SDL Fel: %s\n", SDL_GetError());
        return 0;
    }

    // Skapa fönster
    gWindow = SDL_CreateWindow("SDL Engine",
                               SDL_WINDOWPOS_UNDEFINED,
                               SDL_WINDOWPOS_UNDEFINED,
                               640, 480,
                               SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
    {
        printf("Fönstret kunde inte skapas! SDL Fel: %s\n", SDL_GetError());
        return 0;
    }

    // Skapa renderer med VSync
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (gRenderer == NULL)
    {
        printf("Renderer kunde inte skapas! SDL Fel: %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}

void engine_quit()
{
    // Förstör renderer
    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;

    // Förstör fönster
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    // Stäng SDL
    SDL_Quit();
}

SDL_Renderer* get_renderer()
{
    return gRenderer;
}

void engine_clear(SDL_Color color)
{
    SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(gRenderer);
}
