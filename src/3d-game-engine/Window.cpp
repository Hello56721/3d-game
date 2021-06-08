#include <glad/glad.h>

#include <3d-game-engine/Window.hpp>

#include <GLFW/glfw3.h>
#include <iostream>
#include <string_view>

using namespace n3DGE;

Window::Window() {
    if (!glfwInit()) {
        std::cerr << "[FATAL ERROR]: Failed to initialize GLFW. Program will now exit." << std::endl;
        throw "FATAL::GLFW::INIT::FAILED";
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glfwWindowHint(GLFW_VISIBLE, true);
    
    // Get the width and height of the screen
    const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    
    window = glfwCreateWindow(videoMode->width / 2, videoMode->height / 2, "", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "[FATAL ERROR]: Failed to create GLFW window. Program will now exit." << std::endl;
        glfwTerminate();
        throw "FATAL::GLFW::WINDOW::CREATION::FAILED";
    }
    
    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cerr << "[FATAL ERROR]: Failed to load OpenGL function pointers. Program will now exit." << std::endl;
        glfwTerminate();
        throw "FATAL::glad::LOAD::OPENGL::FAILED";
    }
    
    // Lock the FPS to 60
    glfwSwapInterval(1);
}

Window::Window(unsigned int width, unsigned int height, std::string_view title, bool isFullscreen) {
    if (!glfwInit()) {
        std::cerr << "[FATAL ERROR]: Failed to initialize GLFW. Program will now exit." << std::endl;
        throw "FATAL::GLFW::INIT::FAILED";
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glfwWindowHint(GLFW_VISIBLE, true);
    
    GLFWmonitor* monitor = nullptr;
    
    if (isFullscreen) {
        // Get the width and height of the screen
        const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        this->width = videoMode->width;
        this->height = videoMode->height;
        
        monitor = glfwGetPrimaryMonitor();
    } else {
        this->width = width;
        this->height = height;
    }
    
    window = glfwCreateWindow(this->width, this->height, title.data(), monitor, nullptr);
    if (window == nullptr) {
        std::cerr << "[FATAL ERROR]: Failed to create GLFW window. Program will now exit." << std::endl;
        glfwTerminate();
        throw "FATAL::GLFW::WINDOW::CREATION::FAILED";
    }
    
    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cerr << "[FATAL ERROR]: Failed to load OpenGL function pointers. Program will now exit." << std::endl;
        glfwTerminate();
        throw "FATAL::glad::LOAD::OPENGL::FAILED";
    }
}

void Window::show() {
    glfwShowWindow(window);
}

bool Window::isOpen() {
    return !glfwWindowShouldClose(window);
}

void Window::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Window::setTitle(std::string_view newTitle) {
    glfwSetWindowTitle(window, newTitle.data());
}

void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    
    Window* classHandle = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
    classHandle->width = width;
    classHandle->height = height;
}

Window::~Window() {
    glfwDestroyWindow(window);
}