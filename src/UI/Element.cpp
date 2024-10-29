#include "../../include/UI/Element.h"

namespace Jam::JamUI
{
  Element::Element( std::string path, SDL_Rect clip, SDL_Window* window, SDL_Renderer* renderer )
    : m_rect( &clip ), m_texture(
        SDL_CreateTexture( 
          renderer, 
          SDL_GetWindowPixelFormat( window ), 
          SDL_TEXTUREACCESS_STATIC, 
          clip.w, clip.h 
        ),
        SDL_DestroyTexture
      ) 
  { }
}

