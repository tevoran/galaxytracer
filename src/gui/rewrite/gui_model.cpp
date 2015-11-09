#include "header/gui_model.hpp"

#include <iostream>

//the external init routine for the guiModel
gt::gui::guiModel& gt::gui::guiModel::init()
{
  static guiModel _init;
  //std::cout << "location in RAM for GUI model: "<< &_init;
  
  return _init;
}
