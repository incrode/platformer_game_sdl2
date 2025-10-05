#pragma once

#include "View.hpp"
#include "TextView.hpp"

typedef void* (*ClickFn)(void*);

// Button --> wrapper around TextView
class Button
{
private:
    TextView tv;
    ClickFn fn = NULL;

public:
    void *returnStorage = NULL;

    Button(std::string text, SDL_Renderer *renderer, SDL_Rect dmsns, SDL_Color bgColor, SDL_Color textColor, ClickFn fn = NULL);
    void attachClickListener(ClickFn fn);
    void detachClickListener();
    void render(SDL_Renderer *renderer);
};