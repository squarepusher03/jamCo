#include "../../include/UI/Window.h"
#include "../../include/UI/Knob.h"

#include <stdio.h>

namespace Jam::JamUI
{

  Window::Window()
    : m_window( nullptr, SDL_DestroyWindow ), m_renderer( nullptr, SDL_DestroyRenderer ), 
      m_shape( {0, 0, 1080, 720} ), m_rootElement( nullptr )
  {
    this->m_window.reset(
      SDL_CreateWindow( 
        "JamCo!!",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        this->m_shape.w, this->m_shape.h,
        SDL_WINDOW_SHOWN 
      ) 
    );

    if ( !this->m_window.get() )
    {
      throw WindowInitializationException( 
        fmt::format( "SDL window failed to initialize. SDL Error: {}", SDL_GetError() ) 
      );
    }

    this->m_renderer.reset( 
      SDL_CreateRenderer( this->m_window.get(), -1, SDL_RENDERER_ACCELERATED ) 
    );
    
    if ( !this->m_renderer.get() ) 
    {
      throw WindowInitializationException( 
        fmt::format( "SDL renderer failed to initialize. SDL Error: {}", SDL_GetError() ) 
      );
    }

    SDL_SetRenderDrawColor( this->m_renderer.get(), 0xFF, 0xFF, 0xFF, 0xFF );

    this->m_rootElement.reset( new Element( this->m_shape ) );

    this->m_rootElement->addChild( 
      new Knob( "../assets/knob.png", { 100, 100, 100, 100 }, this->m_renderer.get() ) 
    );

    this->m_rootElement->addChild(
      new Knob( "../assets/knob.png", { 300, 100, 100, 100 }, this->m_renderer.get() )
    );
    
    this->m_rootElement->getChild( 1 )->addChild( 
      new Knob( "../assets/knob.png", { 300, 300, 50, 50 }, this->m_renderer.get() ) 
    );
  }

  void Window::render()
  {
    h_render( *(this->m_rootElement.get()) );
  }

  void Window::h_render( Element& elem )
  {
    if ( elem.getNumberOfChildren() != 0 )
    {
      Element* childElement;
      for ( size_t index = 0; index < elem.getNumberOfChildren(); ++index )
      {
        childElement = elem.getChild( index );
        h_render( *childElement );
      }
    }

    if ( elem.getTexture() != nullptr )
    {
      SDL_RenderSetViewport( this->m_renderer.get(), elem.getViewport() );
      SDL_RenderCopy( this->m_renderer.get(), elem.getTexture(), NULL, NULL );
    }
  }

  SDL_Window* Window::getRealWindow()
  {
    return this->m_window.get();
  }

  SDL_Renderer* Window::getRenderer()
  {
    return this->m_renderer.get();
  }
}

