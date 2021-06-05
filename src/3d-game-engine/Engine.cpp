#include <3d-game-engine/Engine.hpp>

#include <iostream>
#include <3d-game-engine/Window.hpp>

using namespace n3DGE;

extern Window* window;
Window* window = nullptr;

n3DGE::Engine::Engine() {
    window = new Window();
}

void n3DGE::Engine::update() {
    window->update();
}

n3DGE::Engine::~Engine() {
    delete window;
}