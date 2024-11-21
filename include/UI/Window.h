#ifndef _JAM_UI_WINDOW_H
#define _JAM_UI_WINDOW_H

#include <fmt/core.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

#include "../Exceptions.h"
#include "../UI/Element.h"

namespace Jam::JamUI
{
  class Window
  {
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
    SDL_Rect m_shape;

    std::unique_ptr<Element> m_rootElement;
    std::unique_ptr<Element> scenes[5];

    void h_render( Element& elem );

  public:
    Window();

    void render();

    SDL_Window* getRealWindow();
    SDL_Renderer* getRenderer();
  };
}

#endif // _JAM_UI_WINDOW_H
