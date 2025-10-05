#include "Button.hpp"

Button::Button(std::string text, SDL_Renderer *renderer, SDL_Rect dmsns, SDL_Color bgColor, SDL_Color textColor, ClickFn fn):
tv(renderer, text, bgColor, dmsns, textColor)
{
    if (fn) attachClickListener(fn);
}

void Button::attachClickListener(ClickFn fn)
{
    this->fn = fn;
}

void Button::detachClickListener()
{
    this->fn = NULL;
    this->returnStorage = NULL;
}

void Button::render(SDL_Renderer *renderer)
{
    if (this->fn != NULL)
    {
        int click = -1, mx = -1, my = -1;
        click = SDL_GetMouseState(&mx, &my);

        SDL_Point p = {mx,my};
        
        if (click && SDL_PointInRect(&p,&this->tv.render_dmsns))
        {
            this->returnStorage = this->fn(this);
        }
    }
    this->tv.render(renderer);
}