#include <iostream>
#include <SDL2/SDL.h>
#include "Util.hpp"
#include "View.hpp"
#include "TextView.hpp"
#include "ImageView.hpp"
#include "Button.hpp"

using namespace std;

void* myfun(void*)
{
    cout << "OK" << endl;
    return NULL;
}

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

    if (TTF_Init() != 0)
    {
        cout << "TTF_Error: " << TTF_GetError() << endl;
        return (EXIT_FAILURE);
    }
    
    SDL_Window *window = SDL_CreateWindow("Platformer Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    View vw(
        SDL_Rect{
            0,0,100,100
        },
        SDL_Color{
            255,255,255,255
        }
    );

    TextView tv(renderer, "Play", (SDL_Color){25,25,25,255}, (SDL_Rect){100,100,500,100},(SDL_Color){105,250,235,255});
    tv.set_alignment(TextAlign::TEXT_ALIGN_CENTER);

    vw.add_child(&tv);


    Button btn("Click ME",renderer,(SDL_Rect){100,200,100,100},(SDL_Color){255,255,0,255},(SDL_Color){255,255,255,255},myfun);

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
        
        vw.render(renderer);
        btn.render(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // ~60 fps
    }
    

    SDL_DestroyWindow(window);
    SDL_Quit();
    return (EXIT_SUCCESS);
}