#include "../header/gt.hpp"
#include "../header/gui_makros.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <sstream>

//GUI class
gt::gui::gui(int resx,int resy,long seed,bool live) //gui class constructor
{
  //init variables
  render_interface=false; //this tells that the render interface is currently closed
  mouseleftlastframe=sf::Mouse::isButtonPressed(sf::Mouse::Left);
  //window
  window = new sf::RenderWindow(sf::VideoMode(resx,resy),"galaxytracer"); //creating the window
  window->clear(); //blackens the screen
  window->display(); //displays the empty screen
  window->setMouseCursorVisible(false); //doesn't display the mousecursor
  std::cout << "window created\n";
  
  //loading font
  //the font is a parameter for the gui objects
  std::cout << "loading font from data/font/octab-017.ttf...";
  if(!font.loadFromFile("data/font/octab-017.ttf"))
    {
      std::cout << "\nerror while reading font";
    }
  std::cout << "done\n";
  
  //SFML drawing objects
  std::cout << "initializing GUI content...";
  //mousepointer
  mousepointer.setPointCount(4); //the number of point that form mousepointer
  mousepointer.setPoint(0,sf::Vector2f(0,0));
  mousepointer.setPoint(1,sf::Vector2f(8,20));
  mousepointer.setPoint(2,sf::Vector2f(10,10));
  mousepointer.setPoint(3,sf::Vector2f(20,8));
  mousepointer.setFillColor(sf::Color(mousecolor));
  //renderoptions object
  renderobject.setposition(25,50);
  renderobject.settext(font,"RENDEROPTIONS");
  //seedshow object
  seedshow.setposition(resx-250,resy-75);
  std::string tmpstring="seed=";
  std::stringstream tmpstringstream;
  tmpstringstream << seed;
  tmpstring+=tmpstringstream.str();
  seedshow.settext(font,tmpstring,40);
  //liveobject
  liveobject.setposition(25,100);
  if(live==true)
    {
      liveobject.settext(font,"live: on");
    }
  if(live==false)
    {
      liveobject.settext(font,"live: off");
    }
  //resolutionobject
  resolutionobject.setposition(25,150);
  tmpstring="resolution: "; //defined at seedshow object
  tmpstringstream.str(""); //defined at seedshow object
  tmpstringstream << resx;
  tmpstring+=tmpstringstream.str();
  tmpstring+="x";
  tmpstringstream.str("");
  tmpstringstream << resy;
  tmpstring+=tmpstringstream.str();
  resolutionobject.settext(font,tmpstring,40);
  std::cout << "done\n";
  
}
