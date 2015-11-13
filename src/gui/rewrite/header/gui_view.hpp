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
      int resx; //the resolution of the window x
      int resy; //and y
      
    public:
      view(); //the constructor
      sf::RenderWindow* getWindow(){return window;}; //if access to the window is needed
      int getResX(){return resx;}; //returns the x resolution
      int getResY(){return resy;}; //returns the y resolution
      void display(); //displays the content of the window
    };
  }
}

#endif
