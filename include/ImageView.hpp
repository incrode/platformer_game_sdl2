#pragma once

#include "View.hpp"

class ImageView: public View
{
    private:

    SDL_Texture *imgTx = NULL;

    public:

    SDL_Rect srcRect{0,0,0,0};
    SDL_Rect dstRect{0,0,0,0};

    ImageView(SDL_Renderer *renderer,const char *image_path, SDL_Color bgColor = {0,0,0,0});

    static SDL_Texture* LoadImage(SDL_Renderer *renderer, const char *image_path);

    void render(SDL_Renderer *renderer);
};