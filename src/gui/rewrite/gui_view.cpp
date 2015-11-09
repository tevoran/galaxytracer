#include "header/gui_view.hpp"

#include "../../header/gt.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

//view constructor
gt::gui::view::view()
{
  //read config
  gt::config* config_gt=&gt::config::init();

  //creating the window
  std::cout << "Init SFML window...";
  window=new sf::RenderWindow(sf::VideoMode(config_gt->getresx(),config_gt->getresy()),"galaxytracer");
  window->clear();
  window->display();
  std::cout << "done\n";
}


//displays the content of the window and prepares it for the next frame
void gt::gui::view::display()
{
  window->display(); 
  window->clear(); //clears the window for the next frame
}
