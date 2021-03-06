#include "OpenGLDebug.hpp"

#include <glad/glad.h>
#include <string>
#include <iostream>

void n3DGE::OGLD::printErrors() {
    unsigned int errorCode = 0;
    while ((errorCode = glGetError()) != GL_NO_ERROR) {
        std::string error;
        switch (errorCode) {
        case GL_INVALID_ENUM:
            error = "GL_INVALID_ENUM";
            break;
        case GL_INVALID_VALUE:
            error = "GL_INVALID_VALUE";
            break;
        case GL_INVALID_OPERATION:
            error = "GL_INVALID_OPERATION";
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            error = "GL_INVALID_FRAMEBUFFER_OPERATION";
            break;
        case GL_STACK_OVERFLOW:
            error = "GL_STACK_OVERFLOW";
            break;
        case GL_STACK_UNDERFLOW:
            error = "GL_STACK_UNDERFLOW";
            break;
        case GL_OUT_OF_MEMORY:
            error = "GL_OUT_OF_MEMORY";
            break;
        default:
            error = std::to_string(errorCode);
            break;
        }
        
        std::cerr << "[OPENGL ERROR]: " << error << std::endl;
        
        debugBreak();
    }
}

void n3DGE::OGLD::debugBreak() {
    return;
}