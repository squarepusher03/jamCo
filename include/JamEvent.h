#ifndef _JAM_EVENT_CODE
#define _JAM_EVENT_CODE

// 0-3, subsystems
// 4-?? UI shit
namespace Jam
{
  enum class JamEvent 
  {
    JAM_INVALID_EVENT = 0x00,
    JAM_SDL_INIT = 0x01,
    JAM_JUCE_INIT = 0x02,
    JAM_UI_MOUSE_DOWN = 0x03,
    JAM_UI_MOUSE_UP = 0x04,
    JAM_UI_DRAG_UP = 0x05,
    JAM_UI_DRAG_DOWN = 0x06
  };
}

#endif // _JAM_EVENT_CODE
