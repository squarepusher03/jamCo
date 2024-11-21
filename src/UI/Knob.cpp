#include <SDL2/SDL_render.h>

#include "../../include/UI/Knob.h"

namespace Jam::JamUI
{
  Knob::Knob( std::string path, SDL_Rect shape, SDL_Renderer* renderer ) 
    : Element( path, shape, renderer ) { m_clickable = true; }

  void Knob::move( Jam::JamEvent e, SDL_Point dest )
  {
    puts("move");
  }

  void Knob::update( Jam::JamEvent e )
  {
    puts("update");
  }
}
