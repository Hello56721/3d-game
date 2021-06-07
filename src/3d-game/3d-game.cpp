#include <iostream>
#include <3d-game-engine/Engine.hpp>
#include <3d-game-engine/Window.hpp>

extern n3DGE::Window* window;

int main() {
    n3DGE::Engine engine;
    
    while (window->isOpen()) {
        engine.update();
    }
    
    return 0;
}