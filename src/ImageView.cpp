
#include "ImageView.hpp"
#include <SDL2/SDL_image.h>

ImageView::ImageView(SDL_Renderer *renderer,const char *image_path, SDL_Color bgColor)
: View(dstRect, bgColor)
{
    imgTx = LoadImage(renderer, image_path);
}

SDL_Texture* ImageView::LoadImage(SDL_Renderer *renderer, const char *image_path)
{
    return SDL_CreateTextureFromSurface(renderer,IMG_Load(image_path));
}

void ImageView::render(SDL_Renderer *renderer)
{
    SDL_Rect render_dmsns = {0,0,0,0};

    // updating background coords
    this->View::set_rect(dstRect);
    
    View *temp = get_parent();
    while (temp != NULL)
    {
        SDL_Rect p_dmsns = temp->get_rect();

        render_dmsns.x += p_dmsns.x + this->get_rect().x;
        render_dmsns.y += p_dmsns.y + this->get_rect().y;
        render_dmsns.w = this->dstRect.w;
        render_dmsns.h = this->dstRect.h;

        temp = temp->get_parent();
    }

    if (this->get_parent() == NULL)
    {
        render_dmsns.x = this->get_rect().x;
        render_dmsns.y = this->get_rect().y;
        render_dmsns.w = this->dstRect.w;
        render_dmsns.h = this->dstRect.h;
    }

    this->View::render(renderer);
    SDL_RenderCopy(renderer, imgTx, &srcRect, &render_dmsns);
}