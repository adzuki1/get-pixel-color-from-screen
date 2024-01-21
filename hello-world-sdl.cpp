#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

#define WIDTH 320
#define HEIGHT 80
#define TITTLE "Get Pixel Color"


int main(){
    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        cerr << "SDL initialization failed: " << SDL_GetError() << endl;
        return 1;
    }

    // window components
    int x = SDL_WINDOWPOS_CENTERED;
    int y = SDL_WINDOWPOS_CENTERED;
    
    // Create a window
    // OS window
    SDL_Window *window = SDL_CreateWindow(
        TITTLE,
        x,
        y,
        WIDTH, 
        HEIGHT, 
        SDL_WINDOW_OPENGL);

    if(!window){
        cerr << "Window creation failed: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    // Main loop
    bool quit = false;
    SDL_Event event;

    while(!quit){
        // Event handling
        while(SDL_PollEvent(&event) != 0){
            if(event.type == SDL_QUIT)
                quit = true;
        }
        // some random logic here

        // Update window surface
        SDL_GetWindowSurface(window);

        SDL_Delay(16);
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
