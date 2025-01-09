//

#include "app.h"
#include "button.h"
#include "menubar.h"
#include <SDL2/SDL_ttf.h>

void runApp(Engine* engine)
{
    MenuBar* menuBar = createMenuBar();

    while (engine->running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                engine->running = 0;
            }
            handleMenuBarEvents(menuBar, &event);
        }

        updateEngine(engine);
        updateMenuBar(menuBar);

        SDL_SetRenderDrawColor(engine->renderer, 0, 0, 0, 255); // Rensa skärmen med svart
        SDL_RenderClear(engine->renderer);

        drawMenuBar(menuBar, engine->renderer);
        SDL_RenderPresent(engine->renderer);
    }

    destroyMenuBar(menuBar);
    TTF_Quit();
    cleanEngine(engine);
}
