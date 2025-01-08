#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct Engine
{
    int running;
    SDL_Window* window;
    SDL_Renderer* renderer;
} Engine;

Engine* createEngine();
void destroyEngine(Engine* engine);
int initEngine(Engine* engine, const char* title, int width, int height);
void handleEvents(Engine* engine);
void updateEngine(Engine* engine);
void renderEngine(Engine* engine);
void cleanEngine(Engine* engine);
