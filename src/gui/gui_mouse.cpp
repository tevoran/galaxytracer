#include "../header/gt.hpp"
#include "../header/gui_makros.hpp"

#include <SFML/Graphics.hpp>

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
}


//checks for one single click
bool gt::gui::mouseclickleft()
{
  bool returnvalue;
  mouseleftcurrentframe=sf::Mouse::isButtonPressed(sf::Mouse::Left);
  //return true if left button is pressed once
  if(mouseleftlastframe==false and mouseleftcurrentframe==true)
    {
      returnvalue=true;
    }
  else
    {
      returnvalue=false;
    }
  //preparing next frame
  mouseleftlastframe=mouseleftcurrentframe;
  return returnvalue;
}
