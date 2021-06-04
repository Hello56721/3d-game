#include <iostream>
#include <3d-game-engine/Engine.hpp>

int main(int argc, char** argv) {
    n3DGE::Engine engine;
    
    while (true) {
        engine.update();
    }
    
    return 0;
}