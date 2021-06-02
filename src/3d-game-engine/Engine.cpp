#include <3d-game-engine/Engine.hpp>

#include <iostream>

n3DGE::Engine::Engine() {
    std::cout << "Initializing Engine." << std::endl;
}

void n3DGE::Engine::update() {
    std::cout << "Updating Engine." << std::endl;
}

n3DGE::Engine::~Engine() {
    std::cout << "Stopping Engine." << std::endl;
}