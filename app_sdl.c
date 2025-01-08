#include "app_sdl.h"

int app_init()
{
    // Initiera motorn
    if (!engine_init())
    {
        return 0;
    }

    // Initiera fontsystemet
    if (!font_init())
    {
        return 0;
    }

    return 1;
}

void app_quit()
{
    // Stäng motorn
    engine_quit();
}

void app_draw()
{
}

void app_loop()
{
    int quit = 0;
    SDL_Event e;
    SDL_Color black = {0x00, 0x00, 0x00, 0xFF};  // Definiera svart färg

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = 1;
            }
        }

        engine_clear(black);  // Använd engine_clear med svart färg
        app_draw();
        SDL_RenderPresent(get_renderer());
    }
}
