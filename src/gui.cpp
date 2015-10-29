#include "header/gt.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

//GUI class
gt::gui::gui(int resx, int resy) //gui class constructor
{
  //init variables
  render_interface=false; //this tells that the render interface is currently closed
  
  //window
  window = new sf::RenderWindow(sf::VideoMode(resx,resy),"galaxytracer"); //creating the window
  window->clear(); //blackens the screen
  window->display(); //displays the empty screen
  std::cout << "window created\n";

  //SFML drawing objects
  std::cout << "initializing GUI content...";
  mousepointer.setSize(sf::Vector2f(25,25)); //mousepointer size
  std::cout << "done\n";
  
}


void gt::gui::drawpixel(int x,int y,int r,int g,int b) //draw a single pixel
{
  sf::RectangleShape pixel;
  pixel.setSize(sf::Vector2f(1,1));
  pixel.setPosition(x,y);
  pixel.setFillColor(sf::Color(r,g,b));
  window->draw(pixel);
}

void gt::gui::locatemouse(gt::config config_gt) //locate the mouse in the used window
{
  mouseposition=sf::Mouse::getPosition(*window); //saving the location
  //keeping the mouseposition inside the window
  if(mouseposition.x<0)
    {
      mouseposition.x=0;
    }
  if(mouseposition.x>=config_gt.getresx())
    {
      mouseposition.x=config_gt.getresx()-1;
    }
  if(mouseposition.y<0)
    {
      mouseposition.y=0;
    }
  if(mouseposition.y>=config_gt.getresy())
    {
      mouseposition.y=config_gt.getresy()-1;
    }
  std::cout << "X:" << mouseposition.x << "\n";
  std::cout << "Y:" << mouseposition.y << "\n\n";
}

bool gt::gui::update() //updates the gui for each frame
//true == gui works
//false == gui is closed
{
  //mousepointer
  mousepointer.setPosition(mouseposition.x,mouseposition.y);
  //the sfml event loop
  sf::Event event;
  while(window->pollEvent(event))
    {
      if(event.type==sf::Event::Closed) //if the window is closed
	{
	  window->close();
	  return false;
	}
    }
  window->draw(mousepointer);
  window->display(); //display the rendered stuff
  window->clear(); //clear the screen
  return true;
}
