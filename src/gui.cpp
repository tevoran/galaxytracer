#include "header/gt.hpp"
#include "header/gui_makros.hpp"

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
  renderobject.setposition(50,50);
  renderobject.settext(font,"RENDEROPTIONS");
  //seedshow object
  seedshow.setposition(resx-300,resy-75);
  std::string tmpstring="seed=";
  std::stringstream tmpstringstream;
  tmpstringstream << seed;
  tmpstring+=tmpstringstream.str();
  seedshow.settext(font,tmpstring,40);
  //liveobject
  liveobject.setposition(50,100);
  if(live==true)
    {
      liveobject.settext(font,"live: on");
    }
  if(live==false)
    {
      liveobject.settext(font,"live: off");
    }
  //resolutionobject
  resolutionobject.setposition(50,150);
  tmpstring="resolution:"; //defined at seedshow object
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
}

bool gt::gui::mouseclickleft()
{
  bool returnvalue;
  mouseleftcurrentframe=sf::Mouse::isButtonPressed(sf::Mouse::Left);
  //return true if left button is pressed once
  if(mouseleftlastframe==true and mouseleftcurrentframe==true)
    {
      returnvalue=false;
    }
  if(mouseleftlastframe==true and mouseleftcurrentframe==false)
    {
      returnvalue=false;
    }
  if(mouseleftlastframe==false and mouseleftcurrentframe==true)
    {
      returnvalue=true;
    }
  if(mouseleftlastframe==false and mouseleftcurrentframe==false)
    {
      returnvalue=false;
    }
  //preparing next frame
  mouseleftlastframe=mouseleftcurrentframe;
  return returnvalue;
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
