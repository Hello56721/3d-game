#include <3d-game-engine/Engine.hpp>

#include <iostream>
#include <3d-game-engine/Window.hpp>
#include "OpenGLDebug.hpp"
#include <string>

using namespace n3DGE;

extern Window* window;
Window* window = nullptr;

struct {
    float deltaTime;
} Time;

n3DGE::Engine::Engine() {
    window = new Window();
    
    // Print out the OpenGL version
    std::cout << "[INFO]: Using OpenGL version " << glCallR(glGetString, GL_VERSION) << std::endl;
}

void n3DGE::Engine::update() {
    float startTime = glfwGetTime();
    
    window->update();
    
    float endTime = glfwGetTime();
    Time.deltaTime = endTime - startTime;
    
    window->setTitle(std::string("3D Game\tFPS: ") + std::to_string(static_cast<unsigned int>(1.0 / Time.deltaTime)));
}

n3DGE::Engine::~Engine() {
    delete window;
}