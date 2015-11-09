#include <iostream>
#include "header/gt.hpp"
#include "gui/rewrite/header/gui.hpp"

int main()
{
  //reading configfile
  std::cout << "reading data/config\n";
  gt::config* config_gt=&gt::config::init(); //creating the single config instance
  config_gt->readconfig(); //this reads data/config
  std::cout << "seed: " << config_gt->getseed() << "\n";
  
  //starting GUI
  std::cout << "starting GUI\n";
  gt::gui::guiModel* modelGUI=&gt::gui::guiModel::init(); //init GUI model
  std::cout << "location of the GUI model in RAM: " << modelGUI << "\n";
  gt::gui::controller* controllerGUI=&gt::gui::controller::init(); //init GUI controller
  std::cout << "location of GUI controller in RAM: " << controllerGUI << "\n";
  gt::gui::view viewGUI; //init GUI view
  gt::gui::user userGUI; //init GUI user
  
  //  gt::gui gui_gt(config_gt->getresx(),config_gt->getresy(),config_gt->getseed(),config_gt->getlive()); //this inits the GUI
  
  //mainloop
  std::cout << "entering main loop\n";
  while(1)
    {
      viewGUI.display();
      //gui_gt.locatemouse(config_gt);
    }
  return 0;
}
