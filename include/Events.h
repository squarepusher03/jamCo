#ifndef _JAM_EVENT_CODE
#define _JAM_EVENT_CODE

// 0-3, subsystems
// 4-?? UI shit
namespace Jam
{
  enum class JamEvent 
  {
    JAM_INVALID_EVENT,
    JAM_SDL_INIT,
    JAM_SDL_IMG_INIT,
    JAM_JUCE_INIT,
    JAM_UI_MOUSE_DOWN,
    JAM_UI_MOUSE_UP,
    JAM_UI_DRAG_UP,
    JAM_UI_DRAG_DOWN
  };
}

#endif // _JAM_EVENT_CODE
