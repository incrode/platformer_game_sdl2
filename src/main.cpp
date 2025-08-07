#include <iostream>
#include <SDL2/SDL.h>
#include "Util.hpp"

using namespace std;

int main(int ac, char *av[])
{
    (void) ac;
    (void) av;
    // TODO: do something with args

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        cout << "SDL_Error: " << SDL_GetError() << "\n";
        return (EXIT_FAILURE);
    }
    
    SDL_Window *window = SDL_CreateWindow("Platformer Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);


    SDL_Event e;
    bool running = true;

    // Game loop
    while(running)
    {
        while(SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                running = false;
                break;
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // ~60 fps
    }
    

    SDL_DestroyWindow(window);
    SDL_Quit();
    return (EXIT_SUCCESS);
}