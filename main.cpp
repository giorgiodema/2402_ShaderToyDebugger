#include <gui.hpp>
#include <time.h>
#include <math.h>
#define GLM_SWIZZLE 
#include <glm/glm.hpp>
#include <chrono>

using namespace glm;

/*
* AUXILIARY DEFINITIONS
*/
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600
#define IDX(r,c)  ((r)*WINDOW_WIDTH + (c))
inline float startTimer() {
    static thread_local auto start = std::chrono::high_resolution_clock::now();
    auto now = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<float>(now - start).count();
}
std::vector<vec4> buffer0(WINDOW_WIDTH * WINDOW_HEIGHT);

/*
* SHADER INPUTS
*/
#define fragColor buffer0[IDX(r,c)]
#define fragCoord vec2(c,r)
#define iResolution vec2(WINDOW_WIDTH,WINDOW_HEIGHT)
#define iTime startTimer()
#define iMouse GUI::mouseCoords()
int iFrame = 0;

/*
*---- CUSTOM FUNCTIONS HERE ----
*/
/*
*-------------------------------
*/


int main() {

    GUI::initialize(WINDOW_WIDTH,WINDOW_HEIGHT,"CPU ShaderToy");
    while (!GUI::shouldClose()) {
        for(int r = 0; r < WINDOW_HEIGHT; r++){
            for(int c = 0; c < WINDOW_WIDTH; c++){
                /*
                *----- SHADERTOY CODE HERE -----
                */
                vec2 uv = fragCoord/iResolution;
                vec2 st = iMouse.xy()/iResolution.xy();
                vec3 col = 0.5f + 0.5f*cos(iTime+uv.xyx()+vec3(0.0,2.0,4.0));
                if(iMouse.z>=1.){
                    col = vec3(length(uv-st));
                }
                fragColor = vec4(col,1.0);
                /*
                *-------------------------------
                */
            }
        }
        GUI::drawPixelArray(buffer0,WINDOW_WIDTH,WINDOW_HEIGHT);
        iFrame += 1;
    }
    GUI::cleanUp();
    return 0;
}
