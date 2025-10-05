#include "View.hpp"
#include <iostream>

View::View(SDL_Rect dmsns, SDL_Color bgColor):dmsns(dmsns),bgColor(bgColor)
{}

void View::set_rect(SDL_Rect rect)
{
    this->dmsns = rect;
}

SDL_Rect View::get_rect()
{
    return this->dmsns;
}

View* View::get_parent()
{
    return this->parent;
}

void View::set_parent(View *view)
{
    this->parent = view;
}

void View::add_child(View *view)
{
    children.push_back(view);
    view->set_parent(this);
}

int32_t View::get_child_index(View* view)
{
    for (long long unsigned int i = 0; i < children.size(); i++)
    {
        if (children[i] == view) return i;
    }

    return -1;
}

void View::remove_child(uint32_t index)
{
    View *view = children[index];
    view->set_parent(NULL);

    children.erase(children.begin()+index);
}

void View::render(SDL_Renderer *renderer)
{
    // TODO: deal with child overflowing parent
    this->render_dmsns = {0,0,0,0};
    SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);

    View *temp = parent;
    while (temp != NULL)
    {
        SDL_Rect p_dmsns = temp->dmsns;

        render_dmsns.x += p_dmsns.x + this->dmsns.x;
        render_dmsns.y += p_dmsns.y + this->dmsns.y;
        render_dmsns.w = this->dmsns.w;
        render_dmsns.h = this->dmsns.h;
        
        temp = temp->parent;
    }

    if (this->parent == NULL) render_dmsns = this->dmsns;

    // Render View
    SDL_RenderFillRect(renderer, &render_dmsns);

    // Render Children
    for (View *view: children)
    {
        view->render(renderer);
    }
}