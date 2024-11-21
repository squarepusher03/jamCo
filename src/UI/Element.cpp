#include "../../include/UI/Element.h"

namespace Jam::JamUI
{
  Element::Element( std::string path, SDL_Rect shape, SDL_Renderer* renderer )
    : m_imgPath( path ), m_rect( shape ), m_texture( nullptr, SDL_DestroyTexture )
  {
    std::unique_ptr<SDL_Surface, void(&)(SDL_Surface*)> loadedSurface( IMG_Load( path.c_str() ),
                                                                      SDL_FreeSurface );

    if ( loadedSurface == NULL )
    {
      throw FileNotFoundException( 
        fmt::format( "Intermediate element surface failed to initialize. IMG error: {}", 
                    IMG_GetError() )
      );
    }
    else
    {
      this->m_texture.reset( SDL_CreateTextureFromSurface( renderer, loadedSurface.get() ) );
      
      if ( this->getTexture() == NULL )
      {
        throw TextureInitializationException(
          fmt::format( "Texture failed to initialize from surface. SDL error: {}", 
                      SDL_GetError() )
        );
      }
    }
  }

  // for elem groups
  Element::Element( SDL_Rect clip ) 
    : m_imgPath( "" ), m_rect( clip ), m_texture( nullptr, SDL_DestroyTexture ) {}

  void Element::addChild( Element* child )
  {
    if ( child == NULL )
      throw NullChildElementException( "Tried adding null child element, wrong buzzer" );
    else
      this->m_children.push_back( std::unique_ptr<Element>( child ) );
  }

  Element* Element::getChild( size_t index )
  {
    if ( 0 <= index && index < this->m_children.size() )
    {
      return this->m_children[ index ].get();
    }

    return nullptr;
  }

  std::string Element::toString()
  {
    std::ostringstream buffer;

    if ( this->m_texture.get() == nullptr )
      buffer << "group element ";
    else
      buffer << this->m_imgPath << " @ " << this->getTexture() << "; ";

    buffer << "pos ( " << this->m_rect.x << ", " << this->m_rect.y << " ) ";
    buffer << "w/ size " << this->m_rect.w << "px x " << this->m_rect.h << "px";

    return buffer.str();
  }
}

