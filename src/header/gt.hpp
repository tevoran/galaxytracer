#ifndef _gt_hpp
#define _gt_hpp

#include <SFML/Graphics.hpp>

namespace gt
{
  //configuration class
  class config
  {
  private:
    int resx;
    int resy;
    bool live;
    long int seed;
  public:
    config(); //constructor
    void readconfig(); //read the config file data/config
    int getresx(); //getting the x-resolution
    int getresy(); //getting the y-resolution
    long int getseed(); //getting the seed
    bool getlive(); //getting the live-value
  };
  
  //GUI class
  class gui
  {
  private:
    //SFML objects
    sf::RenderWindow* window; //the sfml window object
    sf::Vector2i mouseposition; //sfml vector for the mouse location
    
    //SFML drawing objects
    sf::ConvexShape mousepointer; //the mousepointer drawing object
    
    //GUI variables
    bool render_interface; //the state of the renderinterface
  public:
    gui(int resx, int resy); //constructor for creating the gui
    bool update(); //the update for each frame
    void locatemouse(gt::config config_gt); //locate the mouse in the used window
    void drawpixel(int x,int y,int r,int g, int b); //draw a pixel
    
  };
}


#endif
