#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "View.hpp"

enum TextAlign
{
    TEXT_ALIGN_LEFT,
    TEXT_ALIGN_RIGHT,
    TEXT_ALIGN_CENTER
};

class TextView : public View
{
private:
    SDL_Rect textbox = {};
    TextAlign alignment = TextAlign::TEXT_ALIGN_LEFT;
    SDL_Texture *textTx = NULL;

public:
    TextView(SDL_Renderer *ren, std::string text, SDL_Color bgColor = {}, SDL_Rect dmsns = {}, SDL_Color color = {255, 255, 255, 255});
    static TTF_Font *LoadFont(const char *font_path, int ptsize);
    static SDL_Texture *LoadText(SDL_Renderer *renderer, const char *font_path, const char *text, SDL_Color textColor, SDL_Rect *textbox = NULL);
    void set_alignment(TextAlign align);
    void render(SDL_Renderer *renderer);
};