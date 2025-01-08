#include "engine.h"
#include "app.h"

int main(int argc, char* argv[])
{
    Engine* engine = createEngine();

    if (!initEngine(engine, "Painter", 800, 600)) {
        destroyEngine(engine);
        return -1;
    }

    runApp(engine);

    destroyEngine(engine);
    return 0;
}
