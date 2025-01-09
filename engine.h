#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct FontEngine
{
    TTF_Font *font;
    SDL_Texture *glyphTextures[256]; // Cachar ASCII-tecknen (0-255)
    int glyphWidths[256];           // Bredd för varje tecken
    int glyphHeights[256];          // Höjd för varje tecken
    SDL_Renderer *renderer;
} FontEngine;

typedef struct Engine
{
    int running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font *globalFont;
} Engine;

Engine* createEngine();
void destroyEngine(Engine* engine);
int initEngine(Engine* engine, const char* title, int width, int height);
void handleEvents(Engine* engine);
void updateEngine(Engine* engine);
void renderEngine(Engine* engine);
void cleanEngine(Engine* engine);
