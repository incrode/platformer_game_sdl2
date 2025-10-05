#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <cstdint>

class View
{
    private:

    SDL_Rect dmsns{};
    SDL_Color bgColor{};
    View *parent = NULL;

    std::vector<View*> children;


    public:
    SDL_Rect render_dmsns{};

    View(SDL_Rect dmsns, SDL_Color bgColor);
    SDL_Rect get_rect();
    void set_rect(SDL_Rect rect);
    View* get_parent();
    void set_parent(View *view);
    void add_child(View* view);
    int32_t get_child_index(View *view);
    void remove_child(uint32_t index);
    virtual void render(SDL_Renderer *renderer);
};