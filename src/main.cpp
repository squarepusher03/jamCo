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
#include <stdexcept>
#include <iostream>
#include <array>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

#include "../include/Exceptions.h"
#include "../include/UI/Window.h"

using namespace Jam;


// initializes shit used in project (e.g. SDL2, JUCE, Boost, etc.)
void init();

// closes subsystems specified successfully initialized, specified by params 
void close();

int main( int argc, char* args[] )
{
  try 
  {
    init();
  }
  catch ( const SDLSubsystemException& e )
  {
    std::cerr << "SDL subsystem failed to initialize: " << e.what() << std::endl;
    return -1;
  }
  catch ( const SDLImageSubsystemException& e )
  {
    std::cerr << "SDL image subsystem failed to initialize: " << e.what() << std::endl;
    SDL_Quit();
    return -1;
  }
  catch ( ... )
  {
    std::cerr << "Unknown error during subsys initialization." << std::endl;
    return -1;
  }

  std::unique_ptr<JamUI::Window> window( nullptr );

  try 
  {
    window.reset( new JamUI::Window() );
  } 
  catch ( const WindowInitializationException& e ) 
  {
    std::cerr << "Window wrapper failed to initialize: " << e.what() << std::endl;
    close();
    return -1;
  }
  catch ( const FileNotFoundException& e )
  {
    std::cerr << "Asset path not found: " << e.what() << std::endl;
    close();
    return -1;
  }
  catch ( const TextureInitializationException& e )
  {
    std::cerr << "SDL issue occured when making texture: " << e.what() << std::endl;
    close();
    return -1;
  }
  catch ( const NullChildElementException& e )
  {
    std::cerr << e.what() << std::endl;
    close();
    return -1;
  }
  catch ( ... )
  {
    std::cerr << "Unknown runtime error occurred." << std::endl;
    close();
    return -1;
  }

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

    SDL_RenderClear( window->getRenderer() );
    window->render();
    SDL_RenderPresent( window->getRenderer() );
  }

  close();
  
  return 0;
}

void init()
{
  if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    throw SDLSubsystemException( SDL_GetError() );
  else
  {
    if ( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) )
      throw SDLImageSubsystemException( IMG_GetError() );
  }

  if ( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
    std::cerr << "Warning: Linear texture filtering not enabled!\n";
}

void close()
{
  IMG_Quit();
  puts( "SDL Image quit" );
  SDL_Quit();
  puts( "SDL quit" );
}

