
#include "Util.hpp"
#include "TextView.hpp"


TextView::TextView(SDL_Renderer *ren,std::string text, SDL_Color bgColor, SDL_Rect dmsns, SDL_Color color):View(dmsns,bgColor)
{
    textbox.x = dmsns.x;
    textbox.y = dmsns.y;
    textbox.w = dmsns.w;
    textbox.h = dmsns.h;

    this->textTx = LoadText(ren,
        "D:\\code\\yt_\\platformer_game_sdl2\\asset\\fonts\\PixelOperator8.ttf",
        text.c_str(),
        color,
        &this->textbox);
}

TTF_Font* TextView::LoadFont(const char *font_path, int ptsize)
{
    TTF_Font *font = TTF_OpenFont(font_path, ptsize);

    if (font == NULL)
    {
        std::cout << "Could not load font: " << TTF_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    return font;
}

SDL_Texture *TextView::LoadText(SDL_Renderer *renderer, const char* font_path, const char *text, SDL_Color textColor, SDL_Rect *textbox)
{
    TTF_Font *font = LoadFont(font_path, (3*textbox->h)/4);
    
    SDL_Surface *textSf = TTF_RenderText_Blended(font,text,textColor);

    SDL_Texture *textTx = SDL_CreateTextureFromSurface(renderer,textSf);

    if (textTx == NULL)
    {
        std::cout << "SDL_Error: " << SDL_GetError();
        exit(EXIT_FAILURE);
    }

    int measure_width = WINDOW_WIDTH;
    int count = 0;

    textbox->h = (TTF_FontHeight(font)*4)/3;
    TTF_MeasureText(font, text, measure_width, &textbox->w, &count);


    return textTx;
}

void TextView::set_alignment(TextAlign align)
{
    this->alignment = align;
}

void TextView::render(SDL_Renderer *ren)
{
    // TODO: use View::render_dmsns to update position
    this->View::render(ren);
    this->View::render_dmsns = {0,0,0,0};

    // horizontal alignment setup
    if (alignment == TEXT_ALIGN_CENTER)
    {
        textbox.x = get_rect().w/2;
        textbox.x -= textbox.w/2;
    } else if (alignment == TEXT_ALIGN_RIGHT)
    {
        textbox.x = get_rect().w - textbox.w;
    } else
    {
        textbox.x = 0;
    }
    textbox.y = get_rect().h/2 - textbox.h/2; // centering vertically always

    View *temp = get_parent();
    while (temp != NULL)
    {
        SDL_Rect p_dmsns = temp->get_rect();
        
        render_dmsns.x += p_dmsns.x + this->get_rect().x + textbox.x;
        render_dmsns.y += p_dmsns.y + this->get_rect().y + textbox.y;
        render_dmsns.w = this->textbox.w;
        render_dmsns.h = this->textbox.h;

        temp = temp->get_parent();
    }

    if (this->get_parent() == NULL)
    {
        render_dmsns.x = this->get_rect().x + textbox.x;
        render_dmsns.y = this->get_rect().y + textbox.y;
        render_dmsns.w = this->textbox.w;
        render_dmsns.h = this->textbox.h;
    }

    SDL_RenderCopy(ren, this->textTx, NULL, &render_dmsns);
}