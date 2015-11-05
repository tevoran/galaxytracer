#include <iostream>
#include "header/gt.hpp"

int main()
{
  //reading configfile
  std::cout << "reading data/config\n";
  gt::config* config_gt=&gt::config::init(); //creating the single config instance
  config_gt->readconfig(); //this reads data/config
  std::cout << "seed: " << config_gt->getseed() << "\n";
  
  //starting GUI
  std::cout << "starting GUI\n";
  gt::gui gui_gt(config_gt->getresx(),config_gt->getresy(),config_gt->getseed(),config_gt->getlive()); //this inits the GUI
  
  //mainloop
  std::cout << "entering main loop\n";
  while(gui_gt.update())
    {
      gui_gt.locatemouse(config_gt);
    }
  return 0;
}
