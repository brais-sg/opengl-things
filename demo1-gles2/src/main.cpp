#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengles2.h>
#include <glm/glm.hpp>

#include <GLES2/gl2.h>

static int wx = 800;
static int wy = 600;


SDL_Window* window;
SDL_GLContext gContext;


int main(){
    printf("Init SDL...\n");
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("err: %s\n", SDL_GetError());
        return -1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);

    window = SDL_CreateWindow("OpenGL ES 2.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (!window){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Window creation failed: %s", SDL_GetError());
        return 1;
    }

    gContext = SDL_GL_CreateContext(window);
    if (!gContext){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "OpenGL context creation failed: %s", SDL_GetError());
        return 1;
    }

    printf("%s\n", glGetString(GL_VENDOR));
    printf("%s\n", glGetString(GL_RENDERER));
    printf("%s\n", glGetString(GL_VERSION));

    bool running = true;
    SDL_Event e;

    while(running){
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT){
                running = false;
            }
        }

        glClear(GL_COLOR_BUFFER_BIT);
        // Do stuff


        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(gContext);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}