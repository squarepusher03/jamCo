#ifndef _JAM_UI_ELEMENT_H
#define _JAM_UI_ELEMENT_H

#include "../Events.h"
#include "../Exceptions.h"

#include <fmt/core.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>

#include <vector>
#include <memory>
#include <sstream>

namespace Jam::JamUI
{
  class Element
  {
  protected:
    bool m_clickable;
    std::string m_imgPath;

    SDL_Rect m_rect;

    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> m_texture;

    std::vector<std::unique_ptr<Element>> m_children;

  public:
    Element( std::string path, SDL_Rect shape, SDL_Renderer* renderer );
    Element( SDL_Rect shape );

    bool getClickability() { return m_clickable; }
    SDL_Rect* getViewport() { return &m_rect; }

    virtual void move( JamEvent e, SDL_Point dest );
    virtual void update( JamEvent e );

    void addChild( Element* child );

    SDL_Texture* getTexture() { return m_texture.get(); }
    Element* getChild( size_t index );
    size_t getNumberOfChildren() { return m_children.size(); }

    // debug methods
    virtual std::string toString();
  };
}

#endif // _JAM_UI_ELEMENT_H
