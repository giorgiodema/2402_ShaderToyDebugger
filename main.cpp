#include <gui.hpp>
#include <time.h>
#include <math.h>
#define GLM_SWIZZLE 
#include <glm/glm.hpp>
#include <chrono>

/*
* MACRO
*/
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600
#define IDX(r,c)  ((r)*WINDOW_WIDTH + (c))
#define fragColor buffer0[IDX(r,c)]
#define fragCoord vec2(c,r)
#define iResolution vec2(WINDOW_WIDTH,WINDOW_HEIGHT)
inline float startTimer() {
    static thread_local auto start = std::chrono::high_resolution_clock::now();
    auto now = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<float>(now - start).count();
}
#define iTime startTimer()

/*
* NAMESPACES
*/
using namespace glm;

/*
* GLOBAL VARIABLES
*/
std::vector<vec4> buffer0(WINDOW_WIDTH * WINDOW_HEIGHT);

int main() {

    GUI::initialize(WINDOW_WIDTH,WINDOW_HEIGHT,"CPU ShaderToy");
    while (!GUI::shouldClose()) {
        for(int r = 0; r < WINDOW_HEIGHT; r++){
            for(int c = 0; c < WINDOW_WIDTH; c++){
                /*
                *----- SHADERTOY CODE HERE -----
                */
                vec2 uv = fragCoord/iResolution;
                vec3 col = 0.5f + 0.5f*cos(iTime+uv.xyx()+vec3(0.0,2.0,4.0));
                fragColor = vec4(col,1.0);
                /*
                *-------------------------------
                */
            }
        }
        GUI::drawPixelArray(buffer0,WINDOW_WIDTH,WINDOW_HEIGHT);
    }
    GUI::cleanUp();
    return 0;
}
