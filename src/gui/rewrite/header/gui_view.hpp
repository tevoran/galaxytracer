#ifndef gui_view_hpp
#define gui_view_hpp

#include <SFML/Graphics.hpp>

namespace gt
{
  namespace gui
  {
    class view
    {
    private:
      sf::RenderWindow* window;
    public:
      view(); //the constructor
      void display(); //displays the content of the window
    };
  }
}

#endif
