#ifndef _JAM_UI_ELEMENT_H
#define _JAM_UI_ELEMENT_H

#include "../JamEvent.h"

#include <SDL2/SDL_render.h>

#include <memory>

namespace Jam::JamUI
{
  class Element
  {
  protected:
    bool m_clickable;
    std::shared_ptr<SDL_Rect> m_rect;
    std::shared_ptr<SDL_Texture> m_texture;

  public:
    Element( std::string path, SDL_Rect clip, SDL_Window* window, SDL_Renderer* renderer ); 
    virtual ~Element() = default; 

    bool getClickability() { return m_clickable; }

    virtual void move( JamEvent e, SDL_Point dest ) = 0;
    virtual void update( JamEvent e ) = 0;

    SDL_Texture* getTexture() { return m_texture.get(); }
  };
}

#endif // _JAM_UI_ELEMENT_H
