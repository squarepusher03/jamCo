#ifndef _JAM_UI_KNOB_H
#define _JAM_UI_KNOB_H

#include <memory>
#include <string>

#include "Element.h"

namespace Jam::JamUI
{
  class Knob : public Element
  {
  public:
    Knob( std::string path, SDL_Rect shape, SDL_Renderer* renderer );

    void move( JamEvent e, SDL_Point dest ) override;
    void update( JamEvent e ) override;
  };
}

#endif // _JAM_UI_KNOB_H
