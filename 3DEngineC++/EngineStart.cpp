#include "Engine.h"

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    Engine engine(800, 600, false);
    engine.setBackgroundColor(0.0f,0.0f,0.0f);
    engine.setMaxFPS(60);
    engine.run();

    return 0;
}
