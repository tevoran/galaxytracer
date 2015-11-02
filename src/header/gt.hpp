#ifndef _gt_hpp
#define _gt_hpp

#include <SFML/Graphics.hpp>
#include <string>


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
