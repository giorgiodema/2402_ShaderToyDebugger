// gui.h
#ifndef GUI_H
#define GUI_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include <stdexcept>
#define GLM_SWIZZLE 
#include <glm/glm.hpp>

namespace GUI {
    void initialize(int width, int height, const char* title);
    bool shouldClose();
    void drawPixelArray(std::vector<glm::vec4> &pixels, int width, int height);
    void cleanUp();
    glm::vec4 mouseCoords();
}

#endif // GUI_H