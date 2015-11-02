#include "../header/gt.hpp"
#include "../header/gui_makros.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <sstream>

//GUI class
void gt::gui::drawpixel(int x,int y,int r,int g,int b) //draw a single pixel
{
  sf::RectangleShape pixel;
  pixel.setSize(sf::Vector2f(1,1));
  pixel.setPosition(x,y);
  pixel.setFillColor(sf::Color(r,g,b));
  window->draw(pixel);
}

bool gt::gui::update() //updates the gui for each frame
//true == gui works
//false == gui is closed
{
  //mousepointer
  mousepointer.setPosition(mouseposition.x,mouseposition.y);
  bool mouseleft=mouseclickleft(); //check if the left mousebutton is pressed this frame

  //mouse collisions
  //checking the render options interface
  bool tmpcheckvalue=renderobject.checkmouse(mouseposition.x,mouseposition.y); //checks for collision of mouse and RENDEROPTIONS
  //open optional render_interface by clicking on RENDEROPTIONS
  if(tmpcheckvalue==true and
     mouseleft==true and
     render_interface==false)
    {
      render_interface=true;
      mouseleft=false; //important because the click has been handled
    }
  //closing optional render_interface by clicking on RENDEROPTIONS again
  if(tmpcheckvalue==true and
     mouseleft==true and
     render_interface==true)
    {
      render_interface=false;
    }
  //optional mousecollisions
  if(render_interface==true) //if user had clicked on renderoptions
    {
      liveobject.checkmouse(mouseposition.x,mouseposition.y);
      resolutionobject.checkmouse(mouseposition.x,mouseposition.y);
    }
  
  //draw all the gui stuff
  renderobject.draw(window);
  if(render_interface==true) //if user had clicked on the mouse
    {
      liveobject.draw(window);
      resolutionobject.draw(window);
    }
  seedshow.draw(window);
  
  window->draw(mousepointer);

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
  
  //doing the window based stuff
  window->display(); //display the rendered stuff
  window->clear(); //clear the screen
  return true;
}
