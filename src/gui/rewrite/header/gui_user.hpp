#ifndef gui_user_hpp
#define gui_user_hpp

#include "gui.hpp"
#include <SFML/Graphics.hpp>

#define gtNothing 0
#define gtClose 1
#define gtLeftClick 2

namespace gt
{
  namespace gui
  {
    class user
    {
    private:
      sf::Vector2i mouseposition; //the mouseposition
      sf::Event event; //the sfml event object
    public:
      user(); //constructor
      int update(gt::gui::view viewGUI); //the updatefunction for use in every frame and each event
    };
  }
}

#endif
