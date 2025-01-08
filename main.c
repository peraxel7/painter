#include "app_sdl.h"

int main(int argc, char* args[])
{
    // Initiera applikationen
    if (!app_init())
    {
        app_quit();
        return 1;
    }

    // Kör huvudloopen
    app_loop();

    // Stäng applikationen
    app_quit();

    return 0;
}
