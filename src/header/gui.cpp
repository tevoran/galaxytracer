#include "gt.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

//GUI class
gt::gui::gui(int resx, int resy) //gui class constructor
{
	render_interface=false; //this tells that the render interface
				//is currently closed
	window = new sf::RenderWindow(sf::VideoMode(resx,resy),"galaxytracer");
	window->clear(); //blackens the screen
	window->display(); //displays the empty screen
	std::cout << "window created\n";
}

bool gt::gui::update() //updates the gui for each frame
//true == gui works
//false == gui is closed
{
	sf::Event event;
	while(window->pollEvent(event))
	{
		if(event.type==sf::Event::Closed)
		{
			window->close();
			return false;
		}
	}
	window->display();
	window->clear();
	return true;
}
