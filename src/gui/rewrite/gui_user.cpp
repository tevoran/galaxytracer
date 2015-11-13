#include "header/gui_user.hpp"
#include <iostream>

gt::gui::user::user() //constructor
{
  std::cout << "GUI user created\n";
}

int gt::gui::user::update(gt::gui::view viewGUI) //check for the mouse and other events
{
  int returnvalue=gtNothing; //init returnvalue
  
  //checking for the mouseposition on the screen
  mouseposition=sf::Mouse::getPosition(*viewGUI.getWindow());
  
  //forcing the mouseposition to be inside the window
  if(mouseposition.x<0)
    mouseposition.x=0;
  if(mouseposition.x>viewGUI.getResX())
    mouseposition.x=viewGUI.getResX();
  if(mouseposition.y<0)
    mouseposition.y=0;
  if(mouseposition.y>viewGUI.getResY())
    mouseposition.y=viewGUI.getResY();

  //left click
  static bool lastFrameLeftClick=false;
  static bool currentFrameLeftClick=false;

  lastFrameLeftClick=currentFrameLeftClick; //setting the value for the last frame
  currentFrameLeftClick=sf::Mouse::isButtonPressed(sf::Mouse::Left); //current Frame
  if(currentFrameLeftClick==true and lastFrameLeftClick==false)
    returnvalue+=gtLeftClick; //set left click bit
  
  //getting events
  while(viewGUI.getWindow()->pollEvent(event))
    {
      //if window is closed
      if(event.type==sf::Event::Closed)
	{
	  viewGUI.getWindow()->close();
	  returnvalue+=gtClose; //set close window bit
	}
    }

  //close function
  return returnvalue;
}
