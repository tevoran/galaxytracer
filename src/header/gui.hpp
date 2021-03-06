#ifndef _gui_hpp
#define _gui_hpp

#include "gt.hpp"
#include <SFML/Graphics.hpp>
#include <string>

namespace gt
{
  //GUI object
  class guiobject
  {
  private:
    sf::RectangleShape object; //the SFML object
    sf::Font font; //SFML font
    sf::Text text; //SFML text
    
    bool marked; //shows if mousepointer is over the object
    int position_x; //the x position
    int position_y; //the y position
  public:
    guiobject(); //the constructor
    void draw(sf::RenderWindow* windowforobject); //draw the object on the screen
    void settext(sf::Font font_in,std::string string); //set the text
    void settext(sf::Font font_in,std::string string,int size); //set the text and the charsize
    void setposition(int x,int y); //setting the position of the object
    bool checkmouse(int mouse_x,int mouse_y); //checking for collision with the mouse
  };
  
  //GUI class
  class gui
  {
  private:
    //SFML objects
    sf::RenderWindow* window; //the sfml window object
    sf::Vector2i mouseposition; //sfml vector for the mouse location
    sf::ConvexShape mousepointer; //the mousepointer drawing object
    sf::Font font; //SFML font
    
    //GUI objects
    gt::guiobject renderobject;
    gt::guiobject seedshow;
    gt::guiobject liveobject;
    gt::guiobject resolutionobject;
    
    //GUI variables
    bool render_interface; //the state of the renderinterface
    bool mouseleftcurrentframe; //the state of the left mousebutton in the current frame
    bool mouseleftlastframe; //the state of the left mousebutton in the last frame
    bool mouseleftclick; //if there is actually a click with the left mousebutton
    
  public:
    gui(int resx, int resy,long seed,bool live); //constructor for creating the gui
    bool update(); //the update for each frame
    void locatemouse(gt::config* config_gt); //locate the mouse in the used window
    bool mouseclickleft(); //shows if there was mouse click with the left button
    void drawpixel(int x,int y,int r,int g, int b); //draw a pixel
  };

}

#endif
