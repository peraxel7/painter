#include <SDL2/SDL_ttf.h>
#include "button.h"
#include <SDL2/SDL.h>
#include <stdlib.h>

Button* createButton(int x, int y, int width, int height, const char* label)
{
    Button* button = (Button*)malloc(sizeof(Button));
    initWidget(&button->widget, x, y, width, height, drawButton, updateButton);
    button->label = label;

    // Ladda fonten
    TTF_Font* font = TTF_OpenFont("Arial.ttf", 24);
    if (!font)
    {
        printf("Font kunde inte laddas: %s\n", TTF_GetError());
    }
    button->font = font;

    return button;
}

void drawButton(Widget* widget, SDL_Renderer* renderer)
{
    Button* button = (Button*)widget;

    // Rita knappen bakgrund
    SDL_SetRenderDrawColor(renderer, 192, 192, 192, 255);
    SDL_Rect rect = { button->widget.x, button->widget.y, button->widget.width, button->widget.height };
    SDL_RenderFillRect(renderer, &rect);

    // Rita knappen ram
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);

    // Rita knappen etikett
    SDL_Color textColor = { 0, 0, 0, 255 }; // Svart färg för text
    SDL_Surface* textSurface = TTF_RenderText_Solid(button->font, button->label, textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect = { button->widget.x + (button->widget.width - textSurface->w) / 2, button->widget.y + (button->widget.height - textSurface->h) / 2, textSurface->w, textSurface->h };
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}




void updateButton(Widget* widget)
{
    // Uppdateringslogik för knappen om det behövs
}
