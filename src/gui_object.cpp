#include <iostream>
#include <SFML/Graphics.hpp>
#include "header/gt.hpp"
#include "header/gui_makros.hpp"

//constructor for the class gui_object
gt::guiobject::guiobject()
{
  marked=false; //initially not marked by the mouse
  
  //init SFML object
  object.setSize(sf::Vector2f(object_size_x,object_size_y));
  object.setFillColor(sf::Color(object_color));
  std::cout << "\nobject created\n";
}

//draw the object to the screen
void gt::guiobject::draw(sf::RenderWindow* windowforobject) //using pointer in cause of the usage in the class gui
{
  windowforobject->draw(object);
}

//setting the position of the object
void gt::guiobject::setposition(int x,int y)
{
  position_x=x;
  position_y=y;
  object.setPosition(position_x,position_y);
}

//checking for a collision with the mouse
void gt::guiobject::checkmouse(int mouse_x,int mouse_y)
{
  if(mouse_x>=position_x and
     mouse_x<=position_x+object_size_x and
     mouse_y>=position_y and
     mouse_y<=position_y+object_size_y and
     marked==false)//mouse collides then change color and set marked flag
    {
      marked=true;
      object.setFillColor(sf::Color(object_color_marked)); //setting the highlight color
    }
  if((mouse_x<position_x or
     mouse_x>position_x+object_size_x or
     mouse_y<position_y or
     mouse_y>position_y+object_size_y) and
     marked==true)
    {
      marked=false;
      object.setFillColor(sf::Color(object_color)); //setting the normal color
    }
}
