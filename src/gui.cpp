#include "header/gt.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

//GUI class
gt::gui::gui(int resx, int resy) //gui class constructor
{
	//init variables
	render_interface=false; //this tells that the render interface
				//is currently closed

	//window
	window = new sf::RenderWindow(sf::VideoMode(resx,resy),"galaxytracer"); //creating the window
	window->clear(); //blackens the screen
	window->display(); //displays the empty screen
	std::cout << "window created\n";
}


void gt::gui::drawpixel(int x,int y/*,int r,int g,int b*/) //draw a sinle pixel
{
	sf::RectangleShape pixel;
	pixel.setSize(sf::Vector2f(1,1));
	pixel.setPosition(x,y);
	window->draw(pixel);
}

bool gt::gui::update() //updates the gui for each frame
//true == gui works
//false == gui is closed
{
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
	window->display(); //display the rendered stuff
	window->clear(); //clear the screen
	return true;
}
