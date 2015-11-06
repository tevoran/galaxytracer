#include "header/gui_controller.hpp"
#include <iostream>


gt::gui::controller& gt::gui::controller::init()
{
  static controller _init;
  std::cout << "init the GUI controller instance\n";
  return _init;
}
