//
//  jamCo is a multiplayer electronic music jamming "game" built on SDL2
// 
//  main.cpp -- the driver for the game.
//
//  October 14th, 2024
//
//  Graham Hornecker
//

#include <stdio.h>
#include <array>

#include <SDL2/SDL_image.h>

#include "../include/UI/Knob.h"

using namespace Jam;

using JamSubsysEventArray = std::array<JamEvent, 3>;

// initializes subsystems used in project (e.g. SDL2, JUCE, Boost, etc.)
JamSubsysEventArray init();

// closes subsystems specified by param
void close( JamSubsysEventArray active );

int main( int argc, char* args[] )
{
  JamSubsysEventArray resultCodes = init();

  std::string path = "../assets/knob.png";

  SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
  
  std::shared_ptr<SDL_Window> window(
    SDL_CreateWindow(
      "JamCo!!!", 
      SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
      640, 480,
      SDL_WINDOW_SHOWN 
    ), 
    SDL_DestroyWindow
  );

  std::shared_ptr<SDL_Renderer> renderer( 
    SDL_CreateRenderer( window.get(), -1, SDL_RENDERER_ACCELERATED ), 
    SDL_DestroyRenderer 
  );

  SDL_Rect rect = { 100, 100, 100, 100 };

  std::shared_ptr<JamUI::Knob> knob1( 
   new JamUI::Knob( path, rect, window.get(), renderer.get() ) 
  ); 

  SDL_Event e;
  bool quit = false;

  while ( quit == false )
  {
    while ( SDL_PollEvent( &e ) )
    {
      switch( e.type )
      {
        case SDL_QUIT:
          quit = true;
          break;
      }
    }

    SDL_RenderClear( renderer.get() );
    SDL_RenderCopy( renderer.get(), knob1->getTexture(), NULL, NULL );
    SDL_RenderPresent( renderer.get() );
  }

  close( resultCodes );
  
  return 0;
}

JamSubsysEventArray init()
{
  JamSubsysEventArray result;

  if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
  {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    if ( true ) // TODO
      IMG_Init( IMG_INIT_PNG );
    else
      printf("fuck");
  }
  else
    result[0] = JamEvent::JAM_SDL_INIT;

  result[1] = JamEvent::JAM_INVALID_EVENT;
  result[2] = JamEvent::JAM_INVALID_EVENT;

  return result;
}

void close( JamSubsysEventArray result )
{
  for ( JamEvent e : result )
  {
    switch ( e )
    {
      case JamEvent::JAM_SDL_INIT:
        SDL_Quit();
        IMG_Quit();
        puts("SDL QUIT");
        break;

      case JamEvent::JAM_JUCE_INIT:
        puts("JUCE QUIT");
        break;

      case JamEvent::JAM_INVALID_EVENT:
        puts("INVALID SUBSYS EVENT");
        break;

      default:
        puts("Unrecognized type of subsystem event occurred.");
    }
  }
}

