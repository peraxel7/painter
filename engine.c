#include "engine.h"
#include <stdio.h>
#include <stdlib.h>

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
