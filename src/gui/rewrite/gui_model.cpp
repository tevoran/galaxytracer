#include "header/gui_model.hpp"

#include <iostream>

//the external init routine for the guiModel
gt::gui::guiModel& gt::gui::guiModel::init()
{
  static guiModel _init;
  return _init;
}
